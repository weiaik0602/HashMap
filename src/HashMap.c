#include "HashMap.h"



void _hashMapInit(HashTable *table,int size,int sizeFactor){
  table->list = (LinkedList *)calloc(size*SIZE_FACTOR , sizeof(LinkedList));
  table->size=size;
  table->sizeFactor=sizeFactor;
  int i;
  for(i=0;i<size;i++)
    listInit(&(table->list[i]));
}

void _hashMapAdd(HashTable *table,void *data,uint32_t key,int index,Compare compfunc){
  Item *newItem = (Item *)malloc(sizeof(Item));
  createItem(newItem,data, NULL);
  Data *search=(listSearch(&(table->list)[index],key,compfunc));
  if(search!=NULL)
    listRemove(&(table->list)[index],key,compfunc);
  listAdd(&(table->list)[index], newItem);
}


void *_hashMapSearch(HashTable *table,uint32_t key,int index,Compare compfunc){
  return (listSearch(&(table->list)[index],key,compfunc));
}



void _hashMapRemove(HashTable *table,uint32_t key, int index,Compare compfunc){
 listRemove(&(table->list)[index],key,compfunc);
}



uint32_t hashUsingModulo(uint32_t value,int size){
  return value%size;
}
//////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////
