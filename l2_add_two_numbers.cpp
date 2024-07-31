#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class L2AddTwoNumbers {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    static void delete_list(ListNode* node) {
        while (node != nullptr) {
            ListNode* temp = node;
            node = node->next;
            delete temp;
        }
    }

    static ListNode* helper(ListNode* l1, ListNode* l2, int overflow) {
        int sum = overflow;
        if (nullptr != l1) {
            sum += l1->val;
        }
        if (nullptr != l2) {
            sum += l2->val;
        }
        if (sum > 9) {
            overflow = 1;
        } else {
            overflow = 0;
        }
        ListNode* node = new ListNode(sum % 10);

        if (l1 != nullptr && l1->next != nullptr) {
            if (l2 != nullptr && l2->next != nullptr) {
                node->next = helper(l1->next, l2->next, overflow);
            } else {
                node->next = helper(l1->next, nullptr, overflow);
            }
        } else if (l2 != nullptr && l2->next != nullptr) {
            node->next = helper(nullptr, l2->next, overflow);
        } else if (overflow > 0) {
            node->next = helper(nullptr, nullptr, overflow);
        }

        return node;
    }


    static ListNode* add_two_numbers(ListNode* l1, ListNode* l2) {
        return helper(l1, l2, 0);
    }

    static ListNode* add_two_numbers_solution(ListNode* l1, ListNode* l2) {
        return 0;
    }
};


int main() {
    // L2AddTwoNumbers::ListNode* out = L2AddTwoNumbers::add_two_numbers(l1, l2);

    // std::cout << out << std::endl;

    // L2AddTwoNumbers::delete_list(out);

    return 0;
}
