#include<iostream>
#include <bits/stdc++.h> 
using namespace std;

int main(){
    priority_queue<int, vector<int>, greater<int> > min_heap;
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
        min_heap.push(arr[i]);
        if(min_heap.size()>k){
            min_heap.pop();
        }
    }
    cout << "The k largest elements are:- " << endl;
    while(!min_heap.empty()){
        cout << min_heap.top() <<endl;
        min_heap.pop();
    }
}