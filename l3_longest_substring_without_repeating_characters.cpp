#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class L3LongestSubstringWithoutRepeatingCharacters {
public:
    static int length_of_longest_substring(std::string s) {
        std::unordered_set<char> window;
        int windowStartIdx = 0;
        int biggestWindowSize = 0;
        for (size_t i = 0; i < s.length(); ++i) {
            if (window.find(s[i]) == window.end()) {
                // Not in window already
                window.insert(window.end(), s[i]);
                if (window.size() > biggestWindowSize) {
                    biggestWindowSize = window.size();
                }
            } else {
                for ( ; windowStartIdx < s.length(); ++windowStartIdx) {
                    if (s[windowStartIdx] != s[i]) {
                        window.erase(s[windowStartIdx]);
                    } else {
                        // Break because we found new start
                        ++windowStartIdx;
                        break;
                    }
                }
            }
        }

        return biggestWindowSize;
    }
};


int main() {
    std::string s = "abcabcab";
    int out = L3LongestSubstringWithoutRepeatingCharacters::length_of_longest_substring(s);

    cout << out << endl;

    return 0;
}
