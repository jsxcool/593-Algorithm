//faster searching time at the expense of large memory
// key: word inserted or searched
#include <iostream>
using namespace std;

class Trie{
private:
	class Node{
	public:
		Node* children[26];  // 26 English Alpabet
		bool isLeaf;   // this Node is the end of a key
		Node(){
			for(int i=0; i<26; i++)
				children[i] = nullptr;
			isLeaf = false;
		}
	}
	Node* root;
public:
	Trie(){}
};


int main(){


}
