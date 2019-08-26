/*
 * graphCycleUndirect.cpp
 *
 *  Created on: May 17, 2019
 *      Author: srinivasanmurali
 */



#include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
//Position this line where user code will be pasted.

bool isCyclic(vector<int> adj[], int V);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;

        // array of vectors to represent graph
        vector<int> adj[V];

        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;

            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cout << isCyclic(adj, V)<<endl;
    }
}



/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/


bool isCyclicUtil(vector<int> adj[], int v, bool visited[], int parent) {
    visited[v] = true;

    vector<int>::iterator it;
    for (it = adj[v].begin(); it != adj[v].end(); ++it) {
        if (!visited[*it]) {
            if (isCyclicUtil(adj, *it, visited, v)) {
                return true;
            }
        }
        else if (*it != parent) {
        	return true;
        }
    }
    return false;
}

/* This function is used to detect a cycle in undirected graph
*  adj[]: array of vectors to represent graph
*  V: number of vertices
*/
bool isCyclic(vector<int> adj[], int V)
{
   // Your code here
   bool *visited = new bool[V];

   for (int i = 0; i < V; i++) {
       visited[i] = false;
   }

   for (int u = 0; u < V; u++) {
       if (!visited[u]) {
           if (isCyclicUtil(adj, u, visited, -1))
               return 1;
       }
   }
   return 0;
}
