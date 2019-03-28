#include "LinkedList.h"
#include "ItemType.h"

LinkedList::LinkedList()
{
  length = 0;
  listData = NULL;
}

LinkedList::~LinkedList()
{
  MakeEmpty();
}

bool LinkedList::IsEmpty() const
{
  return(listData == NULL)? true: false;
}

int LinkedList::GetLength() const
{
  return length;
}

void LinkedList::InsertItem(ItemType item)
{
  NodeType* location;
  location = new NodeType;
  location->info = item; 
  location->next = listData;
  listData = location; 
  length++;
}

void LinkedList::MakeEmpty()
{
  NodeType *tempPtr;
  while(listData != NULL)
  {
    tempPtr = listData;
    listData = listData->next;
    delete tempPtr;
  }
  length = 0;
  listData = NULL;
}

void LinkedList::RetrieveItem(ItemType& item, bool& found)
{
  bool moreToSearch;
     NodeType* location;
  location = listData;
     found = false;
     moreToSearch = (location != NULL);
     while (moreToSearch && !found)
     {
        if (item.ComparedTo(location->info))
        {
           found = true;
           item = location->info;
        }
        else
        {
           location = location->next;
           moreToSearch = (location != NULL);
        }
     }
}


void LinkedList::PrintList(LinkedList& list)
{
   int length;
   ItemType item;

   list.ResetList();
   length = list.GetLength();
   for(int counter =1; counter<=length;counter++)
   {
      list.GetNextItem(item);
      item.Print();
   }
}


void LinkedList::DeleteItem(ItemType item)
{
   NodeType* location = listData;
   NodeType* tempLocation; 
   
   if(item.ComparedTo(listData->info) == EQUAL)
   {
      tempLocation = location; 
      listData = listData->next;
   }
   else 
   {
      while (item.ComparedTo((location->next)->info) != EQUAL)
          location = location->next;

      tempLocation = location->next;
      location->next = (location->next)->next;
   }
   delete tempLocation;
   length--;
}

void LinkedList::ResetList()
{
   currentPos = NULL;
}

void LinkedList::GetNextItem(ItemType& item)
{
  if (currentPos == NULL)
    currentPos = listData;
  else 
    currentPos = currentPos->next;
   
  item = currentPos->info;
}


