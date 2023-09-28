#include <bits/stdc++.h>

using namespace std;

void waitingtime(int wt[],int at[],int tat[],int bt[],int n){
    
    //wt[0]=at[0];
    for(int i=0;i<n;i++){
        wt[i] = tat[i] - bt[i];
    }
}

void turnaroundtime(int tat[],int at[],int wt[],int bt[],int fn[],int n){
    int sum = 0;
    for(int i=0;i<n;i++){
        tat[i] = fn[i] - at[i];
    }
}

void print_table(int pid[],int at[],int bt[],int wt[],int tat[],int fn[],int n){
    cout<<"PID\tBT\tWT\tTAT\tFinish Time\n";
    for(int i=0;i<n;i++){
        cout<<i+1<<"\t"<<bt[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<"\t"<<fn[i]<<"\n";
    }
}


void fcfs(int pid[],int at[],int bt[],int n){
    int wt[n],total_wt=0,total_tat=0;
    int tat[n];
    int fn[n];
    int sum=0;
    fn[0] = bt[0];
    sum = fn[0];
    for(int i=1;i<n;i++){
        sum = sum + bt[i];
        fn[i] = sum;
    }
    turnaroundtime(tat,at,wt,bt,fn,n);
    waitingtime(wt,at,tat,bt,n);
    
    //total waiting time will be sum of all the values in array wt
    for(int i=0;i<n;i++){
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
    }
    cout<<"Total waiting time = "<<total_wt<<"\n";
    cout<<"Average waiting time = "<<float(total_wt)/float(n)<<"\n";
    cout<<"Total Turn around time = "<<total_tat<<"\n";
    cout<<"Average Turn around time = "<<float(total_tat)/float(n)<<"\n";
    print_table(pid,bt,at,wt,tat,fn,n);
}


int main()
{
    int n;
    cout<<"Enter number of processes = ";
    cin>>n;
   int pid[n];
   int bt[n];
   int at[n];
   cout<<"Enter burst time\n"; 
   for(int i=0;i<n;i++){
    pid[i] = i;
    cin>>bt[i];
   }
   cout<<"Enter arrival time\n ";
    for(int i=0;i<n;i++){
    cin>>at[i];
   }
   sort(at,at+n);
   fcfs(pid,at,bt,n);
   return 0;
}
