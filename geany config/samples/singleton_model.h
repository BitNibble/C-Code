/*************************************************************************
Title:    SINGLETON_MODEL
Author:   <sergio.salazar.santos@gmail.com>
File:     $Id: singleton_model.h$
Software: GCC
Hardware: PC
License:  GNU General Public License
Comment:
    Singleton module interface with internal state and function pointers.
*************************************************************************/
#ifndef SINGLETON_MODEL_H
	#define SINGLETON_MODEL_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    int fd;
    unsigned int step;
    char buffer[256];
} state_t;

typedef struct {
    state_t par;
    int (*read)(char *buf, unsigned int len);
    void (*close)(void);
} MODULE_t;

/**
 * @brief Get singleton instance of the module.
 * 
 * @return Pointer to the singleton MODULE instance.
 */
MODULE_t *MODULEenable(void);

#ifdef __cplusplus
}
#endif

#endif /* SINGLETON_MODEL_H */
/*** EOF ***/

