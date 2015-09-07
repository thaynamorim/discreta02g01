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
 * \brief programa que cria uma variavel de 128 bits e verificar se e primo 
 * \author Felipe José Alexandrino Calado <<lipecalado@gmail.com>>   
 * \author Hugo Albuquerque de Fonsêca <<hugoalbuquerque0@gmail.com>>
 * \author Lucas Canejo Jurema <<lucasbrgol2010@hotmail.com>>
 * \author Mateus Lenier Rezende <<mateuslenier@gmail.com>>
 * \author Paulo Vitor Alves Patriota <<paulovitorpatriota@gmail.com>>
 * \author Thayna Maria Morim de Barros Barreto <<tmorimbarreto@gmail.com>>  
 * \version 1.0
 * \date 2015-09-04
 */
/**
 * \ 
 * @{ */
/**  @} */


#include <stdio.h>
#include <stdlib.h>

#define MAXULLONG "340282366920938463463374607431768211455"
#define MAXLONG 18446744073709551615
#define BUFFER 128

typedef struct sl
{
    unsigned long h;
    unsigned long l;
} ullong;

int ulet(char *in, ullong *out);
int div2(char *in, char *out);
int uadd(ullong *a, ullong *b, ullong *c);
int usub(ullong *x,ullong *y,ullong *z);
int umult(ullong *a, ullong *b, ullong *c);
int udiv(ullong *n, ullong *d,ullong *r);
void ulprint(ullong *n);
void lutoa(unsigned long n, char *ch);
void mul2(char *in, char *out);
void sadd(char *a, char *b, char *c);

int main(void)
{
    ullong x, y, z;
    //if(ulet("170141183460469231731687303715884105726",&x))
    if(ulet("21",&x))
        printf("x estourou\n");
   // if(ulet("170141183460469231731687303715884105729",&y))
    if(ulet("7",&y))
        printf("y estourou\n");
    ulprint(&x);
    printf(" + ");
    ulprint(&y);
    printf(" = ");
    int i=uadd(&x,&y,&z);
    ulprint(&z);
    printf("[%d]\n",i);
    ulprint(&x);
    printf(" - ");
    ulprint(&y);
    printf(" = ");
    i=usub(&x,&y,&z);
    ulprint(&z);
    printf("[%d]\n",i);
    ulprint(&x);
    printf(" x ");
    ulprint(&y);
    printf(" = ");
    i=umult(&x,&y,&z);
    ulprint(&z);
    printf("[%d]\n",i);
    ulprint(&x);
    printf(" / ");
    ulprint(&y);
    printf(" = ");
    i=udiv(&x,&y,&z);
    ulprint(&z);
    printf("[%d]\n",i);
    return EXIT_SUCCESS;
}

