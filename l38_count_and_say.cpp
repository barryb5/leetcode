#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class L38CountAndSay {
public:
    static string count_and_say(int n) {
        // Base case
        if (n == 1) {
            return "1";
        }

        std::string toEncode = count_and_say(n-1);
        std::string returnString = "";
        int len = toEncode.length();
        char last = toEncode[0];
        int count = 0;
        int i = 0;
        for ( ; i < len; ++i) {
            if (toEncode[i] == last) {
                ++count;
            } else {
                returnString += std::to_string(count);
                returnString += toEncode[i-1];
                last = toEncode[i];
                count = 1;
            }
        }
        if (count != 0) {
            returnString += std::to_string(count);
            returnString += toEncode[i-1];
        }
        return returnString;
    }

    static string countAndSay_solution(int n) {
        return "1";
    }
};


int main() {
    int n = 4;
    std::string out = L38CountAndSay::count_and_say(n);

    std::cout << out << std::endl;

    return 0;
}
