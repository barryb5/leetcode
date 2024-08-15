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

    static int my_sqrt_solution(int x) {
        if (x < 2)
            return x;

        int start = 1;
        int end = x;
        long mid = -1;

        while (start <= end) {
            mid = start + (end-start) / 2;

            if (mid * mid > x)
                end = mid - 1;
            else if (mid * mid == x)
                return mid;
            else
                start = mid + 1;
        }
        return end;
    }
};


int main() {
    int in = 29;
    int out = L69Sqrt::my_sqrt(in);

    cout << out << endl;
    // cout << out->next->val << endl;
}
