#include "LinkedL.h"
#include <stdio.h>
#include <stdint.h>



void listInit(LinkedList *list) {
  list->head = NULL;
  list->tail = NULL;
  list->len = 0;
}


void listInitV2(LinkedList *list,Item *item){
    // Implement your code here...
    list->head=item;
    list->tail=item;
    list->len +=1;
    item->next=NULL;
}

void listAdd(LinkedList *list,Item *item){
    Item *previous,*current;
    // Implement your code here...
    if(list->len==0){
    list->head=item;
    list->tail=item;
    }
    else{
		list->tail->next=item;
		list->tail=item;
    }
    list->len +=1;
    item->next=NULL;
}

Item *listSearch(LinkedList *list,uint32_t key,Compare compareFunction){
  Item *previous,*current;
  previous=NULL;
  current=list->head;
  if(list->len!=0){
    while(compareFunction((void*)key,(void*)&(((Data *)(current->data)))->key)!=0){
      previous=current;
		  current=current->next;
      if(current==NULL)
        break;
    }
    return current;
  }
    else
      return NULL;
}
void *listSearch2(LinkedList *list,uint32_t key,Compare compareFunc){
	Item *temp;
	for(temp = list->head; temp!=NULL;temp = temp->next){
		if(compareFunc(&key,temp->data)!=0)
			return temp->data;
    }
}
void listRemoveHead(LinkedList *list){
  if(list->head == NULL){        //if the list is empty, return NUll
    list= NULL;
  }
  else{
    if(list->head == list->tail){
      //if we only gt 1 data,we empty the list with listInit
      listInit(list);
    }
    else{
    list->head = list->head->next;
    list->len--;
    }
  }
}
void listRemove(LinkedList *list,uint32_t data,Compare compareFunction)
{
  Item *previous,*current;
  int x;
  //for the 1st node, there is no previous,and current is the list->head
  previous=NULL;
  current=list->head;
  /*finding the node that we want, if not match with the name, the previous /
  pointer become current code and the current pointer point to the next node/
   until we find it*/

   while(compareFunction(current->data,&data)!=0)
   {
		previous=current;
		current=current->next;
		if(current==NULL)
			break;
   }
   if(current==NULL)
   {
	   //no data matched until last node
	   current=NULL;
   }
   else
   {
	   if(previous==NULL)
	   {
		   //the data is the head
		   listRemoveHead(list);
	   }
	   else if(current==list->tail)
	   {
		   //the item is tail
		   list->tail=previous;
		   list->tail->next=NULL;
		   list->len--;
	   }

	   else
	   {
		   //the item is in between 2 node
		   previous->next=current->next;
		   list->len--;
	   }
   }
}

void createItem(Item *item,void * data,Item* next){
  item->data=(Data*)data;
  item->next=next;
}
