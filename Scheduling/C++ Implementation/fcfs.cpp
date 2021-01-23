#include<iostream>

using namespace std;

int main()
{
    string pid[10];
    int bt[10],wt[10],tat[10];
    float avg_tat = 0 , avg_wt = 0;

    int i,n;

    std::cout << "\nEnter the number of Processes";
    std::cin >> n;

    for(i=0;i<n;i++)
    {
        std::cout << "\nEnter Process ID ";
        cin >> P[i].pid;
        std::cout << "\nEnter Burst Time";
        cin >> P[i].bt;
    }

    for(i=0;i<n;i++){

        if(i==0){
            P[i].tat = P[i].bt;
        }

        else{
            P[i].tat = P[i].bt + tat[i-1];
        }

        P[i].wt = P[i].tat - P[i].bt;
        avg_tat += P[i].tat;
        avg_wt += P[i].wt;
    }

    std::cout <<"\nPID\t" << "BT\t" << "WT\t" << "TAT";

    for(i=0;i<n;i++){
        std::cout <<'\n'<<P[i].pid<<'\t'<<P[i].bt<<'\t'<<P[i].wt<<'\t'<<P[i].tat<<'\n';
    }

    std::cout<<"\nAverage Waiting Time : "<<avg_wt/n;
    std::cout<<"\nAverage Turnaround Time : "<<avg_tat/n<<'\n';
    
    return 0;
}

