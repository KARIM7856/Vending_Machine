#pragma once
#include <iostream>
using namespace std;
class money {
public:
	int halfLeCoin = 0;
	int leCoin = 0;
	int fiveLeBill = 0;
	int tenLeBill = 0;
	int twentyLeBill = 0;
	void printMoney();
	double toWholeMoney();
	friend istream& operator>>(istream& in, money& m);
};


