#include "unity.h"
#include "HashMapString.h"



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

void test_hashMapAddString(void)
{
  HashTable table;
  hashMapInit(&table,10);

  hashMapAddString(&table,"Hello",1) ;
  Data *head=(table.list)[1].head->data;
  Data *tail=(table.list)[1].tail->data;
  TEST_ASSERT_EQUAL(head->value,"Hello");
  TEST_ASSERT_EQUAL(tail->value,"Hello");

  hashMapAddString(&table,"World",11);
  head=(table.list)[1].head->data;
  tail=(table.list)[1].tail->data;
  TEST_ASSERT_EQUAL(head->value,"Hello");
  TEST_ASSERT_EQUAL(tail->value,"World");

  hashMapAddString(&table,"My friend",21);
  head=(table.list)[1].head->data;
  tail=(table.list)[1].tail->data;
  TEST_ASSERT_EQUAL(head->value,"Hello");
  TEST_ASSERT_EQUAL(tail->value,"My friend");
}

void test_hashMapSearchString(void){
  HashTable table;
  hashMapInit(&table,10);

  hashMapAddString(&table,"Hello",1) ;
  hashMapAddString(&table,"World",11);
  hashMapAddString(&table,"My friend",21);
  //search with key 1
  Data *x=hashMapSearchString(&table,1);
  TEST_ASSERT_EQUAL(x->value,"Hello");
  //search with key 11
  Data *y=hashMapSearchString(&table,11);
  TEST_ASSERT_EQUAL(y->value,"World");
  //search with key 21
  Data *z=hashMapSearchString(&table,21);
  TEST_ASSERT_EQUAL(z->value,"My friend");
  //search with invalid key
  Data *na=hashMapSearchString(&table,221);
  TEST_ASSERT_NULL(na);
}

void test_hashMapRemoveString(void){
  HashTable table;
  hashMapInit(&table,10);

  hashMapAddString(&table,"Hello",1) ;
  hashMapAddString(&table,"World",11);
  hashMapAddString(&table,"My friend",21);
  //remove with the key 1
  hashMapRemoveString(&table,1);
  Data *head=(table.list)[1].head->data;
  Data *tail=(table.list)[1].tail->data;
  TEST_ASSERT_EQUAL(head->value,"World");
  TEST_ASSERT_EQUAL(tail->value,"My friend");
  //remove with the key 21
  hashMapRemoveString(&table,21);
  head=(table.list)[1].head->data;
  tail=(table.list)[1].tail->data;
  TEST_ASSERT_EQUAL(head->value,"World");
  TEST_ASSERT_EQUAL(tail->value,"World");
}
