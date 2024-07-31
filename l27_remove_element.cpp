#include <iostream>
#include <vector>
#include <set>

using namespace std;

class L26RemoveDuplicatesFromSorted {
public:
    static int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                ++k;
            }
        }
        return k;
    }

    static int removeElementSolution(vector<int>& nums, int val) {
        int k = 0;
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                ++k;
            }
        }
        return k;
    }
};


int main() {
    vector<int> nums = {3,2,2,3};
    int val = 3;
    int out = L26RemoveDuplicatesFromSorted::removeElement(nums, val);

    cout << out << endl;

    return 0;
}
