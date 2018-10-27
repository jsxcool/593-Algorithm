#include <iostream>
using namespace std;

// O(n^2)    omega(n)
// the first time, put the biggest to the end;
// the second time, put the second biggest to the next end;
// improve..  j : 0->k       k = n-1; k>1; k--;  that is selection sort
void bubbleSort(int x[], int n){
    for(int i=0; i<n-1; i++){
        bool sorted = false;
        for(int j=0; j<n-1; j++){
            if(x[j] > x[j+1]) {
                int temp = x[j];
                x[j] = x[j+1];
                x[j+1] = temp;
                sorted = true;
            }
        }
        if(sorted == false)  // sorting has been done
            break;
    }
}

// find the biggest num, then put it to the end
// O(n^2)    omega(n^2)
void selectionSort(int x[], int n){
    for(int i=n-1; i>=0; i--){
        int max = x[0];
        int index = 0;
        for(int j=0; j<=i; j++){
            if(x[j] > max){
                max = x[j];
                index = j;
            }
        }
        x[index] = x[i];   // or use swap() function
        x[i] = max;
    }
}

//concise version --- selectionSort
void selectionSort2(int x[], int n){
    for(int i=n-1; i>0; i--){
        int position = 0;
        for(int j=1; j<=i; j++){
            if(x[j] > x[position])
                position = j;
        }

        if(i != position)
            swap(x[position], x[i]);
    }
}

// O(n^n)  omega(n)
// every time, sort a subset, then insert the next one to the subset,
// forming a new subset
void insertSort(int x[], int n){
    for(int i=1; i<n; i++){
        int temp = x[i];
        for(int j=i-1,index=i; j>=0; j--){  // index: the inserting position
            if(temp < x[j]) {
                swap(x[index], x[j]);
                index--;
            }
        }
        // if no any sorting, break;
        // but only from tail to head, it can be used
    }
}

/*
 * pick a pivot
  (1) pivot ← (x[left] + x[right]) / 2              worst pick
  (2) pivot ← (x[left] + x[right] + x[(left+right)/2]) / 3
  (3) pivot ← x[random]                             best pick
*  Do not use…
  (1) pivot ← x[left]
  (2) pivot ← x[right]
 */
// average O(n*log(n)),   omega(n^2)         log2
void quickSort(int x[], int left, int right){
    if(right - left < 2)
        return;

    int pivot = (x[left] + x[right])/2;
    int i=left, j=right;

    while(i<j){
        while(x[i] < pivot)   // && i<j   ???  这样可以提前避免i j交叉
            i++;
        while(x[j] >= pivot)   // && i<j   ???
            j--;
        if(i < j)
            swap(x[i], x[j]);
    }

    quickSort(x, left, i-1);  //because >= pivot, must i ???
    quickSort(x, i, right);
}



void heapify(int x[], int n, int i) {     // O(logn)
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (x[largest] < x[left] && left < n)
        largest = left;
    if (x[largest] < x[right] && right < n)
        largest = right;

    if(largest != i){
        swap(x[i], x[largest]);
        heapify(x, n, largest);
    }
}

// the size for maxHeap decreases one every cycle
void heapSort(int x[], int n){   // O(nlogn)
    // making the largest number to the root
    for(int i=n/2-1; i>=0; i--)
        heapify(x, n, i);

    // swap the biggest root to the end
    for(int i=n-1; i>0; i--){
        swap(x[0], x[i]);
        heapify(x, i, 0);
    }
}

int main() {
    int array[] = {15,6,48,84,6,1,34,4, 139};
    //bubbleSort(array, 9) ;
    //selectionSort(array, 9);
    //insertSort(array, 9);
    //quickSort(array, 0, 8);
    heapSort(array, 9);  // used for reading data from hard drive
    for(int i=0; i<9; i++)
        cout << array[i] << ' ';
}