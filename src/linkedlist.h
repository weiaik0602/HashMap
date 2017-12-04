#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

typedef struct Item Item;
typedef struct LinkedList LinkedList;

struct Item {
  Item *next;
  void *data;
};

struct LinkedList{
  Item *head;
  Item *tail;
  int len;
};

void listInit(LinkedList *list);
void listAdd(LinkedList *list,Item *item);
void listInitV2(LinkedList *list,Item *item);
void listRemoveHead(LinkedList *list);
void listRemoveByName(LinkedList *list, char* name);
#endif // _LINKEDLIST_H
