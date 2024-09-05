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

    static vector<int> count_bits_solution(int n) {
        vector<int> ans;
        for(int i = 0; i<=n; i++)
        {
            int sum = 0;
            int num = i;
            while(num != 0)
            {
                sum += num%2;
                num = num/2;
            }
            ans.push_back(sum);
        }
        return ans;
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
