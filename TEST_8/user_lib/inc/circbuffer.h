/******************************************************************************
	CIRCBUFFER
Author:   <sergio.salazar.santos@gmail.com>
License:  GNU General Public License
Hardware: all
Date:     03112024
Comment:
	Pin Analysis
*******************************************************************************/
#ifndef _CIRCBUFFER_H_
	#define _CIRCBUFFER_H_

#include <stdint.h>

struct circ_buf_par
{
	char* tail;
	char* head;
	char* buff;
	char* orig;
	char* end;
} ;

struct circ_buf_template
{
	struct circ_buf_par par;
	char (*get)(struct circ_buf_template* circ);
	void (*put)(struct circ_buf_template* circ, char data);
	void (*gets)(struct circ_buf_template* circ, char* str);
	void (*puts)(struct circ_buf_template* circ, const char* str);
} ;
typedef struct circ_buf_template circbuff;

circbuff CIRCBUFFenable(size_t size_buff, char* buff);
#endif
/***EOF***/

