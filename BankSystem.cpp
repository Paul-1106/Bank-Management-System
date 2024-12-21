#include <iostream>
#include <string>
#include <cmath>
#include <limits>


void mainMenu() {
	std::cout << "*********************************" << std::endl;
	std::cout << "*     BANK MANAGEMENT SYSTEM    *" << std::endl;
	std::cout << "*********************************" << std::endl;
	std::cout << "1. Show Balance" << std::endl;
	std::cout << "2. Deposit Amount" << std::endl;
	std::cout << "3. Withdraw Amount" << std::endl;
	std::cout << "4. Show Savings" << std::endl;
	std::cout << "5. Add from Balance to Savings" << std::endl;
	std::cout << "6. Add from Savings to Balance" << std::endl;
	std::cout << "7. Pay your bills" << std::endl;
	std::cout << "8. Exit" << std::endl << std::endl;
	std::cout << "*********************************" << std::endl;
}

void billTax() {
	std::cout << "************************" << std::endl;
	std::cout << "*      TAX OPTIONS     *" << std::endl;
	std::cout << "************************" << std::endl;
	std::cout << "1. PARTIAL PAYMENT (10%)" << std::endl;
	std::cout << "2. HALF PAYMENT (25%)" << std::endl;
	std::cout << "3. FULL PAYMENT (50%)" << std::endl;
	std::cout << "************************" << std::endl;
	std::cout << "Select your tax option from 1 to 3" << std::endl;
}


int main() {

	int option;
	double balance = 0.00;
	double savings = 0.00;

	do {
		mainMenu();
		std::cout << "Select your option (1-8): " << std::endl;
		std::cin >> option;

		switch (option) {
		case 1:
			std::cout << "Your balance is: $" << balance << std::endl;
			break;
		case 2:
			double depositAmount;
			std::cout << "Enter your deposit: " << std::endl;

			std::cin >> depositAmount;
			if (depositAmount > 0.00) {
				balance += depositAmount;
			}
			else {
				std::cout << depositAmount << " is not a valid deposit amount." << std::endl;
			}

			std::cout << "Your new balance is: $" << balance << std::endl;

			break;

		case 3:
			double withdrawAmount;

			std::cout << "Enter the withdraw amount: " << std::endl;
			std::cin >> withdrawAmount;

			if (balance >= withdrawAmount) {
				balance -= withdrawAmount;
			}
			else if (balance < withdrawAmount) {
				std::cout << "You do not have enough money to withdraw $" << withdrawAmount << "." << std::endl;
			}
			if (withdrawAmount <= 0) {
				std::cout << "Select your withdraw amount that is greater than 0" << std::endl;
			}

			std::cout << "Your new balance is: $" << balance << std::endl;
			break;

		case 4:
			std::cout << "Your current saving is: $" << savings << std::endl;
			break;

		case 5:
			double addSavings;

			std::cout << "What amount you want to transfer your balance to your savings?" << std::endl;
			std::cout << "Your current balance is: $" << balance << std::endl;
			std::cin >> addSavings;

			if (addSavings <= 0.00) {
				std::cout << "Your input needs to more than 0" << std::endl;
			}
			if (addSavings > balance) {
				std::cout << "You cannot add $" << addSavings << " to your saving (Not enough balance amount)." << std::endl;
			}
			if (addSavings <= balance && addSavings > 0.00) {
				balance -= addSavings;
				savings += addSavings;
			}
			std::cout << "Your new balance is: $" << balance << std::endl;
			std::cout << "Your savings amount: $" << savings << std::endl;

			break;

		case 6:
			double subSavings;

			std::cout << "What amount you want to transfer your savings to your balance?" << std::endl;
			std::cout << "Your savings amount is: $" << savings << std::endl;
			std::cin >> subSavings;

			if (subSavings <= 0.00) {
				std::cout << "Your input need to be more than 0" << std::endl;
			}
			if (subSavings > savings) {
				std::cout << "Your transfer from savings to balance cannot exceed less than 0" << std::endl;
			}
			else if (subSavings <= savings) {
				balance += subSavings;
				savings -= subSavings;
			}
			std::cout << "Your new balance is: $" << balance << std::endl;
			std::cout << "Your savings amount: $" << savings << std::endl;

			break;

		case 7:
			billTax();
			
			int taxOption;
			double billsPaid;

			std::cin >> taxOption;
			if (taxOption == 1) {
				billsPaid = balance * 0.10;
				balance -= billsPaid;

				std::cout << "You have selected to pay 10 percent from your balance." << std::endl;
				std::cout << "Your new balance is: $" << balance << std::endl;
			}
			else if (taxOption == 2) {
				billsPaid = balance * 0.25;
				balance -= billsPaid;

				std::cout << "You have selected to pay 25 percent from your balance." << std::endl;
				std::cout << "Your new balance is: $" << balance << std::endl;

			}
			else if (taxOption == 3) {
				billsPaid = balance * 0.50;
				balance -= billsPaid;

				std::cout << "You have selected to pay 50 percent from your balance." << std::endl;
				std::cout << "Your new balance is: $" << balance << std::endl;

			}
			else {
				std::cout << "Invalid tax option" << std::endl;
				std::cin >> taxOption;
			}
			
			break;

		case 8:
			std::cout << "Have a nice day!" << std::endl;
			break;

		default:
			std::cout << "That is not a valid option!" << std::endl;
			std::cin >> option;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break;
		}
	} while (option != 8);

	return 0;
}


