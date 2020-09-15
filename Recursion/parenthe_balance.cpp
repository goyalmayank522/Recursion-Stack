#include<iostream>
#include<vector>
#include<string>
using namespace std;


void solve(int o,int c,string out,vector<string> &v){
    if(o==0 && c==0){
        v.push_back(out);
        return;
    }
    if(o!=0){
        string op1=out;
        op1.push_back('(');
        solve(o-1,c,op1,v);
    }
    if(c>o){
        string op2=out;
        op2.push_back(')');
        solve(o,c-1,op2,v);
    }
    return;
}

int main(){
    int a;
    cin >> a;
    int o,c;
    o=a;
    c=a;
    string out="";
    vector<string> v;
    solve(o,c,out,v);
    while(v.size()!=0){
        cout << v.front() << endl;
        v.erase(v.begin()+0);
    }
}