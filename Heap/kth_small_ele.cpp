#include<iostream>
#include <bits/stdc++.h> 
using namespace std;

int main(){
    priority_queue<int> max_heap;
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
        max_heap.push(arr[i]);
        if(max_heap.size()>k){
            max_heap.pop();
        }
    }
    cout << "The kth smallest element is:- " << max_heap.top() <<endl;
}