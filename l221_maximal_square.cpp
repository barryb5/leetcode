#include <iostream>
#include <vector>

using namespace std;

class L221MaximalSquare {
public:
    static int maximal_square(vector<vector<char>>& matrix) {
        int max = 0;
        int m = matrix.size();
        int n = matrix.front().size();
        int dp[m][n];
        for(int i = m - 1; i >= 0; --i)
        {
            for(int j = n - 1; j >= 0; --j)
            {
                dp[i][j] = 0;
                if(matrix[i][j] == '0')
                    continue;
                if(i == m - 1 || j == n - 1)
                    dp[i][j] = 1;
                else
                {
                    dp[i][j] = std::min(dp[i + 1][j], dp[i][j + 1]);
                    dp[i][j] = 1+std::min(dp[i + 1][j+1], dp[i][j]);
                }
                if(dp[i][j] > max)
                    max = dp[i][j];
            }
        }
        return max*max;
    }
};


int main() {
    vector<char> row1{'0', '1', '1', '0', '1'};
    vector<char> row2{'0', '1', '1', '1', '1'};
    vector<char> row3{'0', '1', '1', '1', '0'};
    vector<char> row4{'0', '1', '1', '1', '1'};
    vector<vector<char>> rows;
    rows.push_back(row1);
    rows.push_back(row2);
    rows.push_back(row3);
    rows.push_back(row4);
    int out = L221MaximalSquare::maximal_square(rows);

    cout << out << endl;
    return 0;
}
