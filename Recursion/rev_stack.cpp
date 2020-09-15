#include<iostream>
#include<stack>
using namespace std;

void insert(stack<int> &arr,int temp){
    if(arr.empty()){
        arr.push(temp);
        return;
    }
    int val=arr.top();
    arr.pop();
    insert(arr,temp);
    arr.push(val);
    return;
}

void rev_arr(stack<int> &arr, int temp){
    if(arr.size()==1 || arr.empty()){
        return;
    }
    temp=arr.top();
    arr.pop();
    rev_arr(arr,temp);
    insert(arr,temp);
}

int main(){
    stack <int> arr;
    arr.push(5);
    arr.push(4);
    arr.push(3);
    arr.push(2);
    arr.push(1);
    rev_arr(arr, arr.top());
    //cout << arr.top();
    while(!arr.empty()){
        cout << arr.top() <<endl;
        arr.pop();
    }
}