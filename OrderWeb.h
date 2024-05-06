#pragma once
#include "IOrder.h"
#include <iostream>
class OrderWeb : public IOrder
{
private:
public:
	std::string getTypeOfOrder() override;
};