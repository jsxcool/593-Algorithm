/* Hanoi problem: Book - C Programming Desgin Page 189
	Three bases : A, B, C. At first, n plates are put on A from small to big.
	Only smaller plates can be put on bigger plates.
	Convert all plates from A -> C, with the agent B.
	O(2^n - 1) 
*/
#include <iostream>
using namespace std;


// n means how many plates total
// a means the original pos with n plates, c is the destination, b is agency
void hanoi(int n, char a, char b, char c){
    void move(char pos1, char pos2);  // declare
    // goal
    if(n==1){
        move(a, c);
        return;
    }

    // A -> B, with the help of C
    hanoi(n-1, a, c, b);
    // When there is only one plate left on A, put the biggest plate to C
    move(a, c);
    // B->C, with the help of A
    hanoi(n-1, b, a, c);
}

void move(char pos1, char pos2){
    cout << pos1 << " -> " << pos2 << '\n';
}

int main() {
    // move n plates from A -> C, with the help of B
    hanoi(8, 'A', 'B', 'C');
}
