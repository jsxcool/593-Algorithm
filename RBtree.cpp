#include <iostream>
using namespace std;

// ordered balanced binary tree
class RBTree{
private:
	class Node{
	public:
		bool color;  // 1 red; 0 black
		int data;
		Node* left, *right, *parent;
		Node(int v, Node* l, Node* r, Node* p, bool c=0):
			data(v), left(l), right(r), parent(p), color(c) {}
		Node* grandparent(){
			if(parent == nullptr)   // only for root
				return nullptr;
			return parent->parent;
		}
		Node* uncle(){
			if(parent == nullptr)   // only for root
				return nullptr;
			Node* g = this->grandparent(); 
			/*if(parent==g->left)
				return g->right;
			else
				return g->left;*/
			return parent==g->left ?  g->right : g->left ; 
		}
		
		void inorderPrint() {      // recurssive function
			if(left != nullptr)
				left->inorderPrint();
			cout << data << ' ';
			if(right != nullptr)
				right->inorderPrint();
		}
		void preorderPrint(){  
			cout << data << ' ';
			if(left != nullptr)
				left->preorderPrint();
			if(right != nullptr)
				right->preorderPrint();
		}
		void postorderPrint(){  
			if(left != nullptr)
				left->postorderPrint();
			if(right != nullptr)
				right->postorderPrint();
			cout << data << ' ';
		}	
	};
	Node* root;
public:
	RBTree(): root(nullptr){}
	void insertRepair(Node* n) {  // to keep the tree balanced
		if(n->parent == nullptr){  // root = black
			n->color = 0;
			return;
		}
		if(n->parent->color==0)
			n->color = red;
		else
			
		 
	}
	
	void add(int v){
		if(root == nullptr){
			root = new Node(v, nullptr, nullptr, nullptr);
			return;
		}
		
		Node* p = root;
		while(true){
			if(v < p->data){
				if(p->left == nullptr){
					p->left = new Node(v, nullptr, nullptr, p);	
					return;
				}
				p = p->left;
			}
			else{
				if(p->right == nullptr){
					p->right = new Node(v, nullptr, nullptr, p);	
					return;
				}
				p = p->right;
			}
		}
	}
	
	void inorderPrint() {
		if(root != nullptr )
			root->inorderPrint();
		cout << '\n';
	}
	void preorderPrint() {
		if(root != nullptr )
			root->preorderPrint();
		cout << '\n';
	}
	void postorderPrint() {
		if(root != nullptr )
			root->postorderPrint();
		cout << '\n';
	}
	
};


int main(){
	RBTree tr;
	tr.add(57);
	tr.add(5);
	tr.add(88);
	tr.add(10);
	tr.add(111);
	tr.add(25);
	tr.inorderPrint();
	tr.preorderPrint();
	tr.postorderPrint();

}
