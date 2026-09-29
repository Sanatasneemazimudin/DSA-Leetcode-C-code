#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode* next;
};
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    while(curr != NULL) {
        struct ListNode* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}
void printList(struct ListNode* head) {
    while(head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}
int main() {
    struct ListNode* n1 = malloc(sizeof(struct ListNode));
    struct ListNode* n2 = malloc(sizeof(struct ListNode));
    struct ListNode* n3 = malloc(sizeof(struct ListNode));
    n1->val = 1; n1->next = n2;
    n2->val = 2; n2->next = n3;
    n3->val = 3; n3->next = NULL;
    printf("Original List:\n");
    printList(n1);
    struct ListNode* reversed = reverseList(n1);
    printf("Reversed List:\n");
    printList(reversed);
    free(n3); free(n2); free(n1);
    return 0;
}
