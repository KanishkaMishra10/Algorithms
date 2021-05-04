//
//  main.c
//  FCFS
//
//  Created by Kanishka Mishra on 5/2/21.
//

#include<stdio.h>
 
 int main()
 
{
    /*
     bt=burst time; wt=waiting time; tat=turnaround time;
     avwt=average waiting time; avtat= average turnaround time;
     at= arrival time; n=number of processes;
     st=starting time; et=ending time;
     */
    
    int n,bt[20],wt[20],tat[20],i,at[20],st[20],et[20];
    float avwt=0.0,avtat=0.0;
    printf("Enter total number of processes: ");
    scanf("%d",&n);
 
    printf("\nEnter Process Burst Time\n");
    for(i=0;i<n;i++)
    {
        printf("P[%d]:",i+1);
        scanf("%d",&bt[i]);
    }
    
    printf("\nEnter Arrival Time\n");
    for(i=0;i<n;i++)
    {
        printf("P[%d]:",i+1);
        scanf("%d",&at[i]);
    }
    
    //calculating starting time of every process
    st[0]=0;
    for(int i=1;i<n;i++){
        st[i]=st[i-1]+bt[i-1];
    }
    
    //calculating end time of every process
    et[0]=bt[0];
    for(int i=1;i<n;i++){
        et[i]=0;
        for(int j=i;j>=0;j--){
            et[i]=et[i]+bt[j];
        }
    }
    
    //calculating wait time of every process
    for(i=0;i<n;i++)
    {
        wt[i]=st[i]-at[i];
    }
    
    printf("\nGantt Chart:\n\n");
    
    for(int i=0;i<n;i++){
        printf("\t\t\tP[%d] ",i+1);
    }
    
    printf("\n\t");
    for(int i=0;i<n;i++){
        printf("%d \t\t\t\t",st[i]);
    }
    printf("%d\n",et[n-1]);
    
    
    printf("\nProcess\t\tArrival Time\t\tBurst Time\t   Waiting Time\t   Turnaround Time\n");
 
    for(i=0;i<n;i++)
    {
        tat[i]=et[i]-at[i];
        avwt+=wt[i];
        avtat+=tat[i];
        printf("\nP[%d]\t\t\t\t%d\t\t\t\t%d\t\t\t\t%d\t\t\t\t\t%d",i+1,at[i],bt[i],wt[i],tat[i]);
    }
 
    avwt/=n;
    avtat/=n;
    printf("\n\nAverage Waiting Time: %.2f",avwt);
    printf("\nAverage Turnaround Time: %.2f",avtat);
    printf("\n\n");
 
    return 0;
}
