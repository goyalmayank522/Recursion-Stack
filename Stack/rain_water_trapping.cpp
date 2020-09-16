#include<iostream>
#include <bits/stdc++.h>
#include<vector>
#include<stack>
using namespace std;

int min(int a, int b){
    if(a<b){return a;}
    else{return b;}
}
int max(int a, int b){
    if(a>b){return a;}
    else{return b;}
}
int main(){
    int n;
    cout << "Enter array length:- ";
    cin >> n;
    vector<int> arr;
    int ele;
    cout << "Enter the array:- ";
    for(int i=0;i<n;i++){
        cin >> ele;
        arr.push_back(ele);
    }
    vector<int> maxl;
    vector<int> maxr;
    
    maxl.push_back(arr.at(0));
    for(int i=1;i<n;i++){
        maxl.push_back(max(arr.at(i),maxl.at(i-1)));
    }

    maxr.push_back(arr.at(n-1));
    int j=0;
    for(int i=n-2;i>=0;i--){
        maxr.push_back(max(arr.at(i),maxr.at(j)));
        j++;
    }
    reverse(maxr.begin(),maxr.end());

    vector<int> water;
    int sum=0;
    for(int i=0;i<n;i++){
        water.push_back(min(maxl.at(i),maxr.at(i))-arr.at(i));
        sum+=water.at(i);
    }
    cout << "Total amount of rain stored is:- " <<sum;
}