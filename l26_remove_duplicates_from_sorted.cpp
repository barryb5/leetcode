#include <iostream>
#include <vector>
#include <set>

using namespace std;

class L26RemoveDuplicatesFromSorted {
public:
    static int removeDuplicates(vector<int>& nums) {
        int k = 0;
        for (int i = 0; i < nums.size(); ) {
            if (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
                nums.erase(nums.begin() + i);
            } else {
                ++i;
                ++k;
            }
        }
        return k;
    }

    static int removeDuplicatesSolution(vector<int>& nums) {
        int j = 1;
        for (int i = 1; i < nums.size(); ) {
            if (nums[i] != nums[i - 1]) {
                nums[j] = nums[i];
                ++j;
            }
        }
        return j;
    }
};


int main() {
    vector<int> nums = {1,1,2};
    int out = L26RemoveDuplicatesFromSorted::removeDuplicates(nums);

    cout << out << endl;

    return 0;
}
