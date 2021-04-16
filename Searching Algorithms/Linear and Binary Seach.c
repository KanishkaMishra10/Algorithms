//
//  main.c
//  FDS lab 5
//
//  Created by Kanishka Mishra on 9/21/20.
//
/* A. Implement following searching algorithm:
 Linear search with multiple occurrences
 B. Implement following searching algorithms in menu:
 1. Binary search with iteration 2. Binary search with recursion */

#include <stdio.h>

int count=0;

void read_data(int array[10],int num){
    for(int i=0;i<num;i++){
        scanf("%d",&array[i]);
    }
}

void linear(int a[10],int n){
    int num,found=0;
    printf("Enter the element you want to search: ");
    scanf("%d",&num);
    for(int i=0;i<n;i++){
        if(a[i]==num){
            printf("Element found at position %d \n",i+1);
            found++;
        }
    }
    if(found==0){
        printf("Element not found!.\n");
    }
}

void binary_ite(int b[10],int n){
    int beg=0,end=n-1,mid,found=0,num,count=1;
    printf("Enter the number you want search: ");
    scanf("%d",&num);
    while(beg<=end){
        mid=(beg+end)/2;
        if(b[mid]==num){
            printf("Mid %d is : %d \n",count,mid);
            printf("Element found at Position %d \n",mid+1);
            found++;
            return;
        }
        if(b[mid]>num){
            end=mid-1;
            printf("Mid %d is : %d \n",count,mid);
        }
        if(b[mid]<num){
            beg=mid+1;
            printf("Mid %d is : %d \n",count,mid);
        }
        count++;
    }
    if(found==0)
        printf("\n Element not found \n");
}

int binary_rec(int c[10],int start ,int end,int num){
    int beg=start;
    int last=end;
    if(beg<=end){
        int mid=(beg+last)/2;
        if(c[mid]==num){
            count++;
            printf("Mid %d is : %d \n",count,mid);
            return mid;
        }
        if(c[mid]>num){
            count++;
            printf("Mid %d is : %d \n",count,mid);
            return binary_rec(c,start,mid-1,num);
        }
        count++;
        printf("Mid %d is : %d \n",count,mid);
        return binary_rec(c,mid+1,end,num);
    }
    return -1;
}

int main(){
    int choice,ans,num,array[10],num1,binary;
    printf("-------Disclaimer: Position starts from 1 and not 0-------\n\n");
    
    do{
        printf("Choose 1 for Linear Search \n Choose 2 for Binary search with iteration \n Choose 3 for Binary Search with recursion \n ");
        scanf("%d",&choice);
        
        switch(choice){
            case 1:
                printf("Enter the number of elements : ");
                scanf("%d",&num);
                read_data(array,num);
                linear(array,num);
                break;
            case 2:
                printf("Enter the number of elements: ");
                scanf("%d",&num);
                printf("Enter elements in sorted order \n");
                read_data(array,num);
                binary_ite(array,num);
                break;
            case 3:
                printf("Enter the number of elements: ");
                scanf("%d",&num);
                printf("Enter elements in sorted order \n");
                read_data(array,num);
                printf("Enter the number you want search: ");
                scanf("%d",&num1);
                binary=binary_rec(array,0,num-1,num1);
                if(binary==-1){
                    printf("Element not found \n");
                }
                else{
                    printf("Element found at position %d \n",binary+1);
                }
                break;
            default:
                printf("ERROR! Enter a valid choice. \n ");
        }
        printf("Run again 1:YES, 0:NO ");
        scanf("%d",&ans);
    }while(ans!=0);
}
