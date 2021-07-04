// Structures.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "AnyType.h"
#include "exceptionType.h"
#include <crtdbg.h>
#include <iostream>


int main()
{
	AnyType a;
	AnyType b('C');

	try
	{
		double d = a.ToFloat();
	}
	catch (exceptionType& ex)
	{
		std::cout << ex.what() << std::endl;
	}


	std::cout << a.ToBool() << ' ';
	std::cout << a.current_container_type() << '\n';
	a = std::move(b);
	std::cout << a.ToChar() << ' ';
	std::cout << a.current_container_type() << '\n';


	_CrtDumpMemoryLeaks();
	return 0;
}


