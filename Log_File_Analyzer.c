#include <stdio.h>
#include <stdlib.h>


struct LogEntry
{
    char Timestamp[20];
    char level[10];
    char module[10];
    char message[256];
};

int main()
{
    FILE *fptr;
    char line1[100];
    struct LogEntry *Loglist;
    struct LogEntry *tmp;
    int ch;
    int i=0;
    int element=1;
    int j = 0;

    fptr = fopen("log.txt","r");  // Opens the file for reading
    if(fptr == NULL)
    {
        printf("File open failed\n");
        return 1;
    }

    Loglist = malloc(sizeof(struct LogEntry));
    if(Loglist == NULL)
    {
        printf("Memory allocation failed\n");
        fclose(fptr);
        return 1;
    }

    while((ch = fgetc(fptr)) != EOF)
    {
        if(ch == ' ')
        {
            element++;
            i = 0;
            continue;
        }
        if(ch == '\n')
        {
            j++;
            tmp = realloc(Loglist,(j+1)*sizeof(struct LogEntry));
            if(tmp != NULL)
            {
                free(Loglist);
                Loglist = tmp;
            }
            element = 1;
            i = 0;
            continue;
        }
        switch(element)
        {
            case 1 :
            {
            Loglist[j].Timestamp[i]=ch;
            i++;
            break;
            }

            case 2 :
            Loglist[j].level[i] = ch;
            i++;
            break;

            case 3 :
            Loglist[j].module[i]=ch;
            i++;
            break;

            case 4 :
            Loglist[j].message[i]=ch;
            i++;
            break;

            default:
            printf("Unknown case");
        }
    }

    i = 0;
    while(j != 0)
    {
        printf("Timestamp: %s \n Level: %s \n Module: %s \n Message: %s \n",Loglist[i].Timestamp,
        Loglist[i].level,Loglist[i].module,Loglist[i].message);
        printf("---------------------------\n");
        j--;
        i++;
    }

    free(Loglist);

    // fgets(line1,sizeof(line1),fptr);
    // printf("The line is \n %s\n",line1);
    // fgets(line1,sizeof(line1),fptr);
    // printf("The line is \n %s\n",line1);


    fclose(fptr);
    return 0;
}
