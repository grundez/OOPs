#pragma once
#include <string>
class IOrder
{
public:
	virtual std::string getTypeOfOrder() = 0;
};