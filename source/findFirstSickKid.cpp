/*
 * findFirstSickKid.cpp
 *
 *  Created on: May 21, 2019
 *      Author: srinivasanmurali
 */


#include <iostream>
#include <map>
#include <list>
#include <string>
#include <iterator>

using namespace std;



string findFirstSickKid(list<string> & st_list, map<string, list<string> > & st_map) {
	map<string, int> res_map;
	list<string>::iterator it_list;
    map<string, list<string> >::iterator it;
    string firstSick;
    //Could optimize this just inserting into map {string, int}, but using old compiler
    pair<string, int> res_pair;
    for (it = st_map.begin(); it != st_map.end(); ++it) {
        for (it_list = it->second.begin(); it_list != it->second.end(); ++it_list) {
        	if (st_map.find(*it_list) != st_map.end()) {
        		res_pair.first = *it_list;
        		res_pair.second = 1;
        		res_map.insert(res_pair);
        	}
        }
    }
    for (it_list = st_list.begin(); it_list != st_list.end(); ++it_list) {
    	if (res_map.find(*it_list) == res_map.end()) {
    		firstSick = *it_list;
    		break;
    	}
    }
    return firstSick;
}

int main() {
	list<string> inp_list;
	list<string> st_list;
	map<string, list<string> > inp_map;
	pair<string, list<string> > inp_pair;
	string s1 = "S1";
	string s2 = "S2";
	string s3 = "S3";
	string s4 = "S4";
	st_list.push_back(s2);
	st_list.push_back(s3);
	inp_pair.first = "S1";
	inp_pair.second = st_list;
	inp_map.insert(inp_pair);
	st_list.clear();
	st_list.push_back(s4);
	inp_pair.first = "S2";
	inp_pair.second = st_list;
	inp_map.insert(inp_pair);

	inp_list.push_back(s1);
	inp_list.push_back(s2);
	inp_list.push_back(s3);
	inp_list.push_back(s4);
    string sick_kid = findFirstSickKid(inp_list, inp_map);
    if (!sick_kid.empty()) {
    	cout<<sick_kid<<endl;
    } else {
    	cout<<"None found"<<endl;
    }
	return 1;
}

