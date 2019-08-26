/*
 * listreversegrp.c
 *
 *  Created on: Apr 30, 2019
 *      Author: srinivasanmurali
 */



#include<bits/stdc++.h>
#include<iostream>
using namespace std;
/* Link list node */
struct node *reverse (struct node *head, int k);
struct node
{
    int data;
    struct node* next;
}*head;
/* UTILITY FUNCTIONS */
/* Function to push a node */
  void insert()
{
    int n,value;
    cin>>n;
    struct node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            head=(struct node *) malloc( sizeof(struct node) );
            head->data=value;
            head->next=NULL;
            temp=head;
            continue;
        }
        else
        {
            temp->next= (struct node *) malloc( sizeof(struct node) );
            temp=temp->next;
            temp->data=value;
            temp->next=NULL;
        }
    }
}
/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
printf(" ");
}
/* Drier program to test above function*/
int main(void)
{
    /* Start with the empty list */
    int t,k;
     /* Created Linked list is 1->2->3->4->5->6->7->8->9 */
     cin>>t;
     while(t--)
     {
     insert();
     cin>>k;
     head = reverse(head, k);
     printList(head);
     }
     return(0);
}



/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
  Reverse a linked list
  The input list will have at least one element
  Return the node which points to the head of the new LinkedList
  Node is defined as
  struct node
  {
     int data;
     struct Node *next;
  }
*/
void reverseListGrpWrk(struct node * &p,
                       struct node * n,
                       int k,
                       int *count,
                       int *swap) {

    if (*count == k || n == NULL) {
        return;
    }
    *count += 1;
    reverseListGrpWrk(p, n->next, k, count, swap);
    if (*swap < *count) {
    	//struct node * p_tmp = *p;
        int tmp = p->data;
        p->data = n->data;
        n->data = tmp;
        p = p->next;
        *swap += 1;
        *count -=1 ;
    }
}
struct node *reverse (struct node *head, int k)
{
  // Complete this method
  //Get length of list
  struct node *tmp = head;
  struct node *out = head;
  int len = 0;
  while(tmp) {
      len++;
      tmp = tmp->next;
  }
  int ind;
  for (int i = 0; i < len; i+=k) {
      if (i > 0) {
    	  ind = 0;
          while(head && ind < k) {
              ind++;
              head=head->next;
          }
      }
      struct node *p = head;
      int count = 0;
      int swap = 0;
      reverseListGrpWrk(p, head, k, &count, &swap);
  }
  return out;
}


