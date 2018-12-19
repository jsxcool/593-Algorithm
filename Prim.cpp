/*Prim's algorithm is a minimum spanning tree algorithm that takes a graph as input and finds the subset of the edges of that graph which
	
	form a tree that includes every vertex
	has the minimum sum of weights among all the tree that can be formed from the graph

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// make 'V' a preprocessor directive(预处理器指令): the preprocessor repalces 
// those macros by their body before the compiler even sees it
#define V 5

// still a variable
const int inf = 9999999;



// The graph
int G[V][V] = {
  {inf, 9, 75, inf, inf},
  {9, inf, 95, 19, 42},
  {75, 95, inf, 51, 66},
  {inf, 19, 51, inf, 31},
  {inf, 42, 66, 31, inf}
};

bool isConnected(int i, int j){
	if(G[i][j] == inf)
		return false;
	return true;
}

// Assume the graph has been pre-loaded
void Prim(){ 
	bool visited[V];
	for(int i=0; i<V; i++)
		visited[i] = false;
	for(int i=0; i<V-1; i++){  // starting from vertex 0; only v-1 edges
		if(visited[i] == true)
			continue;
		visited[i] = true;
		int endPoint = -1;
		int min = inf;
		for(int j=0; j<V; j++){
			// isConnected is O(1) for matrix, O(n) for list
			if(isConnected(i,j) && !visited[j]){
				if(G[i][j] < min){
					min = G[i][j];
					endPoint = j;
				}
			}
		}
		//visited[endPoint] = true;
		cout << i << "->" << endPoint << ": "<< min << '\n';
	}
}


/*
Same thing to Prim's. But different algorithms:
We start from the edges with the lowest weight and keep adding edges until we we reach our goal.
*/

class Edge{
public:
	int from; // the start vertex
	int to; // the end vertex
	double w; // weight
	Edge(int from, int to, double w): from(from), to(to), w(w) {}
};

bool myfunction(Edge e1, Edge e2){
	return e1.w < e2.w ; 
}
		
void Kruskal(){
	vector<Edge> allEdges;
	for(int i=0; i<V; i++){ 
		for(int j=0; j<V; j++){
			if(G[i][j] != inf){
				allEdges.push_back(Edge(i, j, G[i][j]));
			}
		}
	}
	sort(allEdges.begin(), allEdges.end(), myfunction);
		
	bool visited[V];
	for(int i=0; i<V; i++)
		visited[i] = false;
	int len = allEdges.size();
	for(int i=0; i<len; i++){
		if(visited[allEdges[i].from] && visited[allEdges[i].to])
			continue;
		visited[allEdges[i].from] = true;
		visited[allEdges[i].to] = true;
		cout << allEdges[i].from << "->" << allEdges[i].to << ": "<< allEdges[i].w << '\n';
	}
			
}
	
	

int main() {
	Prim();	
	cout << '\n';
/************************************/	
    Kruskal();

}
