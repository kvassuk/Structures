#include "AnyType.h"
#include "exceptionType.h"
#include<typeinfo>

AnyType::AnyType()
{
	container = nullptr;

}


AnyType::~AnyType()
{
	delete container;
	container = nullptr;
}

AnyType::AnyType(int i)
{
	container = new data;
	container->var.var_int = i;
	container->variabletype = type_name::type_int;

}

AnyType::AnyType(char ch)
{
	container = new data;
	container->var.var_char = ch;
	container->variabletype = type_name::type_char;
}

AnyType::AnyType(double d)
{
	container = new data;
	container->var.var_double = d;
	container->variabletype = type_name::type_double;
}

AnyType::AnyType(float f)
{
	container = new data;
	container->var.var_float = f;
	container->variabletype = type_name::type_float;
}

AnyType::AnyType(bool b)
{
	container = new data;
	container->var.var_bool = b;
	container->variabletype = type_name::type_bool;
}

AnyType::AnyType(const AnyType& other)
{
	container = new data;
	container->variabletype = other.container->variabletype;
	switch (container->variabletype)
	{
	case type_name::type_int:
		container->var.var_int = other.container->var.var_int;
		break;
	case type_name::type_char:
		container->var.var_char = other.container->var.var_char;
		break;
	case type_name::type_double:
		container->var.var_double = other.container->var.var_double;
		break;
	case type_name::type_float:
		container->var.var_float = other.container->var.var_float;
		break;
	case type_name::type_bool:
		container->var.var_bool = other.container->var.var_bool;
		break;
	}
}

AnyType& AnyType::operator=(const AnyType& other)
{
	if (this == &other)
		return *this;
	delete container;
	container = nullptr;
	container = new data;
	container->variabletype = other.container->variabletype;
	switch (container->variabletype)
	{
	case type_name::type_int:
		container->var.var_int = other.container->var.var_int;
		break;
	case type_name::type_char:
		container->var.var_char = other.container->var.var_char;
		break;
	case type_name::type_double:
		container->var.var_double = other.container->var.var_double;
		break;
	case type_name::type_float:
		container->var.var_float = other.container->var.var_float;
		break;
	case type_name::type_bool:
		container->var.var_bool = other.container->var.var_bool;
		break;
	}
	return *this;
}

AnyType::AnyType(AnyType&& other) noexcept
{
	delete container;
	container = nullptr;
	container = other.container;	
	other.container = nullptr;
}

AnyType& AnyType::operator=(AnyType&& other) noexcept
{
	delete container;	
	container = nullptr;
	container = other.container;	
	other.container = nullptr;
	return *this;
}

int AnyType::ToInt() const
{
	if (container)
	{
		if (container->variabletype != type_name::type_int)
			throw exceptionType();
		return container->var.var_int;
	}
	return 0;
}

double AnyType::ToDouble() const
{
		if (container)
		{
			if (container->variabletype != type_name::type_double)
				throw exceptionType();
			return container->var.var_double;
		}
		return 0.0;
}

char AnyType::ToChar() const
{
	if (container)
	{
		if (container->variabletype != type_name::type_char)
			throw exceptionType();
		return container->var.var_char;
	}
	return 0;
}

float AnyType::ToFloat() const
{
	if (container) 
	{
		if (container->variabletype != type_name::type_float)
			throw exceptionType();
		return container->var.var_float;
	}
	return NAN;
}

bool AnyType::ToBool() const
{
	if (container)
	{
		if (container->variabletype != type_name::type_bool)
			throw exceptionType();
		return container->var.var_bool;
	}
	return false;
}

void AnyType::swap(AnyType& other)
{
	if (other.container&& this->container)
	{
		data* temp = this->container;
		this->container = other.container;
		other.container = temp;
		temp = nullptr;
	}
}



const char* AnyType::current_container_type()
{
	if (container)
	{
		switch (container->variabletype)
		{
		case type_name::type_int:
			return typeid(int).name();
			break;
		case type_name::type_char:
			return typeid(char).name();
			break;
		case type_name::type_double:
			return typeid(double).name();
			break;
		case type_name::type_float:
			return typeid(float).name();
			break;
		case type_name::type_bool:
			return typeid(bool).name();
			break;
		}
	}
	return  "Bad cast exception";
}

void AnyType::operator=(int i)
{
	if (this->container == nullptr)
		container = new data;
	container->var.var_int = i;
	container->variabletype = type_name::type_int;
}

void AnyType::operator=(char ch)
{
	if (this->container == nullptr)
		container = new data;
	container->var.var_char = ch;
	container->variabletype = type_name::type_char;
}

void AnyType::operator=(double d)
{
	if (this->container == nullptr)
		container = new data;
	container->var.var_double = d;
	container->variabletype = type_name::type_double;
}

void AnyType::operator=(float f)
{
	if (this->container == nullptr)
		container = new data;
	container->var.var_float = f;
	container->variabletype = type_name::type_float;
}

void AnyType::operator=(bool b)
{
	if (this->container == nullptr)
		container = new data;
	container->var.var_bool = b;
	container->variabletype = type_name::type_bool;
}


