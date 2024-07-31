#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class L88MergeSortedArray {
public:
    static void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int nums1_count = 0;
        int nums2_count = 0;
        for (int i = 0; i < m + n && nums2_count < n; ++i) {
            if (nums1[i] > nums2[nums2_count]) {
                nums1.insert(nums1.begin() + i, nums2[nums2_count]);
                nums1.pop_back();
                ++nums2_count;
            } else {
                ++nums1_count;
            }

            if (nums1[i] == 0 && nums1_count > m) {
                nums1.erase(nums1.begin() + i, nums1.end());
                nums1.insert(nums1.end(), nums2.begin() + nums2_count, nums2.end());
                break;
            }
        }
    }

    static void merge_solution(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
    }
};


int main() {
    vector<int> nums = {1,3,5,0,0,0};
    vector<int> nums2 = {2,4,6};
    L88MergeSortedArray::merge(nums, 3, nums2, nums2.size());

    for (const auto& num : nums) {
        cout << num;
    }
    cout << '\n';

    return 0;
}
