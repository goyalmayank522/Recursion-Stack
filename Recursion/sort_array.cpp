#include<iostream>
#include<vector>
using namespace std;

void insert(vector<int> &arr,int temp){
    if(arr.empty() || arr[arr.size()-1]<=temp){
        arr.push_back(temp);
        return;
    }
    int val=arr[arr.size()-1];
    arr.pop_back();
    insert(arr,temp);
    arr.push_back(val);
    return;
}

void sort_arr(vector<int> &arr){
    if(arr.size()==1){
        return;
    }
    int temp=arr[arr.size()-1];
    arr.pop_back();
    sort_arr(arr);
    insert(arr,temp);
}

int main(){
    vector <int> arr;
    arr.push_back(10);
    arr.push_back(1);
    arr.push_back(5);
    arr.push_back(2);
    arr.push_back(0);
    sort_arr(arr);
    for(int i=0;i<arr.size();i++){
        cout << arr[i] <<endl;
    }
}