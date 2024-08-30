#include <iostream>
#include <cmath>

using namespace std;

class L343IntegerBreak {
public:
    static int integer_break(int n) {
        int numThrees = n / 3;
        int remainder = n % 3;

        if (n == 2)
            return 1;
        else if (n == 3)
            return 2;

        uint out = 0;

        if (remainder == 1) {
            out = std::pow(3, numThrees - 1) * 4;
        } else if (remainder == 2) {
            out = std::pow(3, numThrees) * 2;
        } else {
            out = std::pow(3, numThrees);
        }

        return out;
    }
};


int main() {
    int n{3};
    int out = L343IntegerBreak::integer_break(n);

    cout << out << endl;
    return 0;
}
