#include <stdio.h>
#include <stdlib.h>


int main()
{

    FILE *fp = fopen("n_integers.txt", "r");

    int n;
    fscanf(fp, "%d", &n);
    printf("%d\n", n);
    char c, d;
    fscanf(fp, "%c", &c);
    fscanf(fp, "%c", &d);
    printf(" %c %c ", c, d);
    printf("\n");
    
    int arr[n];
    int i = 1;
    fscanf(fp, "%d", &arr[0]);
    char e = getc(fp);
    while (1)
    {   if (e == ']') break;
        while (1)
        {
            if (e == ']') break;
            printf("%c\n", e);
            fscanf(fp, "%d", &arr[i]);
            printf("%d", arr[i]);
            i++;
            e = getc(fp);
        }
        printf("\n");
    }
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}