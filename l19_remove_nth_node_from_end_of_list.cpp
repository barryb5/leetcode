#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class L19RemoveNthNodeFromEndOfList {
public:
    static ListNode* remove_nth_from_end(ListNode* head, int n) {
        if (head == nullptr)
            return head;
        else if (head->next == nullptr) {
            delete head;
            return nullptr;
        }


        int size = 1;
        ListNode* temp = head;
        while (temp->next != nullptr) {
            ++size;
            temp = temp->next;
        }

        temp = head;
        int counter = 0;

        while (nullptr != temp->next && counter < size - n) {
            temp = temp->next;
            ++counter;
        }

        ListNode* tempNext = temp->next;
        if (nullptr != tempNext && nullptr != tempNext->next)
            temp->next = tempNext->next;
        else
            temp->next = nullptr;
        delete tempNext;
        return head;
    }
};


int main() {
    ListNode* node1 = new ListNode{2, nullptr};
    ListNode* head = new ListNode{1, node1};
    ListNode* out = L19RemoveNthNodeFromEndOfList::remove_nth_from_end(head, 2);

    cout << out->val << endl;
    // cout << out->next->val << endl;
}
