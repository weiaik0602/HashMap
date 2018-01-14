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



void test_HashMap_hashMapInit_not_NULL(void)
{
  HashTable table;
  hashMapInit(&table, 10);

  TEST_ASSERT_NOT_NULL(table.list);
  TEST_ASSERT_EQUAL(table.size,10);
}
void test__hashMapAdd(void){
  HashTable table;
  hashMapInit(&table,10);
  Data *data5 = dataCreate(1,(int*)5);
  Data *data10 = dataCreate(2,(int*)10);
  Data *data15 = dataCreate(3,(int*)15);
  _hashMapAdd(&table,data5,1,1,(Compare)CompareKey) ;
  TEST_ASSERT_EQUAL((table.list)[1].head->data,data5);
  TEST_ASSERT_EQUAL((table.list)[1].tail->data,data5);

  _hashMapAdd(&table,data10,2,1,(Compare)CompareKey);
  TEST_ASSERT_EQUAL((table.list)[1].head->data,data5);
  TEST_ASSERT_EQUAL((table.list)[1].head->next->data,data10);
  TEST_ASSERT_EQUAL((table.list)[1].tail->data,data10);

  _hashMapAdd(&table,data15,3,1,(Compare)CompareKey);
  TEST_ASSERT_EQUAL((table.list)[1].head->data,data5);
  TEST_ASSERT_EQUAL((table.list)[1].head->next->data,data10);
  TEST_ASSERT_EQUAL((table.list)[1].tail->data,data15);


}


void test__hashMapAdd_expect_delete_old_item_replace_it_at_back(void){
  HashTable table;
  hashMapInit(&table,10);
  Data *data5 = dataCreate(1,(int*)5);
  Data *data10 = dataCreate(2,(int*)10);
  Data *data15 = dataCreate(3,(int*)15);
  _hashMapAdd(&table,data5,1,1,(Compare)CompareKey) ;
  _hashMapAdd(&table,data10,2,1,(Compare)CompareKey);
  _hashMapAdd(&table,data15,3,1,(Compare)CompareKey);


  //head is 5 then 10 then 15
  TEST_ASSERT_EQUAL((table.list)[1].head->data,data5);
  TEST_ASSERT_EQUAL((table.list)[1].head->next->data,data10);
  TEST_ASSERT_EQUAL((table.list)[1].tail->data,data15);

  //add 1 more time data 5, expected head is 10 then 15 and 5
    _hashMapAdd(&table,data5,1,1,(Compare)CompareKey);
    TEST_ASSERT_EQUAL((table.list)[1].head->data,data10);
    TEST_ASSERT_EQUAL((table.list)[1].head->next->data,data15);
    TEST_ASSERT_EQUAL((table.list)[1].tail->data,data5);
}


void test__hashMapRemove_from_back_1by1(void){
  HashTable table;
  hashMapInit(&table,10);
  Data *data5 = dataCreate(1,(int*)5);
  Data *data10 = dataCreate(2,(int*)10);
  Data *data15 = dataCreate(3,(int*)15);
  _hashMapAdd(&table,data5,1,1,(Compare)CompareKey) ;
  _hashMapAdd(&table,data10,2,1,(Compare)CompareKey);
  _hashMapAdd(&table,data15,3,1,(Compare)CompareKey);
  //head is 5 then 10 then 15
  TEST_ASSERT_EQUAL((table.list)[1].head->data,data5);
  TEST_ASSERT_EQUAL((table.list)[1].head->next->data,data10);
  TEST_ASSERT_EQUAL((table.list)[1].tail->data,data15);

  //remove15
  _hashMapRemove(&table,3,1,(Compare)CompareKey);
  TEST_ASSERT_EQUAL((table.list)[1].head->data,data5);
  TEST_ASSERT_EQUAL((table.list)[1].head->next->data,data10);
  TEST_ASSERT_EQUAL((table.list)[1].tail->data,data10);



  //remove 10
  _hashMapRemove(&table,2,1,(Compare)CompareKey);
  TEST_ASSERT_EQUAL((table.list)[1].head->data,data5);
  TEST_ASSERT_EQUAL((table.list)[1].tail->data,data5);
  //remove 5
  _hashMapRemove(&table,1,1,(Compare)CompareKey);
  TEST_ASSERT_EQUAL((table.list)[1].head,NULL);
}
void test__hashMapRemove_from_middle(void){
  HashTable table;
  hashMapInit(&table,10);
  Data *data5 = dataCreate(1,(int*)5);
  Data *data10 = dataCreate(2,(int*)10);
  Data *data15 = dataCreate(3,(int*)15);
  _hashMapAdd(&table,data5,1,1,(Compare)CompareKey) ;
  _hashMapAdd(&table,data10,2,1,(Compare)CompareKey);
  _hashMapAdd(&table,data15,3,1,(Compare)CompareKey);


  _hashMapRemove(&table,2,1,(Compare)CompareKey);
  TEST_ASSERT_EQUAL((table.list)[1].head->data,data5);
  TEST_ASSERT_EQUAL((table.list)[1].head->next->data,data15);
  TEST_ASSERT_EQUAL((table.list)[1].tail->data,data15);


}
void test__hashMapSearch(void){
  HashTable table;

  hashMapInit(&table,10);
  Data *data5 = dataCreate(1,(int*)5);
  Data *data10 = dataCreate(2,(int*)10);
  Data *data15 = dataCreate(3,(int*)15);
  _hashMapAdd(&table,data5,1,1,(Compare)CompareKey) ;
  _hashMapAdd(&table,data10,2,1,(Compare)CompareKey);
  _hashMapAdd(&table,data15,3,1,(Compare)CompareKey);
  TEST_ASSERT_NOT_NULL((table.list)[1].head);
  Data *D5,*D10,*D15;
  D5=(table.list)[1].head->data;
  TEST_ASSERT_EQUAL(D5->value,5);
  D10=(table.list)[1].head->next->data;
  TEST_ASSERT_EQUAL(D10->value,10);
  D15=(table.list)[1].tail->data;
  TEST_ASSERT_EQUAL(D15->value,15);


  Data *y=_hashMapSearch(&table,1,1,(Compare)CompareKey);
  TEST_ASSERT_NOT_NULL(y);
  TEST_ASSERT_EQUAL(y,data5);

  Data *z=_hashMapSearch(&table,2,1,(Compare)CompareKey);
  TEST_ASSERT_EQUAL(z,data10);

  Item *a=_hashMapSearch(&table,3,1,(Compare)CompareKey);
  TEST_ASSERT_EQUAL(a,data15);
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

}
