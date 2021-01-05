// < PASS 2 OF A 2 PASS ASSEMBLER >
/* George M Cherian
    CS5A
    Roll No : 28
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>


int  main()
{
    FILE *fip, *ftab, *flen, *fsym;
    int i, j = 0, len;
    char add[5], symadd[5], op[5], start[10], label[20];
    char mnemonic[10], operand[10], symtab[10], opmnemonic[10];
    fip = fopen("input.txt", "r");
    flen = fopen("length.txt", "r");
    ftab = fopen("optab.txt", "r");
    fsym = fopen("symtab.txt", "r");
    fscanf(fip, "%s%s%s%s", add, label, mnemonic, operand);
    if (strcmp(mnemonic, "START") == 0)
    {
        strcpy(start, operand);
        fscanf(flen, "%d", &len);
    }
    printf("\nH^%s^%s^%d\nT^00%s^", label, start, len, start);
    fscanf(fip, "%s%s%s%s", add, label, mnemonic, operand);
    while (strcmp(mnemonic, "END") != 0)
    {
        fscanf(ftab, "%s%s", opmnemonic, op);
        while (!feof(ftab))
        {
            if (strcmp(mnemonic, opmnemonic) == 0)
            {
                fclose(ftab);
                fscanf(fsym, "%s%s", symadd, symtab);
                while (!feof(fsym))
                {
                    if (strcmp(operand, symtab) == 0)
                    {
                        printf("%s%s^", op, symadd);
                        break;
                    }
                    else
                        fscanf(fsym, "%s%s", symadd, symtab);
                }
                break;
            }
            else
                fscanf(ftab, "%s%s", opmnemonic, op);
        }
        if ((strcmp(mnemonic, "BYTE") == 0) || (strcmp(mnemonic, "WORD") == 0))
        {
            if (strcmp(mnemonic, "WORD") == 0)
                printf("0000%s^", operand);
            else
            {
                len = strlen(operand);
                for (i = 2; i < len; i++)
                {
                    printf("%d", operand[i]);
                }
                printf("^");
            }
        }
        fscanf(fip, "%s%s%s%s", add, label, mnemonic, operand);
        ftab = fopen("optab.txt", "r");
        fseek(ftab, SEEK_SET, 0);
    }
    printf("\nE^00%s\n\n", start);
    fclose(fip);
    fclose(ftab);
    fclose(fsym);
    fclose(flen);
    return 0;
}