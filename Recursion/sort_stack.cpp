#include<iostream>
#include<stack>
using namespace std;

void insert(stack<int> &arr,int temp){
    if(arr.empty() || arr.top()<=temp){
        arr.push(temp);
        return;
    }
    int val=arr.top();
    arr.pop();
    insert(arr,temp);
    arr.push(val);
    return;
}

void sort_arr(stack<int> &arr){
    if(arr.size()==1){
        return;
    }
    int temp=arr.top();
    arr.pop();
    sort_arr(arr);
    insert(arr,temp);
}

int main(){
    stack <int> arr;
    arr.push(0);
    arr.push(2);
    arr.push(5);
    arr.push(1);
    arr.push(10);
    sort_arr(arr);
    //cout << arr.top();
    while(!arr.empty()){
        cout << arr.top() <<endl;
        arr.pop();
    }
}