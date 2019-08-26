/*
 * listcountpair.cpp
 *
 *  Created on: Apr 23, 2019
 *      Author: srinivasanmurali
 */



#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct Node
{
int data;
struct Node* next;
};
void append(struct Node** headRef, int newData)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	struct Node *last = *headRef;
	new_node->data = newData;
	new_node->next = NULL;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	return;
}
void printList(struct Node* head){
    while(head){
        cout<<head->data<<' ';
        head = head->next;
    }
}
int countPairs(struct Node* head1, struct Node* head2,	int x);
// Driver program to test above
int main()
{
    int T;
    cin>>T;
    while(T--){
        struct Node* head1 = NULL;
	    struct Node* head2 = NULL;
	    int n1, n2, tmp, x;
	    cin>>n1;
	    while(n1--){
	        cin>>tmp;
	        append(&head1, tmp);
	    }
	    cin>>n2;
	    while(n2--){
	        cin>>tmp;
	        append(&head2, tmp);
	    }
	    cin>>x;
	    cout<<countPairs(head1, head2, x)<<' ';
    }
	return 0;
}



/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
Structure of the node of the linked list is as
struct Node
{
   int data;
   struct Node* next;
};
*/
// your task is to complete this function
int countPairs(struct Node* head1, struct Node* head2,	int x)
{
      //Code here
      if (head1 == NULL || head2 == NULL) {
          return 0;
      }
      int count = 0;
      struct Node *tmp1 = head1;

      int diff;
      while (tmp1 != NULL) {
          diff = 0;
          diff=(x-tmp1->data);
          if (diff <= 0) {
        	  tmp1 = tmp1->next;
        	  continue;
          }

          struct Node *tmp2 = head2;
          while (tmp2 != NULL) {
              if (diff == tmp2->data) {
            	  cout<<"list1 data "<<tmp1->data<<endl;
            	  cout<<"list2 data "<<tmp2->data<<endl;
                  count++;
                  break;
              }
              tmp2 = tmp2->next;
          }
          tmp1 = tmp1->next;
      }
      return count;
}

