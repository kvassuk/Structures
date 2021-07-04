#pragma once
#include <exception>

class exceptionType: public std::exception
{
public:
	
	exceptionType(const char* msg = "Bad cast exception");

	const char* what() const throw ();
private:
	const char* message;

};

