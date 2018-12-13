// good for big complexed graph
#include<iostream>
using namespace std;

double INFINITY = 99999999;

// assume all connections are double-directed
class LowerMatrixGraph{
private:
	int V;   // number of vertice
	double** val;
public:
	LowerMatrixGraph(int v): V(v){
		val = new double*[V];
		for(int i=0; i<V; i++)   // space complexity O((n+1)*n/2)
			val[i] = new double[i+1];
		for(int i=0; i<V; i++)
			for(int j=0; j<=i; j++)
				val[i][j] = INFINITY;  // default: all are infinity
	}
	
	void setValue(int i, int j, double value){
		if(i==j)
			return;
		if(i<j){
			int temp = i;
			i = j;
			j =temp;
		}
		val[i][j] = value;
	}
	
	// self and self are NOT conneted
	bool isConnected(int i, int j){
		if(i<j){
			int temp = i;
			i = j;
			j =temp;
		}
		return val[i][j]==INFINITY ? false: true;
	}
	
	bool* isConnected(int v){
		bool* ret = new bool[v]; 
		// must do this. Otherwise, return address of local variable 
		for(int i=0; i<V; i++){
			if(i > v)
				ret[i] = val[i][v]==INFINITY ? false: true;
			else
				ret[i] = val[v][i]==INFINITY ? false: true;
		}
		return ret;
	}
	
	// print all egdes
	friend ostream& operator << (ostream& s, const LowerMatrixGraph& gf){
		for(int i=0; i<gf.V; i++)
			for(int j=0; j<=i; j++){
				if(gf.val[i][j] != INFINITY){
					i>j?  s << j << "-->" << i << ": " << gf.val[i][j] << '\n' :
					s << i << "-->" << j << ": " << gf.val[i][j] << '\n';
				}
			} 
		return s;	
	}
	
};


int main(){
	LowerMatrixGraph gf(4);
	gf.setValue(0,1,3);
	gf.setValue(1,2,2.5);
	gf.setValue(2,3,1.1);
	gf.setValue(3,0,1);
	cout << gf.isConnected(1, 1) << gf.isConnected(1, 3) << '\n';
	bool* ret = gf.isConnected(1); 
	for(int i=0; i<4; i++)
		cout << ret[i] << ' ';
	cout <<'\n' << gf; 
}

