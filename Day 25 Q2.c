struct ListNode *detectCycle(struct ListNode *head) {
  if (head == NULL)
    return NULL;

  struct ListNode *slow = head;
  struct ListNode *fast = head;

  // Step 1: detect cycle
  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast) {
      // Step 2: find cycle start
      struct ListNode *ptr = head;

      while (ptr != slow) {
        ptr = ptr->next;
        slow = slow->next;
      }

      return ptr; // start of cycle
    }
  }

  return NULL; // no cycle
}