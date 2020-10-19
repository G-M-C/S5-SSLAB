//Producer - Consumer Problem

#include<iostream>

using namespace std;

int main()
{
    int n;
    std::cout << "\nEnter the size of the buffer ";
    std::cin >> n;
    
    int buffer[n];
    int cnt = 0;
    int ch;

    while(1)
    {
        std::cout << "\nChoose from the following : "
                  << "\n1.Produce"
                  <<"\n2.Consume"
                  <<"\n3.Exit\n";
        
        std::cin >> ch;

        switch(ch)
        {
            case 1:
                if (cnt < n)
                {
                    int val;
                    std::cout << "\nEnter data to produce : ";
                    std::cin >> val;
                    buffer[cnt] = val;
                    cnt++;
                }

                else
                {
                    std::cout << "\nBuffer is full !!! Wait for data to be consumed!!!";
                }

                break;
            
            case 2:
                if(cnt > 0)
                { 
                    std::cout << "\nData Consumed : " << buffer[cnt-1];
                    cnt--;


                }

                else
                {
                    std::cout << "\nBuffer is empty !!! Wait for data to be produced!!! ";

                }
                break;

            case 3:
                return 0;
                
                

        }
    }

}
