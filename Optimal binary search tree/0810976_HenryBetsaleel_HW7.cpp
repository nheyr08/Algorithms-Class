//  Created by Henry Betsaleel on 2021/6/22.
//  0810976
//  Optimal binary search trees
//  main.cpp
//  Homework_7
//
#include <iostream>
#include <vector>
#include <iostream>
using namespace std;
using namespace std::chrono;

void DisplayID()
    {
    cout<<endl<<"My ID: 0810976"<<endl;
    }
    
void Optimal_BST(float P[], float Q[], int n,float e[10][9], float w[10][9], int root[9][9],float& m,float& k)
{  
	for(int i=1; i<=n+1; i++){
		e[i][i-1]=Q[i-1];
		w[i][i-1]=Q[i-1];
	}
	for(int l=1; l<=n; l++){
		for(int i=1; i<=n-l+1; i++){
			int j=i+l-1;
			w[i][j]=w[i][j-1]+P[j]+Q[j];
			e[i][j]=e[i][i-1]+e[i+1][j]+w[i][j];
			root[i][j]=i;
			for(int r=i; r<=j; r++){
				float t=e[i][r-1]+e[r+1][j]+w[i][j];
				if(t<e[i][j]){
					e[i][j]=t;
                    m=t;
					root[i][j]=r;
				    k=r;
                }
			}
		}
	}

 
}
int main()
{  
      DisplayID();
     int n;
      float m;
       float k;

        cout<<"Welcm, plz enter val: "<<endl;
        cin>>n;
        cout<<endl;
        float p[]={0,0.15,0.10,0.05,0.10,0.20};
        float q[]={0.05,0.10,0.05,0.05,0.05,0.10};
        //float p[]={0,0.05,0.15,0.05,0.15,0.15};
        //float q[]={0.10,0.05,0.05,0.10,0.05,0.10};
    
     float e[10][9];
     float w[10][9];
     int root[9][9];
     Optimal_BST(p,q,n,e,w,root,m,k);
    cout<<"Cost : "<<m<<endl;
     cout<<"root : "<<k<<endl<<endl;
        
    return 0;
}