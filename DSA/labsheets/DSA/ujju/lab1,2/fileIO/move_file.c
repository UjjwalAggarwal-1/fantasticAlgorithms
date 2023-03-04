#include <stdio.h>

int main(){

    FILE* fpmf = fopen("./move_from.txt", "rb+");
    if(fpmf == NULL)
    {
        printf("Error opening file move_from.txt!");
        return 1;
    }
    FILE* fpmt = fopen("./move_to.txt", "w+");
    if(fpmt == NULL)
    {
        printf("Error opening file move_to.txt!");
        return 1;
    }

    char s[2];
    while(fgets(s, 2, fpmf)){
        fprintf(fpmt, "%s",s);
        // fseek(fpmf, -1, SEEK_CUR);
        // fprintf(fpmf, "\b");
    }

    // rewind(fpmf);
    // fprintf(fpmf, " ");

    fclose(fpmf);
    fclose(fpmt);
    // instead write to the file
    FILE* fpmf2 = fopen("./move_from.txt", "w");
    fclose(fpmf2);
    printf("Finished moving\n");
    return 0;

}