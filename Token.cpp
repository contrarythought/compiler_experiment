#include "Token.h"

using namespace token;

std::ostream& Token::operator<<(std::ostream& os)
{
	return os << "<" << _kind << ">";
}
