#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

void list_init(List *list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

void list_destroy(List *list) {
    Node *current = list->head;
    while (current != NULL) {
        Node *next = current->next;
        free(current->value);
        free(current);
        current = next;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

int list_insert(List *list, const char *value) {
    Node *node = malloc(sizeof(Node));
    if (node == NULL) return 0;

    node->value = strdup(value);
    if (node->value == NULL) {
        free(node);
        return 0;
    }

    node->next = NULL;
    node->prev = list->tail;

    if (list->tail != NULL) {
        list->tail->next = node;
    } else {
        list->head = node;
    }
    list->tail = node;
    list->size++;
    return 1;
}

Node *list_find(List *list, const char *value) {
    Node *current = list->head;
    while (current != NULL) {
        if (strcmp(current->value, value) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int list_delete(List *list, const char *value) {
    Node *node = list_find(list, value);
    if (node == NULL) return 0;

    if (node->prev != NULL) {
        node->prev->next = node->next;
    } else {
        list->head = node->next;
    }

    if (node->next != NULL) {
        node->next->prev = node->prev;
    } else {
        list->tail = node->prev;
    }

    free(node->value);
    free(node);
    list->size--;
    return 1;
}

void list_print(List *list) {
    printf("[");
    Node *current = list->head;
    while (current != NULL) {
        printf("\"%s\"", current->value);
        if (current->next != NULL) printf(", ");
        current = current->next;
    }
    printf("] (size=%d)\n", list->size);
}
