//PASS ONE OF ASSEMBLER
#include<stdio.h>
#include<conio.h>
#include<string.h>
void pass_one()
{
FILE *f1,*f2,*f3,*f4,*f5;
int locctr=0X0,start_ad=0X0,l,op1,o,len;
char m[20],la[20],op[20],otp[20],record[100];
f1=fopen("ques.txt","r");//open ques.txt (input file) in read mode
f2=fopen("ques_inter.txt","w");//open intermediate file in write mode
f3=fopen("ques_symtab.txt","w");//open file (symbol table) in write mode
fscanf(f1,"%s %s %X",la,m,&op1);//input label,mnemonic,and operand(which becomes the starting address)
printf("\nintermediate  file\n\n\n");
if(strcmp(m,"START")==0)
{
 start_ad=op1;
 locctr=start_ad;//assigning starting address to location counter
 fprintf(f2,"%X\t%s\t%s\t%X\n",locctr,la,m,op1);//printing in intermediate file
 printf("%X\t%s\t%s\t%X\n",locctr,la,m,op1);
 }
 else
 {
 locctr=0;
 }
fscanf(f1,"%s %s",la,m);
while(!feof(f1))
{
 fscanf(f1,"%s",op);
 fprintf(f2,"\n%X\t%s\t%s\t%s\n",locctr,la,m,op);
 printf("\n%X\t%s\t%s\t%s\n",locctr,la,m,op);
 if(strcmp(la,"-")!=0)//if label found
 {
 fprintf(f3,"\n%X\t%s\n",locctr,la);//printing in symbol table file(label and its address)
 }
 f4=fopen("quesoptab.txt","r");//open file in read mode containing operation table
 fscanf(f4,"%s %X",otp,&o);
 while(!feof(f4))
 {
  if(strcmp(m,otp)==0)
  {
    locctr=locctr+3;
    break;
  }
  fscanf(f4,"%s %X",otp,&o);
  }
  fclose(f4);//closing file containing operation table
  if(strcmp(m,"WORD")==0)

    {
   locctr=locctr+3;
   }
   else if(strcmp(m,"RESW")==0)
   {
    op1=atoi(op);//converts string argument into integer
    locctr=locctr+(3*op1);
    }
    else if(strcmp(m,"BYTE")==0)
    {
    if(op[0]=='X')
      locctr=locctr+1;
      else
      {
      len=strlen(op)-2;
      locctr=locctr+len;}
    }
    else if(strcmp(m,"RESB")==0)
    {
     op1=atoi(op);//converts string argument into integer
     locctr=locctr+op1;
     }
    fscanf(f1,"%s%s",la,m);
    }
    printf("-\t-\tEND\t%06x\n",start_ad);
    //printf("Program length =\n%x",locctr-start_ad);//prints length of program

    fprintf(f2,"-\t-\tEND\t%06x",start_ad);
    fclose(f1);// closing input file
    fclose(f3);//closing file containing symbol table
    fclose(f2);
   // getch();
  }
    void pass_2()
{
FILE *fint,*ftab,*flen,*fsym,*fout;
int op1[10],i,j=0,len,co=0,c=0;
char add[10],symadd[10],op[10],start[10],la[20],m[10],operand[10],symtab[10],opmne[10];
fint=fopen("ques_inter.txt","r");
flen=fopen("length.txt","r");
ftab=fopen("quesoptab.txt","r");
fsym=fopen("ques_symtab.txt","r");
fout=fopen("result.txt","w+");
fscanf(fint,"%s%s%s%s",add,la,m,op);
printf("\n\n\n\n\nobject file\n\n\n");
if(strcmp(m,"START")==0)
{

strcpy(start,op);
fscanf(flen,"%x",&len);

}
printf("H^%s^%s^%X\nT^00%s^%x",la,start,len,start,len);
fprintf(fout,"H^%s^%s^%X\nT^00%s",la,start,len,start);
fscanf(fint,"%s%s%s%s",add,la,m,operand);
while(strcmp(m,"END")!=0)
{
fscanf(ftab,"%s%s",opmne,op);
while(!feof(ftab))
{
c=0;
if(strcmp(m,opmne)==0)
{
    c==1;
fclose(ftab);
if(strcmp(operand,"-")!=0)
{
    rewind(fsym);
fscanf(fsym,"%s%s",symadd,symtab);

while(!feof(fsym))
{
if(strcmp(operand,symtab)==0)
{
fprintf(fout,"^%s%s",op,symadd);
printf("^%s%s",op,symadd);
break;
}
else
{
fscanf(fsym,"%s%s",symadd,symtab);
}
}
}
else
{
   fprintf(fout,"0000");
printf("0000");
}
break;

}
else
fscanf(ftab,"%s%s",opmne,op);
}
if(c==0)
{
if((strcmp(m,"BYTE")==0)||(strcmp(m,"WORD")==0))
{
if(strcmp(m,"WORD")==0)
{

printf("^0000%s",operand);
fprintf(fout,"^0000%s",operand);
}

else
{
    fprintf(fout,"^");
    printf("^");
len=strlen(operand);
for(i=2;i<len;i++)
{

printf("%d",operand[i]);
fprintf(fout,"%d",operand[i]);
}
//printf("^");
//fprintf(fout,"^");
}
}
}
fclose(ftab);
fscanf(fint,"%s%s%s%s",add,la,m,operand);
ftab=fopen("quesoptab.txt","r");
fseek(ftab,SEEK_SET,0);
//break;
}

printf("\nE^00%s",start);
fprintf(fout,"\nE^00%s",start);
fclose(fint);
fclose(ftab);
fclose(fsym);
fclose(flen);
fclose(fout);
//getch();
}
int main()
{
    pass_one();
    pass_2();
    return 1;
}

  
