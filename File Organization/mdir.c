/*
    Two Level Directory Organization
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
    int i,ch,j,k;
    char file[20],d[20];
    struct DIR dir[10];
    int dircnt=0;

    while(1)
    {
    printf("\nEnter your choice\t1.Create Directory\t2.Create File\t3.Delete File\t4.Search File\t5.Display Files\t6.Exit ");
    scanf("%d",&ch);


    if (ch==1)
    {
        printf("\nEnter the username ");
        scanf("%s",dir[dircnt].dname);
        dir[dircnt].filecnt=0;
        dircnt+=1;
        printf("\nUser has been created");
    }

    else if(ch==2)
    {
        printf("\nEnter the name of the User ");
        scanf("%s",d);
        for(i=0;i<dircnt;i++)
        {
            if(strcmp(dir[i].dname,d)==0)
            {
                int num;
                printf("\nEnter the no:of files to be created");
                scanf("%d",&num);
                for(j=0;j<num;j++)
                {
                    printf("\nEnter the file name");
                    scanf("%s",file);
                    strcpy(dir[i].fname[j],file);
                }

                printf("\nFile(s) have been created ");
                dir[i].filecnt+=num;
                break;


            }

        }
        if(i==dircnt)
        {
            printf("\nUser doesn't exist");
        }
    }

    else if(ch==3)
    {
        printf("\nEnter the user whose file should be deleted ");
        scanf("%s",d);
        for(i=0;i<dircnt;i++)
        {
            if(strcmp(dir[i].dname,d)==0)
            {
                printf("\nEnter the name of the file to be deleted ");
                scanf("%s",file);
                for(j=0;j<dir[i].filecnt;j++)
                {
                    if(strcmp(dir[i].fname[j],file)==0)
                    {
                        printf("\nFile %s has been deleted",file);
                        for(k=j+1;k<dir[i].filecnt;k++)
                        {
                            strcpy(dir[i].fname[k-1],dir[i].fname[k]);
                        }
                        if(j==(dir[i].filecnt)-1)
                        {
                            j+=1;
                        }
                        dir[i].filecnt-=1;
                        break;
                        
                    }
                }
                if(j==dir[i].filecnt)
                {
                    printf("\nFile not found");
                }
                break;
            }
        }
        if(i==dircnt)
        {
            printf("\nUser not found");
        }
    }

    else if(ch==4)
    {
        printf("\nEnter the file to be searched for ");
        scanf("%s",file);
        int flag=0;

        for(i=0;i<dircnt;i++)
        {
            for(j=0;j<dir[i].filecnt;j++)
            {
                if(strcmp(dir[i].fname[j],file)==0)
                {
                    printf("\nFile %s is present with User %s",file,dir[i].dname);
                    flag+=1;
                    break;
                }
            }
        }

        if(flag==0)
        {
            printf("\nThe file %s couldn't be found with any users",file);
        }
        


    }

    else if(ch==5)
    {
        if(dircnt==0)
        {
            printf("\nNo Users found");
        }
        else
        { 
            for(i=0;i<dircnt;i++)
            {
                printf("\n~%s",dir[i].dname);
                if(dir[i].filecnt==0)
                {
                    printf(" Empty");
                    continue;
                }
                for(j=0;j<dir[i].filecnt;j++)
                {
                    printf("\n     |%s",dir[i].fname[j]);
                }

            }
        }
        
    }

    else if(ch==6)
    {
        return 0;
    }


    }
    }





