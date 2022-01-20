// Merge sort in C++

#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <chrono> 
using namespace std;
using namespace std::chrono;







void generateNumbers(int i,int arr[]){
   
      srand((unsigned)time(0));
        int result = 1+(rand()%10);
        arr[i]=result;
        result=0;


}

// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r) {
  
  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

// Divide the array into two subarrays, sort them and merge them
int mergeSort(int arr[], int l, int r) {
  if (l < r) {
    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    // Merge the sorted subarrays
    merge(arr, l, m, r);
    }
  
}
void insertionSort(int array[],int size){
for (int step = 1; step < size; step++) {
    int key = array[step];
    int j = step - 1;

    // Compare key with each element on the left of it until an element smaller than
    // it is found.
    // For descending order, change key<array[j] to key>array[j].
    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
}
// Driver program
int main() {
    clock_t t_start, t_end,t_start2, t_end2;
    int size;
    int siz;

      cout<<"Hello, Please enter a size for the array \n"<<endl;
      cin>>size;
      cout<<"Thanks you, we succesfully created size _"<<size<<"_array"<<endl;
      cout<<endl;
    int array[size];
    int arr[size];
 //create array of randm values
   for(int i=0;i<size;i++)
      array[i]=rand()%100;
//print array
if(size<=100){
 for (int i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}

  siz = sizeof(array) / sizeof(array[0]);
  std:: copy(array, array+siz, arr); // which will work on C++ only (you have to use #include <algorithm>
    
  ///////////////////////////////////////
 // merge sort
 cout<<endl;
 cout<<"MERGE SORT ALGORITHM"<<endl;
 
 
 auto start = high_resolution_clock::now();
 mergeSort(arr, 0, siz - 1);
 auto stop = high_resolution_clock::now();  
 auto duration = duration_cast<microseconds>(stop - start); 
	    cout<<"Total use  "<< duration.count() << "  Microsecond"<<endl;
      cout << "Sorted array by merge sort: \n"<<endl;
  
  //print array(for Ta's convenience)
  if(size<=100){
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
  }
   //insertion Sort
  cout<<endl;
   cout<<" INSERTION SORT ALGORITHM"<<endl;
  ////////////////////////////////////////
  
     auto starte = high_resolution_clock::now();
     insertionSort(array,size);
     auto stope = high_resolution_clock::now();
     auto duratione = duration_cast<microseconds>(stope - starte); 
     cout<<"Total use  "<< duratione.count() << " Microsecond"<<endl;
     cout << "Sorted array by Insertion sort: \n"<<endl;
  //print array//For Ta's  convenience
  if(size<=100){
    cout<<"[";
    for (int i = 0; i < size; i++)
    cout << array[i] << " ";
    cout<<"]";
 }
  cout << endl;

  return 0;
}