#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class L860LemonadeChange {
public:
    static bool lemonade_change(std::vector<int>& bills) {
        int fives = 0;
        int tens = 0;
        int twenties = 0;

        for (int bill : bills) {
            if (bill == 5) {
                ++fives;
            } else if (bill == 10) {
                ++tens;
                if (fives > 0) {
                    --fives;
                } else {
                    return false;
                }
            } else {
                // bill is 20
                ++twenties;
                if (tens > 0 && fives > 0) {
                    --tens;
                    --fives;
                } else if (fives > 2) {
                    fives -= 3;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};


int main() {
    std::vector<int> bills = {5, 5, 5, 10, 20};
    bool out = L860LemonadeChange::lemonade_change(bills);

    std::cout << out << std::endl;
}
