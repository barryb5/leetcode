#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

class L28FirstOccurrenceOfStringInString {
public:
    static int str_str(string haystack, string needle) {
        for (int i = 0; i < haystack.length(); ++i) {
            if (haystack[i] == needle[0]) {
                // start searching
                bool found = true;
                int tempI = i;
                for (int j = 0; j < needle.length(); ++tempI, ++j) {
                    if (tempI >= haystack.length()) {
                        found = false;
                        break;
                    }
                    if (haystack[tempI] != needle[j]) {
                        found = false;
                        break;
                    }
                }
                if (found) {
                    return i;
                }
            }
        }
        return -1;
    }

};


int main() {
    std::string haystack = "aklsdfjiabcskldabc";
    std::string needle = "abc";
    int out = L28FirstOccurrenceOfStringInString::str_str(haystack, needle);

    cout << out << endl;

    return 0;
}
