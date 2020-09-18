#include<iostream>
#include <bits/stdc++.h> 
using namespace std;

int main(){
    priority_queue<pair<int,int> > max_heap;
    int n,k,x;
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
    cout << "Enter X value:- ";
    cin >> x;
    for(int i=0;i<n;i++){
        max_heap.push(make_pair(abs(arr[i]-x),arr[i]));
        if(max_heap.size()>k){
            max_heap.pop();
        }
    }
    cout << "The k closest elements to x are:- " <<endl;
    while(!max_heap.empty()){
        cout << max_heap.top().second << endl;
        max_heap.pop();
    }
}