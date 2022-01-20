#include<sstream>
#include <algorithm>                                                                                                    
#include <vector>                                                                                                       
#include <iostream>                                                                                                     
#include <iterator>                                                                                                     
  
using namespace std;
  



class hireThem{ 
   
public:
//initialization
size_t N=0;
int cost,k;//we set Cost hiring(Ci)=0.01NTD,cost hiring(Ch)=5NTD
int Ci=0.001;
int Ch=5;
int m=0;
int n=0;
int *arr;  
clock_t t_start, t_end; 

//randomize in place function
/*
1. Assuming that the interview cost is 𝑐 𝑖,
 the employment cost is 𝑐 ℎ, 𝑐 ℎ is much larger than 𝑐 𝑖,
if the interview size =n people, hire m times,
the total cost is 𝑐. 𝑖 × 𝑛 + 𝑐 ℎ × 𝑚
*/
void shuffleArray()
{
  random_shuffle(arr, arr+n);
}

// create array random number
 void myA_R(int N)
    {  arr= new int [N];
       n=n+N;   
       for( int i=0;i<N;i++)
       {
          arr[i]=rand()%100000;
        }   //get cost
        t_start = clock();
        hire(N);
        t_end = clock();
        cout<<" Random array time: "<<double(t_end - t_start) / CLOCKS_PER_SEC<<" secs. "<<endl;
       //second step random in place change array components positions(after random in place)
      
        shuffleArray();
        t_start = clock();
        hire(N);
        t_end = clock();
        cout<<"Second step Random array time: "<<double(t_end - t_start) / CLOCKS_PER_SEC<<" secs. "<<endl;
      
       delete[] arr;    
    }
// create array decreasing  number
 void myA_D(int N)
  {     arr= new int [N];
        n=n+N;  
       for( int i=0;i<N;i++)
       {
            arr[i]=N-i;
            
       }    //get cost    
       t_start = clock();
       hire(N);
       t_end = clock();
       cout<<"Decremental array time: "<<double(t_end - t_start) / CLOCKS_PER_SEC<<" secs. "<<endl;
     //second step random in place change array components positions
     if(N>100)
      {
      shuffleArray();
      t_start = clock();
       hire(N);
       t_end = clock();
       cout<<"Second step Decremental array time: "<<double(t_end - t_start) / CLOCKS_PER_SEC<<" secs. "<<endl;
      }
       delete[] arr;     
   }
 // create array incremental number
  void myA_I(int N)
 {  arr= new int [N];
     n=n+N;  
    for( int i=0;i<N;i++)
        {
            arr[i]=i;             
        }  
    t_start = clock();
    hire(N);
    t_end = clock();
    cout<<"Incremental array time: "<<double(t_end - t_start) / CLOCKS_PER_SEC<<" secs. "<<endl;
  //second step random in place change array components positions
      if(N>100)
      {
      shuffleArray();
      t_start = clock();
       hire(N);
       t_end = clock();
       cout<<endl<<"Second step Incremental array time: "<<double(t_end - t_start) / CLOCKS_PER_SEC<<" secs. "<<endl;
      }
       delete[] arr;   
 }
 void print()
 {
     cout<<"The total cost is: "<<((Ci*n)+(Ch*m))<<" NTD"<<endl;
 }


// Hire_assistant function.
void hire(int n)
{
int best= 0 ;                      
for(int i=0;i<n;i++)
    {               
     if(arr[i]>best)
        {
          best=arr[i];
          m++; 
       } 
    }
}

};

// Driver Program
int main()
{    int size; 
   hireThem j;
    //cout<<"please enter a size:  "<<endl;           
    //cin<<size;                
      size=10000;
      cout<<endl<<endl<<"The nbr of interviewee: "<<size<<endl<<endl;       
       //calls the random,decremental,incremental function respectively.
       j.myA_R(size);
       cout<<endl<<endl<<endl;
       j.myA_D(size);
       cout<<endl<<endl<<endl;
       j.myA_I(size);
       cout<<endl<<endl<<endl;
       j.print();  
  return 0;
}

