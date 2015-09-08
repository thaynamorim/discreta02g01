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
int udiv(ullong *n, ullong *d);
void ulprint(ullong *n);
void lutoa(unsigned long n, char *ch);
void mul2(char *in, char *out);
int isprime (ullong *n);
void sadd(char *a, char *b, char *c);


int main(void)
{
    ullong x, y, z;
    //if(ulet("170141183460469231731687303715884105726",&x))
    if(ulet("2157892357238957",&x))
        printf("x estourou\n");
    // if(ulet("170141183460469231731687303715884105729",&y))
    if(ulet("6",&y))
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
    //i=udiv(&x,&y,&z);
    //ulprint(&z);
    printf("[Under construction!]");
    printf("[%d]\n",i);
    return EXIT_SUCCESS;
}

/**
 * \ingroup GroupUnique
 *    
 * \brief transforma de string pra ullong.
 * 
 * \details esta função pega um valor grande de string grande e coloca em uma variavel tipo ullong. 
 *
 * \param[in] char numero escrito por extenso.
 *             
 * \param[out] ullong 
 *                 
 * \retval 0 problema resolvido.
 *                     
 * \retval 1 problema com overflow ou underflow.
 *                                                      
 */

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


/**
 *
 * \ingroup GroupUnique
 *
 * \brief Esta funcao divide um numero por dois. 
 *
 * \details A funcao recebe um strig de numero e o divide por dois.
 *
 * \pre A variavel \a out precisa ter o mesmo numero de digitos que a variavel \a in.
 *
 * \param[in] in A variavel \a in e uma strig de entrada que e dividida por 2 
 * 
 * \param[out] out A variavel \a out recebe o valor da variavel \a in.
 *
 * \retval 0 Se a divisao nao tiver resto.
 * 
 * \retval 1 Se a divisao tiver resto.
 *
 */

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

/**
 * \ingroup GroupUnique
 * 
 * \brief Esta funcaoo soma duas variaveis ullong.
 * 
 * \details Soma duas variaveis ullong e da o resultado.
 * 
 * \param[in] a A variavel \a a  Primeiro numero da soma.
 *  
 * \param[in] b A variavel \a b Segundo numero da soma.
 *
 * \param[out] c A variavel \a c Resultado da soma de a e b.
 * 
 * \retval 0 problema resolvido.
 * 
 * \retval 1 problema com overflow.
 *   
 */

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


/**
 *
 * \ingroup GroupUnique
 *
 * \brief Esta funcao divide dois numeros. 
 *
 * \details A funcao divide um long por outro e retorna o valor da divisao inteira.
 *
 * \param[in] n A variavel \a dividendo armazena o valor do dividendo.  
 * \param[in] d  A variavel \a divisor armazeno o valor do divisor.
 *
 * \retval 0 Se a divisao nao tiver resto.
 * 
 * \retval 1 Se a divisao tiver resto.
 *
 **/

int udiv(ullong *n, ullong *d)
{
    return 0;
}

/**
 *  \ingroup GroupUnique
 *
 *  \brief Multiplica 2 variaveis ullong.
 *
 *  \details  Multiplica a variavel a pela variavel b dando c como resultado.
 *
 *  \param[in] a A variavel \a a primeiro numero da multiplicacao.
 *
 *  \param[in] b A variavel \a b segundo numero da multiplicacao.
 *
 *  \param[out] c A variavel \a c resultado da multiplicacao entre a e b.
 *
 *  \retval 0 problema resolvido.
 *
 *  \retval 1 problema com overflow.
 *
 */

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


/**
 *
 * \ingroup GroupUnique
 *
 * \brief Essa funcao subtrai um numero de outro.
 *
 * \details Atraves de operacoes binarias a funcao subtrai dois numeros.
 *
 * \param[in] x A variavel \a x recebe o minuendo.
 * 
 * \param[in] y A variavel \a out recebe o subtraendo.
 *
 * \param[out] z A variavel \a z armazena o valor da subtracao.
 *
 * \retval 0 Se a variavel \a x for maior que a \a y.
 * 
 * \retval 1 Se a variavel \a x for menor que a \a y.
 *
 **/

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
    w.l = ~w.l + 1;
    w.h = ~w.h;
    uadd(x,&w,z);
    return 0;
}


/**
 *
 * \ingroup GroupUnique
 *
 * \brief Esta funcao imprime o numero. 
 *
 * \details A funcao concatena o high e o low e imprime o numero.
 *
 * \param[in] n  Recebe o valor de entrada. \a
 * 
 * \retval void A funcao em si nao retorna nada.
 *
 **/

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

/**
 * \ingroup GroupUnique
 * 
 * \brief Converte unsigned long para string.
 * 
 * \details Esta funcao converte uma variavel unsigned long para uma string.
 * 
 * \param[in] lu A variavel \a lu vairavel unsigned long para ser convertida
 * 
 * \param[out] ch 
 * 
 * \retval void A funcao em si nao retorna nada.
 *
 */

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


/**
 *
 * \ingroup GroupUnique
 *
 * \brief Esta funcao multiplica um numero por 2.
 *
 * \details A funcao recebe um string de numero e a multiplica por dois.
 *
 * \pre E uma funcao interna da lprint.
 *
 * \param[in] in  A variavel \a in e a string de entrada que e multiplicada por 2.
 * 
 * \param[out] out A variavel \a out recebe o valor da variavel \a in multiplicada por dois.
 *
 * \retval void A funcao em si nao retorna nada.
 * 
 *
 **/

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

/**
 * \ingroup GroupUnique
 * 
 * \brief soma 2 numeros em string.
 *  
 * \details Soma 2 numeros a e b em formato de string e da o resultado c.
 * 
 * \param[in] a A string \a a primeiro numero da soma. 
 * 
 * \param[in] b A string \a b segundo numero da soma.
 *
 * \param[out] c Resultado da soma.
 * 
 * \retval 0 problema resolvido.
 * 
 * \retval 1 problema com overflow.
 * 
 */ 

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


/**
 * \ingroup GroupUnique
 * 
 * \brief Verifica se um numero ullong e primo
 * 
 * \details Esta funcao executa um algoritmo de verificacao de numero primo atraves de operacoes binarias.
 * 
 * \param[in] n A variavel \a *n eh o numero a ser verificado
 * 
 * \retval void A funcao em si nao retorna nada.
 *
 */
int isprime(ullong *n)
{
    ullong c, dois, metade, j;
    dois.l=2;
    dois.h=0;
    c.l=3;
    c.h=0;

    if((n->h == 0) && ((n->l == 0) || (n->l == 1)))
        return 0;
    if((n->h == 0) && ((n->l == 2) || (n->l == 3)))
        return 1;
    if (~(n->l & 1))
        return 0;

    metade.l = n->l >> 1;
    if(n->h && 1)
        metade.l |= 1<<(BUFFER/2-1);
    metade.h = n->h >> 1;

    while(1)
    {
        if((c.h > metade.h)||((c.h==metade.h)&&(c.l>metade.l)))
            break;
        if(~(udiv(n,&c)))
            return 0;
        uadd(&c,&dois,&j);
        c.l = j.l;
        c.h = j.h;
    }

    if ((c.l == n->l) && (c.h == n->h))
        return 1;
    return 0;
}

