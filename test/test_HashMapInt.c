#include "unity.h"
#include "HashMapInt.h"

#include "HashMap.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "malloc.h"
#include "intCompare.h"
#include "LinkedL.h"
#include "Data.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_hashMapAddInteger(void)
{
  HashTable table;
  hashMapInit(&table,10);

  hashMapAddInteger(&table,5,1) ;
  Data *head=(table.list)[1].head->data;
  Data *tail=(table.list)[1].tail->data;
  TEST_ASSERT_EQUAL(head->value,5);
  TEST_ASSERT_EQUAL(tail->value,5);

  hashMapAddInteger(&table,10,11);
  head=(table.list)[1].head->data;
  tail=(table.list)[1].tail->data;
  TEST_ASSERT_EQUAL(head->value,5);
  TEST_ASSERT_EQUAL(tail->value,10);

  hashMapAddInteger(&table,15,21);
  head=(table.list)[1].head->data;
  tail=(table.list)[1].tail->data;
  TEST_ASSERT_EQUAL(head->value,5);
  TEST_ASSERT_EQUAL(tail->value,15);
}


void test_hashMapSearchInteger(void){
  HashTable table;
  hashMapInit(&table,10);

  hashMapAddInteger(&table,5,1) ;
  hashMapAddInteger(&table,10,11);
  hashMapAddInteger(&table,15,21);
  //search with key 1
  Data *x=hashMapSearchInteger(&table,1);
  TEST_ASSERT_EQUAL(x->value,5);
  //search with key 11
  Data *y=hashMapSearchInteger(&table,11);
  TEST_ASSERT_EQUAL(y->value,10);
  //search with key 21
  Data *z=hashMapSearchInteger(&table,21);
  TEST_ASSERT_EQUAL(z->value,15);
  //search with invalid key
  Data *na=hashMapSearchInteger(&table,221);
  TEST_ASSERT_NULL(na);
}


void test_hashMapRemoveInteger(void){
  HashTable table;
  hashMapInit(&table,10);

  hashMapAddInteger(&table,5,1) ;
  hashMapAddInteger(&table,10,11);
  hashMapAddInteger(&table,15,21);
  //remove with the key 1
  hashMapRemoveInteger(&table,1);
  Data *head=(table.list)[1].head->data;
  Data *tail=(table.list)[1].tail->data;
  TEST_ASSERT_EQUAL(head->value,10);
  TEST_ASSERT_EQUAL(tail->value,15);
  //remove with the key 21
  hashMapRemoveInteger(&table,21);
  head=(table.list)[1].head->data;
  tail=(table.list)[1].tail->data;
  TEST_ASSERT_EQUAL(head->value,10);
  TEST_ASSERT_EQUAL(tail->value,10);
}
