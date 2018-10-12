#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

class GrowArray {
private:
    int capacity; // the size of the block of memory
    int size;     // how many are used
    int* p;       // pointer to the block
    void checkGrow() {
        if(size >= capacity){
            int* old = p;
            capacity *= 2;
            p = new int[capacity];
            for(int i=0; i<size; i++)
                p[i] = old[i];
            delete [] old;
        }
    }

public:
    GrowArray() {
        p = new int();
        capacity = 1;
        size = 0;
    }
    GrowArray(int initialSize): capacity(initialSize), size(0) {
        p = new int[capacity];
    }
    ~GrowArray() { delete [] p; }

    GrowArray(const GrowArray& orig) = delete;
    GrowArray& operator = (const GrowArray& orig) = delete;

    void ADD_BACK(int start, int step, int end) { //O(1)
        for(int v=start; v<=end; v += step){
            checkGrow();
            p[size++] = v;   // ++ after assigning
        }
    }

    void ADD_FRONT(int start, int step, int end) {
        int quantity = (end - start)/step + 1;
        size += quantity;
        while(size >= capacity)
            checkGrow();
        for (int i = size; i > quantity; i--) {
            p[i] = p[i - quantity];
        }
        for(int v=start, j=quantity - 1; v<=end; v += step) {
            p[j] = v;
            j--;
        }
    }

    void insert(int pos, int v) {
        checkGrow();
        for(int i=size; i>=pos; i--)
            p[i+1] = p[i];
        p[pos] = v;
        size++;
    }

    void REMOVE_FRONT(int quantity) {
        for(int i=0; i<size-quantity; i++)
            p[i] = p[i+quantity];
        size -= quantity;
    }

    void REMOVE_BACK(int quantity) {
        size -= quantity;
    }

    int getSize() const {
        return size;
    }

    friend ostream& operator << (ostream& s, const GrowArray& g){
        for(int i=0; i<g.size; i++)
            s << g.p[i] <<' ';
        return s;
    }
    
};


void getPara(string part2, int* a){
	int i=0;
	string s;
	while(part2[i] != ':'){
		s += part2[i];
		i++;
	}
	a[0] = atoi(&s[0]);
	string s1;
	for(i=i+1; part2[i] != ':'; i++){
		s1 += part2[i];
	}
	a[1] = atoi(&s1[0]);
	i++;
	string s2;
	while(i<part2.size()){
		s2 += part2[i];
		i++;
		}
	a[2] = atoi(&s2[0]);
}


int main() {
    GrowArray a;
    while(true){
    	string part1, part2; // for an instruction
    	cout << ">>> ";
    	cin >> part1 >> part2;
    	//cout << part1 << ' ' << part2 << '\n';
    	if(part1 == "ADD_FRONT"){
    		int num[3]; 
    		getPara(part2, num);
    		int b=num[0], c=num[1], d=num[2];
    		a.ADD_FRONT(b, c, d);
    	} else if(part1 == "ADD_BACK"){
    		int num[3]; 
    		getPara(part2, num);
    		int b=num[0], c=num[1], d=num[2];
    		a.ADD_BACK(b, c, d);
    		cout << a << '\n';
    	} else if(part1 == "REMOVE_FRONT"){
    		int num = atoi(&part2[0]);
    		a.REMOVE_FRONT(num);
    	} else if(part1 == "REMOVE_BACK"){
    		int num = atoi(&part2[0]);
    		a.REMOVE_BACK(num);
    	} else{   // OUTPUT must be "OUTPUT a" (part1, part2)
    		cout << a << '\n';
    	}
    }
    /*a.ADD_FRONT(1,2,10);    1:2:10
    a.ADD_BACK(5, 5, 25);
    cout << a << '\n' ;
    a.REMOVE_FRONT(2);
    a.REMOVE_BACK(2);
    cout << a << '\n' ;*/
}