int ulet(char *in, ullong *out)
{
    char ch[BUFFER];
    int i = 0;
    unsigned long c;
    while(*in != '\0')
    {
        ch[i] = *in;
        ++in;
        ++i;
    }
    ch[i] = '\0';
    i = 0;
    out->l = 0;
    out->h = 0;
    while(*ch != '\0' && i < BUFFER)
    {
        c = div2(ch,ch);
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
    unsigned long carry = 1, transfer = 0, ht = 0, tt = 0;
    unsigned long x, y;
    c->l = 0;
    c->h = 0;
    x = a->l;
    y = b->l;
    while(carry && ~transfer)
    {
        c->l = x ^ y;
        carry = (x & y);
        if(carry >> (BUFFER/2-1))
            transfer = 1;
        carry = carry << 1;
        x = c->l;
        y = carry;
    }
    x = a->h;
    y = b->h;
    carry = 1;
    while(carry && ~ht) 
    {
        c->h = x ^ y;
        carry = (x & y);
        if(carry >> (BUFFER/2-1))
            ht = 1;
        carry = carry << 1;
        x = c->h;
        y = carry;
    }
    y = transfer;
    while(transfer && ~tt) 
    {
        c->h = x ^ y;
        transfer = (x & y);
        if(transfer >> (BUFFER/2-1))
            tt = 1;
        transfer = transfer << 1;
        x = c->h;
        y = transfer;
    }
    if(tt||ht)
        return 1;
    return 0;
}

int udiv(ullong *n, ullong *d, ullong *r)
{
    r->l = 0;
    r->h = 0;
    if((d->h > n->h) || ((d->h == n->h) && (d->l >n->l)))
        return 1;
    if((d->l == n->l) && (d->h == n->h))
    {
        r->l = 1;
        return 0;
    }
    ullong i,j,k;
    i.l = n->l;
    i.h = n->h;
    while((i.h >= d->h) || ((i.h == d->h) && (i.l >= d->l)))
    {
        printf("!\n");
        //printf("%lu - %lu = ",i.l, d->l);
        usub(&i,d,&j);
        //printf("%lu\n",j.l);
        i.l = j.l;
        i.h = j.h;
        j.l = 1;
        j.h = 0;
        uadd(r,&j,&k);
        r->l = k.l;
        r->h = k.h;

    }
    if(i.l || i.h)
        return 1;
    return 0;
}
int umult(ullong *a, ullong *b, ullong *c)
{
    unsigned long i=0;
    ullong utemp;
    int err=0;

    c->l = 0;
    c->h = 0;

    for(i=0;i<(b->l);i++)
    {
        err |= uadd(c,a,&utemp);
        c->l = utemp.l;
        c->h = utemp.h;
        if(err)
            break;
    }
    for(i=0;i<(b->h);i++)
    {
        err |= uadd(c,a,&utemp);
        c->l = utemp.l;
        c->h = utemp.h;
        if(err)
            break;
    }
    return err;
}

int usub(ullong *x,ullong *y,ullong *z) 
{
    ullong w;
    w.l = y->l;
    w.h = y->h;
    if((y->h > x->h) || ((y->h == x->h) && (y->l >x->l)))
    {
        z->l=0;
        z->h=0;
        return 1;
    }
    if((y->h == x->h) && (y->l == y->h))
    {
        z->l=0;
        z->h=0;
        return 0;
    }
    w.l=~w.l + 1;
    w.h=~w.h;
    uadd(x,y,z);
    return 0;
}

void ulprint(ullong *n)
{
    if(n->h == 0)
    {
        printf("%lu",n->l);
        return;
    }
    char l[BUFFER] = "", h[BUFFER] = "", t[BUFFER] = "";
    unsigned i, j;
    if(n->l)
        lutoa(n->l,l);
    lutoa(n->h,t);
    for(i=0;i<BUFFER/2;i++)
    {
        mul2(t,h);
        for(j=0;j<BUFFER;j++)
        {
            t[j] = h[j];
            if(t[j] == '\0')
                break;
        }
    }
    if(n->l == 0)
    {
        printf("%s",h);
        return;
    }
    /*numero de digitos do high >= numero de digitos do low (decimal)*/
    sadd(h,l,t);
    printf("%s",t);
    return;
}

void lutoa(unsigned long lu, char *ch)
{
    unsigned long n = lu, d, i = 1;
    while(n >= 10)
    {
        n /= 10;
        i *= 10;
    }
    n = lu;
    while(n)
    {
        d = n / i;
        *ch = d + '0';
        n %= i;
        i /= 10;
        ++ch;
    }
    *ch = '\0';
	return;
}

void mul2(char *in, char *out)
{
    int nval = 0, aval, i = 0;
    if(((*in-'0')*2) >= 10)
    {
        *out = '1';
        ++out;
    }
    while(*in != '\0')
    {
        ++in;
        ++out;
        ++i;
    }
    *out = '\0';
    while(i)
    {
        --in;
        --out;
        --i;
        aval = nval;
        if(((*in - '0')*2) >= 10)
        {
            *out = (*in - '5')*2 + aval + '0';
            nval = 1;
        }
        else
        {
            *out = (*in - '0')*2 + aval + '0';
            nval = 0;
        }
    }
    return;
}

void sadd(char *a, char *b, char *c) //assumindo n de digitos de a > b
{
    int i = 0, s = 0, carry = 0, j = 0;
    while(*a != '\0')
    {
        *c = *a;
        ++a;
        ++c;
        ++j;
    }
    *c = '\0';
    while(*b != '\0')
    {
        ++b;
        ++i;
    }
    while(i)
    {
        --i;
        --j;
        --c;
        --b;
        s = *c - '0' + *b - '0' + carry;
        if(s>=10)
        {
            carry = 1;
            s %= 10;
        }
        else
            carry = 0;
        *c = s + '0';
    }
    while(j)
    {
        --c;
        --j;
        if(carry)
        {
            *c += carry;
            carry = 0;
        }
    }
    return;
}




