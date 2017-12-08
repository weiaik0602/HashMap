#include "HashMap.h"



void hashMapInit(HashTable *table,int size){
  table->list = (LinkedList *)calloc(size*SIZE_FACTOR , sizeof(LinkedList));
  table->size=size;
  table->sizeFactor=SIZE_FACTOR;
  int i;
  for(i=0;i<size;i++)
    listInit(&(table->list[i]));
}

void _hashMapAdd(HashTable *table,void *data, int index,Compare compfunc){
  Item *newItem = (Item *)malloc(sizeof(Item));
  createItem(newItem,data, NULL);
  listAdd(&(table->list)[index], newItem);
}

void _hashMapAddNew(HashTable *table,void *data, int index,Compare compfunc){
  Item *newItem = (Item *)malloc(sizeof(Item));
  createItem(newItem,data, NULL);
  Item *search=(listSearch(&(table->list)[index],data,compfunc));
//  if(search!=NULL)
  //  listRemove(&(table->list)[index],data,compfunc);
  //listAdd(&(table->list)[index], newItem);
}

Item *_hashMapSearch(HashTable *table,void *data, int index,Compare compfunc){
  return (listSearch(&(table->list)[index],data,compfunc));
}


void _hashMapRemove(HashTable *table,void *data, int index,Compare compfunc){
 listRemove(&(table->list)[index],data,compfunc);
}



uint32_t hashUsingModulo(uint32_t value,int size){
  return value%size;
}


void hashMapAddInteger(HashTable *table,void *data,Compare compfunc){
  int hashValue=hashUsingModulo((uintptr_t)data,table->size);
  _hashMapAdd(table,(void *)data,hashValue,compfunc);
}

void hashMapSearch(HashTable *table,void *data){

}


void hashMapRemove(HashTable *table,void *data){

}

/////////////////////////////////////////////////////////////////////////////
