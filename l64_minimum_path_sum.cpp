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

    static int min_path_sum_solution(vector<vector<int>>& grid) {
        vector<int> prevRow(grid.front().size(), 2147483647);
        vector<int> curRow(grid.front().size(), 0);

        for (int i = grid.size() - 1; i > -1; --i)
        {
            for (int j = grid.front().size() - 1; j > -1; --j)
            {
                if (j == grid.front().size() - 1) {
                    if (i == grid.size() - 1) {
                        curRow[j] = grid[i][j];
                    } else {
                        curRow[j] = grid[i][j] + prevRow[j];
                    }
                } else {
                    if (i == grid.size() - 1)
                        curRow[j] = grid[i][j] + curRow[j + 1];
                    else
                        curRow[j] = grid[i][j] + std::min(curRow[j + 1], prevRow[j]);
                }
                prevRow[j] = curRow[j];
            }
        }
        return curRow[0];
    }
};


int main() {
    std::vector<std::vector<int>> grid = {};
    std::vector<int> row1 = {1,2,3};
    std::vector<int> row2 = {4,5,6};
    std::vector<int> row3 = {3,3,1};
    grid.push_back(row1);
    grid.push_back(row2);
    // grid.push_back(row3);
    int out = L64MinimumPathSum::min_path_sum_solution(grid);

    cout << out << endl;

    return 0;
}
