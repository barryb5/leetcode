#include <iostream>
#include <vector>
#include <unordered_map>
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

    static int length_of_longest_substring_solution(std::string s) {
        std::unordered_map<char, int> window;
        int windowStartIdx = 0;
        int biggestWindowSize = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (window[s[i]] == 0) {
                // Not in window already
                ++window[s[i]];
                biggestWindowSize = std::max(biggestWindowSize, i-windowStartIdx+1);
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

    static int length_of_longest_substring_solution_second(std::string s) {
        int n = s.length();
        std::vector<int> window(128, -1);
        int windowStartIdx = 0;
        int biggestWindowSize = 0;
        for (int i = 0; i < n; ++i) {
            if (window[s[i]] >= windowStartIdx) {
                windowStartIdx = window[s[i]] + 1;
            }
            window[s[i]] = i;
            biggestWindowSize = std::max(biggestWindowSize, i - windowStartIdx + 1);
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
