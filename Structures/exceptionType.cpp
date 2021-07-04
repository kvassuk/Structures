#include "exceptionType.h"

const char* exceptionType::what () const throw()
{
    return "Bad cast exception";
}
