#include<stdio.h>
int main(){
    int pos,n,x;
    int arr[100];
    scanf("%d",&n);
    
    for (int i = 0 ; i < 0 ; i++){
    scanf("%d",&arr[i]);
    }
    

    scanf("%d",&pos);
    scanf("%d",&x);

    for(int i = n ; i > pos ; i--){
        arr[i]=arr[i-1];

    }
    arr[pos - 1] = x;

}