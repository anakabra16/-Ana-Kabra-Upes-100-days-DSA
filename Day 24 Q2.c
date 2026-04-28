struct ListNode *removeElements(struct ListNode *head, int val) {

  // dummy node
  struct ListNode dummy;
  dummy.next = head;

  struct ListNode *prev = &dummy;
  struct ListNode *curr = head;

  while (curr != NULL) {
    if (curr->val == val) {
      prev->next = curr->next; // remove node
    } else {
      prev = curr; // move prev only if not deleted
    }
    curr = curr->next;
  }

  return dummy.next;
}