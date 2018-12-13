// Find the shortest path from one vertex to all others
#include<iostream>
#include<vector>
#include<limits>
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
	vector<Edge> isConnected(int v){  // O(n)
		vector<Edge> ret;
		LinkedList<Edge> ls = edges[v];
		for(LinkedList<Edge>::Node* node=ls.head; node != nullptr; node=node->next){
			if(node->val.w != inf)
				ret.push_back(node->val);
		}
		return ret;  // this vector is ascending sequence
	}
		
		
	vector<double> BellmanFord(int start, int end){  // O(VE)
		vector<double> cost;
		int len = end - start + 1;
		cost.push_back(0.0); // selt to self is zero
		for(int i=1; i<len; i++)
			cost.push_back(inf);
		for(int i=start; i<=end; i++){
			vector<Edge> adjacent = isConnected(i);
			for(int j=0; j<adjacent.size(); j++){
				if(cost[adjacent[j].to] > cost[i] + adjacent[j].w)
					cost[adjacent[j].to] = cost[i] + adjacent[j].w;
			}
		} 
		return cost;
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
	GraphList gf(4);
	gf.set(0,1,2.5);
	gf.set(1,0,2.5);
	gf.set(1,2,0.5);
	gf.set(2,1,0.5);
	gf.set(2,3,1.5);
	gf.set(3,2,1.5);
	gf.set(3,0,0.5);
	gf.set(0,3,0.5);
	vector<double> ret = gf.BellmanFord(0,3);
	for(int i=0; i<ret.size(); i++)
		cout << ret[i] << ' ';
}
