#include<stdio.h>
#include<conio.h>
struct sym
{
char lab[10];
int val;
};
struct li
{
char oprn[10];
int addr;
};
main ()
{
FILE *f1;
char la[10],op[10],opr[10],a[1000],c;
int i,j,n,k=0,lc=0,m=0,p=0;
struct sym s[10];
struct li l[10];
//clrscr();
f1=fopen("Inp.txt","r");
c=fgetc(f1);
i=0;
printf ("\n SOURCE PROGRAM \n");
printf("%c",c);
while (c !=EOF)
{
a[i]=c;
c=fgetc(f1);
i++;
printf("%c",c);
}
i=0;
printf("\n INTERMEDIATE FILE \n");
while(strcmp(op,"end")!=0)
{
if(a[i]=='\t')
{
strcpy(la," ");
i++;
}
else
{
j=0;
while(a[i]!='\t')
{
la[j]=a[i];
i++;
j++;
}
la[j]='\0';
i++;
}
if(a[i]=='\t')
{
strcpy(op," ");
i++;
}
else
{
j=0;
while (a[i]!='\t')
{
op[j]=a[i];
i++;

j++;
}
op[j]='\0';
i++;
}
if(a[i]=='\n')
{
strcpy(opr," ");
i++;
}
else
 {
 j=0;
while (a[i] !='\n')
 {
opr [j]=a [i];
 i++;
j++;
}
opr[j]='\0';
i++;
}
j=0;
if (strcmp (la," ") !=0)
{
strcpy(s[m].lab,la);
if (strcmp(op, "start") ==0)
{
lc=atoi(opr);
s [m] .val=lc,
m++;
continue;
}
else if (strcmp (op, "equ") ==0)
{
printf("\n%d\t",lc);
s[m] .val=atoi(opr);
m++;
}
else if (strcmp (op, "resw") ==0)
{
printf("\n%d\t",lc);
s[m] .val=lc;
lc=lc+atoi(opr) *3;
m++;
}
else if (strcmp (op, "resb") ==0)
 {
printf("\n%d\t",lc);
s[m] .val=lc;
lc=lc+atoi(opr);
m++;
}
else
{
printf("\n%d\t",lc);
strcpy(s[m].lab,la);
s[m] .val=lc;
lc=lc+3;
m++;
}
}
else
{
printf("\n%d\t",lc);
lc=lc+3;
}
if(opr[0] =='=')
{
strcpy(l[k].oprn,opr);
k++;
}
printf("%s\t%s\n",op,opr);
}
if(strcmp(op,"end")==0)
for(n=p;n<k;n++)
{
l[n].addr=lc-3;
printf("\n%d\t%s\n",l[n].addr,l[n].oprn);
lc=lc+3;
p++;
}
printf("\n symbol table \n");
for(i=0;i<m;i++)
printf("\n%s\t%d\n",s[i].lab,s[i].val);
printf("\n Literal table \n");
for(i=0;i<k;i++)
printf("\n%s\t%d\n",l[i].oprn,l[i].addr);
getch();
}
