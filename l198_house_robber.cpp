#include <iostream>
#include <vector>

using namespace std;

class L198HouseRobber {
public:
    static int rob(vector<int>& nums) {
        std::vector<int> indexes;
        if (nums.size() == 0) {
            return nums[0];
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i == 0 && nums[0] > nums[1]) {
                indexes.push_back(0);
            }
            else if (i == nums.size() - 1 && nums[i] > nums[i - 1]) {
                indexes.push_back(i);
            }
            else if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
                indexes.push_back(i);
            }
        }

        for (int i = 0; i < indexes.size() - 1; ) {
            if (indexes[i + 1] - indexes[i] == 1) {
                if (indexes[i] > indexes[i + 1]) {
                    indexes.erase(indexes.begin() + i + 1);
                    ++i;
                } else {
                    indexes.erase(indexes.begin() + i);
                }
                continue;
            }
            ++i;
        }
        int total = 0;
        for (int i : indexes)
            total += nums[i];
        return total;
    }

    static int rob_solution(vector<int>& nums) {
        vector<int> answers;

        if (nums.size() == 1) {
            return nums[0];
        }
        else if (nums.size() == 2)
        {
            return std::max(nums[0], nums[1]);
        }
        answers.push_back(nums[0]);
        answers.push_back(std::max(nums[0], nums[1]));

        for (int i = 2; i < nums.size(); ++i)
        {
            answers.push_back(std::max(nums[i] + answers[i - 2], answers[i - 1]));
        }

        return answers.back();
    }
};


int main() {
    vector<int> n{7,3,2,6,1,7,3,4};
    int out = L198HouseRobber::rob_solution(n);

    cout << out << endl;
    return 0;
}
