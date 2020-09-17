/* CSCAN Disk Scheduling*/


#include<iostream>
#include<vector>

using namespace std;

int CSCAN(std::vector<int> tracks,int head,int disk_size)
{
    int seek_operations = 0;
    int prev = head; 
    std::vector<int>::iterator i;
    std::vector<int> left,right;
    std::vector<int> seek_sequence;

    for(i = tracks.begin(); i != tracks.end(); i++)
    {
        if (*i < head)
        {
            left.push_back(*i);
        }

        if (*i > head)
        {
            right.push_back(*i);
        }
    }

    left.push_back(0);
    right.push_back(disk_size-1);

    std::sort(left.begin(),left.end());
    std::sort(right.begin(),right.end());



    for(i = right.begin(); i != right.end(); i++)
     {
         seek_sequence.push_back(*i);
         seek_operations += abs(*i-prev);
         prev = *i;
     }

    for(i = left.begin(); i != left.end(); i++)
    {
        seek_sequence.push_back(*i);
        seek_operations += abs(*i-prev);
        prev = *i;
    }

     

    std::cout<<"\nSeek Sequence (CSCAN) : \n";
    
    for(i = seek_sequence.begin(); i != seek_sequence.end(); i++)
    {
        std::cout << *i << " ";
    }

    return seek_operations;

}



int main()
{
    vector<int> tracks;
    int head;
    int size;
    int disk_size;
    int T;
    int seek_operations;

    std::cout << "\nEnter the no:of tracks  ";
    std::cin >> size;
    std::cout << "\nEnter the disk size  ";
    std::cin >> disk_size;
    std::cout << "\nEnter the Request Sequence ";

    for(int i=0;i<size;i++)
    {
       std::cin >> T;
        tracks.push_back(T);

    }

    std::cout << "\nEnter the initial head positon ";
    std::cin >> head;

    seek_operations = CSCAN(tracks,head,disk_size);

    std::cout << "\nTotal no:of seek operations : " << seek_operations << endl;

    return 0;









}

