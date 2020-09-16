//print the array of count of each consecutive smaller or equal to any number in input array...
#include<iostream>
#include <bits/stdc++.h>
#include<vector>
#include<stack>
using namespace std;

int main(){
    vector<int> arr;
    int n, k;
    cout << "Enter array length:- ";
    cin >> n;
    cout << "Enter the elements:- " <<endl;
    for(int i=0;i<n;i++){
        cin >> k;
        arr.push_back(k);
    }
    vector<int> out_arr;
    stack<int> s;
    for(int i=0;i<n;i++){
        if(s.size()==0){
            out_arr.push_back(1);
        }
        else if(s.size()>0 && s.top()>arr[i]){
            out_arr.push_back(1);
        }
        else if(s.size()>0 && s.top()<=arr[i]){
            while (s.size()>0 && s.top()<=arr[i])
            {
                s.pop();
            }
            if(s.size()==0){
                out_arr.push_back(i);
            }
            else{
                out_arr.push_back(i-s.size()+1);
            }
        }
        s.push(arr[i]);
    }
    //reverse(out_arr.begin(),out_arr.end());
    for(int i=0;i<n;i++){
        cout << out_arr[i] << " ";
    }
}
