#include <stdio.h>

void enqueue(int q[], int *f, int *r, int l, int val)
{
    if(*r>=l-1)
    {
        printf("Overflow\n");
    }
    else
    {
        if(*f==-1)
        {
            (*f)++;
        }
        (*r)++;
        q[*r] = val;
    }
}

int dequeue(int q[], int *f, int *r, int l)
{
    int temp = 0;
    if(*r==-1)
    {
        printf("Underflow\n");
        temp = -1;
    }
    else
    {
        temp = q[*f];
        (*f)++;
        if((*f)-1==(*r))
        {
            *f = -1;
            *r = -1;
        }
    }
    return temp;
}

void display(int q[], int f, int r)
{
    while(f!=r)
    {
        printf("%d\n",q[f]);
        f++;
    }
    printf("%d\n",q[f]);
}

int main()
{
    int q[5];
    int l = 5, f = -1, r = -1;
    enqueue(q, &f, &r, l, 5);
    enqueue(q, &f, &r, l, 15);
    enqueue(q, &f, &r, l, 25);
    enqueue(q, &f, &r, l, 35);
    enqueue(q, &f, &r, l, 45);
    enqueue(q, &f, &r, l, 55);
    printf("Deleted Value: %d\n",dequeue(q, &f, &r, l));
    printf("Displaying Queue:\n");
    display(q, f, r);
    
    return 0;
}
