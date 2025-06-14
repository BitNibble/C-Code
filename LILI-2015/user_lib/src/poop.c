/************************************************************************
Title:    poop
Author:   <sergio.salazar.santos@gmail.com>
File:     $Id: poop.c$
Software: GCC
Hardware: OS
License:  Free beer
************************************************************************/
#include "poop.h"
#include <string.h>
#include <stdio.h>

#define BUFF_SIZE 512

static int _strtotok(char* line, char* token[], const char* parser)
{
    int i;
    for (i = 0, token[i] = strtok(line, parser); token[i]; i++, token[i] = strtok(NULL, parser));
    return i;
}

static void _rmcrnl(char* str)
{
    int i;
    int stop;
    size_t len = strlen(str);
    for (i = (int)len, stop = (int)len - 3; i > stop; i--) {
        if (*(str + i) == '\r' || *(str + i) == '\n') {
            *(str + i) = '\0';
        }
    }
}

static void _fplfsm(const char* seq_name, const char* search, size_t line_size, FICHEIRO* file, char* logic, char* feedback)
{
    char line[line_size];
    char LOG[line_size];
    const size_t LINE_SIZE = line_size - 1;
    char* token[4];

    file->openp();
    logic[0] = '\0';

    while (file->fgets(line, LINE_SIZE)) {
        _rmcrnl(line);
        _strtotok(line, token, "=");
        if (token[0]) {
            if (snprintf(LOG, LINE_SIZE, "log+%s", search) > 0) {
                if (!strcmp(LOG, token[0])) {
                    if (token[1]) {
                        strcpy(logic, token[1]);
                        printf("LOG-out: ----> %s\n", logic);
                    }
                }
                if (snprintf(LOG, LINE_SIZE, "%s*%s+%s", seq_name, feedback, search) > 0) {
                    if (!strcmp(LOG, token[0])) {
                        if (token[1]) {
                            strcpy(feedback, token[1]);
                            printf("SEQ-out ----> %s\n", feedback);
                            break;
                        }
                    }
                }
                else { perror("LOG"); }
            }
            else { perror("LOG"); }
        }
    }
    if (feof(file->filepointer())) {
        // End of file reached.
    }
    file->close();
}

static char* _logsnprintf(const char* search)
{
    static char LOG[BUFF_SIZE] = {0};
    const size_t buff_size = BUFF_SIZE - 1;
    if (snprintf(LOG, buff_size, "log+%s", search) > 0) {
        printf("\tlogic: %s\n", LOG);
    }
    else { perror("LOG"); }
    return LOG;
}

static char* _seqsnprintf(const char* seq_name, const char* search, const char* feedback)
{
    static char SEQ[BUFF_SIZE] = {0};
    const size_t buff_size = BUFF_SIZE - 1;
    if (snprintf(SEQ, buff_size, "%s*%s+%s", seq_name, feedback, search) > 0) {
        printf("\tsequence: %s\n", SEQ);
    }
    else { perror("SEQ"); }
    return SEQ;
}

static void _pooplfsm(const char* poopin, const char* parser, size_t line_size, FICHEIRO* file, char* poopout)
{
    char line[line_size];
    const size_t LINE_SIZE = line_size - 1;
    char* token[4];
    file->openp();

    while (file->fgets(line, LINE_SIZE)) {
        _rmcrnl(line);
        _strtotok(line, token, parser);
        if (token[0]) {
            if (!strcmp(poopin, token[0])) {
                if (token[1]) {
                    strcpy(poopout, token[1]);
                    printf("output ----> %s\n", poopout);
                    break;
                }
            }
        }
    }
    if (feof(file->filepointer())) {
        // End of file reached.
    }
    file->close();
}

static POOP setup = {
    .strtotok = _strtotok,
    .rmcrnl = _rmcrnl,
    .fplfsm = _fplfsm,
    .logsnprintf = _logsnprintf,
    .seqsnprintf = _seqsnprintf,
    .pooplfsm = _pooplfsm
};

POOP* POOPenable(void)
{
    return &setup;
}

/***EOF***/

