#include<stdio.h>
#include<conio.h>
#include<string.h>
struct
{
char sym[10];
int val;
}s[10];
struct
{
char opt[10];
int val;
}o[10];
struct
{
char lit[10];
int addr;
}l[10];
struct
{
char op[10],opr[10];
int lc;
}inter[10];
main()
{
FILE *f1,*f2,*f3,*f4;
int i=0,j=0,k=0,m=0,n=0,r;
char c,a[1000];

f1=fopen("H:\\Set2\\symbb.txt","r");
f2=fopen("H:\\Set2\\op.txt","r");
f3=fopen("H:\\Set2\\li.txt","r");
f4=fopen("H:\Set2\\inter.txt","r");
printf("symbol table\n\n");
while(!feof(f1))
{
fscanf(f1,"%s%d",s[j].sym,&s[j].val);
printf("%s\t%d\n",s[j].sym,s[j].val);
j++;
}
printf("optable\n\n");
while(!feof(f2))
{
fscanf(f2,"%s%d",o[k].opt,&o[k].val);
printf("%s\t%d\n",o[k].opt,o[k].val);
k++;
}
printf("Literal table\n\n");
while(!feof(f3))
{
fscanf(f3,"%s%d",l[m].lit,&l[m].addr);
printf("%s\t%d\n",l[m].lit,l[m].addr);
m++;
}
printf("Intermediate file\n");
while(!feof(f4))
{
fscanf(f4,"%d%s%s",&inter[n].lc,inter[n].op,inter[n].opr);
printf("%d\t%s\t%s\n",inter[n].lc,inter[n].op,inter[n].opr);
}
rewind(f4);
printf("\nmachine instruction \n\n");
while(!feof(f4))
{
fscanf(f4,"%d%s%s",&inter[n].lc,inter[n].op,inter[n].opr);
if((strcmp(inter[n].op,"equ")==0)||(strcmp(inter[n].op,"word")==0))
continue;
if((strcmp(inter[n].op,"resw")==0)||(strcmp(inter[n].op,"resb")==0))
continue;
printf("%d\t",inter[n].lc);
for(i=0;i<k;i++)
{
if(strcmp(inter[n].op,o[i].opt)==0)
printf("%d\t",o[i].val);
}
for(i=0;i<m;i++)
{
if(inter[n].op[0]!='*')
if(strcmp(inter[n].opr,l[i].lit)==0)
printf("%d\n",l[i].addr-inter[n].lc-3);
}

for(i=0;i<j;i++)
{
if(strcmp(inter[n].opr,s[i].sym)==0)
{
if(inter[n].op[0]=='+')
printf("%d\n",s[i].val);
else
printf("%d\n",s[i].val-inter[n].lc-3);
}
}
if(inter[n].op[0]=='*')
{
printf("%s\n",inter[n].opr);
}
}
getch();
return 0;
}

