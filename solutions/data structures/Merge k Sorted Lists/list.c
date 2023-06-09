/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <math.h>
#include <stddef.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    struct ListNode head;
    head.next = NULL;
    struct ListNode *cur = &head;
    while (1) {
        int min = pow(10, 4) + 1, index = -1;
        for (int i = 0; i < listsSize; i++) {
            if (lists[i] && lists[i]->val < min) {
                min = lists[i]->val;
                index = i;
            }
        }
        if (index == -1) {
            break;
        }
        cur->next = lists[index];
        lists[index] = lists[index]->next;
        cur = cur->next;
        cur->next = NULL;
    }
    return head.next;
}