#include "HashMapInt.h"



void hashMapAddInteger(HashTable *table,int *data,int key){
  int hashValue=hashUsingModulo(key,table->size);
  _hashMapAdd(table,(void *)data,hashValue,(Compare)integerCompare);
}

void hashMapSearchInteger(HashTable *table,int *data,int key){
  int hashValue=hashUsingModulo(key,table->size);
  _hashMapSearch(table,(void *)data,hashValue,(Compare)integerCompare);
}


void hashMapRemoveInteger(HashTable *table,int *data,int key){
  int hashValue=hashUsingModulo(key,table->size);
   _hashMapRemove(table,(void *)data,hashValue,(Compare)integerCompare);

}
