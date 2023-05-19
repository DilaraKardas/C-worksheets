#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

int main(int argc, char* argv[])
{
    for(int i=0; i<argc; i++)
        printf("%s\n", argv[i]);

    char dizinadi[100];
    strcpy(dizinadi, "./");
    strcat(dizinadi, argv[1]);
    puts(dizinadi);

    mkdir(dizinadi);
    return 0;
}
