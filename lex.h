#pragma once
#ifndef LEX_H
#define LEX_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include "Token.h"

namespace lex
{
	class Lexer
	{
	private:
		std::stringstream buffer;
		std::ifstream build_file;
		int line_number;
		std::unordered_map<std::string, token::Token> words_map;

	public:
		Lexer(std::string file);
		token::Token* scan();
		void reserve(token::Tag tag, std::string attribute);
		bool contains(const std::string& word);
	};
}

#endif