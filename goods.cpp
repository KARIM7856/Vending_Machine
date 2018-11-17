#include "stdafx.h"
#include "goods.h"


double goods::getPrice()
{
	return price;
}

void goods::setPrice(double p)
{
	price = p;
}

int goods::getStash()
{
	return stash;
}

void goods::setStach(int s)
{
	stash = s;
}

goods goods::operator--()
{
	stash--;
	return *this;
}

