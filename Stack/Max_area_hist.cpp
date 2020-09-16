#include<iostream>
#include <bits/stdc++.h>
#include<vector>
#include<stack>
using namespace std;

int main(){
    vector<int> arr;
    int n, k;
    cout << "Enter array length:- ";
    cin >> n;
    cout << "Enter the elements:- " ;
    for(int i=0;i<n;i++){
        cin >> k;
        arr.push_back(k);
    }
    
    //computing Nearest smaller element's index at left;
    int pseudo_index=-1;
    vector<int> left;
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
    vector<int> right;
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
    vector<int> result;
    for(int i=0;i<n;i++){
        result.push_back(right[i]-left[i]-1);
        int temp=arr[i]*(right[i]-left[i]-1);
        //cout << arr[i] << "  " << right[i] <<"  "<< left[i] << "   " <<temp <<endl;
        if(temp>max_area){
            max_area=temp;
        }
    }
    cout << "Max area of Histogram is:- "<< max_area <<endl;
}
