#include <stdio.h>

#include "../list.h"

Node* list_head = NULL;

int main() {
  insertHead(list_head, &list_head, newNode(0, 5.0f));
  printList(list_head);

  insertHead(list_head, &list_head, newNode(0, 6.0f));
  printList(list_head);

  insertHead(list_head, &list_head, newNode(0, 7.0f));
  printList(list_head);

  removeTail(list_head, &list_head);
  printList(list_head);

  removeTail(list_head, &list_head);
  printList(list_head);

  removeTail(list_head, &list_head);
  printList(list_head);

  insertNode(list_head, &list_head, newNode(1, 8.0f));
  printList(list_head);

  insertNode(list_head, &list_head, newNode(1, 5.0f));
  printList(list_head);

  insertNode(list_head, &list_head, newNode(1, 10.0f));
  printList(list_head);

  removeTail(list_head, &list_head);
  printList(list_head);

}
