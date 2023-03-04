#include "set.h"

int answer_checker(char* answers){
    char soln[N] = {'A','A','A','A','A','A','A','A','A','A'};

    int sum = 0;
    for (int i=0;i<N;i++){
        if (answers[i]==soln[i]){
            sum +=4;
        }else if(answers[i]=='N'){

        }else{
            sum--;
        }
    }
    return sum;
}