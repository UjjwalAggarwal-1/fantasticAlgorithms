#include <stdio.h>

int main(){
    FILE* fptr = fopen(__FILE__, "r");
    if(fptr == NULL)
    {
        printf("Error opening file!");
        return 1;
    }
    // reading the file using fgets()
    char line[100];
    int i = 0;
    while(fgets(line, 100, fptr)){
        printf("%d\t%s", ++i, line);
    }printf("\n");

    //cant seem reading the file using fscnaf()
    // char line[100];
    // int i = 0;
    // while(fscanf(fptr, "%s", line)==1){
    //     printf("%d\t%s\n", ++i, line);
    // }printf("\n");

    fclose(fptr);
    return 0;
}