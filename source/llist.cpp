#include <iostream>
#include "Smartptr.h"
#include <assert.h>
#include <string>
using namespace std;

template <class T>
struct node {
	T val;
	node *next;
};

template <class T>
class LList {
private:
    node<T> *head;
public:
    LList() {
        head = NULL;
    }
    node<T> * getHead() {
    	return head;
    }
    void setHead(node<T> *newNode) {
        head = newNode;
    }
    node<T> * allocNewNode(int val) {
    	node<T> *newNode = NULL;
    	try{
    		newNode = new node<T>;
    		//throw 'a';
    		//Smartptr<node> newNode(new node);
    		newNode->val = val;
    		newNode->next = NULL;
    	} catch (...) {
    		cout<<"Error in alloc'ing node"<<endl;
    		return NULL;
    	}
        return newNode;
    }

    int insertNode(T val) {
    	try {
    		node<T> *newNode = allocNewNode(val);
    		if (!newNode) {
    			throw 'a';
    		}
    		if (NULL == head) {
    			//llist is empty
    			head = newNode;
    		} else {
    			//node *node_tmp = head;
    			newNode->next = head;
    			head = newNode;
    		}
    		return 0;
    	} catch (...) {
    		cout<<"Error alloc'ing new node"<<endl;
    		return 1;
    	}
    }

    int deleteNode(T val) {
    	try{
    		node<T> *node_tmp = head;
    		if (head->val == val) {
    			head = head->next;
    			delete(node_tmp);
    		} else {
    			node <T> *prev = NULL;
    			while (node_tmp != NULL) {
    				if (node_tmp->val == val) {
    					prev->next = node_tmp->next;
    					delete (node_tmp);
    					break;
    				}
    				prev = node_tmp;
    				node_tmp = node_tmp->next;
    			}
    		}
    		return 0;
    	} catch(...) {
    		cout<<"Error deleting node "<<val<<endl;
    		return 1;
    	}
    }

    void displayList() {
    	node<T> * node_iter = head;
    	while (NULL != node_iter) {
            cout<<node_iter->val;
            if (node_iter->next != NULL) {
            	cout<<"->";
            }
            node_iter = node_iter->next;
    	}
    }

    void freeList() {
    	node<T> *node_iter = head;
    	node<T> *node_tmp = NULL;
    	while (NULL != node_iter) {
            node_tmp = node_iter->next;
            delete node_iter;
    		node_iter = node_tmp;
    	}
    }

    ~LList() {
    	cout<<endl<<"Destructor of Llist being called"<<endl;
    	cout<<"Freeing list"<<endl;
    	freeList();
    	head = NULL;
    }

};

int main(int argc, char **argv) {
    cout<<"Krsna-The Supreme Personality of Godhead"<<endl;
    cout<<"From llist.cpp"<<endl;
    LList<char> llistObj;
    cout<<"Adding 'a' to linked list"<<endl;
    assert(0 == llistObj.insertNode('a'));
    cout<<"Adding 'b' to linked list"<<endl;
    assert(0 == llistObj.insertNode('b'));
    cout<<"Adding 'c' to linked list"<<endl;
    assert(0 == llistObj.insertNode('c'));
    cout<<"Adding 'd' to linked list"<<endl;
    assert(0 == llistObj.insertNode('d'));
    cout<<"Displaying list"<<endl;
    llistObj.displayList();
    cout<<endl;
    cout<<"Deleting 'a' from list"<<endl;
    llistObj.deleteNode('a');
    cout<<"Displaying list"<<endl;
    llistObj.displayList();
    cout<<endl<<"Deleting 'c' from list"<<endl;
    llistObj.deleteNode('c');
    cout<<"Displaying list"<<endl;
    llistObj.displayList();
    cout<<endl<<"Deleting 'd' from list"<<endl;
    llistObj.deleteNode('d');
    cout<<"Displaying list"<<endl;
    llistObj.displayList();
    return 0;
};
