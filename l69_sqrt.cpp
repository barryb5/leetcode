#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class L69Sqrt {
public:
    static int my_sqrt(int x) {
        int sqrt = 0;
        for (int i = 1; x > 0; i += 2) {
            x -= i;
            ++sqrt;
        }
        if (x < 0)
            --sqrt;

        return sqrt;
    }
};


int main() {
    int in = 29;
    int out = L69Sqrt::my_sqrt(in);

    cout << out << endl;
    // cout << out->next->val << endl;
}
