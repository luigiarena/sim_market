#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <errno.h>

/* Struttura che definisce l'oggetto Cassa */
typedef struct Cassa {
    long id;            // identificativo della cassa
    int stato;          // booleano, 1 -> cassa aperta, 0 -> cassa chiusa

    int t_servizio;     // tempo di servizio definito per servire un cliente
    int num_clienti;    // numero totale di clienti serviti
    int num_prodotti;   // numero totale di prodotti scansionati
    int chiusure;       // numero di chiusure della cassa

} Cassa;

void* cassa_main(void* arg);