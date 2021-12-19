#include <iostream>
#include <fstream>
#include <string>
std::string decToHex(int num) {
	std::string str;
	int temp_deg = num;
	int deg = 0;
	while ((temp_deg /= 16) != 0)
		++deg;
	int big_deg = 1 << 4 * deg;
	while (big_deg > 0) {
		int mod = num / big_deg;
		if (mod > 9) {
			str += (char)(mod + 55);
		}
		else
			str += (char)(mod + 48);
		num %= big_deg;
		big_deg >>= 4;
	}
	return str;
}
int main() {
	std::ifstream fin("input.txt", std::ifstream::binary);
	if (!fin.is_open()) {
		std::cout << "Input file could not open";
		return -1;
	}
	int counter = 0;
	//Find length of the file
	fin.seekg(0, fin.end);
	int length = fin.tellg();
	fin.seekg(0, fin.beg);
	//Create buffer
	char* buffer = new char[length];
	fin.read(buffer, length);
	//Variables for creating the line that keeps track of shift from the beginning of file
	size_t lineNumber = 0;
	for (int i = 0; i < 10; ++i) {
		std::cout << '0';
	}
	std::cout << ": ";
	for (size_t idx = 0; idx <= length; ++idx) {

		//cout elements in human language if reached the eof
		if (idx == length) {
			int diff;
			if (counter > 8)
				diff = 16 - counter;
			else
				diff = 17 - counter;
			for (size_t spaces = 0; spaces < diff; ++spaces) {
				std::cout << "   ";
			}
			for (size_t c = idx - counter; c < idx; ++c) {
				std::cout << buffer[c];
			}
			std::cout << "\n";
			break;
		}
		else {
			//Change control symbols to "."
			int temp = (int)buffer[idx];
			if (temp < 32) {
				temp = 46;
			}
			//Convert from decimal to hex
			std::string currSymbol = decToHex(temp);
			for (size_t i = 0; i < currSymbol.length(); ++i) {
				std::cout << currSymbol[i];
			}
			std::cout << " ";
			++counter;
			//Check if finished printing the first half
			if (counter == 8) {
				std::cout << "|";
			}
			//Check if finished printing the second half
			if (counter == 16) {
				counter = 0;
				++lineNumber;
				//Cout elements in human language
				for (int c = idx - 15; c <= idx; ++c) {
					if ((int)buffer[c] < 32)
						std::cout << (char)46;
					else
						std::cout << buffer[c];
				}
				std::cout << "\n";
				//Check the shift from beginning of the file
				std::string hexLineNumber = decToHex(lineNumber);
				int diff = 9 - (int)hexLineNumber.length();
				for (size_t i = 0; i < diff; ++i) {
					std::cout << 0;
				}
				std::cout << hexLineNumber << "0: ";
			}
		}
	}
	delete[] buffer;
	fin.close();
	return 0;
}
