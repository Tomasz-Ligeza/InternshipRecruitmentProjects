#include <iostream>
#include <algorithm>
#include <limits>

long pow(int exp, int base) {
	long val{ 1 };
	for (;;) {
		if(exp & 1)
			val *= base;
		exp >>= 1;
		if (!exp)
			break;
		base *= base;
	}
	return val;
}

int binToDec(std::string binary) {
	int exponent = binary.size() - 1;
	int decimal { 0 };
	for (auto& digit : binary) {
		if (digit == '1')
			decimal += pow(exponent, 2);
		exponent--;
	}
	return decimal;
}

std::string decToBin(int decimal) {
	std::string binary;
	while (decimal > 0) {
		binary += '0' + decimal % 2;
		decimal >>= 1;
	}
	std::reverse(binary.begin(), binary.end());
	return binary;
}

bool isInputValid(std::string binary) {
	for (auto& digit : binary)
		if (digit != '0' && digit != '1')
			return false;
	return true;
}

int main() {
	do {
		char option {' '};
		std::cout << "Select operation: \n"
			<< "-> [1] conversion from binary to decimal\n"
			<< "-> [2] conversion from decimal to binary\n"
			<< "-> [*] exit\t\t\t\t*=any\n";
		std::cin >> option;
		switch (option) {
		case '1': {
			system("cls");
			std::cout << "Please enter binary number: ";
			std::string binary;
			std::cin >> binary;
			if (isInputValid(binary))
				std::cout << "\n" << binary << " [BIN] = " << binToDec(binary) << " [DEC]\n";
			else
				std::cout << "This is not a number in binary system.\n";
			break;
		}
		case '2': {
			system("cls");
			std::cout << "Please enter decimal number: ";
			int decimal;
			std::cin >> decimal;
			if (!std::cin.fail()) {
				std::cout << "\n" << decimal << " [DEC] = " << decToBin(decimal) << " [BIN]\n";
			}
			else {
				std::cout << "This is not number in decimal system.\n";
			}
			std::cin.clear();
			std::cin.sync();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break;
		}
		default: {
			return 0;
		}
		}
		std::cout << "One more conversion? [y/n] ";
		std::cin >> option;
		if (option == 'n')
			break;
		else
			system("cls");
	} while (true);
	
	return 0;
}