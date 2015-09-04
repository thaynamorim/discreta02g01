#include <stdio.h>
#include <stdlib.h>

#define MAXULLONG "340282366920938463463374607431768211455"
#define BUFFER 128

typedef struct sl
{
    unsigned long h;
    unsigned long l;
} ullong;

int ulet(char *in, ullong *out);
int div2(char *in, char *out);

int main(void)
{
    ullong x, y, z;
    char a[] = "5", b[] = "255", c[] = "1509890185901285921459";
    if(ulet(a,&x))
        printf("x estourou\n");
    if(ulet(b,&y))
        printf("y estourou\n");
    if(ulet(c,&z))
        printf("z estourou\n");
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

