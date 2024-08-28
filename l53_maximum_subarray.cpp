#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class L53MaximumSubArray {
public:
    static int max_sub_array(vector<int>& nums) {
        int biggest = nums[0];
        if (nums.size() < 2)
            return biggest;

        int left = 0;
        int temp = nums[0];
        int prev = nums[0];

        for (int right = 1; right < nums.size(); ++right) {
            temp += nums[right];
            if (temp > biggest) {
                biggest = temp;
                prev = temp;
            }
            else if (temp < prev)
            {
                left = right;
                prev = nums[left];
                temp = nums[left];
            }
            else
            {
                prev = temp;
            }
        }

        return biggest;
    }

    int max_sub_array_solution(vector<int>& nums) {
        int n = size(nums), ans = INT_MIN;
        for(int i = 0; i < n; i++)
            for(int j = i, curSum = 0; j < n ; j++)
                curSum += nums[j],
                ans = max(ans, curSum);
        return ans;
    }
};


int main() {
    vector<int> n{-2,1,-3,4,-1,2,1,-5,4};
    int out = L53MaximumSubArray::max_sub_array(n);

    cout << out << endl;
    return 0;
}
