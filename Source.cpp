/*
* Write a number conversion program in whatever programming language you are most comfortable with that does the following.
1.Asks for the type of number being entered (DEC, BIN, HEX, or float. Float is entered by the user as a DEC)
2.Asks for what type of number to convert to (It will not be an option to convert float to DEC or HEX)
3.Display the converted number.
Bonus (100points):
Ask for two numbers, each of any available base,
convert the second number to the first one's base.
ask if the user wants to add/multiply those numbers.
Do the arithmetic and display the numbers.
*/

#include <iostream>
#include <string>

std::string decToBin(double decNumber);
std::string decToHex(int decNumber);

int binToDec(std::string binNumber);
std::string binToHex(std::string binNumber);

int hexToDec(std::string hexNumber);
std::string hexToBin(std::string hexNumber);
//int baseConvert(int bonusNum, int fromBase, int toBase);


 


int main() {
	double decNumber{ 0 };
	int bonusNum{ 0 };
	std::string binNumber{ "00000000"};
	std::string hexNumber{"00"};

	int whichType{0};
	int conversionType{ 0 };
	bool another{ true };

	while (another) {

		system("CLS");

		std::cout << "Which type of number are we converting?\n0.DEC\n1.BIN\n2.HEX\n";
		std::cin >> whichType;



		switch (whichType) {
		case 0:
			std::cout << "Enter the Decimal number.\n";
			std::cin >> decNumber;
			std::cout << "Which type are we converting it to?";
			std::cout << "\n1.BIN\n2.HEX\n";
			std::cin >> conversionType;

			switch (conversionType)
			{
			case 1:
				std::cout << decToBin(decNumber);
				break;
			case 2:
				std::cout << decToHex(decNumber);
				break;
			}

			break;

		case 1:
			std::cout << "Enter the Binary number.\n";
			std::cin >> binNumber;
			std::cout << "Which type are we converting it to?";
			std::cout << "\n0.Dec\n2.HEX\n";
			std::cin >> conversionType;

			switch (conversionType)
			{
			case 0:
				std::cout << binToDec(binNumber);
				break;
			case 2:
				std::cout << binToHex(binNumber);
				break;
			}

			break;
		case 2:
			std::cout << "Enter the Hexadecimal code. (Capital letters) Ex: 7B \n";
			std::cin >> hexNumber;
			std::cout << "Which type are we converting it to?";
			std::cout << "\n0.Dec\n1.Bin\n";
			std::cin >> conversionType;

			switch (conversionType)
			{
			case 0:
				std::cout << hexToDec(hexNumber);
				break;
			case 1:
				std::cout << hexToBin(hexNumber);
				break;
			}

			break;
		}



		std::cout << "\nAnother?\n0.No\n1.Yes\n";
		std::cin >> another;
	};
};




std::string decToBin(double decNumber)
{
	int leftOfDecimal = (int)decNumber;
	double rightOfDecimal = decNumber - leftOfDecimal;

	std::string binary{};
	while (leftOfDecimal > 0) 
	{
		int remainder = leftOfDecimal % 2;
		binary = std::to_string(remainder) + binary;
		leftOfDecimal /= 2;
	}
	while (binary.size() < 8)
	{
		binary = "0" + binary;
	}

	if (rightOfDecimal > 0)
	{
		binary += ".";
	}

	const int maxDigits = 17;
	while (rightOfDecimal > 0 && binary.size() < maxDigits)
	{
		rightOfDecimal *= 2;
		if (rightOfDecimal > 1)
		{
			binary += "1";
			rightOfDecimal - 1;
		}
		else
		{
			binary += "0";
		}
	}



	return binary;
}

std::string decToHex(int decNumber)
{
	std::string hex{};
	while (decNumber > 0) {
		int remainder = decNumber % 16;
		if (remainder < 10)
		{
			hex = std::to_string(remainder) + hex;
		}
		else
		{
			char hexLetter = 'A' + (remainder - 10);
			hex = hexLetter + hex;
		}
		decNumber /= 16;
	}
	return hex;
}

int binToDec(const std::string binNumber)
{
	int decimal{ 0 };
	for (char digit : binNumber)
	{
		decimal = decimal * 2 + (digit - '0');
	}
	return decimal;
}

std::string binToHex(std::string binNumber)
{
	std::string hex = decToHex(binToDec(binNumber));
	return hex;
}

int hexToDec(std::string hexNumber)
{
	int decimal = binToDec(hexToBin(hexNumber));
	return decimal;
}

std::string hexToBin(const std::string hexNumber)
{
	std::string binary{};

	for (char hexChar : hexNumber)
	{
		switch (hexChar) {
		case '0':binary += "0000"; break;
		case '1':binary += "0001"; break;
		case '2':binary += "0010"; break;
		case '3':binary += "0011"; break;
		case '4':binary += "0100"; break;
		case '5':binary += "0101"; break;
		case '6':binary += "0110"; break;
		case '7':binary += "0111"; break;
		case '8':binary += "1000"; break;
		case '9':binary += "1001"; break;
		case 'A':binary += "1010"; break;
		case 'B':binary += "1011"; break;
		case 'C':binary += "1100"; break;
		case 'D':binary += "1101"; break;
		case 'E':binary += "1110"; break;
		case 'F':binary += "1111"; break;
		}
	}
	return binary;
}
