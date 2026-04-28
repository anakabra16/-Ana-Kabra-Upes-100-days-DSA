struct ListNode *reverseList(struct ListNode *head) {
  struct ListNode *prev = NULL;
  struct ListNode *curr = head;
  struct ListNode *next = NULL;

  while (curr != NULL) {
    next = curr->next; // store next
    curr->next = prev; // reverse link
    prev = curr;       // move prev
    curr = next;       // move curr
  }

  return prev;
}