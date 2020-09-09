/*
    Single Level Directory Organization
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct DIR
{
    char dname[15];
    char fname[20][20];
    int filecnt;
};

int main()
{
    int i,ch;
    char file[20];
    struct DIR dir;
    dir.filecnt=0;
    strcpy(dir.dname,"root");
    while(1)
    {
    printf("\nEnter your choice\t1.Create File\t2.Delete File\t3.Search File\t4.Display Files\t5.Exit  ");
    scanf("%d",&ch);

    if(ch==1)
    {
        int num;
        printf("\nEnter the number of files to be created ");
        scanf("%d",&num);
        for(i=0;i<num;i++)
        {
            printf("\nEnter the file name ");
            scanf("%s",dir.fname[dir.filecnt]);
            dir.filecnt+=1;


        }

    }
    else if(ch==2)
    {
        printf("\nEnter the name of the file to be deleted ");
        scanf("%s",file);
        for(i=0;i<dir.filecnt;i++)
        {
            if (strcmp(dir.fname[i],file)==0)
            {   printf("\nFile %s has been deleted",file);
                for(int j=i+1;j<dir.filecnt;j++)
                {  
                    strcpy(dir.fname[j-1],dir.fname[j]);
                    
                }
                break;
            }
        }
        if(i==dir.filecnt)
        {
            printf("\nFile %s is not found",file);
        }
        else
        {
           dir.filecnt-=1;
        }
    }

    else if(ch==3)
    {
        printf("\nEnter the file to be searched for ");
        scanf("%s",file);
        
        for(i=0;i<dir.filecnt;i++)
        {
            if(strcmp(file,dir.fname[i])==0)
            {
                printf("\nFile %s is found",file);
                break;
            }
        }

        if(i==dir.filecnt)
        {
            printf("\nFile %s is not found",file);
        }


    }

    else if(ch==4)
    {
        printf("\n~%s",dir.dname);
        for(i=0;i<dir.filecnt;i++)
        {
            printf("\n    |%s",dir.fname[i]);
        }
    }

    else if(ch==5)
    {
        return 0;
    }





    

    }
    }





