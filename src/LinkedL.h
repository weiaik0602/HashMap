#ifndef _LINKEDL_H
#define _LINKEDL_H

#include "Data.h"
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


typedef int (*Compare)(void *data, void *refdata);


void listInit(LinkedList *list);
void listInitV2(LinkedList *list,Item *item);
void listAdd(LinkedList *list,Item *item);
void *listSearch(LinkedList *list,uint32_t data,Compare compareFunction);
void *listSearch2(LinkedList *list,uint32_t key,Compare compareFunc);
void listRemoveHead(LinkedList *list);
void listRemove(LinkedList *list,uint32_t data,Compare compareFunction);
void createItem(Item *item,void * data,Item* next);
/*
void listInit(LinkedList *list);

void createItem(Item *item,Data * data,Item* next);
void listAdd(LinkedList *list,Item *item);
void listInitV2(LinkedList *list,Item *item);
void listRemoveHead(LinkedList *list);
void listRemoveByName(LinkedList *list, char* name);
void listRemove(LinkedList *list, void* data,Compare compareFunction);
Item *listSearch(LinkedList *list,void * data,Compare compareFunction);

*/
#endif // _LINKEDL_H
