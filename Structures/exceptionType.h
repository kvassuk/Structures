#pragma once
#include <exception>

class exceptionType: public std::exception
{
public:
	exceptionType () :exception () {}
	const char* what () const throw ();	

};

