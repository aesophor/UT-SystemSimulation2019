#include "list.h"

#include <stdio.h>
#include <stdlib.h>

Node* newNode(EventType type, double clock) {
  Node* new_node = (Node*) malloc(sizeof(Node));
  new_node->type = type;
  new_node->clock = clock;
  new_node->next = NULL;
  return new_node;
}

void insertNode(Node* list_head, Node** list_head_ref, Node* node) {
  if (!list_head) {
    *list_head_ref = node;
    return;
  }

  Node* ptr = list_head;
  while (ptr->next && ptr->clock < node->clock) {
    ptr = ptr->next;
  }
  node->next = ptr->next;
  ptr->next = node;
}

// 1->2->4->5
// 

void removeHead(Node* list_head, Node** list_head_ref) {
  Node* old_head = list_head;
  Node* new_head = list_head->next;
  free(old_head);
  *list_head_ref = new_head;
}

void printList(Node* list_head) {
  Node* ptr = list_head;
  while (ptr) {
    printf("[%d,%f] -> ", ptr->type, ptr->clock);
    ptr = ptr->next;
  }
  printf("\n");
}
