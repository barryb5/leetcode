#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class L46Permutations {
public:
    static void helper(std::vector<std::vector<int>>& out, std::vector<int>& nums, std::vector<int>& base) {
        if (nums.size() == base.size()) {
            out.push_back(base);
        }

        for (int val : nums) {
            if (std::find(base.begin(), base.end(), val) != base.end()) {
                continue;
            }
            base.push_back(val);
            helper(out, nums, base);
            base.pop_back();
        }
    }
    static std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> out;

        for (int val : nums) {
            std::vector<int> base{val};
            helper(out, nums, base);
        }
        return out;
    }

    void func(vector<int>& nums, int i, vector<vector<int>>& ans) {
        if (i == nums.size() - 1) {
            ans.push_back(nums);
            return;
        }

        for (int j = i; j < nums.size(); j++) {
            swap(nums[j], nums[i]);
            func(nums, i + 1, ans);
            swap(nums[i], nums[j]);
        }
    }

    vector<vector<int>> permute_solution(vector<int>& nums) {
        vector<vector<int>> ans;
        func(nums, 0, ans);
        return ans;
    }
};

int main() {
    std::vector<int> input{1, 2, 3};
    std::vector<std::vector<int>> out = L46Permutations::permute(input);

    std::cout << "[" << std::endl;;
    for (const auto& per : out) {
        std::cout << "[ ";
        for (int val : per) {
            std::cout << val << ", ";
        }
        std::cout << "]" << std::endl;
    }
    std::cout << "]" << std::endl;
    return 0;
}
