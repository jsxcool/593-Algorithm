#include<iostream>
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
        int quantity = end - start + 1;
        size += quantity;
        if(size >= quantity)
            checkGrow();
        for (int i = size; i > quantity; i--) {
            p[i] = p[i - quantity];
        }
        for(int v=start, j=quantity - 1; v<=end&&j>=0; v += step) {
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


int main() {
    GrowArray a;
    //a.ADD_FRONT(1,2,10);
    a.ADD_BACK(5, 5, 25);
    cout << a << '\n' ;
    a.REMOVE_FRONT(2);
    a.REMOVE_BACK(2);
    cout << a;
}