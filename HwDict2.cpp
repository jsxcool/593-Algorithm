/* This perfect Hash does not work well. Because the algorithm in Session08 
 * can NOT GURANTEE there is no collison. If collison happens, the latter
 * word would cover the former word. So for the add() function, I still need to
 * go back to regular hash using "position++" while colliding. In general, it just 
 * decreases the probability of collison, but can not avoid it.
*/
#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<cmath>
using namespace std;

int primeNumber[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199};  // 46 counts

int count=0;

vector<string> load(const char* file){
	vector<string> words;
	ifstream f(file);
	string temp;
	while(!f.eof()){
		f >> temp;
		words.push_back(temp); 
	}
	f.close();
	return words;
}

// PerfectHash is like a interconnect layer
class PerfectHash{
private:
	class Hash{ // regular hash table, used as chain
	public:
		class HashNode{
		public:
			int key;
			string val;
			HashNode(int k=0, string v=""): key(k), val(v) {}
		};
		int size, used;
		HashNode* words;
	public:
		Hash(int size): size(size), used(0){
			words = new HashNode[size];
		}
		void rearrange(){
			for(int i=0; i<44; i++){  // the number of primeNumber[] - 2
				if(used+1 == primeNumber[i]){
					HashNode* oldWords = words;
					int oldSize = size;
					size = primeNumber[i+2];
					words = new HashNode[size];
					for(int j=0; j<oldSize; j++){
						if(!oldWords[j].val.empty()){
							this->add(oldWords[j].val, oldWords[j].key);
						}
					}
					return;
				}
			}
		}
		void add(string s, int sum){
			int pos = sum % size;
			while(words[pos].key != 0){
				pos++;
				if(pos > size - 1)
					pos = 0;
			}
			words[pos] = HashNode(sum, s);
			used++;
		}
	};
	
	int capacity;
	Hash** data;
public:
	PerfectHash(): capacity(1001) {
		data = new Hash*[capacity];
		for(int i=0; i<capacity; i++)
			data[i] = nullptr;
	}
	~PerfectHash() {
		for(int i=0; i<capacity; i++){
			if(data[i] != nullptr)
				delete data[i];
		}
		delete [] data;
		cout << count++ << ' ';
	}
	
	void add(string word){
		int basic = 2;
		int len = word.size();
		int sum = 0;
		for(int i=0; i<len; i++){
			int num = word[i] - 'a'; //a-0, b-1, c-2....
			sum += num*basic;
			basic *= 2; 
		}
		int pos = sum % capacity;
		if(data[pos]==nullptr)
			data[pos] = new Hash(1);
		else
			data[pos]->rearrange();  // check and decide if rearrange
		data[pos]->add(word, sum);
	}
	
	bool search(string word){
		int basic = 2;
		int len = word.size();
		int sum = 0;
		for(int i=0; i<len; i++){
			int num = word[i] - 'a'; //a-0, b-1, c-2....
			sum += num*basic;
			basic *= 2; 
		}
		int pos = sum % capacity; 
		if(data[pos] == nullptr)
			return false;
		else{
			int index = sum % data[pos]->size;
			if(data[pos]->words[index].val == word)
				return true;
			return false;
		}
	}
};

void addToHash(string s, PerfectHash dict[26][26]){
	int index0 = s[0]-'a';   
	int index1 = s[1]-'a';
	if(s[2] == '\0')   // eg "aa" can't solve
		return ;
	string wordLeft = s.substr(2);
	dict[index0][index1].add(wordLeft);
}

void searchInHash(string s, PerfectHash dict[26][26]){
	int index0 = s[0] - 'a';
	int index1 = s[1] - 'a';
	if(s[2] == '\0')   // eg "aa" can't solve
		return ;
	string wordLeft = s.substr(2);
	if(dict[index0][index1].search(wordLeft))
		cout << s << " is found!\n";
	else
		cout << s << " is not found!\n";
}

int main(){
	PerfectHash dict[26][26];
	vector<string> dictionary;
	dictionary = load("dict.txt");
	int len = dictionary.size();
	for(int i=0; i<len; i++){  
		addToHash(dictionary[i], dict);
	}
	
	ifstream f("words.dat");
	string word;
	while(!f.eof()){
		f >> word;
		searchInHash(word, dict);
	}
	f.close();
	cout << count;
}

/* serialize: only need load the HashMap once, when searching different words
Why the destructor runs so many times ????
*/


