#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int> &v, int k, int index){
    if(v.size()==1){
        return (v.at(0));
    }
    index=(index+k)%v.size();
    v.erase(v.begin()+index);
    solve(v,k,index);
}

int main(){
    int n,k;
    cout << "Enter the total no of peoples:- ";
    cin >> n;
    cout << "Enter the kth value:- ";
    cin >> k;
    vector<int> v;
    for(int i=0;i<n;i++){
        v.push_back(i+1);
    }
    int res=solve(v,k-1,0);
    cout << "The person got escaped is:- " << res;
}