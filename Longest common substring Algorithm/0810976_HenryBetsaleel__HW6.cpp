//  Created by Henry Betsaleel on 2021/6/19.
//  0810976
//  Longest common sequence
//  main.cpp
//  Homework_6
//
/* Dynamic Programming implementation of LCS problem */

#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
using namespace std::chrono;

void print(int X[],int Y[],int Z[],int n,int m,int R);
void DisplayID()
{    cout<<endl<<"My ID: 0810976"<<endl;
}

void lcs( int *X, int *Y, int m, int n )
{
int L[m+1][n+1];

for (int i=0; i<=m; i++)
{
	for (int j=0; j<=n; j++)
	{
	if (i == 0 || j == 0)
		L[i][j] = 0;
	else if (X[i-1] == Y[j-1])
		L[i][j] = L[i-1][j-1] + 1;
	else
		L[i][j] = max(L[i-1][j], L[i][j-1]);
	}
}

int index = L[m][n];
int lcs[index+1];
lcs[index] = 0; 

int i = m, j = n;
while (i > 0 && j > 0)
{
	if (X[i-1] == Y[j-1])
	{
		lcs[index-1] = X[i-1]; 
		i--; j--; index--;	 
	}
	else if (L[i-1][j] > L[i][j-1])
		i--;
	else
		j--;
}
int R=L[m][n];
print(X, Y,lcs, m, n,R);
}
void print(int X[],int Y[],int Z[],int n,int m,int R)
{
    cout<<"X=[ ";
	for(int i = 0; i < n; i++) {
         if(i!=0)
        cout<<", ";
        cout<<X[i];
	}
    cout<<"]"<<endl;
    
    cout<<"Y=[ ";
	for(int i = 0; i < m; i++) {
        if(i!=0)
        cout<<", ";
        cout<<Y[i];
    }
    cout<<"]"<<endl;
    cout<<endl;
    cout<<"Z=[ ";
	for(int i = 0; i < R; i++) {
        if(i!=0)
        cout<<", ";
        cout<<Z[i];
    }
    cout<<"]"<<endl;
    cout<<endl;
 }

/* Driver program */
int main()
{
int n, m;
    DisplayID();

    cout<<"Welcome, plz enter two array sizes: "<<endl;
    cout<<"n: ";
    cin>>n;
    cout<<endl;
    cout<<"m: ";
    cin>>m;
    cout<<endl;
    int X[n];
    int Y[m];
    for(int i = 0; i < m; i++) 
            Y[i]=rand() %10;
    for(int i = 0; i < n; i++) 
        X[i]=rand()%10; 
   auto start_ = high_resolution_clock::now();  
    lcs(X, Y, m, n);
   auto stop_ = high_resolution_clock::now(); 
   auto duration_ = duration_cast<microseconds>(stop_ - start_);
    cout << "Time for lcs and print: "<< duration_.count() << " microseconds" << endl<<endl;

return 0;
}
