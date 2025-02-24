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

ListNode *detectCycle(ListNode *head) {
    if (!head || !head->next) {
        return NULL;
    }
    ListNode *fir = head, *sec = head->next;
    while (fir != sec) {
        if (!sec->next || !sec->next->next) {
            return NULL;
        }
        fir = fir->next;
        sec = sec->next->next;
    }
    fir = fir->next;
    while (head != fir) {
        head = head->next;
        fir = fir->next;
    }
    return head;
}