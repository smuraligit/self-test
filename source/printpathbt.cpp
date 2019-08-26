#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <map>
#include <vector>
#include <iterator>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
void printPaths(struct Node *root);
struct Node* newNode(int data)
{
  struct Node* node = (struct Node*)malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
void inorder(struct Node* root)
{
    if(root==NULL)return;
    inorder(root->left);
    cout<<root->data<<' ';
    inorder(root->right);
}
/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  cin>>t;
  while (t--)
  {
     map<int, Node*> m;
     int n;
     cin>>n;
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        cin>>n1>>n2>>lr;
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
     printPaths(root);
  }
  return 0;
}



/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Structure of Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};*/
void printQueue(vector<int> & q) {
    vector<int>::iterator it;
    for(it = q.begin(); it != q.end(); ++it) {
        cout<<*it<<" ";
    }
    cout<<"#";
}
void printPathsUtil(Node *root, vector<int> & q) {
    if (root == NULL) {
        return;
    }
    q.push_back(root->data);
    if (root->left == NULL && root->right == NULL) {
        printQueue(q);
    }
    printPathsUtil(root->left, q);
    printPathsUtil(root->right, q);
    if (!q.empty()) {
        q.pop_back();
    }
    return;
}
/* The function should print all the paths from root
 to leaf nodes of the binary tree */
void printPaths(Node* root)
{
    // Code here
    if (root == NULL) {
        return;
    }
    vector<int> q;
    printPathsUtil(root, q);
}
