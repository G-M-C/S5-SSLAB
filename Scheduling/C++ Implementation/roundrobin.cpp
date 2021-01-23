#include<iostream>
#include<numeric>

using namespace std;
struct Process{
    string pid;
    int bt;
    int wt;
    int tat;
};



void time_calc(int qtm,Process P[],int n)
{
    int rbt[10];
    int t = 0;
    int i;

    for(i =0;i<n;i++){

        rbt[i] = P[i].bt;

    }

    while(true){
        bool finished = true;

        for(i=0;i<n;i++){
            
            if(rbt[i] > 0){
                finished = false;

                if(rbt[i] > qtm){
                    rbt[i] -= qtm;
                    t += qtm;
                }

                else{
                    t = t + rbt[i];
                    P[i].wt = t - P[i].bt;
                    
                    P[i].tat = P[i].wt + P[i].bt;
                    
                    rbt[i] = 0;
                }
            }
        }

        if (finished==true){
        break;
        }

    }


}



int main()
{
    Process P[10];

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

    int qtm;
    cout << "\nEnter Time QTM";
    cin >> qtm;

    time_calc(qtm,P,n);


    

    


    std::cout <<"\nPID\t" << "BT\t" << "WT\t" << "TAT";
    float avg_wt =0 , avg_tat = 0;

    for(i=0;i<n;i++){
        std::cout <<'\n'<<P[i].pid<<'\t'<<P[i].bt<<'\t'<<P[i].wt<<'\t'<<P[i].tat<<'\n';
        avg_wt += P[i].wt;
        avg_tat += P[i].tat;
    }

    std::cout<<"\nAverage Waiting Time : "<<avg_wt/n;
    std::cout<<"\nAverage Turnaround Time : "<<avg_tat/n<<'\n';
    
    return 0;
}