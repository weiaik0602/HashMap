#include "HashMapInt.h"



void hashMapAddInteger(HashTable *table,int intvalue,int key){
  int index=hashUsingModulo(key,table->size);
  Data *data=dataCreate(key,(int*)((intptr_t)intvalue));
  _hashMapAdd(table,data,key,index,(Compare)CompareKey);
}

void *hashMapSearchInteger(HashTable *table,int key){
  int index=hashUsingModulo(key,table->size);
  return _hashMapSearch(table,key,index,(Compare)CompareKey);
}


void hashMapRemoveInteger(HashTable *table,int key){
  int index=hashUsingModulo(key,table->size);
  _hashMapRemove(table,key,index,(Compare)CompareKey);
}
