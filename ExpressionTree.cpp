// operand: 3, 5, 8...          operator: + - * ...
// operands can only be leaf
#include<iostream>
#include<stack>
#include<cstring>
#include<fstream>
#include<sstream>
#include<vector>
using namespace std;

bool isOperator(char c){
	if(c=='+' || c=='-' || c=='*' || c=='/')
		return true;
	return false;
}

int charToInt(char c){
	// only convert 0~9; others will be regarded as 0
	return (int(c)<58 && int(c)>47)? c-'0' : 0;
}

class BinarySearchTree{  // have been sorted
private:
    class Node{
    public:
        char val;
        Node* left, *right;
        Node(char v, Node* l=nullptr, Node* r=nullptr):
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
    void add(char v){
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
    
    void inorderPrint(){
    	cout << "inorderPrint: ";
        root->inorderPrint();
        cout << '\n';
    }
    void preorderPrint(){
    	cout << "preorderPrint: ";
        root->preorderPrint();
        cout << '\n';
    }
    void postorderPrint(){
    	cout << "postorderPrint: ";
        root->postorderPrint();
        cout << '\n';
    }
};


class ExpressionTree{
private:
	class Node{
	public:
		char val;
		Node* left, *right;
		Node(char c, Node* l=nullptr, Node* r=nullptr)
			: val(c), left(l), right(r) {}
			
		void inorder(){
			if(left != nullptr)
				left->inorder();
			cout << val;
			if(right != nullptr)
				right->inorder();
		}
		
		// for English alphabet, I regard them as their ASCII value 
		int evaluate(){   // only for inorder
			if(!isOperator(val)) // for leaf(lowest level in recurssion)
				return charToInt(val);
			else{	
				int valLeft = left->evaluate();    // recurssion
				int valRight = right->evaluate();  // recurssion
				if(val == '+')
					return valLeft+valRight;
				if(val == '-')
					return valLeft-valRight;
				if(val == '*')
					return valLeft*valRight;
				if(val == '/')
					return valLeft/valRight;	
			}
		}
	};
	Node* root;
public:
	ExpressionTree() { root = nullptr; }
	
	//reference for example: https://en.wikipedia.org/wiki/Binary_expression_tree
	void insert(string s){
		stack<Node*> sta;
		int len = s.size();
		for(int i=0; i<len; i++){
			if(!isOperator(s[i]))   // for operands
				sta.push(new Node(s[i]));
			else{                   // for operators
				if(root==nullptr){  
					root = new Node(s[i]);
					root->right = sta.top();
					sta.pop();
					root->left = sta.top();
					sta.pop();
				}
				else{
					if(sta.size() >= 2){
						Node* temp = new Node(s[i], nullptr, sta.top());
						sta.pop();
						temp->left = sta.top();
						sta.pop();
						sta.push(temp);
					}
					else{  // i.e. only one Node left in the stack
						Node* p = root;
						root = new Node(s[i], p, sta.top());
						sta.pop();
					}
				}
			}
		}
	}
	
	int evaluate(){
		if(root == nullptr)
			return 0;
		return root->evaluate();
	}
	
	
	void inorderPrint(){
		cout << "inorderPrint: ";
		root->inorder();
		cout << '\n';
	}
};

vector<string> load(const char* file){
	vector<string> data;
	ifstream f(file);
	string lineBuffer;
	while(!f.eof()){
		getline(f, lineBuffer);
		string s;
		int len = lineBuffer.size();
		for(int i=0; i<len; i+=2)
			s += lineBuffer[i]; 
		/*istringstream ls(lineBuffer);  // line stream
		char token;
		while(ls){
			ls >> token; 
			s += token; 
		}*/
		data.push_back(s);
	}
	data.pop_back(); // I don't know why there are one more blank line
	f.close();
	return data;
}

int main(){
	vector<string> data = load("hw8inp.dat");
	cout << "For BinarySearchTree: \n";
	for(int i=0; i<data.size(); i++){
		BinarySearchTree tr;
		int len = data[i].size();
		for(int j=0; j<len; j++)
			tr.add(data[i][j]);
		tr.inorderPrint();
		tr.preorderPrint();
		tr.postorderPrint();
		cout << '\n';
	}
	
	
	cout << "\n\nFor ExpressionTree: \n";
	for(int i=0; i<data.size(); i++){
		ExpressionTree tr;
		tr.insert(data[i]);
		tr.inorderPrint();
		cout << "evaluation: " << tr.evaluate() << '\n';
	}
}


