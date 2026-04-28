bool hasCycle(struct ListNode *head) {
  if (head == NULL)
    return false;

  struct ListNode *slow = head;
  struct ListNode *fast = head;

  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;       // move 1 step
    fast = fast->next->next; // move 2 steps

    if (slow == fast) // cycle found
      return true;
  }

  return false; // no cycle
}