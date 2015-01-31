/******************************************************************/
/**Author: Jiayin Cai**********************************************/
/**Date: Jan 31, 2015**********************************************/
/**This program explains what is link list and how to use it*******/
/**, also explains what is a recurion function*********************/
/******************************************************************/
#include <stdio.h>
#include <stdlib.h>


//define a ListNode
typedef struct Node {
  int x;
  struct Node *next;
}Node;

//display all values in a list
void displayLinkList(Node *head)
{
    while(head)
    {
        printf("%d\t",head->x);
        head = head->next;
    }
    printf("\n");
}

//sum all values in a list
int sumList(Node *root)
{
    if(root->next == 0)
    {
        return root->x;
    }
    return root->x + (sumList(root->next));
}

//compute n!
//return a double is more appropriate beacuse 17! is out of the range of int
double factorial(double n)
{
    if(n==0)
        return 1;
    return n * factorial(n-1);
}

//compute Fibonacci using recursion
int re_fibonacci(int n)
{
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    return re_fibonacci(n-1) + re_fibonacci(n-2);
}
//compute Fibonacci using loop
int loop_fibonacci(int n)
{
    int n0 = 0;
    int n1 = 1;
    if(n==0)
    {
        return 0;
    }
    int i = 1;
    int out=0;
    while(i<n)
    {
        out = n0 + n1;
        n0 = n1;
        n1 = out;
        i++;
    }
    return out;
}


int main()
{
    int i;
    //test the function of factorial
    double a = factorial(5);
    printf("%0.0f\n",a);
    printf("\n");
    ///////////////////////////////////////////////////////////////////
    //test the function of re_fibonacci and loop_fibonacci
    printf("The first 10 numbers in fibonacci sequence using re_fibonacci\n");
    for(i=0;i<10;i++)
    {
        printf("%d  ",re_fibonacci(i));
    }
    printf("\n");
    printf("The first 10 numbers in fibonacci sequence using loop_fibonacci\n");
    for(i=0;i<10;i++)
    {
        printf("%d  ",loop_fibonacci(i));
    }
    printf("\n");
    printf("\n");



    //build a link list with a for loop
    Node *root = malloc(sizeof(Node));
    Node *conductor = root;
    root->x = 0;
    for(i=0;i<10;i++)
    {
        conductor->x = i;
        if(i==9)
        {
            conductor->next = 0;
        }
        else
        {
            conductor->next = malloc(sizeof(Node));
            conductor = conductor->next;
        }
    }
    ////////////////////////////////////////////////////////////////////
    //tranverse the link list and display all values
    printf("Display linklist\n");
    conductor = root;
    while(conductor)
    {
        printf("%d\t",conductor->x);
        conductor = conductor->next;
    }
    printf("\n");
    printf("\n");
    ////////////////////////////////////////////////////////////////////
    //insert an element into link list after the fifth element
    int count = 1;
    conductor = root;
    while(conductor)
    {
        if(count == 5)
        {
            Node *tmp = malloc(sizeof(Node));
            tmp->x = 100;
            tmp->next = conductor->next;
            conductor->next = tmp;
            break;
        }
        conductor = conductor->next;
        count++;
    }
    /////////////////////////////////////////////////////////////////////
    //display the link list after inserting an element
    printf("Display linklist after inserting an element\n");
    displayLinkList(root);
    //display the sum of all values in link list
    printf("The sum of all values in link list is %d\n",sumList(root));
    printf("\n");
    //remove the fifth element from the list
    count = 1;
    conductor = root;
    while(conductor)
    {
        if(count == 5)
        {
            Node *tmp = conductor->next;
            conductor->next = tmp->next;
            free(tmp);
            break;
        }
        conductor = conductor->next;
        count++;
    }
    ////////////////////////////////////////////////////////////////////
    //display the linklist after removing an element
    printf("Display linklist after removing an element\n");
    displayLinkList(root);
    //display the sum of all values in link list
    printf("THe sum of all values in link list is %d\n",sumList(root));

    return 0;
}
