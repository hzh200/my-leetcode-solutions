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
    bool isPalindrome(ListNode* head) {
        ListNode root;
        root.next = head;
        ListNode* p1 = &root;
        ListNode* p2 = &root;
        while (p2->next != NULL && p2->next->next != NULL) {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        if (p2->next != NULL) {
            p1 = p1->next;
            p2 = p2->next;
        }
        if (p1 == p2) { // One-element linked list.
            return true;
        }
        reverseList(p1, p2);
        ListNode* cur1 = root.next;
        ListNode* cur2 = p1->next;
        int flag = 0;
        while (cur1 != NULL && cur2 != NULL) {
            if (cur1->val != cur2->val) {
                flag = 1;
                break;
            }
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        // ListNode *next = &root;
        // while (next != NULL) {
        //     cout << next->val << " ";
        //     next = next->next;
        // }
        return !flag;
    }

    ListNode* reverseList(ListNode* root, ListNode* tail) {
        ListNode *cur = root;
        while (root->next != tail) {
            ListNode *next = root->next;
            root->next = next->next;
            next->next = tail->next;
            tail->next = next;
        }
        return root->next;
    }
};