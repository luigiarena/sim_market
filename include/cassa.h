#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <errno.h>

/* Struttura che definisce l'oggetto Cassa */
typedef struct Cassa {
    long id;        // identificativo della cassa
    int stato;      // booleano, 1 -> cassa aperta, 0 -> cassa chiusa
} Cassa;

void* cassa_main(void* arg);