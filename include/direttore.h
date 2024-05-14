#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <errno.h>

typedef struct {
    int S1;         // soglia chiusura casse
    int S2;         // soglia apertura casse
} Direttore;

void* direttore_main(void* arg);