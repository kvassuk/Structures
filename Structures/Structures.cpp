// Structures.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "AnyType.h"
#include "exceptionType.h"
#include <crtdbg.h>
#include <iostream>


int main()
{
	AnyType a(5);

	try
	{
		double d = a.ToFloat();
	}
	catch (exceptionType& ex)
	{
		std::cout << ex.what() << std::endl;
	}


	std::cout << a.ToInt() << ' ';
	std::cout << a.current_container_type() << '\n';


	_CrtDumpMemoryLeaks();
	return 0;
}


