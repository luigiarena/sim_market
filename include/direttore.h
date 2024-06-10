#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <errno.h>

typedef struct {
    int S1;         // soglia chiusura casse
    int S2;         // soglia apertura casse

    int n_usciti;   // numero di clienti che hanno richiesto l'uscita

    pthread_mutex_t *mtx_direttore; // puntatore mutex per l'accesso delle richieste al direttore
    pthread_cond_t *cond_direttore; // puntatore variabile condizionale per il direttore 
} Direttore;

void* direttore_main(void* arg);