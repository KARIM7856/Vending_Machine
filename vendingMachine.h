#pragma once
#include "goods.h"
#include "money.h"
class vendingMachine {
private:

	goods *item;
	money cash;
	int buyers;

public:
	vendingMachine();
	vendingMachine( vendingMachine& anotherMachine);
	~vendingMachine();


	double calcChange(double p, goods i);
	money calcBillAndCoinChange(int change);

	bool isAvailable(goods it);

	void printAvailableItems();
	void printAvailableMoney();

	money getCash();
	void setCash(money m);

	int to_piasters(double cost);
	int to_piasters();
	void incrementBuyers() { buyers++; }

	goods& operator[] (int index);
};

