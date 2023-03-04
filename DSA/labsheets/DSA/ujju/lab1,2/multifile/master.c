#include <stdio.h>
#include "count.h"

int main(void)
{
    char s[100];
    printf("Enter a string: ");
    scanf("%[^\t]", s);
    int n = count(s);
    printf("Count = %d\n", n);
}
