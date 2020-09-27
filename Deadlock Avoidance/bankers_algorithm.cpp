//#####-BANKERS ALGORITHM-#######

#include<iostream>

using namespace std;



void read(int res_alloc[][10], int max_need[][10], int available[10], int need[][10], int n, int m)
{
    int i, j;

    for(i = 0; i < n; i++)
    {
        std::cout << "\nProcess : " << i+1;
        std::cout << "\nEnter the current resource allocation " ;

        for(j = 0; j < m; j++)
        {
            std::cin >> res_alloc[i][j];
        }

        std::cout << "\nEnter the maximum no:of resource instances required ";

        for(j = 0; j < m; j++)
        {
            std::cin >> max_need[i][j];
        }
    }

    std::cout << "\nEnter the no: of resource instances currently available ";

    for(i = 0; i < m; i++)
    {
        std::cin >> available[i];
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            need[i][j] = max_need[i][j] - res_alloc[i][j];
        }
    }

    
}


void is_safe(int res_alloc[][10], int available[10], int need[][10], int n, int m )
{
    int i, j, k, count = 0;
    int seq[10];
    bool finished[10] = {false};


    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            if(!finished[i])
            {
                for(j = 0; j < m; j++)
                {
                    if(available[j] >= need[i][j])
                    {
                        continue;
                    }

                    else
                    {
                        break;
                    }
                    
                }

                if(j == m)
                {
                    for(j = 0; j < m; j++)
                    {
                        available[j]+=res_alloc[i][j];
                    }
                    seq[count] = i+1;
                    count += 1;
                    finished[i] = true;

                }
            }
        }
    }

    if(count == n)
    {
        std::cout << "\n#####-SAFE STATE-#####";
        std::cout << "\nSequence : ";
        int  i;
        for(i = 0; i < n; i++)
        {
            std::cout << "P" << seq[i] << " ";
        }
        std::cout<<'\n';
        
    }

    if(count != n)
    {
        std::cout << "\n#####-DEADLOCK-#####\n";
    }

}

void display(int arr[][10], int n, int m)
{
    int i,j;
    
    for(i = 0; i < n; i++)
    {
        std::cout << "\nP" << i+1 << '\t';
        for(j = 0; j < m; j++)
        {
            std::cout << '\t' << arr[i][j];
        }
    }
}

int main()
{
    int res_alloc[10][10];
    int max_need[10][10];
    int available[10];
    int need[10][10]; 
    int n, m;

    std::cout << "\nEnter the number of processes ";
    std::cin >> n;

    std::cout << "\nEnter the no:of resources ";
    std::cin >> m;

    read(res_alloc, max_need, available, need, n, m);

    std::cout <<"\nProcesses " << "\tCurrent Allocation ";
    display(res_alloc,n,m);

    std::cout <<"\nProcesses " << "\tMaximum Need ";
    display(max_need,n,m);

    std::cout <<"\nProcesses " << "\tCurrent Need ";
    display(need,n,m);

    is_safe(res_alloc,available,need,n,m);

    return 0;



}

