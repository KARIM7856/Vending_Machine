#include "stdafx.h"
#include "money.h"

void money::printMoney()
{
	cout << halfLeCoin << " Half LE. coin" << endl;
	cout << leCoin << " One LE. coin" << endl;
	cout << fiveLeBill << " Five LE. bill" << endl;
	cout << tenLeBill << " Ten LE. bill" << endl;
	cout << twentyLeBill << " Twenty LE. bill" << endl;
}

double money::toWholeMoney()
{
	return fiveLeBill * 5 + static_cast<double>(halfLeCoin) / 2.0 +
		leCoin + tenLeBill * 10 + twentyLeBill * 20;
}

istream & operator>>(istream & in, money& m)
{
	cout << "Input half LE coins: " << endl;
	cin >> m.halfLeCoin;
	cout << "Input LE coins: " << endl;
	cin >> m.leCoin;
	cout << "Input 5LE bill: " << endl;
	cin >> m.fiveLeBill;
	cout << "Input 10LE bill: " << endl;
	cin >> m.tenLeBill;
	cout << "Input 20LE bill: " << endl;
	cin >> m.twentyLeBill;
	cout << endl;

	return in;
}