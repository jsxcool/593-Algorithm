#include <iostream>
#include <cmath>
using namespace std;

class LinkedList2{
private:
	class Node{
		public:
			int val;
			Node* next;
			Node* prev; 
			Node(int v=0, Node* n=nullptr, Node* p=nullptr)
				: val(v), next(n), prev(p) {}
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
		temp->next = new Node(v, nullptr, tail);
		tail = temp->next;
	}
	
	void removeNode(int pos){  // non-recoverable
		if(pos == 0){        // delete head
			Node* temp = head->next;
			delete head;
			head = temp;
			head->prev = nullptr;
			return;
		}
		Node* getNode = head;
		for(int i=0; i<pos; i++)   // reach the position
			getNode = getNode->next;
		if(getNode == tail){    // delete tail
			getNode->prev->next = nullptr;
			delete getNode;
			// why can't just getNode = nullptr ??? 
			return;
		}
		getNode->prev->next = getNode->next;
		getNode->next->prev = getNode->prev;
		delete getNode;
	}
	
	friend ostream& operator << (ostream& s, const LinkedList2& l){
		Node* p = l.head;
		while(p != nullptr){
			s << p->val << ' ';
			p = p->next;
		}
		return s;
	}
	
	void reversePrint(){
		Node* p = tail;
		while(p != nullptr){
			cout << p->val << ' ';
			p = p->prev;
		}
		cout << '\n';
	}
};

// after delete one element, the whole sequence changed
LinkedList2 inputAndDelete(int num){
	LinkedList2 l;
	for(int i=1; i<=num; i++)
		l.addEnd(i);
	int length = num;
	int deleted = 0;  // how many nodes deleted before
	for(int i=0; i<num; i++){
		if(i%3 == 0){
			l.removeNode(i-deleted);
			deleted++;
			length--;
		}
	}
	deleted = 0;
	for(int i=0; i<length; i++){
		if(i%3 == 0){
			l.removeNode(i-deleted);
			deleted++;
		}
	}
	return l;
}


int main(){
	LinkedList2 a = inputAndDelete(10);
	cout << a << '\n';
	cout << a.getTail()->val << '\n'; 
	cout << a.getTail()->prev->val << '\n'; 
	//a.reversePrint();
}
