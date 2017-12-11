#include "unity.h"
#include "HashMap.h"
#include "LinkedL.h"
#include "intCompare.h"
#include <malloc.h>
#include "Data.h"

void setUp(void)
{
}

void tearDown(void)
{
}

/*

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


void test__hashMapAdd_expect_delete_old_item_replace_it_at_back(void){
  HashTable table;
  hashMapInit(&table,10);
  _hashMapAdd(&table,(int *)5,1,(Compare)integerCompare) ;
  _hashMapAdd(&table,(int *)10,1,(Compare)integerCompare);
  _hashMapAdd(&table,(int *)15,1,(Compare)integerCompare);
  TEST_ASSERT_EQUAL((table.list)[1].head->data,5);
  TEST_ASSERT_EQUAL((table.list)[1].head->next->data,10);
  TEST_ASSERT_EQUAL((table.list)[1].tail->data,15);
  _hashMapAdd(&table,(int *)10,1,(Compare)integerCompare);
  TEST_ASSERT_EQUAL((table.list)[1].head->data,5);
  TEST_ASSERT_EQUAL((table.list)[1].head->next->data,15);
  TEST_ASSERT_EQUAL((table.list)[1].tail->data,10);
}


void test__hashMapRemove(void){
  HashTable table;
  hashMapInit(&table,10);
  _hashMapAdd(&table,(int *)5,1,1,(Compare)integerCompare) ;
  _hashMapAdd(&table,(int *)10,2,1,(Compare)integerCompare);
  _hashMapAdd(&table,(int *)15,3,1,(Compare)integerCompare);
  //head is 5 then 10 then 15
  TEST_ASSERT_EQUAL((table.list)[1].head->data,5);
  TEST_ASSERT_EQUAL((table.list)[1].head->next->data,10);
  TEST_ASSERT_EQUAL((table.list)[1].tail->data,15);

  //remove15
  _hashMapRemove(&table,3,1,(Compare)integerCompare);
  TEST_ASSERT_EQUAL((table.list)[1].head->data,5);
  TEST_ASSERT_EQUAL((table.list)[1].head->next->data,10);
  TEST_ASSERT_EQUAL((table.list)[1].tail->data,10);




  _hashMapRemove(&table,2,1,(Compare)integerCompare);
  TEST_ASSERT_EQUAL((table.list)[1].tail->data,5);
  _hashMapRemove(&table,1,1,(Compare)integerCompare);
  TEST_ASSERT_EQUAL((table.list)[1].head->data,5);
  TEST_ASSERT_EQUAL((table.list)[1].tail->data,5);
}*/
void test__hashMapSearch(void){
  HashTable table;

  hashMapInit(&table,10);
  Data *data5 = dataCreate(1,(int*)5);
  Data *data10 = dataCreate(2,(int*)10);
  Data *data15 = dataCreate(3,(int*)15);
  _hashMapAdd(&table,data5,1,1,(Compare)integerCompare) ;
  _hashMapAdd(&table,data10,2,1,(Compare)integerCompare);
  _hashMapAdd(&table,data15,3,1,(Compare)integerCompare);
  TEST_ASSERT_NOT_NULL((table.list)[1].head);
  Data *D5,*D10,*D15;
  D5=(table.list)[1].head->data;
  TEST_ASSERT_EQUAL(D5->value,5);
  D10=(table.list)[1].head->next->data;
  TEST_ASSERT_EQUAL(D10->value,10);
  D15=(table.list)[1].tail->data;
  TEST_ASSERT_EQUAL(D15->value,15);
  // /TEST_ASSERT_EQUAL((table.list)[1].tail->data,15);
  //Item *x=_hashMapSearch(&table,5,1,(Compare)CompareKey);
  //TEST_ASSERT_EQUAL(x->data,5);

  Data *y=_hashMapSearch(&table,1,1,(Compare)CompareKey);
  TEST_ASSERT_NOT_NULL(y);
  TEST_ASSERT_EQUAL(y,data5);

  Item *z=(Item*)_hashMapSearch(&table,2,1,(Compare)integerCompare);
  //TEST_ASSERT_EQUAL(z,NULL);

  Item *a=(Item*)_hashMapSearch(&table,3,1,(Compare)integerCompare);
//  TEST_ASSERT_EQUAL(a,NULL);
}
void test__hashMapAdd_given_empty_hash_table_and_value_5_david_has_added(void){
  Data *David;
  HashTable hashTable;
  hashMapInit(&hashTable,10);
  Data *data = dataCreate(5,"David");
  _hashMapAdd(&hashTable,data,3,7,(Compare)CompareKey);
  TEST_ASSERT_NOT_NULL(hashTable.list[7].head);
  David = (Data *)(hashTable.list[7].head->data);
  TEST_ASSERT_EQUAL_STRING("David",David->value);
  //TEST_ASSERT_EQUAL((hashTable.list)[7].head->data->value,"David");
  //TEST_ASSERT_EQUAL((hashTable.list)[7].tail->data->value,"David");
/*

  data = (Data *)(hashTable.list[7].head->data);
  TEST_ASSERT_EQUAL(5,data->key);
  TEST_ASSERT_EQUAL_STRING("David",data->name);
  free(data);*/
}
