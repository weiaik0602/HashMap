#include "unity.h"
#include "HashMap.h"
#include "LinkedL.h"
#include "intCompare.h"
#include <malloc.h>
void setUp(void)
{
}

void tearDown(void)
{
}


void test_hashUsingModulo(void){
  int x=hashUsingModulo(5,10);
  //TEST_ASSERT_EQUAL(x,0);

}
void test_HashMap_hashMapInit_not_NULL(void)
{
  HashTable table;
  hashMapInit(&table, 10);

  TEST_ASSERT_NOT_NULL(table.list);
  TEST_ASSERT_EQUAL(table.size,10);
  //free(&table);
}
void test__hashMapAdd(void){
  HashTable table;
  hashMapInit(&table,10);
  _hashMapAdd(&table,(int *)5,1,(Compare)integerCompare) ;
  TEST_ASSERT_EQUAL(table.list[0].head,NULL);
  TEST_ASSERT_EQUAL((table.list)[1].head->data,5);
  TEST_ASSERT_EQUAL((table.list)[1].tail->data,5);
  TEST_ASSERT_EQUAL((table.list)[1].len,1);
  TEST_ASSERT_EQUAL((table.list)[0].head,NULL);
  _hashMapAdd(&table,(int *)10,1,(Compare)integerCompare);
  // /TEST_ASSERT_EQUAL((table.list)[0].head->data,10);
  TEST_ASSERT_EQUAL((table.list)[1].head->data,5);
  TEST_ASSERT_EQUAL((table.list)[1].head->next->data,10);
  TEST_ASSERT_EQUAL((table.list)[1].tail->data,10);
  TEST_ASSERT_EQUAL((table.list)[0].tail,NULL);
  TEST_ASSERT_EQUAL((table.list)[0].head,NULL);
  _hashMapAdd(&table,(int *)10,0,(Compare)integerCompare);
  TEST_ASSERT_EQUAL((table.list)[0].tail->data,10);
  TEST_ASSERT_EQUAL((table.list)[0].head->data,10);
  //free(&table);
}


void test__hashMapSearch(void){
  HashTable table;
  hashMapInit(&table,10);
  _hashMapAdd(&table,(int *)5,1,(Compare)integerCompare) ;
  _hashMapAdd(&table,(int *)10,1,(Compare)integerCompare);
  _hashMapAdd(&table,(int *)15,1,(Compare)integerCompare);
  Item *x=_hashMapSearch(&table,(int *)5,1,(Compare)integerCompare);
  TEST_ASSERT_EQUAL(x->data,5);

  Item *y=_hashMapSearch(&table,(int *)15,1,(Compare)integerCompare);
  TEST_ASSERT_EQUAL(y->data,15);

  Item *z=_hashMapSearch(&table,(int *)20,1,(Compare)integerCompare);
  TEST_ASSERT_EQUAL(z,NULL);
}
void test__hashMapAddNew(void){
  HashTable table;
  hashMapInit(&table,10);
  _hashMapAddNew(&table,(int *)5,1,(Compare)integerCompare) ;
  _hashMapAddNew(&table,(int *)10,1,(Compare)integerCompare);
  _hashMapAddNew(&table,(int *)15,1,(Compare)integerCompare);
}
void test__hashMapRemove(void){
  HashTable table;
  hashMapInit(&table,10);
  _hashMapAdd(&table,(int *)5,1,(Compare)integerCompare) ;
  _hashMapAdd(&table,(int *)10,1,(Compare)integerCompare);
  _hashMapAdd(&table,(int *)15,1,(Compare)integerCompare);
  TEST_ASSERT_EQUAL((table.list)[1].tail->data,15);
  _hashMapRemove(&table,(int *)15,1,(Compare)integerCompare);
  TEST_ASSERT_EQUAL((table.list)[1].tail->data,10);
  _hashMapRemove(&table,(int *)10,1,(Compare)integerCompare);
  TEST_ASSERT_EQUAL((table.list)[1].tail->data,5);
  _hashMapRemove(&table,(int *)10,1,(Compare)integerCompare);
  TEST_ASSERT_EQUAL((table.list)[1].head->data,5);
  TEST_ASSERT_EQUAL((table.list)[1].tail->data,5);
}
