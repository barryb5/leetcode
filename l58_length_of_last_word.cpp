#include <iostream>
#include <vector>
#include <unordered_map>
#include <ranges>
#include <algorithm>

using namespace std;

class L58LengthOfLastWord {
public:
    static int length_of_last_word(string s) {
        bool foundWord = false;
        int len = 0;
        for (auto itr = s.rbegin(); itr != s.rend(); ++itr) {
            if (foundWord && *itr == ' ') {
                return len;
            }
            if (*itr != ' ') {
                foundWord = true;
                ++len;
            }
        }
        return len;
    }
};


int main() {
    std::string sentence = "  the quick  brown fox ";
    int out = L58LengthOfLastWord::length_of_last_word(sentence);

    std::cout << out << endl;

    return 0;
}
