
// C++ Program to print Bottom View of Binary Tree
#include<bits/stdc++.h>
#include <iostream>
#include <map>
#include <stack>
#include <iterator>
using namespace std;
// Tree node class
struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references
    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
};
Node *newNode(int k)
{
    return new Node(k);
}
// Method that prints the bottom view.
void bottomView(Node *root);

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Tree node class
struct Node
{
    int data;
    Node *left, *right;
}; */
void storeMap(Node *root, int hd, map<int, stack<int> >&m) {
    if (root == NULL) {
        return;
    }
    storeMap(root->left, hd-1, m);
    m[hd].push(root->data);
    storeMap(root->right, hd+1, m);
}
// Method that prints the bottom view.
void bottomView(Node *root)
{
   // Your Code Here
   map<int, stack<int> > m;
   map<int, stack<int> >::iterator itr;
   storeMap(root, 0, m);
   for (itr = m.begin(); itr != m.end(); ++itr) {
	   cout<<itr->second.top()<<" ";
   }
}

/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = newNode(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = newNode(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     bottomView(root);
     cout << endl;
  }
  return 0;
}




