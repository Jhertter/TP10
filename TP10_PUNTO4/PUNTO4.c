/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: ivan
 *
 * Created on May 19, 2021, 12:32 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/*
 * 
 */
void mi_printf(char string[], ...);
void hexa(int);
void integer(int);

int main(int argc, char** argv) {
    //printf("%x", 0xff);
    mi_printf("hola %x %d %c", 0xFACE, 6589710, '7');
    
    
    return (EXIT_SUCCESS);
}

void mi_printf(char string[], ...)
{
    va_list list;
    va_start(list, string);
    
    int i = 0;
    for (i=0; string[i] != 0; i++)
    {
        if(string[i] != '%')
            putchar(string[i]);
        else
        {
            switch(string[++i])
            {
                case '%':
                {
                    putchar('%');
                    break;
                }
                case 'x':
                {
                    hexa(va_arg(list, int)); //para cada uno de estos putchar hay que hacer una función que castee el parametro recibido a string
                    
                    break;
                }
                case 'd':
                {
                    integer(va_arg(list, int));
                    break;
                }
                case 'c':
                {
                    putchar(va_arg(list, int));
                    break;
                }
            }
        }
    }
    va_end(list);
}

void hexa (int arg)
{
    if(arg<0)
    {
        putchar('-');
        arg *= -1;
    }
          
    if(arg < 16)
    {
        if (arg > 9 && arg < 16)
        {
            putchar('A'+(arg-10));
        }
        else
        {
            putchar(arg);
        }
    }
    else
    {
        hexa(arg/16);
        
        if (arg%16 > 9)
        {
            putchar('A'+(arg%16-10));
        }
        else
        {
            putchar((arg%16)+'0');
        }
    }
}

void integer(int arg)
{
    if(arg < 10)
    {
        putchar(arg+'0');
    }
    else
    {
        integer(arg/10);
        putchar((arg%10)+'0');
    }
}
