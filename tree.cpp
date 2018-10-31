#include <iostream>
using namespace std;

/*(1)Trees (with some ordering e.g., BST) provide moderate access/search    (quicker than Linked List and slower than arrays).
  (2)Trees provide moderate insertion/deletion (quicker than Arrays and slower than Unordered Linked Lists).
*/
class BinarySearchTree{  // have been sorted
public:
	class Node{
	public:
		int val;
		Node* left, *right;
		Node(int v, Node* l=nullptr, Node* r=nullptr):
			val(v), left(l), right(r) {}
		
		// 3 ways of tree traversal
		void inorderPrint(){  //print sequence: left-self-right
			if(!this)      // this==nullptr
				return;
			if(left != nullptr)
				left->inorderPrint();
			cout << val << ' ';
			if(right != nullptr)
				right->inorderPrint();
		}
		void preorderPrint(){  //print sequence: self-left-right
			if(!this)
				return;
			cout << val << ' ';
			if(left != nullptr)
				left->preorderPrint();
			if(right != nullptr)
				right->preorderPrint();
		}
		void postorderPrint(){  //print sequence: left-right-self
		}
		
	};

	Node* root;

public:
	BinarySearchTree(): root(nullptr) {}
	
	// rule: smaller num is on the left, bigger num is on the right
	void add(int v){
		if(root==nullptr){
			root = new Node(v);
			return;
		}
		Node* p = root;
		while(true){
			if(v <= p->val){
				if(p->left == nullptr){
					p->left = new Node(v);
					return;
				}
				else
					p = p->left;
			}
			else{ 
				if(p->right == nullptr){
					p->right = new Node(v);
					return;
				}
				else
					p = p->right;
			}
		}
	}
	
	void inorderPrint(){
		this->root->inorderPrint();
		cout << '\n';
	}
	void preorderPrint(){
		this->root->preorderPrint();
		cout << '\n';
	}

};


int main(){
	BinarySearchTree tr;
	tr.add(57);
	tr.add(5);
	tr.add(88);
	tr.add(10);
	tr.add(129);
	tr.add(25);
	tr.inorderPrint();
	tr.preorderPrint();
}
