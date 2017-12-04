#ifndef _HASHMAP_H
#define _HASHMAP_H
#include "linkedlist.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "malloc.h"

#define SIZE_FACTOR 3

typedef struct HashTable HashTable;

struct HashTable{
  LinkedList **list;
  int size;
};

typedef int (*Compare)(void *data, void *refdata);
void hashMapInit(HashTable *table,int size);
void _hashMapAdd(HashTable *table,void *data, int hashValue);
void _hashMapSearch(HashTable *table,void *data, int index,Compare compfunc);
void _hashMapRemove(HashTable *table,void *data, int index,Compare compfunc);
uint32_t hashUsingModule(uint32_t value);
void hashMapAddInteger(HashTable *table,void *data);
void hashMapSearch(HashTable *table,void *data);
void hashMapRemove(HashTable *table,void *data);
#endif // _HASHMAP_H
