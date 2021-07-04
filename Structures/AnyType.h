#pragma once
#include "exceptionType.h"
#include<string.h>
#include<typeinfo>

enum class  type_name
{
	type_int, type_char, type_double, type_float, type_bool
};



class AnyType
{
public:
	AnyType ();
	~AnyType ();
	explicit AnyType (int i);
	explicit AnyType (char ch);
	explicit AnyType (double d);
	explicit AnyType (float f);
	explicit AnyType (bool b);
	AnyType (const AnyType& other);
	AnyType& operator=(const AnyType& other);
	AnyType (AnyType&& other) noexcept;
	AnyType& operator=(AnyType&& other) noexcept;
	int ToInt () const;
	double ToDouble ()const;
	char ToChar ()const;
	float ToFloat ()const;
	bool ToBool ()const;
	void swap (AnyType& other);
	const char* current_container_type ();
	void operator=(int i);
	void operator=(char ch);
	void operator=(double d);
	void operator=(float f);
	void operator=(bool b);

private:

	struct data
	{	
		union variable
		{
			double var_double;
			float var_float;
			int var_int;
			char var_char;
			bool var_bool = false;
		};
		type_name  variabletype =type_name::type_bool;
		variable var;
	};
	

	data* container;
};

