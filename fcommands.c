//Test program of fcommands

#include <stdio.h>

int main(){
    FILE *fileToRead, *fileToWrite;
    fileToRead=fopen("input.txt","r");
    if (!fileToRead){
        return 1;
    }

    char buffer[1024];
    unsigned int bytesRead = fread(buffer,sizeof(char),1023,fileToRead);
    buffer[bytesRead]='\0';

    unsigned int wrote = fwrite(buffer,sizeof(char),1023,fileToWrite);

    fscanf(fileToRead,"%d",&wrote);
    fprintf(fileToWrite,"%d",wrote);

    fileToWrite=fopen("output.txt","w");
    if (!fileToWrite) {
        return 1;
    }

    fclose(fileToRead);
    fclose(fileToWrite);
    return 0;
}