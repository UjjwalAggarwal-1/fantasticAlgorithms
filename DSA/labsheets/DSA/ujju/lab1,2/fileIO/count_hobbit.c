#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){

    FILE *fptr;
    fptr = fopen("LOTR.txt", "r");
    if (fptr == NULL)
    {
    printf("Error opening file");
    exit(1);
    }
    int i = 0;
    char str1[200];
    char hobbit[6] = "hobbit";
    int flag = 0;
    while(fscanf(fptr, "%s", str1)==1){

        //useful things
        // printf("%d %s \n",i, str1);
        // printf("%ld \n", strlen(str1));
        // printf("%c ", toupper(str1[10]));
        // printf("%c ", tolower(str1[10]));
        
        if ((strlen(str1) < 6 )) continue;
        flag = 0;
        
        if (strlen(str1) == 6 ){
            for (int k = 0;k<6;k++){
                if(!((char)tolower(str1[k])==hobbit[k])){
                    flag = 1;break;
                }
            }
        }else{
        for (int k = 0;k<strlen(str1)-5;k++){
            char c = str1[k];
            // printf("%d %c ", k,c);
            // printf("%d ", k);
            // printf("%d char hai %c \n",k, c);
            if (c !='h') continue;
            
            for (int k2 = 0;k2<6;k2++){
                flag = 0;
                // printf("%c %c \n", (char)tolower(str1[k+k2]), hobbit[k2]);
                if(!((char)tolower(str1[k+k2])==hobbit[k2])){
                    flag = 1;break;
                }
            }
            if (!flag) i++;
        }
        }
    }
    printf("%d\n", i);
    return 1;
}