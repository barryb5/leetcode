#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

class L13RomanToInteger {
public:
    static int roman_to_int(string s) {
        std::unordered_map<char, int> mapping = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };
        int total = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (i + 1 < s.size() && mapping[s[i]] < mapping[s[i+1]]) {
                total += mapping[s[i+1]] - mapping[s[i]];
                ++i;
            } else {
                total += mapping[s[i]];
            }
        }
        return total;
    }

    static int roman_to_int_solution(string s) {
        std::unordered_map<char, int> mapping = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };

        int ans = 0;
        for(int i = 0; i < s.length(); i++){
            if(mapping[s[i]] < mapping[s[i+1]]){
                ans -= mapping[s[i]];
            }
            else{
                ans += mapping[s[i]];
            }
        }
        return ans;
    };
};

int main() {
    std::string word = "CMLXXVI";
    int out = L13RomanToInteger::roman_to_int(word);

    std::cout << out << std::endl;

    return 0;
}
