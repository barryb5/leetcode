#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class L108ConvertSortedArrayToBinarySearchTree {
public:
    static TreeNode* sorted_array_to_bst(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) {
            return nullptr;
        } else if (len == 1) {
            return new TreeNode(nums[0]);
        }
        int mid = len/2;
        TreeNode* root = new TreeNode(nums[mid]);
        std::vector<int> left = std::vector<int>(nums.begin(), nums.begin() + mid);
        std::vector<int> right = std::vector<int>(nums.begin() + mid + 1, nums.end());
        root->left = sorted_array_to_bst(left);
        root->right = sorted_array_to_bst(right);

        return root;
    }

    static TreeNode* helper(vector<int>& nums, int start, int end) {
        if (start > end) {
            return nullptr;
        }
        int mid = (start + end) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        if (start == end) {
            return node;
        }
        node->left = helper(nums, start, mid-1);
        node->right = helper(nums, mid+1, end);

        return node;
    }

    static TreeNode* sorted_array_to_bst_solution(vector<int>& nums) {
        TreeNode* root = helper(nums, 0, nums.size()-1);
        return root;
    }
};


int main() {
    vector<int> nums = {1,3,5,7,8,9};
    L108ConvertSortedArrayToBinarySearchTree::sorted_array_to_bst(nums);

    for (const auto& num : nums) {
        cout << num;
    }
    cout << '\n';

    return 0;
}
