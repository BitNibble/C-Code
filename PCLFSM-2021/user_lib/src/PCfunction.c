/**************************************************************************
Title:    PCFUNCTION
Author:   Sergio Manuel Santos <sergio.salazar.santos@gmail.com>
File:     $Id: PCfunction.c, v 0.1 2015/08/01 14:00:00 sergio Exp $
Software: GCC
Hardware: PC
License:  GNU General Public License
Description:
	PC emulation
Comment:
	Very Stable
*************************************************************************/
#include"..\inc\PCfunction.h"
/*
** constant and macro
*/
/*
** variable
*/
char FUNCstr[256];
char *value=NULL;
/*
** procedure and function header
*/
int StringLength (const char string[]);
void Reverse(char s[]);
uint8_t FUNCintinvstr(int32_t n, char* res, uint8_t n_digit);
char* FUNCftoa(float n, char* res, uint8_t afterpoint);
char* FUNCfltos(FILE* stream);
char* FUNCftos(FILE* stream);
int FUNCstrtotok(char* line,char* token[],const char* parser);
char* FUNCputstr(char* str);
int FUNCgetnum(char* x);
unsigned int FUNCgetnumv2(char* x);
int FUNCreadint(int nmin, int nmax);
unsigned int FUNCmayia(unsigned int xi, unsigned int xf, unsigned int nbits);
unsigned int FUNCpinmatch(unsigned int match, unsigned int pin, unsigned int HL);
unsigned int FUNClh(unsigned int xi, unsigned int xf);
unsigned int FUNChl(unsigned int xi, unsigned int xf);
unsigned int FUNCdiff(unsigned int xi, unsigned int xf);
char* FUNCprint_binary(unsigned int n_bits, int number);
unsigned int FUNCdecimal_binary(unsigned int n);
unsigned int FUNCbinary_decimal(unsigned int n);
void FUNCstrflip(char* s);
/*
** Object Inicialize
*/
FUNC FUNCenable( void )
{
	value=(char*)realloc(value, sizeof(char));
	*(value)='\0';
	// struct object
	FUNC func;
	//func.value=NULL;
	func.stringlength=StringLength;
	func.reverse=Reverse;
	func.ftoa=FUNCftoa;
	func.fltos=FUNCfltos;
	func.ftos=FUNCftos;
	func.strtotok=FUNCstrtotok;
	func.putstr=FUNCputstr;
	func.getnum=FUNCgetnum;
	func.getnumv2=FUNCgetnumv2;
	func.readint=FUNCreadint;
	func.mayia=FUNCmayia;
	func.pinmatch=FUNCpinmatch;
	func.lh=FUNClh;
	func.hl=FUNChl;
	func.diff=FUNCdiff;
	func.print_binary=FUNCprint_binary;
	func.decimal_binary=FUNCdecimal_binary;
	func.binary_decimal=FUNCbinary_decimal;
	func.strflip=FUNCstrflip;
	return func;
}
/*
** procedure and function
*/
/***StringLength***/
int StringLength (const char string[])
{
	int count = 0;
	while ( string[count] != '\0' )
		++count;
	return count;
}
/***Reverse***/
void Reverse(char s[])
{
	int c, i, j;
	for (i = 0, j = StringLength(s)-1; i < j; i++, j--){
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
/***intinvstr***/
uint8_t FUNCintinvstr(int32_t n, char* res, uint8_t n_digit)
{
	uint8_t k=0;
	for(res[k++] = (n % 10) + '0'; (n/=10) > 0; res[k++] = (n % 10) + '0');
	for( ; k < n_digit ; res[k++] = '0');
	res[k]='\0';
	return k;
}
/***/
/***ftoa***/
char* FUNCftoa(float n, char* res, uint8_t afterpoint)
{
	uint8_t k=0;
	int32_t ipart;
	float fpart;
	int8_t sign;
	if (n < 0){
		n = -n;
		sign=-1;
	}else
		sign=1;
	ipart = (int32_t) n;
	fpart = n - (float)ipart;
	k=FUNCintinvstr( ipart, res, 1 );
	if (sign < 0)
		res[k++] = '-';
	else
		res[k++] = ' ';
	res[k]='\0';
	Reverse(res);
	if (afterpoint > 0){
		res[k++] = '.';
		FUNCintinvstr( fpart * pow(10, afterpoint), res+k, afterpoint );
		Reverse(res+k);
	}	
	return res;
}
/***/
/***fltos***/
char* FUNCfltos(FILE* stream)
{
	int i, block, NBytes;
	char caracter;
	//made it a file variable so do not need to free it up all the time except on exitting program.
	//char* value=NULL;
	free(value);
	for(value=NULL, i=0, block=8, NBytes=0; (caracter=getc(stream)) != EOF; i++){
		if(i>NBytes-1){
			NBytes+=block;
			value=(char*)realloc(value, NBytes*sizeof(char));
			if(value==NULL){
				perror("fltos at realloc");
				break;
			}
		}
		if(caracter == '\n'){
			break;
		}
		*(value+i)=caracter;
	}
	if(i) *(value+i)='\0';
	return value;
}
/***ftos***/
char* FUNCftos(FILE* stream)
{
	int i, block, NBytes;
	char caracter;
	//made it a file variable so do not need to free it up all the time except on exiting program.
	//char* value=NULL;
	free(value);
	for(value = NULL, i=0, block=8, NBytes=0; (caracter=getc(stream)) != EOF; i++){
		if(i>NBytes-1){
			NBytes+=block;
			value=(char*)realloc(value, NBytes*sizeof(char));
			if(value==NULL){
				perror("ftos at realloc");
				break;
			}
		}
		*(value+i)=caracter;
	}
	if(i) *(value+i)='\0';
	return value;
}
/***strtotok***/
int FUNCstrtotok(char* line, char* token[], const char* parser)
{
	int i; // strtok simply replaces the parser with '\0' in the input string <line>
	for (i = 0, token[i] = strtok(line, parser); token[i]!=NULL ; i++, token[i] = strtok(NULL, parser)){ // all cyclic are while condition
		//printf("%d: %s\n", i, token[i]); //if no data it returns NULL
	}
	return i;
}
/***putstr***/
char* FUNCputstr(char* str)
{
	unsigned int n,i; char* ptr;
	n=strlen(str);
	ptr = (char*)calloc(n, sizeof(char));
	if(ptr == NULL){
		perror("error at calloc\n");
	}else{
		for(i=0; i<n ; i++)
			ptr[i] = str[i];
		ptr[i] = '\0';
	}
	return ptr;
}
/***getnum***/
int FUNCgetnum(char* x)
{
	int num;
	if(x != NULL){
		if(!sscanf(x, "%d", &num))
			num=0;
	}else
		num = 0;
	return num;
}
/***getnumv2***/
unsigned int FUNCgetnumv2(char* x)
{
	unsigned int ret;
	unsigned int value;
	unsigned int n;
	if(x != NULL){
		errno=0;
		n = sscanf(x, "%d", &value);
		if(n == 1){
			ret = value;
		}else if(errno != 0){
			perror("Error at FUNCgetnumv2");
			ret = 0;
		}else{
			ret = 0;
		}
	}else
		ret = 0;
	return ret;
}
/***readint***/
int FUNCreadint(int nmin, int nmax)
{
	int num;
	int flag;
	for(flag=1; flag;){
		for( num=0; !scanf("%d",&num); getchar())
			;
		//printf("num: %d nmin: %d nmax: %d\n",num, nmin, nmax);
		if((num < nmin) || (num > nmax))
			continue;
		flag=0;
	}
	return num;
}
/***magic***/
unsigned int FUNCmayia(unsigned int xi, unsigned int xf, unsigned int nbits)
{
	unsigned int mask;
	unsigned int diff;
	unsigned int trans;
	mask=pow(2,nbits)-1;
	xi=xi&mask;
	xf=xf&mask;
	diff=xf^xi;
	trans=diff&xf;
	return (trans<<nbits)|diff;
}
/***pinmatch***/
unsigned int FUNCpinmatch(unsigned int match, unsigned int pin, unsigned int HL)
{
	unsigned int result;
	result=match&pin;
	if(HL){
		if(result==match);
		else
			result=0;
	}else{
		if(result)
			result=0;
		else
			result=match;
	}
	return result;
}
/***lh***/
unsigned int FUNClh(unsigned int xi, unsigned int xf)
{
	unsigned int i;
	i=xf^xi;
	i&=xf;
	return i;
}
/***hl***/
unsigned int FUNChl(unsigned int xi, unsigned int xf)
{
	unsigned int i;
	i=xf^xi;
	i&=xi;
	return i;
}
/***diff***/
unsigned int FUNCdiff(unsigned int xi, unsigned int xf)
{
	return xi^xf;
}
/***print_binary***/
char* FUNCprint_binary(unsigned int n_bits, int number)
{
	int i,c;
    for(i=(1<<(n_bits-1)), c=0; i; i >>= 1, c++)
		(number & i) ? (FUNCstr[c]='1') : (FUNCstr[c]='0');
	FUNCstr[c]='\0';
	return FUNCstr;
}
/***decimal_binary***/
unsigned int FUNCdecimal_binary(unsigned int n) /*Function to convert decimal to binary*/
{
	unsigned int rem, i=1, binary=0;
	while (n!=0)
	{
		rem=n%2;
		n/=2;
		binary+=rem*i;
		i*=10;
	}
	return binary;
}
/***binary_decimal***/
unsigned int FUNCbinary_decimal(unsigned int n) /* Function to convert binary to decimal.*/
{
    unsigned int decimal=0, i=0, rem;
    while (n!=0)
    {
        rem = n%10;
        n/=10;
        decimal += rem*pow(2,i);
        ++i;
    }
    return decimal;
}
/***flip***/
void FUNCstrflip(char* s)
{
	int i,j; char c;
	for(i=0, j=(strlen(s)-1); i<j ; c=s[i], s[i]=s[j], s[j]=c, i++, j--);
}
/*
** interrupt
*/
/***EOF***/
