#include<iostream>
#include<vector>
#include<string>
using namespace std;


void solve(int once,int zero,int n,string out,vector<string> &v){
    if(n==0){
        v.push_back(out);
        return;
    }
    // Always push 1...
    string op1=out;
    op1.push_back('1');
    solve(once+1,zero,n-1,op1,v);
    // Push 0 when (no. of 1's - no. of 0's ) = atleast(1)...
    if(once>zero){
        string op2=out;
        op2.push_back('0');
        solve(once,zero+1,n-1,op2,v);
    }
    return;
}

int main(){
    int n;
    cin >> n;
    int o,z;
    o=0;
    z=0;
    string out="";
    vector<string> v;
    solve(o,z,n,out,v);
    while(v.size()!=0){
        cout << v.front() << endl;
        v.erase(v.begin()+0);
    }
}