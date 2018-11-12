//Open Addressing Linear Probing
// <map> -- SearchTree
// <unordered_map> -- Hash
#include<iostream>
using namespace std;

class HashNode{   // pair: key --- val
public:
	int key;
	int val;
	HashNode(int k, int v): key(k), val(v) {}
	friend ostream& operator << (ostream& s, HashNode h){
		s << h.key << "--" << h.val << ' ';
		return s;
	}
};

class HashMap{
private:
	HashNode** arr;
	int capacity;
	int size;
	void checkGrow(){ 
		// give hash table more empty space; this is a prerequisite for O(1)
		if(size >= capacity/2){  
			HashNode** old = arr;
			capacity *= 2;
			arr = new HashNode*[capacity];
			for(int i=0; i<capacity/2; i++){
				arr[i] = old[i];
			}
			delete [] old;
		}
	}
public:
	HashMap(int c): capacity(c), size(0){
		arr = new HashNode*[capacity];
		for(int i=0; i<capacity; i++)
			arr[i] = nullptr;
	}
	
	void add(int key, int val){
		checkGrow();
		int pos = key % capacity;    // get the position
		while(arr[pos] != nullptr){  // deal with collison
			if(arr[pos]->key = key){  //cover its value(key must be unique)
				arr[pos]->val = val;
				return;
			}
			pos++;
			if(pos == capacity)
				pos = 0;
		}
		arr[pos] = new HashNode(key, val);
		size++;
	}
	
	int getValue(int key){ // return val
		int pos = key % capacity;
		int count = 0;
		while(arr[pos]==nullptr || arr[pos]->key != key){
			pos++;
			if(pos == capacity)
				pos = 0;
			count++;
			if(count>capacity){
				cout << "This key is not in hash map, return: ";
				return -1;
			}
		}
		return arr[pos]->val;
	}
	
	void remove(int key){
		int pos = key % capacity;
		int count = 0;
		while(arr[pos]==nullptr || arr[pos]->key != key){
			pos++;
			if(pos == capacity)
				pos = 0;
			count++;
			if(count>capacity){
				cout << "This key is not in hash map, return: ";
				return ;
			}
		}
		arr[pos] = nullptr;
		size--;
	}
	
	friend ostream& operator << (ostream& s, HashMap m){
		for(int i=0; i<m.capacity; i++){
			if(m.arr[i] != nullptr)
				s << *m.arr[i] << ' ';
		}
		return s;
	}
	
};

int main(){
	HashMap hs(4);  // initial capacity should be relative big
	hs.add(1,10);
	hs.add(2,20);
	hs.add(21,210);
	hs.add(88,80);
	cout << hs << '\n';
	hs.add(1,8);
	hs.remove(5);
	cout << hs << '\n';
	cout << hs.getValue(88) << '\n';
}
