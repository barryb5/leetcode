#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class L125ValidPalindrome {
public:
    static void treeSearch(TreeNode* root, std::vector<int>& vals, int upstreamVal) {
        upstreamVal *= 10;
        upstreamVal += root->val;

        if (nullptr != root->left) {
            treeSearch(root->left, vals, upstreamVal);
        }
        if (nullptr != root->right) {
            treeSearch(root->right, vals, upstreamVal);
        }
        if (nullptr == root->left && nullptr == root->right) {
            vals.push_back(upstreamVal);
        }
    }
    static int sum_numbers(TreeNode* root) {
        std::vector<int> vals;
        treeSearch(root, vals, 0);
        return std::accumulate(vals.begin(), vals.end(), 0);
    }

    static void treeSearchSolution(TreeNode* root, int& total, int upstreamVal) {
        upstreamVal *= 10;
        upstreamVal += root->val;

        if (nullptr != root->left) {
            treeSearchSolution(root->left, total, upstreamVal);
        }
        if (nullptr != root->right) {
            treeSearchSolution(root->right, total, upstreamVal);
        }
        if (nullptr == root->left && nullptr == root->right) {
            total += upstreamVal;
        }
    }
    int sum_numbers_second_attempt(TreeNode* root) {
        int total = 0;
        treeSearchSolution(root, total, 0);
        return total;
    }
};

int main() {
    TreeNode* root = new TreeNode(0);
    int out = L125ValidPalindrome::sum_numbers(root);

    delete root;
    cout << out << endl;

    return 0;
}
