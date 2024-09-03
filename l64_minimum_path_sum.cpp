#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class L64MinimumPathSum {
public:
    static void work_back(vector<vector<int>>& grid, vector<vector<int>>& solution, int i, int j, int currentVal) {
        if (solution[i][j] > grid[i][j] + currentVal) {
            solution[i][j] = grid[i][j] + currentVal;
        } else {
            return;
        }
        if (i == 0 && j == 0) {
            return;
        }
        if (i > 0) {
            work_back(grid, solution, i - 1, j, solution[i][j]);
        }
        if (j > 0) {
            work_back(grid, solution, i, j - 1, solution[i][j]);
        }
    }

    static int min_path_sum(vector<vector<int>>& grid) {
        vector<vector<int>> solution(grid.size(), vector<int>(grid.front().size(), 2147483647));
        work_back(grid, solution, grid.size() - 1, grid.front().size() - 1, 0);
        return solution[0][0];
    }
};


int main() {
    std::vector<std::vector<int>> grid = {};
    std::vector<int> row1 = {1,1,4};
    std::vector<int> row2 = {2,1,1};
    std::vector<int> row3 = {3,3,1};
    grid.push_back(row1);
    grid.push_back(row2);
    grid.push_back(row3);
    int out = L64MinimumPathSum::min_path_sum(grid);

    cout << out << endl;

    return 0;
}
