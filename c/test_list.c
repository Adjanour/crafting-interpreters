#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "list.h"

static int tests_passed = 0;
static int tests_failed = 0;

#define TEST(name) printf("  %-40s", name)
#define PASS() do { printf("PASS\n"); tests_passed++; } while(0)
#define FAIL(msg) do { printf("FAIL - %s\n", msg); tests_failed++; } while(0)

static void test_init_and_empty(void) {
    TEST("init creates empty list");
    List list;
    list_init(&list);
    assert(list.head == NULL);
    assert(list.tail == NULL);
    assert(list.size == 0);
    list_destroy(&list);
    PASS();
}

static void test_insert_one(void) {
    TEST("insert single element");
    List list;
    list_init(&list);
    assert(list_insert(&list, "hello") == 1);
    assert(list.size == 1);
    assert(list.head == list.tail);
    assert(strcmp(list.head->value, "hello") == 0);
    assert(list.head->prev == NULL);
    assert(list.head->next == NULL);
    list_destroy(&list);
    PASS();
}

static void test_insert_multiple(void) {
    TEST("insert multiple elements (doubly linked)");
    List list;
    list_init(&list);
    list_insert(&list, "one");
    list_insert(&list, "two");
    list_insert(&list, "three");
    assert(list.size == 3);
    assert(strcmp(list.head->value, "one") == 0);
    assert(strcmp(list.tail->value, "three") == 0);
    assert(list.head->prev == NULL);
    assert(list.head->next == list.tail->prev);
    assert(list.tail->next == NULL);
    assert(list.tail->prev->prev == list.head);
    list_destroy(&list);
    PASS();
}

static void test_find(void) {
    TEST("find existing and non-existing elements");
    List list;
    list_init(&list);
    list_insert(&list, "apple");
    list_insert(&list, "banana");
    list_insert(&list, "cherry");
    Node *found = list_find(&list, "banana");
    assert(found != NULL);
    assert(strcmp(found->value, "banana") == 0);
    assert(list_find(&list, "dragonfruit") == NULL);
    list_destroy(&list);
    PASS();
}

static void test_delete_middle(void) {
    TEST("delete middle element");
    List list;
    list_init(&list);
    list_insert(&list, "a");
    list_insert(&list, "b");
    list_insert(&list, "c");
    assert(list_delete(&list, "b") == 1);
    assert(list.size == 2);
    assert(strcmp(list.head->value, "a") == 0);
    assert(strcmp(list.tail->value, "c") == 0);
    assert(list.head->next == list.tail);
    assert(list.tail->prev == list.head);
    list_destroy(&list);
    PASS();
}

static void test_delete_head(void) {
    TEST("delete head element");
    List list;
    list_init(&list);
    list_insert(&list, "x");
    list_insert(&list, "y");
    list_insert(&list, "z");
    assert(list_delete(&list, "x") == 1);
    assert(list.size == 2);
    assert(strcmp(list.head->value, "y") == 0);
    assert(list.head->prev == NULL);
    list_destroy(&list);
    PASS();
}

static void test_delete_tail(void) {
    TEST("delete tail element");
    List list;
    list_init(&list);
    list_insert(&list, "x");
    list_insert(&list, "y");
    list_insert(&list, "z");
    assert(list_delete(&list, "z") == 1);
    assert(list.size == 2);
    assert(strcmp(list.tail->value, "y") == 0);
    assert(list.tail->next == NULL);
    list_destroy(&list);
    PASS();
}

static void test_delete_nonexistent(void) {
    TEST("delete non-existent element returns 0");
    List list;
    list_init(&list);
    list_insert(&list, "only");
    assert(list_delete(&list, "nope") == 0);
    assert(list.size == 1);
    list_destroy(&list);
    PASS();
}

static void test_delete_last(void) {
    TEST("delete last element empties list");
    List list;
    list_init(&list);
    list_insert(&list, "solo");
    assert(list_delete(&list, "solo") == 1);
    assert(list.size == 0);
    assert(list.head == NULL);
    assert(list.tail == NULL);
    list_destroy(&list);
    PASS();
}

int main(void) {
    printf("Doubly Linked List Tests\n");
    printf("========================\n");

    test_init_and_empty();
    test_insert_one();
    test_insert_multiple();
    test_find();
    test_delete_middle();
    test_delete_head();
    test_delete_tail();
    test_delete_nonexistent();
    test_delete_last();

    printf("========================\n");
    printf("Passed: %d, Failed: %d\n", tests_passed, tests_failed);

    printf("\nManual verification:\n");
    List demo;
    list_init(&demo);
    list_insert(&demo, "hello");
    list_insert(&demo, "world");
    list_insert(&demo, "linked");
    list_insert(&demo, "list");
    printf("After inserts: ");
    list_print(&demo);

    list_delete(&demo, "linked");
    printf("After delete 'linked': ");
    list_print(&demo);

    list_delete(&demo, "hello");
    printf("After delete 'hello': ");
    list_print(&demo);

    list_delete(&demo, "list");
    list_delete(&demo, "world");
    printf("After deleting all: ");
    list_print(&demo);

    list_destroy(&demo);
    return tests_failed > 0 ? 1 : 0;
}
