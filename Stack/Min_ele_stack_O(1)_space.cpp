#include<iostream>
#include<stack>
using namespace std;
stack<int> s;
int min_ele;
void push(int a){
    if(s.size()==0){
        s.push(a);
        min_ele=a;
    }
    else{
        if(a<min_ele){
            s.push(2*a-min_ele);
            min_ele=a;
        }
        else /*(a>=min_ele)*/ {
            s.push(a);
        }
    }
    
}
int pop(){
    if(s.size()==0){
        return -1;
    }
    int res;
    if(s.top()<min_ele){
        res=min_ele;
        min_ele=2*res-s.top();
        s.pop();
    }
    else{
        res=s.top();
        s.pop();
    }
    return res;
}
int top(){
    if(s.size()==0){
        return -1;
    }
    else{
        if(s.top()>=min_ele){
            return s.top();
        }
        else{
            return min_ele;
        }
    }
}

int get_min(){
    if(s.size()==0){
        return -1;
    }
    return min_ele;
}

int main(){
    push(5);
    push(3);
    cout << "Min. element:- "<< get_min() << endl;
    cout << "Top element:- "<< top() <<endl;
    cout << "Popped element:- "<< pop() << endl;
    push(7);
    cout << "Min. element:- "<< get_min() << endl;
    cout << "Popped element:- "<< pop() << endl;
    cout << "Min. element:- "<< get_min() << endl;
    }