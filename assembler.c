# ASSEMBLER.C
CONVERSION OF ASSEMBLY INTO MACHINE CODE
#include<stdio.h>
#include<conio.h>
#include<string.h>
void op_code();
void label();
void read();
struct op_table
{
char opcode[10],object_code[10];
}ass_optable[3]={
{"LDACU","00"},//LOAD ACCUMULATOR
{"JUMP","01"},//JUMP
{"STACU","02"},//STORE ACCUMULATOR DIRECT
{"JMPSUB","48"},//JUMP IF SUBROUTINE
{"STAX","5"},//STORE ACCUMULATOR INDIRECT
{"COMPR","A0"},
{"LDCH","50"},
{"STL","14"},
{"JEQ","30"},
{"LDL","08"},
{"RSUB","4C"},
{"LDX",""04"},
{"TDD","E0"},
{"LDXX","04"},
}
struct sym_table
{
char symbol[10];
int address;
}ass_symtable[10];
int start_address,locctr,sym_count=0,length;
char LINE[50],LABEL[10],OPCODE[10],OPERAND[10],program_name;
void pass_one
{
FILE *fp_inp,*fp_int;
fp_inp=fopen("input_file.txt","r");
fp_int=fopen("intermediate_file.txt","w");
printf("LOCATION    LABEL\t  OPERAND\t  OPCODE\n");
printf("___________________________________________________________");
fgets(LINE,50,fp_inp);
read();
if(!strcmp(OPCODE,START)
{
start_address=atoi(OPERAND);
locctr=start_address;
strcpy(program_name,LABEL);
fprintf(fp_int,"%s",LINE);
fgets(LINE,50,fp_inp);
}
else
{
program_name[0]='\0';
start_address=0;
locctr=0;
}
printf("\n  %d \t %s \t %s \t %s",locctr,LABEL,OPCODE,OPERAND);
while(strcmp(LINE,"END")!=0)
{
read();
printf("\n %d\t  %s\t  %s\t  %s",locctr,LABEL,OPCODE,OPERAND);
if(LABEL[0]!='\0')
label();
op_code();
fprintf(fp_int,"%s  %s  %s \n",LABEL,OPCODE,OPERAND);
fgets(LINE,50,fp_inp);
}
printf("\n %d\t\t%s",locctr,LABEL);
fprintf(fp_int,"%s",LINE);
fclose(fp_inp);
fclose(fp_int);
}
//___________________________________________________________________________________________________________________________
//___________________________________________________________________________________________________________________________




