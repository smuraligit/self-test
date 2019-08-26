/*
 * testDataStruct.cpp
 *
 *  Created on: Jul 25, 2019
 *      Author: srinivasanmurali
 */

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <iterator>
using namespace std;

int main() {
    vector<int> vect;

    cout<<"Testing vector"<<endl;

    for (int i = 0; i < 10; i++)
        vect.push_back(i);

    cout<<"Printing at 5th index "<<vect[4]<<endl;
    vector<int>::iterator vect_it;
    for (vect_it = vect.begin(); vect_it != vect.end(); ++vect_it) {
        cout<<*vect_it<<endl;
    }


    cout<<"Testing List"<<endl;
    list<int> testList;
    for(int j = 0; j < 10; j++)
    	testList.push_back(j);

    list<int>::iterator list_it;
    for(list_it = testList.begin(); list_it != testList.end(); ++list_it) {
    	cout<<*list_it<<endl;
    }

    cout<<"Testing map"<<endl;
    map<int, int> m;
    pair<int, int> p;
    for(int k = 0; k < 9; k++) {
    	p.first = k;
    	p.second = k*10;
    	m.insert(p);
    }

    cout<<"Printing at 5th key "<<m[4]<<endl;

    map<int, int>::iterator m_it;
    for(m_it = m.begin(); m_it != m.end(); ++m_it) {
    	cout<<m_it->first<<" "<<m_it->second<<endl;
    }

    cout<<"check if key 4 exists "<<endl;
    if (m.find(4) != m.end()) {
    	cout<<"match found"<<endl;
    } else
    	cout<<"match not found"<<endl;


    cout<<"Testing queue "<<endl;
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout<<"Queue's front "<<q.front()<<endl;
    q.pop();
    cout<<"Queue's front after pop "<<q.front()<<endl;

    cout<<"Testing stack "<<endl;
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout<<"Stack's top "<<st.top()<<endl;
    st.pop();
    cout<<"Stack's top after pop "<<st.top()<<endl;


    return 0;
}


