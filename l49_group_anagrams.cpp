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
