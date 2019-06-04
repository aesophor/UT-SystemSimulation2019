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

void
insertNode(Node* list_head, Node** list_head_ref, Node* node) {
  if (!list_head) {
    *list_head_ref = node;
    return;
  }

  if (node->clock < list_head->clock) {
    insertHead(list_head, list_head_ref, node);
    return;
  } else {
    Node* ptr = list_head;
    while (ptr->next && ptr->clock < node->clock) {
      ptr = ptr->next;
    }
    node->next = ptr->next;
    ptr->next = node;
  }
}

// 1->2->4->5
// 

void
insertHead(Node* list_head, Node** list_head_ref, Node* node) {
  if (!list_head) {
    *list_head_ref = node;
    return;
  }

  node->next = list_head;
  *list_head_ref = node;
}

Node*
removeHead(Node* list_head, Node** list_head_ref) {
  Node* old_head = list_head;
  Node* new_head = list_head->next;
  *list_head_ref = new_head;
  return old_head;
}

Node*
removeTail(Node* list_head, Node** list_head_ref) {
  if (!list_head) {
    return NULL;
  } else if (list_head && !list_head->next) {
    *list_head_ref = NULL;
    return list_head;
  }

  Node* ptr = list_head;
  Node* prev = NULL;
  while (ptr->next) {
    prev = ptr;
    ptr = ptr->next;
  }
  prev->next = NULL;
  return ptr;
}

Node*
getTail(Node* list_head) {
  Node* ptr = list_head;
  while (ptr->next) {
    ptr = ptr->next;
  }
  return ptr;
}

void printList(Node* list_head) {
  Node* ptr = list_head;
  while (ptr) {
    printf("[%d,%f] -> ", ptr->type, ptr->clock);
    ptr = ptr->next;
  }
  printf("\n");
}
