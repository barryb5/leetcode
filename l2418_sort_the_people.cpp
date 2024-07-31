#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <chrono>

using namespace std;

class L2418SortThePeople {
public:
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
        std::map<int, string> htn;
        for (size_t i = 0; i < heights[i]; ++i) {
            htn[heights[i]] = names[i];
        }

        std::vector<string> returnNames;
        for (const auto& pair : htn) { returnNames.push_back(pair.second); }
        return returnNames;
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
