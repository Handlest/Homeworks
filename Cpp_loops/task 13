#include <iostream>

char letter(int num) {
    if (num == 1000)
        return 'M';
    else if (num == 500)
        return 'D';
    else if (num == 100)
        return 'C';
    else if (num == 50)
        return 'L';
    else if (num == 10)
        return 'X';
    else if (num == 5)
        return 'V';
    else
        return 'I';
}
//fix later
int main() {
    int max_deg = 1000;
    int num;
    int oper = 2;
    std::cout << "enter num: ";
    std::cin >> num;
    bool check = true;
    while (check) {
        if ((num % max_deg != num and num % max_deg != 0) or (num % max_deg == 0 and max_deg == 1)) {
            int count = num / max_deg;
            if ((count == 4 or count == 9) and letter(max_deg) != 'M') {
                (oper == 5) ? (oper = 2) : (oper = 5);
                std::cout << letter(max_deg) << letter(max_deg * oper);
                (oper == 5) ? (oper = 2) : (oper = 5);
                num %= max_deg;
                max_deg /= oper;
                (oper == 5) ? (oper = 2) : (oper = 5);
            } else {
                while (count) {
                    std::cout << letter(max_deg);
                    count--;
                }
                num %= max_deg;
                max_deg /= oper;
                (oper == 5) ? (oper = 2) : (oper = 5);
            }
        } else if (num % max_deg == 0) {
            std::cout << letter(max_deg);
            check = false;
        }
        else {
            max_deg /= oper;
            (oper == 5) ? (oper = 2) : (oper = 5);
        }
        //std::cout << "num, max_deg, oper: " << num << ' ' << max_deg << ' ' << oper << '\n';
    }
}
