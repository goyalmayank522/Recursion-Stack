#include<stdio.h>
int fact(int n){
    if(n==1){
        return 1;
    }
    return n*fact(n-1);
    
}
void main(){
    int res=fact(0);
    printf("%d",res);
}