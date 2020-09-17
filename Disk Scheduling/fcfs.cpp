/* FCFS Disk Scheduling*/


#include<iostream>
#include<vector>

using namespace std;

int FCFS(std::vector<int> tracks,int head)
{
    int seek_operations = 0;
    int prev = head; 
    std::vector<int>::iterator i;
    std::cout<<"\nSeek Sequence (FCFS) : \n";
    
    for(i = tracks.begin();i!=tracks.end();i++)
    {
        seek_operations+=abs(*i - prev);
        prev = *i;
        std::cout << *i << " ";


    }

    return seek_operations;

}



int main()
{
    vector<int> tracks;
    int head;
    int size;
    int T;
    int seek_operations;

    std::cout << "\nEnter the no:of tracks  ";
    std::cin >> size;
     std::cout << "\nEnter the Request Sequence ";

    for(int i=0;i<size;i++)
    {
       std::cin >> T;
        tracks.push_back(T);

    }

    std::cout << "\nEnter the initial head positon ";
    std::cin >> head;

    seek_operations = FCFS(tracks,head);

    std::cout << "\nTotal no:of seek operations : " << seek_operations << endl;

    return 0;









}

