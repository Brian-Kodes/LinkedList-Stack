#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot)
{
  
 if (head == NULL) //
 {
   smaller = NULL;
   larger = NULL;
   return;
 }
 else if ((head -> val) <= pivot)
 {
   //head -> next = smaller;
   smaller = head;
   //smaller = smaller -> next;
   llpivot(head->next, smaller, larger, pivot);
 }
 else if ((head -> val) > pivot)
 {
   //head -> next = larger;
   larger = head;

   llpivot(head->next, smaller, larger, pivot);
 }
  head = NULL;

}

