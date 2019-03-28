#ifndef LINKEDLIST_H
#define LINKEDLIST_H

using namespace std;
#include <iostream>
#include "ItemType.h"

struct NodeType 
{
   int info;
   NodeType* next;
};

class LinkedList
{
public: 
  LinkedList();
  ~LinkedList();
  void MakeEmpty();
  bool IsEmpty() const;
  int GetLength() const;
  void RetrieveItem(ItemType& item, bool& found);
  void InsertItem(ItemType item);
  void DeleteItem(ItemType item);
  void ResetList();
  void GetNextItem(ItemType& item);
  void PrintList(LinkedList& list); 
private: 
  NodeType* listData; 
  int length;
  NodeType* currentPos;
};

#endif
