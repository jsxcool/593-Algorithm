#include <iostream>
#include <cmath>
using namespace std;

class LinkedList2{
private:
	class Node{
		public:
			int val;
			Node* next; 
			Node(int v=0, Node* n = nullptr): val(v), next(n) {}
	};
	Node* head;
	Node* tail;

public:
	LinkedList2() : head(nullptr), tail(nullptr) {}
	~LinkedList2() {
		Node* p = head;
		while(p != nullptr){
			Node* q = p->next;
			delete p;
			p = q;
		}
	}
	
	Node* getTail() { return tail; }
	
	void addEnd(int v){
		if(head == nullptr){
			head = new Node(v);
			tail = head;
			return ;
		}
		Node* temp = tail;
		temp->next = new Node(v);
		tail = temp->next;
	}
	
	friend ostream& operator << (ostream& s, const LinkedList2& l){
		Node* p = l.head;
		while(p != nullptr){
			s << p->val << ' ';
			p = p->next;
		}
		return s;
	}
	
	LinkedList2 inputAndDelete(int num){
		LinkedList2 l;
		for(int i=1; i<=num; i++)
			l.addEnd(i);
		int length = num;
		for(int i=0; i<length; i++){
			
		}
	} 
	


};




int main(){
	LinkedList2 a;
	for(int i=0; i<10; i++)
		a.addEnd(i);
	cout << a << '\n';
}
