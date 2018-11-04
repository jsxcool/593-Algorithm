//faster searching time at the expense of large memory
// key: word inserted or searched
#include <iostream>
using namespace std;

class Trie{
private:
    class Node{
    public:
        Node* children[26];  // 26 English Alpabet
        //the position: 0~25 corresponds to a~z
        bool isLeaf;   // this Node is the end of a key
        Node():isLeaf(false){
            for(int i=0; i<26; i++)
                children[i] = nullptr;
        }
    };
    Node* root;
public:
    Trie(){ root = nullptr; }

    void insert(string key){
        if(root == nullptr)
            root = new Node();
        Node* p = root;
        int len = key.size();
        for(int i=0; i<len; i++){
            int index = key[i] - 'a';
            if(p->children[index]== nullptr) // if key[i] is not in the tree
                p->children[index] = new Node();
            p = p->children[index];
        }
        p->isLeaf = true;
    }
    
    bool search(string key){
    	if(root == nullptr)
    		return false;
    	Node* p = root;
    	int len = key.size();
    	for(int i=0; i<len; i++){
    		int index = key[i] - 'a';
    		if(p->children[index] == nullptr)
    			return false;
    		p = p->children[index];
    	}
    	return p->isLeaf ? true : false;
    }
    
};


int main(){
    Trie tr;
    tr.insert("forest");
    cout << tr.search("forest") << '\n';
    cout << tr.search("fores") << '\n';
}
