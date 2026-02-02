#include<stdio.h>
int main(){
    int n,pos,x;
    scanf("%d", &n);
    int arr[100];

    for (int i=0 ; i < n ; i++){
        scanf("%d",&arr[i]);
    }
    printf("enter position to delete (1 to %d): ", n );
    scanf("%d",&pos);

    if (pos < 1 || pos > n)
{
        printf("invalid pos");
    }
    else{
        for (int i = pos - 1 ; i < n - 1 ; i++ ){
            arr[i] = arr[i+1];

        }
        n--;
        printf("array after deletion:\n" );
            for (int i=0 ; i < n ; i++){
        printf("%d",&arr[i]);


    
    }
    return 0;
}



    
}