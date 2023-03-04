#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void optiona(){
    printf("optiona\n");
}
void optionb(){
    printf("optionb\n");
}
void optionc(){
    printf("optionc\n");
}

void print_arr(int n, char* arr){
    for (int i=0;i<n;i++){
        printf("%s\n", (arr+20*i));
    }
}

int main()
{
    int n;
    printf("enter kar bhai n: ");
    scanf("%d",&n);

    char* arr = (char*) calloc(n, 20*sizeof(char));

    if (arr == NULL)
    {
    printf("Unable to allocate memory\n");
    return -1;
    }

    printf("Enter the strings: \n");
    for (int i = 0; i < n; i++)
    {
    scanf("%s", (arr+i));
    }

    print_arr(n, arr);

    // while(1){
    //     int x = 0;
    //     // char s[1];
    //     // scanf("%s", &s);
    //     printf("Enter option number:");
    //     int s;
    //     scanf("%d", &s);

    //     switch(s)
    //     {    
    //     case 1:   optiona(); break;
    //     case 2:   optionb(); break;
    //     case 3:   optionc(); break;
    //     case 4:   x = 1; break;
    //     default:    printf("Invalid option"); break;
        
    //     }    
    //     if(x) break;

    // }

}