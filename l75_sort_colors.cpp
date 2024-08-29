#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class L75SortColors {
public:
    static void sort_colors(vector<int>& nums) {
        int startIdx = 0;
        int backIdx = nums.size() - 1;
        int midIdx = 0;

        while (midIdx <= backIdx) {
            if (startIdx > backIdx) {
                break;
            }
            if (nums[startIdx] == 0) {
                ++startIdx;
                if (midIdx < startIdx)
                    midIdx = startIdx;
                continue;
            }
            if (nums[backIdx] == 2) {
                --backIdx;
                if (midIdx > backIdx)
                    midIdx = backIdx;
                continue;
            }
            if (nums[midIdx] == 0) {
                std::iter_swap(nums.begin() + startIdx, nums.begin() + midIdx);
                continue;
            } else if (nums[midIdx] == 2) {
                std::iter_swap(nums.begin() + midIdx, nums.begin() + backIdx);
                continue;
            } else {
                ++midIdx;
            }
        }
    }

    static void sort_colors_solution(vector<int>& nums) {
        unordered_map<int, int> count = {{0, 0}, {1, 0}, {2, 0}};

        for (int num : nums) {
            count[num]++;
        }

        int idx = 0;
        for (int color = 0; color < 3; color++) {
            int freq = count[color];
            for (int j = 0; j < freq; j++) {
                nums[idx] = color;
                idx++;
            }
        }
    }
};


int main() {
    std::vector<int> sentence = {2,1,0,2,2,1,0,2};
    L75SortColors::sort_colors(sentence);

    for (auto a : sentence) {
        std::cout << a << endl;
    }
    return 0;
}
