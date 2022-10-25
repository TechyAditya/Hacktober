//Leetcode question: 237. Delete Node in a Linked List

class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        ListNode *temp = node->next;
        node->val = temp->val;
        node->next = node->next->next;
        delete (temp);
    }
};
