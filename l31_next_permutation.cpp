#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class L31NextPermutation {
public:
    static void next_permutation(std::vector<int>& nums) {
        if (nums.size() == 1) {
            return;
        }

        auto smallest = std::min_element(nums.begin(), nums.end());
        auto smallestSwap = std::min_element(nums.begin(), smallest);

        while (smallest == smallestSwap) {
            if (smallest == nums.begin()) {
                std::reverse(nums.begin(), nums.end());
                return;
            }
            smallest = std::min_element(nums.begin(), std::prev(smallest));
            smallestSwap = std::min_element(nums.begin(), smallest);
        }
        std::swap(*smallest, *smallestSwap);
        return;
    }

    static void next_permutation_solution(std::vector<int>& nums) {
        if (nums.size() == 1) {
            return;
        }

        auto smallest = std::min_element(nums.begin(), nums.end());
        auto smallestSwap = std::min_element(nums.begin(), smallest);

        while (smallest == smallestSwap) {
            if (smallest == nums.begin()) {
                std::reverse(nums.begin(), nums.end());
                return;
            }
            smallest = std::min_element(nums.begin(), std::prev(smallest));
            smallestSwap = std::min_element(nums.begin(), smallest);
        }
        std::swap(*smallest, *smallestSwap);
        return;
    }
};


int main() {
    vector<int> nums = {3,2,2,3};
    int val = 3;
    L31NextPermutation::next_permutation(nums, val);

    for (int n : nums) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}
