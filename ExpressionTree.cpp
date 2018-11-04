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
	return c-'0';
}

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
		
		int evaluate(){   // only for inorder
			if(!isOperator(val)) // for leaf
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
	void insert(char s[]){
		stack<Node*> sta;
		int len = strlen(s);
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
		root->inorder();
		cout << '\n';
	}
};

vector<string> load(const char file[]){
	vector<string> data;
	ifstream f(file);
	string lineBuffer;
	while(!f.eof()){
		getline(f, lineBuffer);
		istringstream ls(lineBuffer);  // line stream
		string s;
		char token;
		while(ls){
			ls >> token; 
			s += token; 
		}
		data.push_back(s);
		cout << s << '\n';
	}
	f.close();
	return data;
}

int main(){
	ExpressionTree tr;
	char input[] = "234*+"; 
	tr.insert(input);
	tr.inorderPrint();
	cout << tr.evaluate() << '\n';
	//vector<string> data = load("hw8inp.dat");
	/*ExpressionTree tr2;
	char input2[] = "12+345+**"; 
	tr2.insert(input2);
	tr2.inorderPrint();*/
}
