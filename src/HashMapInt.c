#include "HashMapInt.h"



void hashMapAddInteger(HashTable *table,int intvalue,int key){
  int index=hashUsingModulo(key,table->size);
  int v1=(int)intvalue;
  Data *data=dataCreate(key,(int*)v1);
  _hashMapAdd(table,data,key,index,(Compare)CompareKey);
}

void hashMapSearchInteger(HashTable *table,int *data,int key){
  int index=hashUsingModulo(key,table->size);
  _hashMapSearch(table,key,index,(Compare)CompareKey);
}


void hashMapRemoveInteger(HashTable *table,int *data,int key){
  int index=hashUsingModulo(key,table->size);
   _hashMapRemove(table,key,index,(Compare)CompareKey);
}
