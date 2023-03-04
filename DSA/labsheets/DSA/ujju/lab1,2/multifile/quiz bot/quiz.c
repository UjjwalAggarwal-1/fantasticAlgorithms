#include <stdio.h>
#include "set.h"

int main(){

    printf("Enter your answers(A/B/C/D/N): \n");
    char ans[N];

    for (int i=0;i<N;i++){
        char ic;
        scanf("%c ",&ic);
        if (!(ic=='A' || ic=='B' || ic=='C' || ic=='D' || ic=='N')){
            printf("INVALID CHARACTER %c\n",ic);
            i--;
        }else{
            ans[i]=ic;
        }
    }
    
    for(int i=0;i<N;i++) printf("%c ",ans[i]);

    int result = answer_checker(ans);
    printf("%d\n", result);

    return 0;
}