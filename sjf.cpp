#include<bits/stdc++.h>
using namespace std;
#define N 10

struct Process{
    int n;
    int pid[N];
    int at[N];
    int bt[N];
};

void ta_t(Process p,int wt[],int tat[]){
    for(int i=0;i<p.n;i++){
        tat[i] = wt[i] + p.bt[i];
    }
}

void w_t(Process p,int wt[]){
    int rt[p.n],fn = 0;
    int  complete = 0,cur_time = 0,smallest = 0;
    bool check = false;
    int min = INT_MAX;
    //rt mai poora bt store kar dungi
    for(int i=0;i<p.n;i++){
        rt[i] = p.bt[i];
    }
    while(complete != p.n){
        // ab neeche wala loop smallest value in bt pick karega
        for(int j=0;j<p.n;j++){
            //cout<<"arrival time hai yeh "<<p.at[j]<<" current time hai "<<cur_time<<"\n";
            if(p.at[j] <= cur_time && (rt[j] < min) && rt[j] > 0){
                    
                min = rt[j];
                smallest = j;
                check  = true;
                cout<<"arrival time hai yeh "<<p.at[j]<<" min time hai "<<min<<"\n";
            
            }
        }
        cout<<"hi\n";
        if(check == false){
            cur_time++;
            continue;
        }
        rt[smallest]--;
        min = rt[smallest];
        if(min == 0){
            min = INT_MAX;
        }
        if(rt[smallest] == 0){
            complete++;
            check = false;
            fn = cur_time+1;
            cout<<"\nFinish time for P"<<smallest+1<<" is"<<fn<<"\n";
            wt[smallest] = fn - p.bt[smallest] - p.at[smallest];
            if(wt[smallest] <= 0){
                wt[smallest] = 0;
            }
        }
        
        
        //wapas same value nhi lega kyunki rt mai uska burst time 0 ho jaaega aur vo fir if k andar jaa hi nhi paayega
    }
    
}

void sjf(Process p){
    int wt[p.n],tat[p.n];
    w_t(p,wt);
    ta_t(p,wt,tat);
    cout<<"PID\tAT\tBT\tWT\tTAT\n";
    for(int i=0;i<p.n;i++){
        cout<<p.pid[i]<<"\t"<<p.at[i]<<"\t"<<p.bt[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<"\n";
    }
    int sum_wt = 0;
    for(int i=0;i<p.n;i++){
        sum_wt = sum_wt + wt[i];
    }
    cout<<"Average Waiting Time = "<<float(sum_wt)/float(p.n);
    int sum_tat = 0;
    for(int i=0;i<p.n;i++){
        sum_tat = sum_tat + tat[i];
    }
    cout<<"Average Turn Around Time = "<<float(sum_tat)/float(p.n);
}



int main() {
    Process p;
    cout<<"Enter the number of processes = ";
    cin>>p.n;
    if(p.n > N){
        cout<<"Cannot take that large number :(\n";
        return 0;
    }
    
    
    
    for(int i=0;i<p.n;i++){
        p.pid[i] = i;
    }
    cout<<"\nEnter the arrival time\n";
    for(int i=0;i<p.n;i++){
        cin>>p.at[i];
    }
    cout<<"\nEnter the burst time\n";
    for(int i=0;i<p.n;i++){
        cin>>p.bt[i];
    }
    
    sjf(p);
}
