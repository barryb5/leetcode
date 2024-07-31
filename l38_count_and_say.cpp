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
                returnString += last;
                last = toEncode[i];
                count = 1;
            }
        }
        if (count != 0) {
            returnString += std::to_string(count);
            returnString += last;
        }
        return returnString;
    }

    // Same speed (3ms) but more memory efficient
    static string count_and_say_non_recursive(int n) {
        std::string startString = "1";
        std::string returnString = "";

        for (int i = 1; i < n; ++i) {
            returnString = "";
            int j = 0;
            int len = startString.length();
            char last = startString[0];
            int count = 0;
            for ( ; j < startString.length(); ++j) {
                if (startString[j] == last) {
                    ++count;
                } else {
                    returnString += std::to_string(count);
                    returnString += last;
                    last = startString[j];
                    count = 1;
                }
            }
            if (count != 0) {
                returnString += std::to_string(count);
                returnString += last;
            }
            startString = std::move(returnString);
        }
        return startString;
    }
};


int main() {
    int n = 4;
    std::string out = L38CountAndSay::count_and_say_non_recursive(n);

    std::cout << out << std::endl;

    return 0;
}
