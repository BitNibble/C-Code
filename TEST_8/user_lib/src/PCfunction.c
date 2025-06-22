/**************************************************************************
Title:    PCFUNCTION
Author:   <sergio.salazar.santos@gmail.com>
File:     $Id: PCfunction.c, v 0.1 2015/08/01 14:00:00 sergio Exp $
Software: GCC
Hardware: PC
License:  Free beer
Comment:

*************************************************************************/
#include "PCfunction.h"

#define FUNC_STR_SIZE 256

static char FUNCstr[256];
const size_t func_str_size = (FUNC_STR_SIZE - 1);
static char *value = NULL; // Object variable

int StringLength (const char string[]);
void Reverse(char s[]);
uint8_t FUNCintinvstr(int32_t n, char* res, uint8_t n_digit);
char* FUNCftoa(float n, char* res, uint8_t afterpoint);
char* FUNCfltos(FILE* stream);
char* FUNCftos(FILE* stream);
int FUNCstrtotok(char* line,char* token[],const char* parser);
int FUNCgetnum(char* x);
unsigned int FUNCgetnumv2(char* x);
int FUNCreadint(int nmin, int nmax);
char* FUNCprint_binary(unsigned int n_bits, int number);
unsigned int FUNCdecimal_binary(unsigned int n);
unsigned int FUNCbinary_decimal(unsigned int n);
void FUNCstrflip(char* s);
char* FUNCprint(char *format, ... );

static FUNC setup = {0};

void ofunc_enable(void)
{
	setup.stringlength=StringLength;
	setup.reverse=Reverse;
	setup.ftoa=FUNCftoa;
	setup.fltos=FUNCfltos;
	setup.ftos=FUNCftos;
	setup.strtotok=FUNCstrtotok;
	setup.getnum=FUNCgetnum;
	setup.getnumv2=FUNCgetnumv2;
	setup.readint=FUNCreadint;
	setup.print_binary=FUNCprint_binary;
	setup.decimal_binary=FUNCdecimal_binary;
	setup.binary_decimal=FUNCbinary_decimal;
	setup.strflip=FUNCstrflip;
	setup.print=FUNCprint;
}

FUNC* ofunc(void){ return &setup; }

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
	char c;
	int i, j;
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
		FUNCintinvstr( (double)fpart * pow((double)10, (double)afterpoint), res+k, afterpoint );
		Reverse(res+k);
	}	
	return res;
}

/***fltos***/
char* FUNCfltos(FILE* stream)
{
	int i, block, NBytes;
	char caracter;
	if(value) free(value);
	for(value=NULL, i=0, block=8, NBytes=0; (caracter=getc(stream)); i++){
		if(i>NBytes-1){
			NBytes+=block;
			value=(char*)realloc(value, NBytes*sizeof(char));
			if(value==NULL){
				fprintf(stderr, "fltos at realloc");
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
	int i = 0, block = 0, NBytes = 0;
	char caracter = '\0';
	if(value) free(value);
	for(value = NULL, i=0, block=8, NBytes=0; (caracter=getc(stream)) != EOF; i++){
		if(i>NBytes-1){
			NBytes+=block;
			value=(char*)realloc(value, NBytes*sizeof(char));
			if(value==NULL){
				fprintf(stderr, "ftos at realloc");
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
	int i;
	for (i = 0, token[i] = strtok(line, parser); token[i]!=NULL ; i++, token[i] = strtok(NULL, parser));
	return i;
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
        decimal += rem*(1 << i);
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

/***print***/
char* FUNCprint(char *format, ... )
{
	va_list aptr;
	int ret;

	va_start(aptr, format);
	ret = vsprintf(FUNCstr, format, aptr);
	va_end(aptr);
	if(ret < 0){
		return NULL;
	}else
		return FUNCstr;
}
/***EOF***/

