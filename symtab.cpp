/* SYMTAB IMPLEMENTATION */


#include<iostream>
#include<string.h>
#define len 11


using namespace std;


struct hashtable{

    char label[20];
    int addr;

}ht[len];


void add_label()
{
    int addr;
    char label[20];

    std::cout << "\nEnter the label name ";
    std::cin >> label;
    std::cout << "\nEnter the label address ";
    std::cin >> addr;

    int loc = addr % len;
    if(ht[loc].addr == -1)
    {
        ht[loc].addr = addr;
        strcpy(ht[loc].label,label);
    }
    else{
           int ind = (addr+1) % len;
           while (loc != ind){
               if(ht[ind].addr == -1){
                   ht[ind].addr = addr;
                   strcpy(ht[ind].label,label);
                   break;
               }
               else{
                     ind = (++ind)%len;
               }
            
                
           }

           if (loc == ind)
           {
               std::cout << "\nHashTable is Full";
           }
    }


}


void display()
{   std::cout<<"\n"<<"ADRRESS"<<"  "<<"LABEL";
    for (int i = 0; i < len; i++)
    {
        if(ht[i].addr != -1)
        {
            std::cout<<"\n"<<ht[i].addr<<"  "<<ht[i].label;
        }

        else{
            std::cout<<"\n"<<"~"<<"  "<<"????";
        }
    }
}

void search()
{
    int addr;
    int loc;

    std::cout << "\nEnter the address of the label to search for ";
    std::cin >> addr;

    loc = addr % len;

    if (ht[loc].addr != addr)
    {
        loc = (loc+1)%addr;
        while((ht[loc].addr!=addr) && (loc != addr%len))
        {
            loc = (loc+1) % len;

        }
    }



    if (ht[loc].addr == -1)
    {
        std::cout << "\nLabel doesn't exist @ Specified Address";
    }
    else
    {
        std::cout << ht[loc].addr << "  " << ht[loc].label;
    }
}


void modify()
{
    int addr;
    int loc;
    char label[10];

    std::cout << "\nEnter the address of the label to be modified ";
    std::cin >> addr;

    loc = addr % len;

    if (ht[loc].addr != addr)
    {
        loc = (loc+1)%addr;
        while((ht[loc].addr!=addr) && (loc != addr%len))
        {
            loc = (loc+1) % len;

        }
    }



    if (ht[loc].addr == -1)
    {
        std::cout << "\nLabel doesn't exist @ Specified Address";
    }
    else
    {   

        std::cout << "\nEnter the new label ";
        std::cin >> label;
        strcpy(ht[loc].label,label);
        std::cout << ht[loc].addr << "  " << ht[loc].label;
    }
}


int main()
{
    for (int i = 0; i < len; i++)
    {
        ht[i].addr = -1;
        strcpy(ht[i].label," ");
    }
    
    while(1)
    {int ch;
    std::cout << "\nChoose from the below"<<"\n1.Add Labels to the Symtab"<<"\n2.View Symtab"<<"\n3.Search for a Label"<<"\n4.Modify "<<"\n5.Exit";
    std::cin >> ch;

    if(ch==1)
    {
        std::cout << "\nEnter number of labels to be added ";
        int n;
        std::cin >> n;

        for (int j = 0; j < n;j++)
        {
            add_label();
        }
    }

    if(ch==2)
    {
        display();
    }

    if(ch==3)
    {
        search();
    }

    if(ch==4)
    {
        modify();
    }

    if(ch==5)
    {
        return 0;
    }
}
}


