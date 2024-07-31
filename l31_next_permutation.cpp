#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class L31NextPermutation {
public:
    static void helper(vector<int>& nums, vector<int>::reverse_iterator end) {
        auto last = nums.rbegin();
        auto secondLast = std::next(last);

        while (secondLast != end) {
            if (*secondLast < *last) {
                auto smallest = std::min_element(nums.rbegin(), last);
                std::swap(*smallest, *secondLast);
                helper(nums, last);
                return;
            }
            ++last;
            ++secondLast;
        }

    }

    static void next_permutation(std::vector<int>& nums) {
        if (nums.size() == 1) {
            return;
        }

        auto last = nums.rbegin();
        auto secondLast = std::next(last);

        while (secondLast != nums.rend()) {
            if (*secondLast < *last) {
                auto smallest = std::min_element(nums.rbegin(), last);
                std::swap(*smallest, *secondLast);
                helper(nums, last);
                return;
            }
            ++last;
            ++secondLast;
        }

        std::reverse(nums.begin(), nums.end());
        return;
    }

    static void next_permutation_solution(std::vector<int>& nums) {
        if (nums.size() == 1) {
            return;
        }

        auto it = is_sorted_until(nums.rbegin(), nums.rend());

        if (it != nums.rend()) {
            auto next = std::upper_bound(nums.rbegin(), it, *it);
            std::swap(*it, *next);
            std::reverse(nums.rbegin(), it);
            return;
        }

        std::reverse(nums.begin(), nums.end());
        return;
    }
};


int main() {
    vector<int> nums = {1,3,2};
    int val = 3;
    L31NextPermutation::next_permutation_solution(nums);

    for (int n : nums) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}
