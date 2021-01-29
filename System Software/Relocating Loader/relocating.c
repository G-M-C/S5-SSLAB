#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char add[6],length[10],input[10],bitmask[12],relocbit;
    int start,len,i,opcode,address,addr,actualadd;

    FILE *fp1,*fp2;

    printf("\nEnter the starting address");
    scanf("%d",&start);

    fp1 = fopen("relinput.txt","r");
    fp2 = fopen("reloutput.txt","w");

    fscanf(fp1,"%s",input);

    while(strcmp(input,"E")!=0)
    {
        if(strcmp(input,"H")==0)
        {
            fscanf(fp1,"%s",add);
            fscanf(fp1,"%s",length);
            fscanf(fp1,"%s",input);
        }

        if(strcmp(input,"T")==0)
        {
            fscanf(fp1,"%d",&address);
            fscanf(fp1,"%s",bitmask);

            address += start;
            len = strlen(bitmask);

            for(i=0;i<len;i++)
            {
                relocbit = bitmask[i];
                fscanf(fp1,"%d",&opcode);
                fscanf(fp1,"%d",&addr);

                if(relocbit=='0')
                {
                   actualadd = addr;
                }

                else{

                    actualadd = addr + start;
                }
                fprintf(fp2,"\t%d\t%d%d\n",address,opcode,actualadd);
                address += 3;
            }

            fscanf(fp1,"%s",input);


        }
    }
    fclose(fp1);
    fclose(fp2);
    printf("\nFiniished");
    return 0;

}