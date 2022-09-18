#include <iostream>
#include <string>
#include <fstream>
#include "lex.h"


int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "File to build" << std::endl;
		std::exit(1);
	}

	lex::Lexer* l = new lex::Lexer{ argv[1] };
	
	l->scan();

	delete l;
	return 0;
}
