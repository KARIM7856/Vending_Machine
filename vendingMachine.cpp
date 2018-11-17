#include "stdafx.h"
#include "vendingMachine.h"

vendingMachine::vendingMachine()
{
	item = new goods[10];
	cash.halfLeCoin = 100;
	cash.leCoin = 100;
	cash.fiveLeBill = 100;
	cash.tenLeBill = 100;
	cash.twentyLeBill = 100;
	buyers = 0;

	item[0].setPrice(2);
	item[1].setPrice(0.5);
	item[2].setPrice(3);
	item[3].setPrice(3.5);
	item[4].setPrice(1);
	item[5].setPrice(1.25);
	item[6].setPrice(3);
	item[7].setPrice(3);
	item[8].setPrice(5);
	item[9].setPrice(5);
}

vendingMachine::vendingMachine( vendingMachine& anotherMachine)
{
	cash = anotherMachine.getCash();
	buyers = anotherMachine.buyers;
	item = new goods[10];
	for (int i = 0; i < 10; i++) {
		item[i] = anotherMachine[i];
	}
}

vendingMachine::~vendingMachine()
{
	delete[] item;
}

double vendingMachine::calcChange(double p, goods item)
{
	return p - item.getPrice();
}

money vendingMachine::calcBillAndCoinChange(int change)
{
	money temp;
	while (change > 0) {
		if ((change >= 2000) && (cash.twentyLeBill > 0)) {
			change -= 2000;
			cash.twentyLeBill--;
			temp.twentyLeBill++;
		}
		else if ((change >= 1000) && (cash.tenLeBill > 0)) {
			change -= 1000;
			cash.tenLeBill--;
			temp.tenLeBill++;
		}
		else if ((change >= 500) && (cash.fiveLeBill > 0)) {
			change -= 500;
			cash.fiveLeBill--;
			temp.fiveLeBill++;
		}
		else if ((change >= 100) && (cash.leCoin > 0)) {
			change -= 100;
			cash.leCoin--;
			temp.leCoin++;
		}
		else if ((change >= 50) && (cash.halfLeCoin > 0)) {
			change -= 50;
			cash.halfLeCoin--;
			temp.halfLeCoin++;
		}
	}
	return temp;
}

bool vendingMachine::isAvailable(goods i)
{
	return (i.getStash() > 0);
}

void vendingMachine::printAvailableItems() {
	cout << "Available items are:" << endl;
	for (int i = 1; i <= 10; i++) {
		if (item[i - 1].getStash() == 0)
			continue;
		cout << i << "- Item" << i << ": "
			<< item[i - 1].getPrice() << "LE." << endl;
	}
}

void vendingMachine::printAvailableMoney()
{
	cout << "We have:" << endl;
	cout << cash.halfLeCoin << " Half LE. coin" << endl;
	cout << cash.leCoin << " one LE. coin" << endl;
	cout << cash.fiveLeBill << " Five LE. bill" << endl;
	cout << cash.tenLeBill << "Ten LE. bill" << endl;
	cout << cash.twentyLeBill << "Twenty LE. bill" << endl;
}

money vendingMachine::getCash()
{
	return cash;
}

void vendingMachine::setCash(money m)
{
	cash = m;
}

goods & vendingMachine::operator[](int index)
{
	return item[index];
}

int vendingMachine::to_piasters(double cost)
{
	return (cost * 100);
}

int vendingMachine::to_piasters()
{

	return cash.toWholeMoney() * 100;
}