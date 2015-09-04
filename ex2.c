/* ************************************************************************ *
 *    ex2.c, v1.0                                                           *
 *    Programa feito para criar uma variavel de 128 bits para calcular      *
 *    se um certo numero grande é primo                                     *
 *                                                                          *
 *    Copyright (C) 2015                                                    *
 *    Felipe José Alexandrino Calado                                        *
 *    Hugo Albuquerque de Fonsêca                                           *
 *    Lucas Canejo Jurema                                                   *
 *    Mateus Lenier Rezende                                                 *
 *    Paulo Vitor Alves Patriota                                            *
 *    Thayna Maria Morim de Barros Barreto                                  *
 *                                                                          *
 *    This program is free software; you can redistribute it and/or modify  *
 *    it under the terms of the GNU General Public License as published by  *
 *    the Free Software Foundation; either version 2 of the License, or     *
 *    (at your option) any later version.                                   *
 *                                                                          *
 *    This program is distributed in the hope that it will be useful,       *
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *    GNU General Public License for more details.                          *
 *                                                                          *
 *    You should have received a copy of the GNU General Public License     *
 *    along with this program; if not, write to the                         *
 *    Free Software Foundation, Inc.,                                       *
 *    59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 *                                                                          *
 *    To contact the author, please write to:                               *
 *    Felipe José Alexandrino Calado  <lipecalado@gmail.com>                *
 *    Phone: 55 (819) 9521-3911                                             *
 *                                                                          *
 *    Hugo Albuquerque de Fonsêca <hugoalbuquerque0@gmail.com>              *
 *    Phone: 55 (819) 9875-6561                                             *
 *                                                                          *
 *    Lucas Canejo Jurema <lucasbrgol2010@hotmail.com>                      *
 *    Phone: 55 (819) 9547-1048                                             *
 *                                                                          *    
 *    Mateus Lenier Rezende <mateuslenier@gmail.com>                        *
 *    Phone: 55 (819) 9891-2596                                             *
 *                                                                          *
 *    Paulo Vitor Alves Patriota <paulovitorpatriota@gmail.com>             *
 *    Phone: 55 (819) 9966-1154                                             *
 *                                                                          *
 *    Thayna Maria Morim de Barros Barreto <tmorimbarreto@gmail.com>        *
 *    Phone: 55 (819) 9746-8034                                             *
 *                                                                          *
 *                                                                          *
 *                                                                          *       
 * ************************************************************************ *
 * 
 */
/**
 * \file ex2.c
 * \brief 
 * \author Your Name Here
 * \version 
 * \date 2015-09-04
 */
/**
 * \name 
 * @{ */
/**  @} */


#include <stdio.h>
#include <stdlib.h>

#define MAXULLONG "340282366920938463463374607431768211455"
#define MAXLONG 18446744073709551615
#define BUFFER 4

typedef struct sl
{
    unsigned long h;
    unsigned long l;
} ullong;

int ulet(char *in, ullong *out);
int div2(char *in, char *out);
int uadd(ullong *a, ullong *b, ullong *c);

int main(void)
{
    ullong x, y, z;
    char a[] = "7", b[] = "4";
    if(ulet(a,&x))
        printf("x estourou\n");
    if(ulet(b,&y))
        printf("y estourou\n");
    if(uadd(&x,&y,&z))
        printf("OVERFLOW!\n");
    printf("x: %lu | %lu\ny: %lu | %lu\nz: %lu | %lu\n",x.l,x.h,y.l,y.h,z.l,z.h);
    /*ulet(&x,"170141183460469231731687303715884105726");
    ulet(&y,"170141183460469231731687303715884105723");
    uadd(&x,&y,&z);
    printf("Aritmetica de exemplo: \n");
    ulprint(x);
    printf(" + ");
    ulprint(y);
    printf(" = ");
    ulprint(z);
    printf("\n");*/
    return EXIT_SUCCESS;
}

int ulet(char *in, ullong *out)
{
    int i = 0;
    int c;
    out->l = 0;
    out->h = 0;
    while(*in != '\0' && i < BUFFER)
    {
        c = div2(in,in);
        if(i<BUFFER/2)
            out->l |= (c << i);
        else
            out->h |= (c << (i-BUFFER/2));
        ++i;
    }
    if(*in != '\0')
        return 1;
    return 0;
}

int div2(char *in, char *out)
{
    int nval = 0, aval;
    int f = 1;
    if((*in-'0')/2)
        f = 0;
    while(*in != '\0')
    {
        aval = nval;
        nval = 0;
        if(*in%2)
            nval = 5;
        *out = (*in - '0')/2 + aval + '0';
        ++in;
        if(f)
            f = 0;
        else
            ++out;
    }
    *out = '\0';
    return (nval/5);
}

int uadd(ullong *a, ullong *b, ullong *c)
{
    unsigned carry = 1, i = 0;
    unsigned long x, y;
    c->l = 0;
    c->h = 0;
    x = a->l;
    y = b->l;
    while(i < BUFFER/2 && carry == 1)
    {
        i++;
        c->l = x ^ y;
        carry = (x & y);
        if(i != (BUFFER/2))
            carry = carry << 1;
        x = c->l;
        y = carry;
    }
    x = a->h;
    y = b->h;
    i = 0;
    if(carry)
        carry = 1;
    i++;
    c->h = x ^ y;
    carry = (x & y);
    if(i != (BUFFER/2))
         carry = carry << 1;
    x = c->h;
    while(i < BUFFER/2 && carry == 1) 
    {
        i++;
        c->h = x ^ y;
        carry = (x & y);
        if(i != (BUFFER/2))
            carry = carry << 1;
        x = c->h;
    }
    if(carry)
        carry = 1;
    return carry;
}
