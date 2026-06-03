#ifndef LIST_H
#define LIST_H

typedef struct Node {
    char *value;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct {
    Node *head;
    Node *tail;
    int size;
} List;

void list_init(List *list);
void list_destroy(List *list);
int list_insert(List *list, const char *value);
Node *list_find(List *list, const char *value);
int list_delete(List *list, const char *value);
void list_print(List *list);

#endif
