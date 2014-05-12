#include <stdio.h>
#include <functional>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>
#include <set>
using namespace std;

struct Node{
	size_t key;
};

map<size_t, struct Node*> consistentHash;

void add(size_t key, struct Node* node){
	consistentHash[key] = node;
	node->key = key;
}

struct Node* remove(size_t key){
	struct Node* erasedNode = consistentHash[key];
	consistentHash.erase(key);

	return erasedNode;
}

struct Node* get(size_t key){
	struct Node* getNode;
	map<size_t, struct Node*>::iterator it = consistentHash.upper_bound(key);
	if (it == consistentHash.end()){
		getNode = consistentHash.begin()->second;
	}
	else{
		getNode = it->second;
	}

	return getNode;
}

int main(){
	
	struct Node node1;
	struct Node node10;
	struct Node node2000;

	add(1, &node1);
	add(10, &node10);
	add(2000, &node2000);

	struct Node* retNode = get(30);
	retNode = get(5);
	retNode = get(3000);

	return 0;
}
