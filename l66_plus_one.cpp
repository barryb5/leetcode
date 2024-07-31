#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class L66PlusOne {
public:
    static vector<int> plus_one(vector<int>& digits) {
        auto reverse_itr = digits.rbegin();
        while (reverse_itr != digits.rend()) {
            if (*reverse_itr < 9) {
                *reverse_itr += 1;
                return digits;
            } else {
                *reverse_itr = 0;
                ++reverse_itr;
            }
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }

    static vector<int> plus_one_solution(vector<int>& digits) {
        return digits;
    }
};


int main() {
    vector<int> nums = {1,2,3};
    vector<int> out = L66PlusOne::plus_one(nums);

    for (const auto& num : out) {
        cout << num;
    }
    cout << '\n';
    
    return 0;
}
