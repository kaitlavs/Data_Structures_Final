#ifndef UNSORTEDTYPE_H
#define UNSORTEDTYPE_H

#include "ItemType.h"


struct NodeType {
     char info;
     NodeType * next;
};


class LinkedList		// declares a class data type
{				
public : 			
  LinkedList();
  ~LinkedList();
  void MakeEmpty( );        // 8 public member functions
  bool IsFull( ) const;
  bool IsEmpty( ) const;              
  int  GetLength( ) const;  // returns length of list
  void RetrieveItem(char&  item, bool&  found );
  void InsertItem(char item ); 	
  void DeleteItem(char item ); 	
  void ResetList( );
  void GetNextItem(char& item ); 
  void PrintList(LinkedList& list);	
private:		
  NodeType* listData;
  int length;
  NodeType* currentPos;
};	


#endif
