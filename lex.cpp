#include "lex.h"

using namespace lex;

#define DEBUG 1

Lexer::Lexer(std::string file)
	: line_number{ 1 }
{
	build_file.open(file);

	if (!build_file)
	{
		std::cerr << "Failed to open file to lex" << std::endl;
		std::exit(1);
	}


#if DEBUG
	std::cout << "success" << std::endl;
#endif

	buffer << build_file.rdbuf();

	// reserve key words
	reserve(token::ID, "printf");
	reserve(token::TRUE, "true");
	reserve(token::FALSE, "false");
}

void Lexer::reserve(token::Tag tag, std::string attribute)
{
	words_map[attribute] = token::Word{ attribute };
}

int Lexer::get_num_value(const char& num)
{
	switch (num)
	{
	case '0':
		return 0;
	case '1':
		return 1;
	case '2':
		return 2;
	case '3':
		return 3;
	case '4':
		return 4;
	case '5':
		return 5;
	case '6':
		return 6;
	case '7':
		return 7;
	case '8':
		return 8;
	case '9':
		return 9;
	}
}

std::vector<token::Token> Lexer::scan()
{
	std::vector<token::Token> tokens;
	std::string input = "";
	for (; std::getline(buffer, input); )
	{
		for (unsigned int i = 0; i < input.length();)
		{
#if DEBUG
			std::cout << input[i] << std::endl;
#endif
			// take care of whitespace
			if (std::isspace(input[i]))
			{
				if (input[i] == '\n')
					line_number++;
				i++;
			}
			else
			{
				// take care of digits
				if (std::isdigit(input[i]))
				{
					int value = 0;
					do
					{
						value = value * 10 + get_num_value(input[i]);
#if DEBUG
						std::cout << "value: " << value << std::endl;
#endif
						i++;
					} while (std::isdigit(input[i]));

					// return new number token
#if DEBUG
					std::cout << "Num: " << value << std::endl;
#else
					tokens.push_back(token::Num{value});
#endif
				}
				else
				{
					// take care of id's
					std::string id_buf = "";
					for (; std::isalpha(input[i]) || std::isdigit(input[i]); i++)
						id_buf += input[i];

					// return id token
#if DEBUG
					std::cout << "ID: " << id_buf << std::endl;
#else
					tokens.push_back(contains(id_buf) ? words_map[id_buf] : token::Word{ id_buf });
#endif
				}
			}
		}

		input = "";
	}

	return tokens;
}

bool Lexer::contains(const std::string& word)
{
	return words_map.find(word) != words_map.end();
}
