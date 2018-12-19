/*  find the shortest distance from any nodes to any nodes
 *  O(V^3)
*/

#include <iostream>
using namespace std;

int inf = 9999999;

#define V 5

// The original graph
int G[V][V] = {
  {0, 9, 75, inf, inf},
  {9, 0, 95, 19, 42},
  {75, 95, 0, 51, 66},
  {inf, 19, 51, 0, 31},
  {inf, 42, 66, 31, 0}
};

void FloyedWarshall(int g[][5]){
	for(int k=0; k<V; k++)  // k is like the intermediate node
		for(int i=0; i<V; i++)
			for(int j=0; j<V; j++)
				if(g[i][j] > g[i][k] + g[k][j])
					g[i][j] = g[i][k] + g[k][j];
}

int main() {
	int graph[V][V];
	for(int i=0; i<V; i++)
		for(int j=0; j<V; j++)
			graph[i][j] = G[i][j];
	
	FloyedWarshall(graph);
	
	for(int i=0; i<V; i++){
		for(int j=0; j<V; j++)
			cout << graph[i][j] << ' ';
		cout << '\n';
	}
	
	


}
