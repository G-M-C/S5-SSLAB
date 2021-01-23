#include<iostream>

using namespace std;
struct Process{
    string pid;
    int bt;
    int wt;
    int tat;
};

bool compare(Process a , Process b){

    return a.bt <= b.bt;
}



int main()
{
    Process P[10];

    int i,n;
    float avg_wt=0,avg_tat=0;

    std::cout << "\nEnter the number of Processes";
    std::cin >> n;

    for(i=0;i<n;i++)
    {
        std::cout << "\nEnter Process ID ";
        cin >> P[i].pid;
        std::cout << "\nEnter Burst Time";
        cin >> P[i].bt;
    }

    std::sort(P,P + n,compare);

    

    

    for(i=0;i<n;i++){

        if(i==0){
            P[i].tat = P[i].bt;
        }

        else{
            P[i].tat = P[i].bt + P[i-1].tat;
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
