#include<iostream>
#include<string.h>
using namespace std;

void solve(string inp,string out){
if(inp.length()==0){
    cout << out << endl;
    return;
}
string op1=out;
string op2=out;
op2.push_back(inp[0]);
inp.erase(inp.begin()+0);
solve(inp,op1);
solve(inp,op2);
return;
}

int main(){
    string inp;
    cin >> inp;
    string out="";
    solve(inp,out);
}