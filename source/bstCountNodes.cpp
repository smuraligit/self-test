#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};
Node *createNewNode(int value)
{
    Node *temp=new Node;
    temp->data=value;
    temp->left=temp->right=NULL;
    return temp;
}
Node *newNode(Node *root,int data)
{
    if(root==NULL)
    root=createNewNode(data);
    else if(data<root->data)
    root->left=newNode(root->left,data);
    else
    root->right=newNode(root->right,data);
    
    return root;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
The structure of a BST node is as follows:
struct Node
{
    int data;
    Node *left;
    Node *right;
};
*/
void getCountBSTNodes(Node *root, int l, int h, int *count) {
    if (root == NULL) {
        return;
    }
    if (root->left != NULL) {
        getCountBSTNodes(root->left, l, h, count);
    }
    if (root->data <= l || root->data >= h) {
        *count+=1;
    }
    if (root->right != NULL) {
        getCountBSTNodes(root->right, l, h, count);
    }
    return;
}
int getCountOfNode(Node *root, int l, int h)
{
  // your code goes here   
  int count = 0;
  if (root == NULL) {
      return count;
  }
  getCountBSTNodes(root, l, h, &count);
  return count;
}

//Position this line where user code will be pasted.
int main() {
    
    int testcases;
    cin>>testcases;
    while(testcases--)
    {
        Node *root=NULL;
        int sizeOfArray;
        cin>>sizeOfArray;
        int arr[sizeOfArray];
        
        for(int i=0;i<sizeOfArray;i++)
        cin>>arr[i];
        
        for(int i=0;i<sizeOfArray;i++)
        {
            root=newNode(root,arr[i]);
        }
        int l,h;
        cin>>l>>h;
        cout<<getCountOfNode(root,l,h)<<endl;
    
        
    }
	return 0;
}


