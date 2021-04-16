//
//  main.c
//  quick sort
//
//  Created by Kanishka Mishra on 1/3/21.
//

#include <stdio.h>

int num;

void read_array(int array[],int num){
    for(int i=0;i<num;i++){
        scanf("%d",&array[i]);
    }
}

void display(int a[],int n){
    for(int i=0;i<n;i++){
        printf("%d \t",a[i]);
    }
    printf("\n");
}

int partition(int a[],int p, int r){
    int i,temp,temp2;
    int x=a[r];
    //printf("%d",x);
    i=p-1;
    for(int j=p;j<r;j++){
        if(a[j]<=x){
            i++;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    temp2=a[i+1];
    a[i+1]=a[r];
    a[r]=temp2;
    //printf("Pass: \t");
    //display(a,num);
    return i+1;
}

void quicksort(int a[20],int p,int r){
    if(p<r){
        int q;
        q=partition(a,p,r);
        printf("Pass: \t");
        display(a,r+1);
        quicksort(a,p,q-1);
        quicksort(a,q+1,r);
    }
}


int main(){
    int array[20];
    printf("Enter size: ");
    scanf("%d",&num);
    read_array(array,num);
    quicksort(array, 0, num-1);
    printf(" \n Sorted: ");
    display(array,num);
    return 0;
    
}
