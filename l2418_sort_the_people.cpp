#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <chrono>
#include <unordered_map>

using namespace std;

class L2418SortThePeople {
    // struct Comp{
    //     vector<string>& names;
    //     vector<int>& heights;
    //     Comp(vector<string>& n, vector<int>& h) : names(n), heights(h) {}

    //     bool operator() (int lhs, int rhs) {
    //         if (lhs < rhs) {
    //             auto idx1 = std::distance(heights.begin(), std::find(heights.begin(), heights.end(), lhs));
    //             auto idx2 = std::distance(heights.begin(), std::find(heights.begin(), heights.end(), rhs));
    //             std::iter_swap(names.begin() + idx1, names.begin() + idx2);
    //             return true;
    //         }
    //         return false;
    //     }
    // };
public:
    // static vector<string> sort_people_doesnt_work(vector<string>& names, vector<int>& heights) {
    //     std::sort(names.begin(), names.end(), Comp(names, heights));
    //     return names;
    // }

    static vector<string> sort_people(vector<string>& names, vector<int>& heights) {
        std::map<int, string> htn;
        for (size_t i = 0; i < heights.size(); ++i) {
            htn[heights[i]] = names[i];
        }

        std::vector<string> returnNames;
        for (const auto& pair : htn) { returnNames.push_back(pair.second); }
        std::reverse(returnNames.begin(), returnNames.end());
        return returnNames;
    }

    static vector<string> sort_people_solution(vector<string>& names, vector<int>& heights) {
        std::unordered_map<int, string> htn;
        for (size_t i = 0; i < heights.size(); ++i) {
            htn[heights[i]] = names[i];
        }

        std::sort(heights.rbegin(), heights.rend());

        for (size_t i = 0; i < htn.size(); ++i) {
            names[i] = htn[heights[i]];
        }
        return names;
    }
};


int main() {
    vector<int> nums = {1,3,2};
    vector<string> people = {"steve", "bob", "joe" };
    std::chrono::high_resolution_clock::time_point start(std::chrono::high_resolution_clock::now() );
    vector<string> out = L2418SortThePeople::sort_people(people, nums);
    std::cout << (std::chrono::high_resolution_clock::now() - start) << std::endl;

    for (string name : out) {
        std::cout << name << " ";
    }
    std::cout << std::endl;

    return 0;
}
