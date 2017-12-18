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

#define hashMapInit(t,s)    _hashMapInit(t,s,SIZE_FACTOR);


void _hashMapInit(HashTable *table,int size,int sizeFactor);
//void _hashMapAdd(HashTable *table,void *data, int index,Compare compfunc);
void _hashMapAdd(HashTable *table,void *data,uint32_t key,int index,Compare compfunc);
void *_hashMapSearch(HashTable *table,uint32_t key,int index,Compare compfunc);
void *_hashMapRemove(HashTable *table,uint32_t key, int index,Compare compfunc);
uint32_t hashUsingModulo(uint32_t value,int size);

/*
void hashMapInit(HashTable *table,int size);
void _hashMapAdd(HashTable *table,void *data, int index,Compare compfunc);
Item *_hashMapSearch(HashTable *table,void *data, int index,Compare compfunc);
void _hashMapRemove(HashTable *table,void *data, int index,Compare compfunc);
uint32_t hashUsingModulo(uint32_t value,int size);
*/
//////////////////////////////////////////////////////////////////////////////

#endif // _HASHMAP_H
