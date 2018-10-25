#include <iostream>
#include <cmath>
using namespace std;

template<typename T>
class DoubleLinkedList{
private:
	class Node{
		public:
			T val;
			Node* next;
			Node* prev; 
			Node(const T& v, Node* n=nullptr, Node* p=nullptr)
				: val(v), next(n), prev(p) {}
			/* if the type for val is template T, the constructor should be:
			 * Node(const T& val, Node* n, node* p): ... {}
			 * Avoid copy; is a pointer(8 bytes)
			 */
	};
	Node* head;
	Node* tail;

public:
	DoubleLinkedList() : head(nullptr), tail(nullptr) {}
	~DoubleLinkedList() {
		Node* p = head;
		while(p != nullptr){
			Node* q = p->next;
			delete p;
			p = q;
		}
	}
	
	void addEnd(T v){
		if(head == nullptr){
			head = new Node(v);
			tail = head;
			return ;
		}
		Node* temp = tail;
		temp->next = new Node(v, nullptr, tail);
		tail = temp->next;
	}
	
	T getVal(int pos) const {    // O(n)
		Node* p = head;
		for(int i=0; i<pos; i++){
			if(p == nullptr){
				cout << "exceed the length!" ;
				return -1;
				}
			p = p->next;
		}
		return p->val;
	}
	
	friend ostream& operator << (ostream& s, const DoubleLinkedList& l){
		Node* p = l.head;
		while(p != nullptr){
			s << p->val << ' ';
			p = p->next;
		}
		return s;
	}
	
	//Read-Only, can't change the list
	class ConstIterator{
	private:
		Node* current;
	public:
		ConstIterator(const DoubleLinkedList<T>& list): current(list.head) {}
		void toNext(){
			current = current->next;
		}
		bool finished() const {
			return  current==nullptr;
		}
		T getVal() const{    //O(1), but can only get current; current starts from head
			return current->val;
		}
	};
	
	class Iterator{
	private:
		Node* current;
	public:
		Iterator(DoubleLinkedList<T>& list): current(list.head) {}
		void toNext(){
			current = current->next;
		}
		bool finished() const {
			return  current==nullptr;
		}
		T getVal() const{    //O(1), but can only get current; current starts from head
			return current->val;
		}
		void changeVal(int v){
			current->val = v; 
		}
	};
};

int main(){
	DoubleLinkedList<int> a;
	for(int i=0; i<10; i++)
		a.addEnd(i);
	cout << a << '\n';
	cout << a.getVal(5) << a.getVal(12) << '\n';
	
	//									  equals i(a)
	for(DoubleLinkedList<int>::ConstIterator i = a; i.finished()==0; i.toNext()  ){
		cout << i.getVal() << '\n';
	}
	
	for(DoubleLinkedList<int>::Iterator i = a; i.finished()==0; i.toNext()  ){
		i.changeVal(3);
	}
	cout << a << '\n';
}
