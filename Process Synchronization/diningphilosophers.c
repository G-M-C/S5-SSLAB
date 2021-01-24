// Dining Philosophers Problem


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool all_philosophers_have_eaten(bool philosophers[], int n)
{
    for (int i = 0; i < n; i++)
        if (!philosophers[i])
            return false;
    return true;
}

void clear_forks(bool forks[], int n)
{
    for (int i = 0; i < n; i++)
        forks[i] = true;
}

int main()
{
    printf("Enter number of philosophers : ");
    int n;
    scanf("%d", &n);
    bool forks[n];
    bool philosophers_finished_eating[n];
    clear_forks(forks, n);

    bool flag = true;
    int iter = 1;
    while (flag)
    {
        printf("\nIteration : %d\n",iter);
        iter++;
        clear_forks(forks, n);
        flag = false;
        for (int i = 0; i < n; i++)
        {
            if (!philosophers_finished_eating[i])
            {
                if (forks[i] && forks[(i + 1) % n])
                {
                    forks[i] = false;
                    forks[(i + 1) % n] = false;
                    printf("Philosopher %d is eating\n", i);
                    philosophers_finished_eating[i] = true;
                    flag = true;
                }
                else
                    printf("Philosopher %d is thinking\n", i);
            }
            else
                printf("Philosopher %d has finished eating\n", i);
        }
        if (all_philosophers_have_eaten(philosophers_finished_eating, n))
        {
            printf("All philosophers have eaten !!! Successful completion !!!\n");
            return 0;
        }
    }
    printf(" A Deadlock is present\n");
}

