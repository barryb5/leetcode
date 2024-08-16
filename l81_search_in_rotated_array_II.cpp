#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class L81SearchInRotatedArrayII {
public:
    static bool search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int mid = -1;

        while (start <= end) {
            mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                return true;
            } else if (nums[start] == target) {
                return true;
            } else if (nums[end] == target) {
                return true;
            } else if (nums[start] == nums[mid] || nums[mid] == nums[end]) {
                if (std::find(nums.begin() + start, nums.end(), target) != nums.end()) {
                    return true;
                }
                return false;
            } else if (nums[start] < nums[mid]) {
                // Pivot is in second half
                if (nums[start] < target && target < nums[mid])
                    end = mid - 1;
                else
                    start = mid + 1;
            } else {
                // Pivot is in first half
                if ((nums[mid] < target && target < nums[end]))
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        }

        return false;
    }
};


int main() {
    std::vector<int> nums = {10,10,10,-10,-10,-10,-10,-9,-9,-9,-9,-9,-9,-9,-8,-8,-8,-8,-8,-8,-8,-8,-7,-7,-7,-7,-6,-6,-6,-5,-5,-5,-4,-4,-4,-4,-3,-3,-2,-2,-2,-2,-2,-2,-2,-2,-1,-1,-1,-1,-1,0,0,0,0,0,0,0,1,1,1,1,2,2,2,2,2,2,2,3,3,3,4,4,4,5,5,5,5,6,6,6,7,7,7,7,7,8,8,8,8,9,9,9,9,9,9,9,10,10};
    int target = 6;
    bool out = L81SearchInRotatedArrayII::search(nums, target);

    cout << out << endl;
    // cout << out->next->val << endl;
}
