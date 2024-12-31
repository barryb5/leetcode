#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class L21MergeLists
{
public:
    static ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *merge = nullptr;
        ListNode *temp = nullptr;

        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val < list2->val)
            {
                if (temp == nullptr)
                {
                    temp = new ListNode(list1->val);
                }
                else
                {
                    temp->next = new ListNode(list1->val);
                    temp = temp->next;
                }
                list1 = list1->next;
            }
            else
            {
                if (temp == nullptr)
                {
                    temp = new ListNode(list2->val);
                }
                else
                {
                    temp->next = new ListNode(list2->val);
                    temp = temp->next;
                }
                list2 = list2->next;
            }
            if (merge == nullptr)
            {
                merge = temp;
            }
        }

        if (list1 != nullptr)
        {
            if (temp == nullptr)
                merge = list1;
            else
                temp->next = list1;
        }
        else if (list2 != nullptr)
        {
            if (temp == nullptr)
                merge = list2;
            else
                temp->next = list2;
        }

        return merge;
    }

    static int mergeTwoLists_solution(ListNode *list1, ListNode *list2)
    {
        return 0;
    }
};

int main()
{
    ListNode *list1 = new ListNode(1, nullptr);
    list1->next = new ListNode(3, nullptr);
    ListNode *list2 = new ListNode(2, nullptr);
    list2->next = new ListNode(4, nullptr);
    ListNode *out = L21MergeLists::mergeTwoLists(list1, list2);

    cout << "[";
    while (out != nullptr)
    {
        cout << out->val << ", ";
        out = out->next;
    }
    cout << "]" << endl;

    delete list1->next;
    delete list2->next;
    delete list1;
    delete list2;

    return 0;
}
