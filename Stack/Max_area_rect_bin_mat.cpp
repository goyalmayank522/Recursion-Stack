#include<iostream>
#include <bits/stdc++.h>
#include<vector>
#include<stack>
using namespace std;

int max(int a, int b){
    if(a>=b){
        return a;
    }
    else{
        return b;
    }
}

int mah(vector <int> arr,int n, vector<int> left, vector<int> right){
    //computing Nearest smaller element's index at left;
    int pseudo_index=-1;
    stack<pair<int,int> > s_left;
    for(int i=0;i<n;i++){
        if(s_left.size()==0){
            left.push_back(pseudo_index);
        }
        else if(s_left.size()>0 && s_left.top().first <arr[i]){
            left.push_back(s_left.top().second);
        }
        else if(s_left.size()>0 && s_left.top().first>=arr[i]){
            while (s_left.size()>0 && s_left.top().first>=arr[i])
            {
                s_left.pop();
            }
            if(s_left.size()==0){
                left.push_back(pseudo_index);
            }
            else{
                left.push_back(s_left.top().second);
            }
        }
        s_left.push(make_pair(arr[i], i));
    }

    //computing Nearest smaller element's index at right;
    pseudo_index=n;
    stack<pair<int,int> > s_right;
    for(int i=n-1;i>=0;i--){
        if(s_right.size()==0){
            right.push_back(pseudo_index);
        }
        else if(s_right.size()>0 && s_right.top().first <arr[i]){
            right.push_back(s_right.top().second);
        }
        else if(s_right.size()>0 && s_right.top().first>=arr[i]){
            while (s_right.size()>0 && s_right.top().first>=arr[i])
            {
                s_right.pop();
            }
            if(s_right.size()==0){
                right.push_back(pseudo_index);
            }
            else{
                right.push_back(s_right.top().second);
            }
        }
        s_right.push(make_pair(arr[i], i));
    }
    reverse(right.begin(),right.end());
    int max_area=0;
    for(int i=0;i<n;i++){
        //result.push_back(right[i]-left[i]-1);
        int temp=arr[i]*(right[i]-left[i]-1);
        //cout << arr[i] << "  " << right[i] <<"  "<< left[i] << "   " <<temp <<endl;
        if(temp>max_area){
            max_area=temp;
        }
    }
    return max_area;
}

int main(){
    int n, m;
    cout << "Enter number of rows & columns of array:- ";
    cin >> n >> m;
    vector<vector<int> > array(m);
    cout << "Enter the binary matrix:- " << endl;
    int ele;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> ele;
            array[i].push_back(ele);
        }   
    }
    
    vector<int> left;
    vector<int> right;
    vector<int> v;
    for(int j=0;j<m;j++){
        v.push_back(array[0][j]);
    }
    int mx= mah(v, m, left, right);
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(array[i][j]==0){
                v[j]=0;
            }
            else{
                v[j]=v[j]+array[i][j];
            }
        }
        int temp=mah(v, m, left, right);
        mx=max(mx,temp);
    }
    cout << "Max area of Rectangle in binary matrix is:- "<< mx <<endl;
}
