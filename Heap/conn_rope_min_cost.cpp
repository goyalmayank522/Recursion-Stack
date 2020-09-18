#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<int, vector<int>, greater<int> > min_heap;
    int n;
    cout << "Enter array length:- ";
    cin >> n;
    int arr[n];
    cout << "Enter the array:- ";
    for(int i=0;i<n;i++){
        int ele;
        cin >> ele;
        arr[i]=ele;
        min_heap.push(ele);
    }
    int total_cost=0;
    while(min_heap.size()!=1){
        int a=min_heap.top();
        min_heap.pop();
        int b=min_heap.top();
        min_heap.pop();
        min_heap.push(a+b);
        total_cost+=(a+b);
        //cout<< "TC :- " << total_cost << endl;
    }
    cout << "The total cost is "<< total_cost<< endl;
}
