#pragma once
#ifndef TOKEN_H
#define TOKEN_H

#include <ostream>

namespace token
{
	enum Tag {NUM = 256, ID, TRUE, FALSE, RELOP};

	class Token
	{
	private:
		Tag _kind;

	public:
		Token()
		{}
		Token(Tag kind)
			: _kind{ kind }
		{}

		Tag get_tag() { return this->_kind; }
		std::ostream& operator<<(std::ostream& os);
	};

	class Num : public Token
	{
	private:
		int _value;

	public:
		// initialize parent class with NUM tag
		Num(int value)
			: Token(NUM), _value{value}
		{}

		int get_value() { return this->_value; }
		//std::ostream& operator<<(std::ostream& os);
	};

	class Word : public Token
	{
	private:
		std::string _attribute;

	public:
		Word(std::string attribute)
			: Token(ID), _attribute{ attribute }
		{}

		std::string get_attribute() { return this->_attribute; }
		//std::ostream& operator<<(std::ostream& os);
	};

	class Relop : public Token
	{
	private:
		std::string _attribute;

	public:
		Relop(std::string attribute)
			: Token(RELOP), _attribute{attribute}
		{}

		std::string get_attribute() { return this->_attribute; }
		//std::ostream& operator<<(std::ostream& os);
	};
}

#endif