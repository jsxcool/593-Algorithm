#include <iostream>
#include "Linkedlist.cc"
using namespace std;

class Queue{
private:
	LinkedList2 l;  // have head and tail
public:
	void enqueue(int v){
		l.addStart(v);  // O(1)
	}
	void dequeue(){
		l.removeEnd();
	}
	bool isEmpty() const{
		return l.getSize();
	}

};
