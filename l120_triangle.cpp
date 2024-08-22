#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class L120Triangle {
public:
    static int minimum_total(vector<vector<int>>& triangle) {
        int total = 0;
        int lastIdx = 0;
        for (auto& vec : triangle) {
            if (vec.size() > 1) {
                if (vec[lastIdx] < vec[lastIdx + 1]) {
                    total += vec[lastIdx];
                } else {
                    total += vec[lastIdx + 1];
                    ++lastIdx;
                }
            } else {
                total += vec[0];
                lastIdx = 0;
            }
        }
        return total;
    }

    static int minimum_total_solution(std::vector<std::vector<int>> triangle) {
        std::vector<int> solutions(triangle.size() + 1, 0);

        for (int row = triangle.size() - 1; row >= 0; --row) {
            for (int col = 0; col <= row; ++col)
            {
                solutions[col] = std::min(solutions[col], solutions[col + 1]) + triangle[row][col];
            }
        }

        return solutions[0];
    }
};


int main() {
    std::vector<int> row1{3};
    std::vector<int> row2{3,2};
    std::vector<int> row3{1,4,6};
    std::vector<int> row4{2,5,4,8};
    std::vector<std::vector<int>> sentence;
    sentence.push_back(row1);
    sentence.push_back(row2);
    sentence.push_back(row3);
    sentence.push_back(row4);
    int out = L120Triangle::minimum_total_solution(sentence);

    std::cout << out << endl;
    return 0;
}
