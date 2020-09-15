#include<iostream>
#include<stack>
using namespace std;

void sort_arr(stack<int> &arr, int k){
    if(k==1){
        arr.pop();
        return;
    }
    int temp=arr.top();
    arr.pop();
    sort_arr(arr, k-1);
    arr.push(temp);
    return;
}

int main(){
    stack <int> arr;
    arr.push(5);
    arr.push(4);
    arr.push(3);
    arr.push(2);
    arr.push(1);
    int k=(arr.size()/2+1);
    sort_arr(arr,k);
    //cout << arr.top();
    while(!arr.empty()){
        cout << arr.top() <<endl;
        arr.pop();
    }
}