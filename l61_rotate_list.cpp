#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class L61RotateList {
public:
    static ListNode* rotate_right(ListNode* head, int k) {
        std::vector<ListNode*> nodes;
        ListNode* temp = head;
        while (temp != nullptr) {
            nodes.push_back(temp);
            temp = temp->next;
        }

        if (nodes.size() == 0) {
            return head;
        }

        k = k % nodes.size();
        if (k <= 0) {
            return head;
        }
        k = nodes.size() - k;

        nodes[k-1]->next = nullptr;
        nodes.back()->next = head;
        return nodes[k];
    }

    static ListNode* rotate_right_solution(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0)
            return head;

        int n = 1;
        ListNode* tail = head;

        while (tail->next) {
            ++n;
            tail = tail->next;
        }

        k = k % n;
        if (k <= 0) {
            return head;
        }
        tail->next = head;

        ListNode* temp = head;
        for (int i = 1; i < n - k; ++i) {
            temp = temp->next;
        }
        ListNode* newHead = temp->next;
        temp->next = nullptr;
        return newHead;
    }
};

int main() {
    ListNode* node3 = new ListNode{3, nullptr};
    ListNode* node2 = new ListNode{2, node3};
    ListNode* node = new ListNode{1, node2};

    std::cout << node->val << std::endl;
    std::cout << node->next->val << std::endl;
    std::cout << node->next->next->val << std::endl;

    ListNode* out = L61RotateList::rotate_right_solution(node, 1);
    std::cout << "Answer:" << std::endl;
    std::cout << out->val << std::endl;
    std::cout << out->next->val << std::endl;
    std::cout << out->next->next->val << std::endl;

    delete node;
    delete node2;
    delete node3;

    return 0;
}
