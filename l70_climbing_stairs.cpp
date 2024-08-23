#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class L70ClimbingStairs {
public:
    static void dfs(int curr, int end, int &total)
    {
        if (curr + 1 == end) {
            ++total;
        } else if (curr + 2 == end) {
            ++total;
        } else if (curr + 1 > end) {
            return;
        } else if (curr + 2 > end) {
            return;
        }

        dfs(curr + 1, end, total);
        dfs(curr + 2, end, total);
    }
    static int climbing_stairs_dfs(int n) {
        int total = 0;
        dfs(0, n, total);
        return total;
    }
    static int climbing_stairs_dp(int n) {
        int cache[n+1];
        for (int i = n; i > -1; --i) {
            if (i == n || i == n-1) {
                cache[i] = 1;
            } else {
                cache[i] = cache[i + 1] + cache[i + 2];
            }
        }
        return cache[0];
    }
    static int climbing_stairs_solution(int n) {
        int one = 1;
        int two = 1;
        int temp;
        for (int i = 0; i < n - 1; ++i)
        {
            temp = one;
            one = one + two;
            two = temp;
        }
        return one;
    }
};


int main() {
    int n = 5;
    int out = L70ClimbingStairs::climbing_stairs_dfs(n);

    cout << out << endl;
    return 0;
}
