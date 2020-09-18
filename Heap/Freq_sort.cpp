// compile it with "g++ -std=c++11 Freq_sort.cpp" bcoz unordered map is currently experimental...
#include<iostream>
#include <bits/stdc++.h> 
#include<unordered_map>
using namespace std;
typedef pair<int, int> pi;

int main(){
    unordered_map<int,int > mp;
    priority_queue<pi > max_heap;
    int n;
    cout << "Enter array length:- ";
    cin >> n;
    int arr[n]; 
    cout << "Enter the array:- ";
    for(int i=0;i<n;i++){
        int ele;
        cin >> ele;
        arr[i]=ele;
    }
    
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }

    for(auto i=mp.begin();i!=mp.end();i++){
        max_heap.push(make_pair(i->second,i->first)); //pointer bcoz iterations...
    }
    cout << "The frequency sorted array is:- " << endl;
    while(!max_heap.empty()){
        int freq=max_heap.top().first;
        int ele=max_heap.top().second;
        for(int i=0;i<freq;i++){
            cout << ele << endl;
        }
        max_heap.pop();
    }
}