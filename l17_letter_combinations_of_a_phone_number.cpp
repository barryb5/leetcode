#include <iostream>
#include <vector>
#include <map>

using namespace std;

class L17LetterCombinationsOfAPhoneNumber {
public:
    static std::vector<std::string> helper(string digits) {
        std::map<char, std::vector<std::string>> numberLetterMatch {
            {'2', {"a", "b", "c"}},
            {'3', {"d", "e", "f"}},
            {'4', {"g", "h", "i"}},
            {'5', {"j", "k", "l"}},
            {'6', {"m", "n", "o"}},
            {'7', {"p", "q", "r", "s"}},
            {'8', {"t", "u", "v"}},
            {'9', {"w", "x", "y", "z"}},
        };
        if (digits.length() == 1) {
            return numberLetterMatch[digits[0]];
        }

        std::vector<std::string> returnStrings;

        std::vector<std::string> base = helper(digits.substr(1));
        for (std::string& c : numberLetterMatch[digits[0]]) {
            for (std::string& s : base) {
                std::string add = c + s;
                returnStrings.push_back(add);
            }
        }

        return returnStrings;
    }

    static std::vector<std::string> letter_combinations(string digits) {
        return helper(digits);
    }
};

int main() {
    std::string num = "292";
    std::vector<std::string> out = L17LetterCombinationsOfAPhoneNumber::letter_combinations(num);

    for (const auto& i : out) {
        std::cout << i << std::endl;
    }

    return 0;
}
