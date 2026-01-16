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
    fptr = fopen("log.txt","r");  // Opens the file for reading
    char line1[30];

    if(fptr == NULL)
    {
        printf("File open failed\n");
        return 1;
    }

    fgets(line1,sizeof(line1),fptr);
    printf("The line is \n %s\n",line1);

    fclose(fptr);
    return 0;
}
