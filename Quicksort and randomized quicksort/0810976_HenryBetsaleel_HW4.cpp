#include <iostream>
using namespace std;
#include <cmath>

// function to swap elements
class Quicksort
{
    public:
    int N;
    //int A[1000];
    int a=0;
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// function to print the array
void printArray(int array[], int size) {
  int i;
  for (i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}

// function to rearrange array (find the partition point)
int partition(int array[], int low, int high) {
    
  // select the rightmost element as pivot
  int pivot = array[high];
  
  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
        
      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;
      
      // swap element at i with element at j
      swap(&array[i], &array[j]);
    }
  }
  
  // swap pivot with the greater element at i
  swap(&array[i + 1], &array[high]);
   // return the partition point
  return (i + 1); 
}
int RANDOMIZED_PARTITION(int A[], int p, int r)
 {
  int i= RANDOM(p,r);                               // exchange A[r] with A[i]         
     swap(&A[r], &A[i]);
    return partition_r(A, p, r);
 }
  void RANDOMIZED_QUICKSORT(int A[], int p, int r)
  {
    if (p<r)
     { 
       int q=RANDOMIZED_PARTITION (A, p, r);
       RANDOMIZED_QUICKSORT(A,p,q-1);
       RANDOMIZED_QUICKSORT(A,q+1,r);
     }
   }
  int RANDOM(int p,int r)
  {
    int k= ((rand() % r) + p);
    return k;
  }  
  int PARTITION(int arr[], int low, int high)
{
    // pivot
    int pivot = arr[high];
   // Index of smaller element
    int i = (low - 1);
 
    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller
        // than or equal to pivot
        if (arr[j] <= pivot) {
             a++;
            // A[i]=pivot;
            // increment index of
            // smaller element
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

int partition_r(int arr[], int low, int high)
{
    // Generate a random number in between
    // low .. high
    srand(time(NULL));
    int random = low + rand() % (high - low);
 
    // Swap A[random] with A[high]
    swap(&arr[random], &arr[high]);
 
    return PARTITION(arr, low, high);
}
 void quickSort(int arr[], int low, int high)
{
    if (low < high) {
 
        /* pi is partitioning index,
        arr[p] is now
        at right place */
        int pi = partition_r(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
 void print(int A[],int N)
 { 
     cout<<endl;
     for(int i=0;i<N;i++)
    {
       cout<<A[i]<<", ";
    }
 }
 
 void Difference(int a[],int b[],int n){
 int c[n];
 for (int i=0; i<n; i++) {
  bool found = false;
  for (int j=0; j<n; j++) {
    if (a[i] == b[j]) {
      found = true;
      break;
    }
  }
  if (!found) {
    std::cout << "a["<<i<<"] is not in b"<<std::endl;
      }
    }
    

/*int k = 0;
int i=0;
//int i = 0;
for(int i=0;i<n;i++)
{
   int f=0;
   for(int j=0;j<n;j++)
   {
      if(a[i]==b[j])
          f=1;
      if(!f)
          c[k++]=a[i];
   }
}
//Shows the difference array
cout << endl;
cout << "\nc[ ";
for (int i = 0; i < k; i++) {
    cout << c[i] << " ";
}
cout << "]";
 }*/
 }
};

//Driver program
int main(){
    int p=0;
    int size;
    clock_t t_start, t_end; 
    cout<<endl;
    cout<<"Please input size:  "<<endl;
    cin>>size;
    Quicksort j;
    int A[size];
    int A1[size];
    int A2[size];
    int A3[size];
    //j.A=A;
    j.N=size;
    //j.A=A1;
/*----------------------------------------------------------------------------------------*/
    //1. Generate an array A with 1000 elements. 
    for(int i=0;i<size;i++)
    { int t=rand()%10; 
          A1[i]=t;
          A2[i]=t;
          A3[i]=t;  
         // cout<<A1[i]<<", ";
    }   
     int n =sizeof(A1) / sizeof(A1[0]);
/*----------------------------------------------------------------------------------------*/
     //2. Perform the following three things 
      /*--------------------------------------^^^^^^-------------------------------------*/
     //(a) Use Randomized Quicksort to arrange array A and calculate the number of executions of the fourth row 
          j.RANDOMIZED_QUICKSORT(A3,0,n-1);
          cout<<endl<<"number of execution of 4th line is : "<<j.a<<" times"<<endl;
      /*--------------------------------------^^^^^^-------------------------------------*/
    //(b) Try to compare the difference between A array through Randomized Quicksort and A random before running Quicksort for 1000 elements.
      j.RANDOMIZED_QUICKSORT(A3,0,n-1);
     // if(size<1000)
    //  j.Difference(A1,j.A,n);
      /*--------------------------------------^^^^^^-------------------------------------*/
    // (c) Choose one of the two methods in the previous task 1 to compare 
    //the complexity with Randomized Quicksort
    // (please indicate the program execution speed or time of the two) 
    

    t_start = clock();
       j.RANDOMIZED_QUICKSORT(A1,0,n-1);
    t_end = clock();
    double k1=double(t_end - t_start);
        cout<<" Sorted array With randomized quicksort time: "<< k1 / CLOCKS_PER_SEC<<" secs. "<<endl;
                                                                                                                                //cout<<endl<<"With randomized quicksort"<<endl;
                                                                                                                                //j.printArray(B, n);
    t_start = clock();
        j.quickSort(A2, 0, n - 1);
    t_end = clock();
     double k2=double(t_end - t_start);
        cout<<" Sorted array in quicksort(Normal) time: "<<k2/ CLOCKS_PER_SEC<<" secs. "<<endl;
        cout<<"the difference is: "<< abs(k2-k1)/ CLOCKS_PER_SEC <<"secs. "<<endl<<endl; 

                                                                                                                                // cout << "Sorted array in quicksort(Normal) \n";
 /*----------------------------------------------------------------------------------------*/                                                                                                                               //j.printArray(A, n);
     return 0;
}


//`````````````````````````````````````END OF PROGRAM THANKYOU```````````````````````````````````````````````````````````//
