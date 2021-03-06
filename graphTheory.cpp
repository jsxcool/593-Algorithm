// advanced graph list
#include<iostream>
#include<vector>
#include<limits>
#include<queue>
using namespace std;

double inf = std::numeric_limits<double>::infinity();

template<typename T>
class LinkedList{
public:
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
	// when it works ???   delete pointer in advance
	/*~LinkedList() {   
		Node* p = head;
		while(p != nullptr){
			Node* q = p->next;
			delete p;
			p = q;
		}
	}*/
};

class GraphList{
private:
	// Advantage: Only need to search the vertex's subset, if we want the path
	// from this vertex to some others
	class Edge{
	public:
		// 'from' is edges's index  (self)
		int to; // the end vertex
		double w; // weight
		Edge(int to, double w): to(to), w(w) {}
	};
	// i.e. LinkedList: 0-->1-->2-->3.....-->n
	// Edge: -->1, -->2, -->3, -->n
	
	vector<LinkedList<Edge>> edges; // every vertex is one LinkedList of edges(with a certain order of vertex arrangement)
	int V;
	
	//preorder: self first, then bigger children, then smalle children
	void DFS(int v, bool* visited){
		visited[v] = true;
		vector<int> adjacent = isConnected(v);
		int len = adjacent.size();
		for(int i=len-1; i>=0; i--){
			if(!visited[adjacent[i]]){
				cout << adjacent[i] << ' ';
				DFS(adjacent[i], visited);
			}
		}
	}
	
public:
	GraphList(int num): V(num) { // the number of vertexes
		for(int i=0; i<V; i++)
			edges.push_back(LinkedList<Edge>());
		// default: all edges' weights are inf
		for(int i=0; i<V; i++){   
			edges[i].head = new LinkedList<Edge>::Node(Edge(0, inf));
			LinkedList<Edge>::Node* iter = edges[i].head;
			for(int j=1; j<V; j++){
				iter->next = new LinkedList<Edge>::Node(Edge(j, inf));
				iter = iter->next; 
			}
		}
	}
	
	~GraphList() {
	
	}
	
	void set(int i, int j, double w){
		LinkedList<Edge> ls = edges[i];  // the vertex we want to set
		// scan the LinkedList
		for(LinkedList<Edge>::Node* node=ls.head; node != nullptr; node=node->next){
			if(node->val.to == j){
				node->val.w = w;
				return;
			}	
		}
	}
	
	//Edge uses <vector>,  could be faster
	bool isConnected(int i, int j){  // O(n)    
		LinkedList<Edge> ls = edges[i];
		for(LinkedList<Edge>::Node* node=ls.head; node != nullptr; node=node->next){
			if(node->val.to == j)
				if(node->val.w != inf)
					return true;
		}
		return false;
	}
	
	// all connected points to vertex v
	vector<int> isConnected(int v){  // O(n)
		vector<int> ret;
		LinkedList<Edge> ls = edges[v];
		for(LinkedList<Edge>::Node* node=ls.head; node != nullptr; node=node->next){
			if(node->val.w != inf)
				ret.push_back(node->val.to);
		}
		return ret;  // this vector is ascending sequence
	}
	
	void DFSRecurssive(int v){  // the start vertex
		bool visited[V];
		for(int i=0; i<V; i++) 
			visited[i] = false;
		cout << v << ' ';
		DFS(v, visited);
	}
	
	void BFSIterable(int v){
		bool visited[V];
		for(int i=0; i<V; i++) 
			visited[i] = false;
		queue<int> myqueue;
		myqueue.push(v);
		visited[v] = true;
		while(!myqueue.empty()){
			int temp = myqueue.front(); // the 'oldest'(frontest) element in this queue
			cout << temp << ' ';
			myqueue.pop();
			vector<int> adjacent = isConnected(temp);
			for(int i=0; i<adjacent.size(); i++){
				if(!visited[adjacent[i]]){
					myqueue.push(adjacent[i]);
					visited[adjacent[i]] = true;
				}
			}
		}
	}

	friend ostream& operator <<(ostream& s, const GraphList& gl){
		for(int i=0; i<gl.V; i++){
			LinkedList<Edge> ls = gl.edges[i];
			for(LinkedList<Edge>::Node* node=ls.head; node != nullptr; 
			node=node->next){
				if(node->val.w != inf){
					s << i << "->" << node->val.to << ": " << node->val.w << '\n';
				}
			}
		}
		return s;
	}

};


int main(){
	GraphList gl(4);
	gl.set(0,1,1);
	gl.set(1,0,1);
	gl.set(1,2,2);
	gl.set(2,1,2);
	gl.set(2,3,3);
	gl.set(3,2,3);
	gl.set(0,3,4);
	gl.set(3,0,4);
	/*cout << gl;
	cout << gl.isConnected(2,3) <<' '<< gl.isConnected(1,3) << '\n' ;
	vector<int> nei = gl.isConnected(3);
	for(int i=0; i<nei.size(); i++)
		cout << nei[i] << ' '; */
	gl.DFSRecurssive(3);
	cout << '\n';
	gl.BFSIterable(3);
	cout << '\n';
}
