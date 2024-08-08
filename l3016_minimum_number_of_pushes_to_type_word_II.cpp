#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

class L3016MinimumNumberOfPushesToTypeWordII {
public:
    static int minimum_pushes(string word) {
        std::unordered_map<char, int> charTracker;
        for (int i = 0; i < word.length(); ++i) {
            ++charTracker[word[i]];
        }

        std::map<int, std::vector<char>> occurranceTracker;
        for (auto& [c, count] : charTracker) {
            occurranceTracker[count].push_back(c);
        }

        int total = 0;
        int lettersUsed = 0;
        for (auto itr = occurranceTracker.rbegin(); itr != occurranceTracker.rend(); ++itr) {
            for (int i = 0; i < itr->second.size(); ++i) {
                ++lettersUsed;
                if (lettersUsed < 9)
                    total += itr->first;
                else if (lettersUsed < 17)
                    total += itr->first * 2;
                else if (lettersUsed < 25)
                    total += itr->first * 3;
                else
                    total += itr->first * 4;
            }
        }
        return total;
    }

    static int minimum_pushes_solution(string word) {
        std::vector<int> letterFreq(26, 0);
        for (char c : word) {
            letterFreq[c - 'a']++;
        }

        std::sort(letterFreq.rbegin(), letterFreq.rend());

        int totalPresses = 0;
        for (int i = 0; i < 26; i++) {
            if (letterFreq[i] == 0)
                break;
            totalPresses += (i / 8 + 1) * letterFreq[i];
        }

        return totalPresses;

    }
};

int main() {
    std::string word = "alporfmdqsbhncwyu";
    int out = L3016MinimumNumberOfPushesToTypeWordII::minimum_pushes(word);

    std::cout << out << std::endl;

    return 0;
}
