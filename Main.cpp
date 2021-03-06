#include "stdafx.h"
#include "vendingMachine.h"




int main() {
	vendingMachine machine1;
	money customerMoney;
	cin >> customerMoney;

	machine1.printAvailableItems();

	int wantedItem;

	while (true) {
		int Ans;
		cout << "Which item do you want: ";
		cin >> wantedItem;
		if (!machine1.isAvailable(machine1[wantedItem - 1])) {
			cout << "Sorry but requested item is not available" << endl;
			cout << "Do you want to choose another item (yes = 1, no = 0): ";
			if (Ans == 1) {
				continue;
			}
			else if (Ans == 0) {
				break;
			}
			else {
				cout << endl << "Invalid Input: ";
				break;

			}
		}

		else if (machine1.calcChange(customerMoney.toWholeMoney(), machine1[wantedItem - 1]) < 0) {
			cout << "The money you entered is not enough." << endl;
			cout << "Do you want to choose another item (yes = 1, no = 0): ";
			cin >> Ans;

			if (Ans == 1)
				continue;
			else if (Ans == 0)
				break;
			else {
				cout << "Invalid input";
				break;
			}
		}
		else {
			machine1.incrementBuyers();
			--machine1[(wantedItem - 1)];
			int change = machine1.to_piasters(
				machine1.calcChange(
				customerMoney.toWholeMoney(), machine1[wantedItem - 1]));

			cout << "\nBuying Operation was successful!" << endl;

			if (change > 0) {
				cout << "Here's your Change!" << endl;
				money billChange = machine1.calcBillAndCoinChange(change);
				billChange.printMoney();
			}
			break;
		}
	}
}









