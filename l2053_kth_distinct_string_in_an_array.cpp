#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class L2053KthDistinctStringInAnArray {
public:
    static string kth_distinct(vector<string>& arr, int k) {
        std::unordered_map<string, int> distinct;
        for (const string& str : arr) {
            ++distinct[str];
        }

        int counter = 0;
        for (const string& str : arr) {
            if (distinct[str] == 1)
                ++counter;
            if (counter == k)
                return str;
        }
        return "";
    }
};


int main() {
    std::vector<std::string> sentence = {"the", "the", "quick", "brown", "fox", "brown"};
    string out = L2053KthDistinctStringInAnArray::kth_distinct(sentence, 2);

    std::cout << out << endl;

    return 0;
}
