#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class L118PascalsTriangle {
public:
    static vector<vector<int>> generate(int numRows) {
        vector<vector<int>> returnRows;
        returnRows.push_back(vector<int>{1});
        if (numRows == 1) {
            return returnRows;
        }
        returnRows.push_back(vector<int>{1, 1});
        if (numRows == 2) {
            return returnRows;
        }
        for (int i = 3; i <= numRows; ++i) {
            vector<int> row(i, 1);

            int mid = i % 2 == 0 ? i/2: i/2 + 1;
            for (int j = 1; j < mid; ++j) {
                row[j] = returnRows[i-2][j-1] + returnRows[i-2][j];
                row[i-j-1] = row[j];
            }
            returnRows.push_back(row);
        }
        return returnRows;
    }

    static vector<vector<int>> generate_solution(int numRows) {
        vector<vector<int>> returnRows;
        // Is the same as mine
        return returnRows;
    }
};


int main() {
    int nums = 5;
    vector<vector<int>> out = L118PascalsTriangle::generate(nums);

    for (const auto& line : out) {
        for (const int val : line) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    cout << '\n';
    return 0;
}