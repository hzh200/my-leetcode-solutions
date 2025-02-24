/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stddef.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode ListNode;

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    ListNode dummy;
    dummy.next = head;
    ListNode *fir = &dummy, *sec = &dummy;
    while (sec->next && n) {
        sec = sec->next;
        n--;
    }
    if (n) {
        return NULL;
    }
    while (sec->next) {
        fir = fir->next;
        sec = sec->next;
    }
    fir->next = fir->next->next;
    return dummy.next;
}