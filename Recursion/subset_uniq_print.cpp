#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;

void solve(string inp,string out,vector <string> &v){
if(inp.length()==0){
    v.push_back(out);
    return;
}
string op1=out;
string op2=out;
op2.push_back(inp[0]);
inp.erase(inp.begin()+0);
solve(inp,op1,v);
solve(inp,op2,v);
return;
}

int main(){
    string inp;
    cin >> inp;
    vector<string> v;
    string out="";
    solve(inp,out,v);
    set<string> s(v.begin(),v.end());
    for(auto it=s.begin();it !=s.end();++it){
        cout << ' ' << *it;
    }
}