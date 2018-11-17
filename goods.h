#pragma once
class goods {
private:
	double price;
	int stash = 10;
public:
	double getPrice();
	void setPrice(double);
	int getStash();
	void setStach(int);

	goods operator--();
};

