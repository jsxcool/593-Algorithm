#include<iostream>
#include<vector>
#include<fstream>
#include<string>
using namespace std;

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

class HashMap{
private:
	int capacity, collision;
	string* data;
public:
	HashMap(): capacity(20001), collision(0) {
		data = new string[capacity]();
	}
	~HashMap() { delete [] data; }
	
	int getCollision() {return collision;}
	
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
		if(!data[pos].empty())
			collision++;
		while(!data[pos].empty()){
			pos++;
			if(pos==capacity)
				pos = 0;
		}
		data[pos] = word;
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
		int count = 0;
		while(count < capacity){
			if(data[pos]==word)
				return true;
			if(data[pos].empty())  // when adding, continuous even if collision
				return false;
			pos++;
			if(pos==capacity)
				pos = 0;
			count++;
		}
		return false;
	}
	
	friend ostream& operator << (ostream& s, HashMap hs){
		for(int i=0; i<hs.capacity; i++){
			if(!hs.data[i].empty())
				s << hs.data[i] << ' ';
		}
		return s;
	}
};

void addToHash(string s, HashMap dict[26][26]){
	int index0 = s[0]-'a';   
	int index1 = s[1]-'a';
	if(s[2] == '\0')   // eg "aa" can't solve
		return ;
	string wordLeft = s.substr(2);
	dict[index0][index1].add(wordLeft);
}

void searchInHash(string s, HashMap dict[26][26]){
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
	HashMap dict[26][26];
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
	
	cout << "\nCollison map for dict[26][26]\n";
	for(int i=0; i<26; i++){
		for(int j=0; j<26; j++)
			cout << dict[i][j].getCollision() << "  ";
		cout << '\n';
	}
}
