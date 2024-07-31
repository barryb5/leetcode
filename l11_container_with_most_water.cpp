#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class L11ContainerWithMostWater {
public:
    static int max_area(vector<int>& height) {
        int max1 = height[0];
        int index1 = 1;
        int max2 = height[1];
        int index2 = 2;
        int n = height.size();
        for (int i = 2; i < n; ++i) {
            if (std::min(height[i], max1) * std::abs((i+1) - index1) > std::min(max1, max2) * std::abs(index1 - index2)
                && (std::min(height[i], max1) != std::min(max1, max2) || (height[i] >= max2 && std::abs((i+1)-index1) > std::abs(index2-index1)))) {
                if (std::min(max2, height[i]) * std::abs((i+1) - index2) > std::min(height[i], max1) * std::abs((i+1) - index1)) {
                    max1 = max2;
                    index1 = index2;
                }
                max2 = height[i];
                index2 = i + 1;
            } else if (std::min(max2, height[i]) * std::abs((i+1) - index2) > std::min(max1, max2) * std::abs(index1 - index2)
                && (std::min(height[i], max2) != std::min(max1, max2) || (height[i] >= max1 && std::abs((i+1)-index2) > std::abs(index1-index2)))) {
                max1 = height[i];
                index1 = i + 1;
            }
        }

        return std::min(max1, max2) * std::abs(index1 - index2);
    }

    static int max_area_solution(vector<int>& height) {
        return 1;
    }
};


int main() {
    vector<int> nums = {1,2,4,3};
    int out = L11ContainerWithMostWater::max_area(nums);

    cout << out << endl;

    return 0;
}
