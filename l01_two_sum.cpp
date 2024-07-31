#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class L01TwoSum {
public:
    static vector<int> two_sum(vector<int>& nums, int target) {
        vector<int> solutions;

        for (size_t i = 0; i < nums.size(); ++i) {
            for (size_t j = i+1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target) {
                    solutions.push_back(i);
                    solutions.push_back(j);
                    return solutions;
                }
            }
        }
        return solutions;
    }

    static vector<int> two_sum_solution(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap;

        for (int i = 0; i < nums.size(); ++i) {
            int compliment = target - nums[i];
            if (hashmap.find(compliment) != hashmap.end()) {
                return {hashmap[compliment], i};
            }
            hashmap[nums[i]] = i;
        }

        return {};
    }
};


int main() {
    int target = 0;
    vector<int> nums = {-3,4,3,90};
    vector<int> out = L01TwoSum::two_sum(nums, target);

    for (const auto& num : out) {
        cout << num << endl;
    }
    
    return 0;
}
