#include <iostream>
using namespace std;

/*(1)Trees (with some ordering e.g., BST) provide moderate access/search    (quicker than Linked List and slower than arrays).
  (2)Trees provide moderate insertion/deletion (quicker than Arrays and slower than Unordered Linked Lists).
*/
class BinarySearchTree{  // have been sorted
private:
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
            if(!this)
                return;
            if(left != nullptr)
                left->postorderPrint();
            if(right != nullptr)
                right->postorderPrint();
            cout << val << ' ';
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
            if(v <= p->val){     // the identical value is on the left 
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

    //assumption: no same values in the tree
    void remove(int v){
        if(v==root->val){
            root = nullptr;
            return;
        }
        Node* p = root;
        Node* pBefore = nullptr;
        while(true){
        	if(v < p->val){
        		if(p->left == nullptr){
        			cout << "This value is not in the tree !";
        			return;
        		}
                pBefore = p;
        		p = p->left;
        	}
        	else if(v > p->val){
        		if(p->right == nullptr){
        			cout << "This value is not in the tree !";
        			return;
        		}
                pBefore = p;
        		p = p->right;
        	}
        	else{  // find the target node
        		if(pBefore->left == p){
                    if(p->right == nullptr) {
                        pBefore->left = p->left;
                        return ;
                    }
                    Node* l = p->left;
                    pBefore->left = p->right;
                    if(p->right->left == nullptr){
                        p->right->left = l;
                        return;
                    }
                    // find the leftest one to connect with l
                    Node* temp = p->right->left;
                    while(temp->left != nullptr)
                        temp = temp->left;
                    temp->left = l;
                    return;
                }
                else{
                    if(p->right == nullptr) {
                        pBefore->right = p->left;
                        return ;
                    }
                    Node* l = p->left;
                    pBefore->right = p->right;
                    if(p->right->left == nullptr){
                        p->right->left = l;
                        return;
                    }
                    // find the leftest one to connect with l
                    Node* temp = p->right->left;
                    while(temp->left != nullptr)
                        temp = temp->left;
                    temp->left = l;
                    return;
                }

        	}
        }
    }

    void inorderPrint(){
        root->inorderPrint();
        cout << '\n';
    }
    void preorderPrint(){
        root->preorderPrint();
        cout << '\n';
    }
    void postorderPrint(){
        root->postorderPrint();
        cout << '\n';
    }

};


int main(){
    BinarySearchTree tr;
    tr.add(57);
    tr.add(5);
    tr.add(88);
    tr.add(10);
    tr.add(111);
    tr.add(25);
    tr.inorderPrint();
    //tr.preorderPrint();
    //tr.postorderPrint();
    tr.remove(10);
    tr.inorderPrint();
}
