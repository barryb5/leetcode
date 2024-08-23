#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class L121BestTimeToBuyAndSellStock {
public:
    static int max_profit(vector<int>& prices) {
        int biggest = 0;
        for (int windowSize = 1; windowSize < prices.size(); ++windowSize) {
            for (int i = 0; i + windowSize < prices.size(); ++i) {
                if (prices[i + windowSize] - prices[i] > biggest) {
                    biggest = prices[i + windowSize] - prices[i];
                }
            }
        }

        return biggest;
    }
};


int main() {
    vector<int> prices{7,1,5,3,6,4};
    int out = L121BestTimeToBuyAndSellStock::max_profit(prices);

    cout << out << endl;
    return 0;
}
