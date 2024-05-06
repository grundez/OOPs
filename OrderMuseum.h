#pragma once
#include "IOrder.h"
#include <iostream>
class OrderMuseum : public IOrder
{
private:
public:
	std::string getTypeOfOrder() override;
};