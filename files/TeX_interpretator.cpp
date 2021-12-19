#include <iostream>
#include <fstream>
int main(int argc, char* argv[]) {
	if (argc < 3) {
		std::cout << "Incorrect input!\n";
		std::cout << "Usage: filename, in_filename, out_filename";
	}
	std::ifstream in(argv[1]);
	if (!in.is_open()) {
		std::cout << "Input file is not opened";
	}
	std::ofstream out(argv[2]);
	if (!out.is_open()) {
		std::cout << "Output file is not opened";
	}
	char c;
	int check = 0;
	while ((c = in.peek()) != EOF) {
		c = in.get();
		if ((c == '$') && (in.peek() != '$')) {
			if (check == 0) {
				out << "<math>";
				check++;
			}
			else {
				out << "</math>";
				check--;
			}
		}
		else if ((c == '$') && (in.peek() == '$')) {
			if (check == 0) {
				out << "<math>";
				in.get();
				check++;
			}
			else {
				out << "</math>";
				in.get();
				check--;
			}
		}
		else
			out << c;
	}
	std::cout << "Data successfully transmitted!\n";
	in.close();
	out.close();

	return 0;
}
