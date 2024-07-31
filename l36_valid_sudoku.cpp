#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

class L36ValidSudoku {
public:
    static bool test_horizontal(vector<char>& line) {
        std::set<char> vals;
        for (auto& num : line) {
            if (num == '.')
                continue;
            if (vals.find(num) != vals.end())
                return false;
            vals.insert(vals.end(), num);
        }
        return true;
    }

    static bool test_vertical(std::vector<std::vector<char>>& board) {
        std::set<char> verticals[9];
        for (auto& row : board) {
            for (int i = 0; i < 9; ++i) {
                if (row[i] == '.')
                    continue;
                if (verticals[i].find(row[i]) != verticals[i].end())
                    return false;
                verticals[i].insert(verticals[i].end(), row[i]);
            }
        }
        return true;
    }

    static bool test_square(std::vector<std::vector<char>>& board, int i, int j) {
        std::set<char> vals;
        int j_init = j;
        int horcap = i + 3;
        int vercap = j + 3;
        for ( ; i < horcap; ++i) {
            for ( ; j < vercap; ++j) {
                if (board.at(i).at(j) == '.')
                    continue;
                if (vals.find(board.at(i).at(j)) != vals.end())
                    return false;
                vals.insert(vals.end(), board.at(i).at(j));
            }
            j = j_init;
        }
        return true;
    }

    static bool testHorVer(vector<vector<char>>& board) {
        std::set<char> horizontals[9];
        std::set<char> verticals[9];
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.')
                    continue;
                if (horizontals[i].find(board[i][j]) != horizontals[i].end())
                    return false;
                if (verticals[j].find(board[i][j]) != verticals[j].end())
                    return false;
                horizontals[i].insert(horizontals[i].end(), board[i][j]);
                verticals[j].insert(verticals[j].end(), board[i][j]);
            }
        }
        return true;
    }

    static bool is_valid_sudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 3; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                if (!test_square(board, i, j))
                    return false;
            }
        }

        return true;
    }

    static bool is_valid_sudoku_attempt_two(vector<vector<char>>& board) {
        if (!testHorVer(board))
            return false;

        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                if (!test_square(board, i, j))
                    return false;
            }
        }
        return true;
    }
};


int main() {
    int target = 3;
    vector<vector<char>> board;
    vector<char> row1{'5','3','.','.','7','.','.','.','.'};
    vector<char> row2{'6','.','.','1','9','5','.','.','.'};
    vector<char> row3{'.','9','8','.','.','.','.','6','.'};
    board.push_back(row1);
    board.push_back(row2);
    board.push_back(row3);
    bool out = L36ValidSudoku::is_valid_sudoku(board);

    std::cout << out << std::endl;

    return 0;
}
