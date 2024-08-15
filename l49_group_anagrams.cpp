#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class L49GroupAnagrams {
public:
    static std::vector<std::vector<string>> group_anagrams(vector<string>& strs) {
        std::vector<std::vector<std::string>> out;
        std::unordered_map<std::string, std::vector<string>> sorted;

        for (std::string& str : strs) {
            std::string sortedWord = str;
            std::sort(sortedWord.begin(), sortedWord.end());
            sorted[sortedWord].push_back(str);
        }

        for (const auto& [sorted, vec] : sorted) {
            out.emplace_back(vec);
        }

        return out;
    }

    static std::vector<std::vector<std::string>> group_anagrams_solution(std::vector<std::string>& strs) {
        if(strs.size()==0) return {};

        unordered_map<string, vector<string>> ump;

        for(auto str: strs){
            string temp = str;
            sort(temp.begin(), temp.end());
            ump[temp].push_back(str);
        }

        vector<vector<string>> ans;
        for(auto &it:ump){
            ans.push_back(it.second);
        }
        return ans;
    }
};


int main() {
    std::vector<std::string> anagrams = {"cat", "act", "tac", "fad", "daf", "lsd"};
    std::vector<std::vector<string>> out = L49GroupAnagrams::group_anagrams(anagrams);

    for (auto& vec : out) {
        for (const auto& str : vec) {
            std::cout << str << " ";
        }
        std::cout << std::endl;
    }
}
