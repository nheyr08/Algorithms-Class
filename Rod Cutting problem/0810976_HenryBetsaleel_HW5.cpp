//  Created by Henry Betsaleel on 2021/6/7.
//  0810976
//  Rod Cutting problem
//  main.cpp
//  Homework_5
//
#include <iostream>
#include <vector>
#include <iostream>
using namespace std;
using namespace std::chrono;


void cutRod(int p[], int s,int n);
void DisplayID()
    {
    cout<<endl<<"My ID: 0810976"<<endl;
    }
void Determine(int Prce[],int n,int s, int foix)
    {   foix++;
        int k=0;
        int p=0;
         for(int i=0;i<n;i++)
            {
             for(int j=0;j<n;j++)
               {
                 if((Prce[i]+Prce[j]>=Prce[n+1]))
                    {
                     k=i;
                     p=j;  
                     goto theEnd;
                    } 
                } 
            }
         theEnd:

    if(p+k==s)
    { int size = sizeof(Prce)/sizeof(Prce[0]);
        if(p>k)
        { 
        cout<<" "<<k<<" "; 
        Determine(Prce,n-k,n-k+1,foix);
        }
        else
        {
        cout<<p<<" ";
        Determine(Prce,size,n-p+1,foix);
        }
    }   
   
    else if (p==6||p<4)
    {  
       cout<<" "<<s<<endl<<"No more cuts!"<<endl;
       cout<<foix<<" piece(s)" <<endl;   
    } 
    else if((p<10)&&(p>6))
    {   cout<<" "<<s;
        cout<<endl<<endl<<"No more cuts!"<<endl;   
        cout<<foix<<" piece(s)" <<endl<<endl;   
    } 
    else 
    {
    cout<<s<<endl<<endl;;
    }
}

void cutRod(int p[], int s,int n)
{    
    int Prce[n+1];
    Prce[0]=0;//rod of n price set to 0
    int i, j;
    // fills table using bottom up approach
    for (i = 1; i<=n; i++)
    { 
        int B = INT_MIN;
        for (j = 0; j < i && j<s; j++)
        {
            B = max(B, p[j] + Prce[i-j-1]);
            Prce[i] = B;
        }
    }
    Determine(Prce,n-1,n,0);  
}

// Naive Version of algortithm
int Naive_CUT_ROD(int p[],int n,int s){
    if(n <= 0){
        return 0;
    }
    int q = INT_MIN;
    for(int i=0;i<n&& i<s;i++){
        q = max(q,p[i] + Naive_CUT_ROD(p,n-i-1,s));
    }
    return q;
}


int MEMOIZED_VERSION_AUX(int p[],int n,int r[],int s){
    if(r[n] >= 0)
    { return r[n]; 
    }
    int q;
    if(n == 0){ q = 0;
     }
    else
    {
        q = INT_MIN;
        for(int i=0;i<n && i<s;i++)
        {
         q = max(q,p[i] + MEMOIZED_VERSION_AUX(p,n-i-1,r,s));
        }
    }
    r[n] = q;
    return q;
}

int TOP_DOWN_VERSION(int p[],int n, int s){
    int r[n+1];
    for(int i = 0;i<n+1;i++){
        r[i] = INT_MIN;
    }
    return MEMOIZED_VERSION_AUX(p,n,r,s);
}
//bottom up version
int BOTTOM_UP_CUT(int p[], int s,int n)
    {   
     int Prce[n+1];
     Prce[0]=0;//rod of n price set to 0
     int i, j;
     // fills table using bottom up approach
     for (i = 1; i<=n; i++)
        { 
         int B = INT_MIN;
         for (j = 0; j < i && j<s; j++)
            {
             B = max(B, p[j] + Prce[i-j-1]);
             Prce[i] = B;
            }
        }
return Prce[n];
}

int MODIFIED_CUT_ROD_AUX(int p[],int n,int r[],int s[],int ss){
    int q;
    if(r[n] > 0){ return r[n]; }
    if(n == 0) { q = 0; }
    else{
        q = INT_MIN;
        for (int i = 0; i < n&&i<ss; i++)
        {
            int val = MODIFIED_CUT_ROD_AUX(p,n-i-1,r,s,ss);
            if(q < (p[i] + val)){
                q = p[i] + val;
                s[n] = i;
            }
        }
    }
    r[n] = q;
    return q;
}

int MODIFIED_CUT_ROD(int p[],int n,int ss){
    int r[n+1];int s[n+1];
    for (int i = 0; i < n+1; i++)
    {
        r[i] = INT_MIN;
    }
        int val = MODIFIED_CUT_ROD_AUX(p,n,r,s,ss);
    //   auto duration = duration_cast<microseconds>(stop - start); 
    for(int j = n;j>0&&j<ss; j - s[n])
    {
        cout<<"length of "<<s[j]<<", price is $"<<r[s[j]]<<endl;
    }
}
//extended bottom up version 
int Extended_Bottom_UP(int p[],int n,int r[],int s[],int ss){
    int q;
    r[0] = 0;s[0] = 0;
    for (int j = 1; j < n+1; j++)
    {
        q = INT_MIN;
        for (int i = 0; i < j&&i<ss; i++)
        {
            if(q < (p[i] + r[j-i-1])){
                q = p[i] + r[j-i-1];
                s[j] = i;
            }
        }
        r[j] = q;
    }
    return q;
}
    
int main()
{
    DisplayID();
    int price[] = {1,5,8,9,10,17,17,20,24,30};
    int n;
    int size = sizeof(price)/sizeof(price[0]);
    int Outcome;

    cout<<"Welcome, plz enter length of rod: "<<endl;
    cin>>n;
    cout<<endl;

    //this function determines the number of cut and displays where to cut
    cutRod(price, size,n);
  
    if(n<20){
    //Naive version of the algorithm's running time
    auto start = high_resolution_clock::now(); 
    Outcome = Naive_CUT_ROD(price,n,size);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout<<"Naive_CUT_ROD, Max gain: "<<Outcome<<endl;
    cout << "Time : "<< duration.count() << " microseconds" << endl<<endl;
    }
    // Bottom-Up with Tabulation method
    auto start_ = high_resolution_clock::now(); 
    Outcome= BOTTOM_UP_CUT(price,size,n);
    auto stop_ = high_resolution_clock::now(); 
    auto duration_ = duration_cast<microseconds>(stop_ - start_);
    cout<<"BOTTOM UP with tabulation Max gain: "<<Outcome<<endl;
    cout << "Time: "<< duration_.count() << " microseconds" << endl<<endl;

    //Top-Down with Memoization method
    start_ = high_resolution_clock::now(); 
    Outcome= TOP_DOWN_VERSION(price,n, size);
    stop_ = high_resolution_clock::now(); 
    duration_ = duration_cast<microseconds>(stop_ - start_);
    cout<<"Top down with MEMOIZATION, Max gain:"<<Outcome<<endl;
    cout << "Time: "<< duration_.count() << " microseconds" << endl<<endl;
    
    //extended bottom up
    int r[n+1];
    int s[n+1];
    start_ = high_resolution_clock::now(); 
    int outcoume = Extended_Bottom_UP(price,n,r,s,size);
    stop_ = high_resolution_clock::now(); 
    duration_ = duration_cast<microseconds>(stop_ - start_);
    cout<<"Extended_Bottom_UP, Max gain: "<<outcoume<<endl;
    cout << "Time: "<< duration_.count() << " microseconds" << endl<<endl;

    return 0;
}