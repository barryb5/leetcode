#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class L125ValidPalindrome {
public:
    static bool is_palindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left <= right) {
            if (!std::isalnum(s[left])) {
                ++left;
                continue;
            }
            if (!std::isalnum(s[right])) {
                --right;
                continue;
            }
            if (std::tolower(s[left]) != std::tolower(s[right])) {
                return false;
            }

            ++left;
            --right;
        }
        return true;
    }

    static bool is_palindrome_solution(string s)
    {
        int start = 0;
        int end = s.size() - 1;
        while (start <= end)
        {
            if (!isalnum(s[start]))
            {
                start++;
                continue;
            }
            if (!isalnum(s[end]))
            {
                end--;
                continue;
            }
            if (tolower(s[start]) != tolower(s[end]))
                return false;
            else
            {
                start++;
                end--;
            }
        }
        return true;
    }
};

int main() {
    std::string palindrome{"0p"};
    bool out = L125ValidPalindrome::is_palindrome(palindrome);

    cout << out << endl;

    return 0;
}
