/******************************************************************/
/**Author: Jiayin Cai**********************************************/
/**Date: Feb 7, 2015***********************************************/
/**This program explains what is va_list and how to use it*********/
/******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h> //stdarg.h includes all the va_list function

//The function to compute the average of x numbers using va_list
//x stands for how many numbers will be input and '...' means this funciton use va_list
double average(int x,...)
{
    int i;
    va_list lst;    //va_list declares a list that stores a list of input numbers
    double sum = 0;
    va_start(lst,x);    //va_start initializes the list,accepts two arguments, a va_list type variable and the number of inputs
    for(i=0;i<x;i++)
    {
        sum += va_arg(lst,double);  //va_arg takes a va_list and a variable type, and returns the next argument in the list
    }
    va_end(lst);    //cleans up the variable argument list.
    return sum / x;
}

int main()
{
    printf("%0.0f\n",average(4,5,1.0,2.0,3.0,4.0,5.0));
    return 0;
}
