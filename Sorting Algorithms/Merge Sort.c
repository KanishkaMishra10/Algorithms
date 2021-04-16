//
//  main.c
//  FDS Lab 7
//
//  Created by Kanishka Mishra on 10/11/20.
//

#include <stdio.h>

int num;

void read_array(int a[],int num){
    for(int i=0;i<num;i++){
        scanf("%d",&a[i]);
    }
}

void display(int array[],int n){
    for(int i=0;i<n;i++){
        printf("%d \t",array[i]);
    }
    printf("\n");
}

void Merge(int a[],int beg,int end, int last){
    int n1=end-beg+1;
    int n2=last-end;
    int left[n1+1],right[n2+1];
    for(int i=0;i<n1;i++){
        left[i]=a[beg+i];
    }
    for(int j=0;j<n2;j++){
        right[j]=a[end+1+j];
    }
    left[n1]=9999;
    right[n2]=9999;
    int i=0,j=0;
    for(int k=beg;k<=last;k++){
        if(left[i]<=right[j]){
            a[k]=left[i];
            i++;
        }
        else{
            a[k]=right[j];
            j++;
        }
    }
    printf("Pass: ");
    display(a,num);
}

void merge_sort(int array[],int beg, int end){
    if(beg<end){
    int div=(beg+end)/2;
    merge_sort(array,beg,div);
    merge_sort(array,div+1,end);
    Merge(array,beg,div,end);
    }
}

int main(){
    int array[20];
    printf("Enter the number of elements: ");
    scanf("%d",&num);
    read_array(array, num);
    printf("The given unsorted data is: ");
    display(array,num);
    merge_sort(array,0,num-1);
    printf("\nThe sorted array is: ");
    display(array,num);
    printf("\n");
    
}
