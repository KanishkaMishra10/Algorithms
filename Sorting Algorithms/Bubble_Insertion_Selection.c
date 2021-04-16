//
//  main.c
//  FDS Lab 6
//
//  Created by Kanishka Mishra on 9/27/20.
//
/* A.Implement following sortalgorithmusing function(Separateprograms or using menu):
 1.Bubble sort(display all passes)
 2.Insertion sort(display all passes)
 3.Selection sort((display all passes) */

#include <stdio.h>

void read_array(int array[20],int num){
    for(int i=0;i<num;i++){
        scanf("%d",&array[i]);
    }
}

void display(int a[20],int n){
    for(int i=0;i<n;i++){
        printf("%d \t",a[i]);
    }
    printf("\n");
}

void bubble(int b[20],int n){
    int temp,swap=0;
    for(int i=0;i<n-1;i++){ //number of passes
        for(int j=0;j<n-(i+1);j++){
            if(b[j]>b[j+1]){
                temp=b[j];
                b[j]=b[j+1];
                b[j+1]=temp;
                swap++;
            }
        }
        printf("Pass %d is: \t",i+1);
        display(b,n);
        printf("Swaps: %d \n",swap);
    }
}

void insertion(int c[20],int n){
    int temp,swap=0;
    for(int i=0;i<n;i++){   //number of passes
        int j=i;
        while(j>0){     //stopping condition
            if(c[j]<c[j-1]){
                temp=c[j];
                c[j]=c[j-1];
                c[j-1]=temp;
                swap++;
            }
            j--;
        }
        printf("Pass %d : \t",i+1);
        display(c,n);
        printf("Swap: %d \n",swap);
    }
}

void selection(int a[20],int n){
    int min,temp,swap=0;
    for(int i=0;i<n-1;i++){     //number of passes
        min=i;
        for(int j=i+1;j<n;j++){
            if(a[min]>a[j]){
                min=j;
            }
        }
        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
        swap++;
        printf("Pass %d: \t",i+1);
        display(a,n);
    }
    printf("Swap: %d \n",swap);
}

int main(){
    int choice,ans,num,array[20];
    do{
        printf("Choose 1 for Bubble Sort \n Choose 2 for Insertion Sort \n Choose 3 for Selection sort \n ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the number of elements: ");
                scanf("%d",&num);
                read_array(array,num);
                bubble(array,num);
                break;
            case 2:
                printf("Enter the number of elements: ");
                scanf("%d",&num);
                read_array(array,num);
                insertion(array,num);
                break;
            case 3:
                printf("Enter the number of elements: ");
                scanf("%d",&num);
                read_array(array,num);
                selection(array,num);
                break;
            default:
                printf("ERROR! Enter a valid choice \n");
        }
        printf("Run again 1:YES 0:NO \n");
        scanf("%d",&ans);
    }while(ans!=0);
}
