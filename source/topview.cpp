#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <queue>
#include <utility>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
void topView(struct Node *root);
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
  struct Node* node = (struct Node*)malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
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
     topView(root);
     cout << endl;
  }
  return 0;
}


/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

//Structure of binary tree
/*struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};*/

// function should print the topView of the binary tree
void topView(struct Node *root)
{
    // Your code here
    if (root == NULL) {
        return;
    }
    map<int, queue<int> > m;
    queue<pair<Node *, int> > q;
    int hd = 0;
    if (m[hd].empty()) {
    	cout<<root->data<<" ";
    }
    m[hd].push(root->data);
    pair<Node *, int> p = make_pair(root, hd);
    q.push(p);
    while (!q.empty()) {
        pair<Node *, int> p_tmp = q.front();
        q.pop();
        Node *tmp = p_tmp.first;
        if (tmp->left) {
        	//cout<<"left push "<<tmp->left->data<<endl;
        	if (m[p_tmp.second - 1].empty()) {
        		cout<<tmp->left->data<<" ";
        	}
            m[p_tmp.second - 1].push(tmp->left->data);
            q.push(make_pair(tmp->left, p_tmp.second - 1));
        }
        if (tmp->right) {
        	//cout<<"right push "<<tmp->right->data<<endl;
        	if (m[p_tmp.second + 1].empty()) {
        		cout<<tmp->right->data<<" ";
        	}
            m[p_tmp.second + 1].push(tmp->right->data);
            q.push(make_pair(tmp->right, p_tmp.second + 1));
        }
    }
    //map<int, queue<int> >::iterator it;
    //for (it = m.begin(); it != m.end(); ++it) {
      //  cout<<it->second.front()<<" ";
    //}
    cout<<endl;
}
