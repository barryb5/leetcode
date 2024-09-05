#include <iostream>
#include <vector>

using namespace std;

class L338CountingBits {
public:
    static vector<int> count_bits(int n) {
        std::vector<int> out(n+1);
        out[0] = 0;

        for (int i = 1; i <= n; ++i) {
            out[i] = i % 2;
            out[i] += out[i/2];
        }
        return out;
    }
};


int main() {
    int n{7};
    vector<int> out = L338CountingBits::count_bits(n);

    for (int i : out) {
        cout << i << endl;
    }
    return 0;
}
