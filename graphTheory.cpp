// advanced graph list
#include<iostream>
#include<vector>
using namespace std;

template<typename T>
class LinkedList{
private:
	class Node{
	public:
		T val;
		Node* next; 
		Node(const T& v, Node* n=nullptr): val(v), next(n) {}
	};
	Node* head;
	// add tail
public:
	LinkedList() : head(nullptr) {}
	~LinkedList() {
		Node* p = head;
		while(p != nullptr){
			Node* q = p->next;
			delete p;
			p = q;
		}
	}
};

class GraphList{
private:
	class Edge{
	public:
		// from is Edge's index  (self)
		int to; // the end vertex
		double w; // weight
		Edge(int to, double w): to(to), w(w) {}
	};
	
	vector<LinkedList<Edge>> edges; // every vertex is one LinkedList of edges(with a certain order of vertex arrangement)
	int V;
	
public:
	GraphList(int num): V(num) { // the number of vertexes
		for(int i=0; i<V; i++)
			edges.push_back(LinkedList<Edge>());
	}
	
	void set(int from, int to, double w){
		Edge* temp = &edges[from];  // the vertex we want to set
		//for(int i=0; i<temp->size(); i++)
		// scan the LinkedList
	}


};


int main(){
	GraphList gl(4);

}
