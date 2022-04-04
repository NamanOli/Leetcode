https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

https://leetcode.com/problems/swapping-nodes-in-a-linked-list/discuss/1009800/C%2B%2BJP3-One-Pass


When we reach k-th node, we set n1 to the current node, and n2 - to the head.

We continue traversing the list, but now we also move n2. When we reach the end, n2 will points to k-th node from end.

```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
    ListNode *n1 = nullptr, *n2 = nullptr;
    for (auto p = head; p != nullptr; p = p->next) {
        n2 = n2 == nullptr ? nullptr : n2->next;
        if (--k == 0) {
            n1 = p;
            n2 = head;
        }
    }
    swap(n1->val, n2->val);
    return head;
}
};
```
