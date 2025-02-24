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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        ListNode root;
        root.next = head;
        ListNode *tail = &root;
        ListNode *next = head;
        while (next != NULL) {
            tail = tail->next;
            next = next->next;
        }
        ListNode *cur = &root;
        while (root.next != tail) {
            next = root.next;
            root.next = next->next;
            next->next = tail->next;
            tail->next = next;
        }
        return root.next;
    }
};