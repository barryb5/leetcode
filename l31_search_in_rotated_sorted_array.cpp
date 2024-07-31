#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class L31SearchInRotatedSortedArray {
public:
    static int helper(vector<int>& nums, int target, int high, int low) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target) {
            return mid;
        } else if (nums[high] == target) {
            return high;
        } else if (nums[low] == target) {
            return low;
        } else if (high == low) {
            return -1;
        }

        // Rotate is left or right
        if (nums[low] < nums[mid] && nums[mid] > nums[high]) {
            // Rotate is on the right
            if (low == mid || high == mid) {
                return -1;
            }

            if (nums[low] < target && target < nums[mid]) {
                return helper(nums, target, mid, low);
            } else {
                return helper(nums, target, high, mid);
            }
        } else {
            // Rotate is on the left
            if (low == mid || high == mid) {
                return -1;
            }
            if (nums[mid] < target && target < nums[high]) {
                return helper(nums, target, high, mid);
            } else {
                return helper(nums, target, mid, low);
            }
        }
        return 0;
    }

    static int search(vector<int>& nums, int target) {
        return helper(nums, target, nums.size()-1, 0);
    }

    static int search_solution(vector<int>& nums, int target) {
        return 0;
    }
};


int main() {
    int target = 3;
    vector<int> nums = {1, 3};
    int out = L31SearchInRotatedSortedArray::search(nums, target);

    std::cout << out << std::endl;

    return 0;
}
