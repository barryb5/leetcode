#include <iostream>
#include <vector>
#include <unordered_map>
#include <ranges>
#include <algorithm>

using namespace std;

class L38CountAndSay {
public:
    static void dfs(const std::vector<int>& A, int s, int target, vector<int>&& path, vector<vector<int>>& ans) {
        if (target < 0) {
            return;
        } else if (target == 0) {
            ans.push_back(path);
            return;
        }

        for (int i = s; i < A.size(); ++i) {
            path.push_back(A[i]);
            dfs(A, i, target - A[i], move(path), ans);
            path.pop_back();
        }
    }

    static vector<vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        vector<vector<int>> out;
        std::ranges::sort(candidates);

        dfs(candidates, 0, target, {}, out);
        return out;
    }
};


int main() {
    int target = 12;
    std::vector<int> candidates{1, 3, 7, 8, 9, 11};
    std::vector<std::vector<int>> out = L38CountAndSay::combinationSum(candidates, target);

    for (auto a : out) {
        for (auto b : a) {
            std::cout << b;
        }
        std::cout << endl;
    }

    return 0;
}
