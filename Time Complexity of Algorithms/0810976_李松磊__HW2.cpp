

#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <chrono> 
#include <algorithm>
using namespace std;
using namespace std::chrono;
void Mergesort(vector<int> & bar);
void mergeSort(vector<int>&left,vector<int>& right,vector<int>& bars);

 using namespace std;
    //selection algortithm with a vector
    void SelectionSort(vector<int> &v) 
    {
        for (size_t i = 0; i < v.size() - 1; i++)
        {
            size_t min = i;
            for (size_t j = i + 1; j < v.size(); j++)
                if (v[j] < v[min])
                    min = j;
            int t = v[i];
            v[i] = v[min];
            v[min] = t;
        }
    }



    //Merge sort algorithm with vecot
    void Mergesort(vector<int> & v)
    {
        if (v.size() <= 1) return;

        int mid = v.size() / 2;
        vector<int> left;
        vector<int> right;

        for (size_t j = 0; j < mid;j++)
            left.push_back(v[j]);
        for (size_t j = 0; j < (v.size()) - mid; j++)
            right.push_back(v[mid + j]);

        Mergesort(left);
        Mergesort(right);
        mergeSort(left, right, v);
    }
    void mergeSort(vector<int>&left, vector<int>& right, vector<int>& bars)
    {
        int nL = left.size();
        int nR = right.size();
        int i = 0, j = 0, k = 0;

        while (j < nL && k < nR) 
        {
            if (left[j] < right[k]) 
            {
                bars[i] = left[j];
                j++;
            }
            else 
            {
                bars[i] = right[k];
                k++;
            }
            i++;
        }
        while (j < nL) 
        {
            bars[i] = left[j];
            j++; i++;
        }
        while (k < nR) 
        {
            bars[i] = right[k];
            k++; i++;
        }
    }
    // Driver program
    int main() 
    {
        clock_t t_start, t_end,t_start2, t_end2;
        int size;
        int n;
        cout<<"Hello, Please enter a size for the array \n"<<endl;
        cin>>size;
        cout<<"Thanks you, we succesfully created size _"<<size<<"_array"<<endl;
        cout<<endl;
        vector<int> array;
        vector<int> array2;
        // add of same randm values to two arrays.
        for(int i=0;i<size;i++)
        {
            int k=rand()%10;
            array.push_back(k);
            array2.push_back(k);
        }

        //computes times***************************

        auto start = high_resolution_clock::now();
        SelectionSort (array);
        auto stop = high_resolution_clock::now(); 
        ///////////////////////////////////////
        auto start2 = high_resolution_clock::now();
        Mergesort(array2);
        auto stop2 = high_resolution_clock::now(); 

        //////////////////////////////////////////
        //****************************************


        // display of result
        cout<<"SELECTION SORT ALGORITHM (BRUTE FORCE)"<<endl;
        auto duration = duration_cast<microseconds>(stop - start); 
        cout<<"Total use  "<< duration.count() << "  Microsecond"<<endl;
        //////////////////////////////////////////////
        cout<<endl;
        cout<<" MERGE SORT ALGORITHM (DIVIDE AND CONQUER)"<<endl;
        auto duration2 = duration_cast<microseconds>(stop2 - start2); 
        cout<<"Total use  "<< duration2.count() << "  Microsecond"<<endl;

    return 0;
}