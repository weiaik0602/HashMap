#ifndef _HASHMAP_H
#define _HASHMAP_H

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "malloc.h"
#include "intCompare.h"
#include "LinkedL.h"
//#include "linkedlist.h"

#define SIZE_FACTOR 3



typedef struct HashTable HashTable;

struct HashTable{
  LinkedList *list;
  int size;
  int sizeFactor;
};


void hashMapInit(HashTable *table,int size);
void _hashMapAdd(HashTable *table,void *data, int index,Compare compfunc);
Item *_hashMapSearch(HashTable *table,void *data, int index,Compare compfunc);
void _hashMapRemove(HashTable *table,void *data, int index,Compare compfunc);
uint32_t hashUsingModulo(uint32_t value,int size);
void hashMapAddInteger(HashTable *table,void *data,Compare compfunc);
void hashMapSearch(HashTable *table,void *data);
void hashMapRemove(HashTable *table,void *data);
void _hashMapAddNew(HashTable *table,void *data, int index,Compare compfunc);
//////////////////////////////////////////////////////////////////////////////

#endif // _HASHMAP_H
