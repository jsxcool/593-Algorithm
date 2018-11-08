#include<iostream>
using namespace std;

class LinkedList{
private:
	class Node{
	public:
		int val;
		Node* next;
		Node(int v): val(v), next(nullptr) {}
	};
	Node* head;
public:
	LinkedList() { head==nullptr; }
	~LinkedList(){
		Node* p = head;
		while(p != nullptr){
			Node* q = p->next;
			delete p;
			p = q;
		}
	}
	
	Node* getHead() { return head; }
	
	void add(int v){
		if(head==nullptr){
			head = new Node(v);
			return ;
		}
		Node* p = head;
		while(p->next != nullptr){
			p = p->next;
		}
		p->next = new Node(v);
	} 
	
	friend ostream& operator << (ostream& s, const LinkedList& l) {
		Node* p = l.head;
		while(p != nullptr){
			s << p->val << ' ';
			p = p->next;
		}
		return s;
	}
};

class HashLinearChain{
private:
	int capacity, size;
	LinkedList* table;
public:
	HashLinearChain(int c): capacity(c), size(0) {
		table = new LinkedList[capacity];
	}
	~HashLinearChain(){
		delete [] table;
	}
	void add(int v){
		int pos = v % capacity;
		table[pos].add(v);
		size++;
	}
	
	friend ostream& operator << (ostream& s, const HashLinearChain& hs){
		for(int i=0; i<hs.capacity; i++){
			if(hs.table[i].getHead() != nullptr){
				s << hs.table[i] << '\n';
			}
		}
		return s;
	}
};

int main(){
	HashLinearChain hs(10);
	hs.add(1);
	hs.add(11);
	hs.add(5);
	hs.add(15);
	cout << hs << '\n';
}
