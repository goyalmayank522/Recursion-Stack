// compile it with "g++ -std=c++11 Top_k_freq_num.cpp" bcoz unordered map is currently experimental...
#include<iostream>
#include <bits/stdc++.h> 
#include<unordered_map>
using namespace std;
typedef pair<int, int> pi;

int main(){
    unordered_map<int,int > mp;
    priority_queue<pi, vector <pi>, greater <pi> > min_heap;
    int n,k;
    cout << "Enter array length:- ";
    cin >> n;
    int arr[n]; 
    cout << "Enter the array:- ";
    for(int i=0;i<n;i++){
        int ele;
        cin >> ele;
        arr[i]=ele;
    }
    cout << "Enter k value:- ";
    cin >> k;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }

    for(auto i=mp.begin();i!=mp.end();i++){
        min_heap.push(make_pair(i->second,i->first)); //pointer bcoz iterations...
        if(min_heap.size()>k){
            min_heap.pop();
        }
    }
    cout << "Top k frequent numbers are:- " << endl;
    while(!min_heap.empty()){
        cout << min_heap.top().second <<endl;
        min_heap.pop();
    }
}