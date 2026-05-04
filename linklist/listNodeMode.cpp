#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int       val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* build(vector<int>& a)
{
    ListNode  dummy(0);
    ListNode* cur = &dummy;
    for (int x : a)
        cur = cur->next = new ListNode(x);
    return dummy.next;
}

void print(ListNode* head)
{
    while (head)
    {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "null\n";
}

int main()
{
    vector<int> a    = { 1, 2, 3, 4, 5 };
    ListNode*   head = build(a);
    print(head);
    return 0;
}