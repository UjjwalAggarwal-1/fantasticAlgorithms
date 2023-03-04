#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *CreateNode(int data)
{
    struct node *n1 = malloc(sizeof(struct node));
    n1->data = data;
    n1->next = NULL;

    return n1;
}

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
    // struct node *arr[n] ;

    // for( int k = 0; k<n;k++)
    // {
    //         arr[k]= malloc(sizeof(struct node));

    // }

    // arr[n-1]->next = NULL;

    // for (int i = 0; i < n; i++)
    // {
    //     if(i<n-1)
    //     {arr[i]->next = arr[i+1];};

    //     fscanf(fp, "%d", &arr[i]->data);

    //     printf("%d->", arr[i]->data);
    // }
    int arr[n];
    int i = 1;
    fscanf(fp, "%d", &arr[0]);
    char e = getc(fp);
    while (e != ']')
    {
        while (e != '\n')
        {
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