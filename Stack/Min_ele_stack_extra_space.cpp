#include<iostream>
#include<stack>
using namespace std;
stack<int> s;
stack<int> ss;
void push(int a){
    s.push(a);
    if(ss.size()==0 || a<=ss.top()){
        ss.push(a);
        return;
    }
}
int pop(){
    if(s.size()==0){
        return -1;
    }
    int res=s.top();
    s.pop();
    if(ss.top()==res){
        ss.pop();
    }
    return res;
}
int get_min(){
    if(ss.size()==0){
        return -1;
    }
    return ss.top();
}

int main(){
    push(18);
    push(19);
    cout << "Min. element:- "<< get_min() << endl;
    push(21);
    push(15);
    cout << "Min. element:- "<< get_min() << endl;
    cout << "Popped element:- "<< pop() << endl;
    cout << "Min. element:- "<< get_min() << endl;
    }