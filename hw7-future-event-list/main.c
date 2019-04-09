#include <stddef.h>

#include "list.h"

int main() {
  // Driver code
  Node* list_head = NULL;

  insertNode(list_head, &list_head, newNode(0, 0));
  printList(list_head);

  insertNode(list_head, &list_head, newNode(0, 3));
  printList(list_head);

  insertNode(list_head, &list_head, newNode(0, 5));
  printList(list_head);

  removeHead(list_head, &list_head);
  printList(list_head);
}
