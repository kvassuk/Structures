#include "exceptionType.h"

exceptionType::exceptionType(const char* msg)
	:exception()
{
	message= msg;
}

const char* exceptionType::what() const throw()
{
	return message;
}
