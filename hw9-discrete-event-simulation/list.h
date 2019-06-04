#ifndef LIST_H_
#define LIST_H_

typedef enum {
  ARRIVAL = 0,
  DEPARTURE
} EventType;

typedef struct node_t {
  EventType type;
  double clock;
  struct node_t* next;
} Node;


Node* newNode(EventType type, double clock);

void insertNode(Node* list_head, Node** list_head_ref, Node* node);
void insertHead(Node* list_head, Node** list_head_ref, Node* node);

Node* removeHead(Node* list_head, Node** list_head_ref);
Node* removeTail(Node* list_head, Node** list_head_ref);
Node* getTail(Node* list_head);

void printList(Node* list_head);

#endif // LIST_H_
