#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class L12IntegerToRoman {
public:
    // Didn't figure it out on my own
    static string int_to_roman(int num) {
        std::string numeral = "";
        if (int m = num / 1000) {
            numeral += std::string(m, 'M');
            num %= 1000;
        }

        if (int d = num / 500 && num < 900) {
            numeral += std::string(d, 'D');
            num %= 500;
        }

        if (int c = num / 100) {
            if (c == 9) {
                numeral += "CM";
            } else if (c == 4) {
                numeral += "CD";
            } else {
                numeral += std::string(c, 'C');
            }
            num %= 100;
        }

        if (int l = num / 50 && num < 90) {
            numeral += std::string(l, 'L');
            num %= 50;
        }

        if (int x = num / 10) {
            if (x == 9) {
                numeral += "XC";
            } else if (x == 4) {
                numeral += "XL";
            } else {
                numeral += std::string(x, 'X');
            }
            num %= 10;
        }

        if (int v = num / 5 && num < 9) {
            numeral += std::string(v, 'V');
            num %= 5;
        }

        if (int i = num) {
            if (i == 9) {
                numeral += "IX";
            } else if (i == 4) {
                numeral += "IV";
            } else {
                numeral += std::string(i, 'I');
            }
        }

        return numeral;
    }

    static string int_to_roman_solution(int num) {
        std::string ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        std::string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        std::string hrns[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        std::string ths[]={"","M","MM","MMM"};

        return ths[num/1000] + hrns[(num%1000)/100] + tens[(num%100)/10] + ones[num%10];
    }
};

int main() {
    int num = 1924;
    std::string out = L12IntegerToRoman::int_to_roman(num);

    cout << out << endl;

    return 0;
}
