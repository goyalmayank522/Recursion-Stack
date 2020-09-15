#include<iostream>
#include<string>
using namespace std;

void solve(string inp,string out){
if(inp.length()==0){
    cout << out << endl;
    return;
}
if(isdigit(inp[0])){
    string op1=out;
    op1.push_back(inp[0]);
    inp.erase(inp.begin()+0);
    solve(inp,op1);
}
else{
    string op1=out;
    string op2=out;
    op1.push_back(tolower(inp[0]));
    op2.push_back(toupper(inp[0]));
    inp.erase(inp.begin()+0);
    solve(inp,op1);
    solve(inp,op2);
}
return;
}

int main(){
    string inp;
    cin >> inp;
    string out="";
    solve(inp,out);
}