class Solution{public : void removeLoop(Node * head){if (head == NULL) return;

Node *slow = head, *fast = head;

// Step 1: detect loop
while (fast != NULL && fast->next != NULL) {
  slow = slow->next;
  fast = fast->next->next;

  if (slow == fast) {
    // Step 2: find start of loop
    Node *ptr = head;

    while (ptr != slow) {
      ptr = ptr->next;
      slow = slow->next;
    }

    // Step 3: remove loop
    Node *temp = ptr;
    while (temp->next != ptr) {
      temp = temp->next;
    }

    temp->next = NULL;
    return;
  }
}
}
}
;