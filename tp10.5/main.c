/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: ivan
 *
 * Created on 24 de mayo de 2021, 18:16
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
void bitSet(void*, unsigned int, char);
void bitClr(void*, unsigned int, char);
/*int bitGet(puerto* p1, unsigned int bit);
void bitToggle(puerto* p1, unsigned int bit);
void maskOn(puerto* p1, char mask);
void maskOff(puerto* p1, char mask);
void maskToggle(puerto* p1, char mask);
*/

/*
 * 
 */


typedef struct
{
    int8_t B;
    int8_t A;
    
}portD;
 


int main(int argc, char** argv) 
{
    portD puertoD;
    puertoD.A = 0xFF;
    puertoD.B = 0xFF;
    //void * ptr = puertoD.A;
    bitClr(&puertoD, 15, 'D');
    printf("%x", puertoD.A);
    printf("%x", puertoD.B);
    
  //  00010002 00030004
  //     A        B
   /*
   
    00010002
    00030004
    
    
    
    */ 
            
            
            
            
    return (EXIT_SUCCESS);
}

void bitSet(void* ptr, unsigned int nro, char puerto)
{
    int16_t mascara;
    if (puerto == 'D')
    {
        mascara = (1 << nro);
        *(int16_t*)ptr = (*(int16_t*)ptr | mascara);
    }
    else
    {
        mascara = (1 << nro);
        *(int8_t*)ptr = (*(int8_t*)ptr | mascara);
    }

}

void bitClr (void* ptr, unsigned int nro, char puerto)
{
    int16_t mascara;
    if (puerto == 'D')
    {
        mascara = ~(1 << nro);
        *(int16_t*)ptr = (*(int16_t*)ptr & mascara);
    }
    else
    {
        mascara = ~(1 << nro);
        *(int8_t*)ptr = (*(int8_t*)ptr & mascara);
    }
}

char bitGet(void* ptr, unsigned int nro, char puerto)
{
    if(puerto == 'D')
    {
        
    }
}