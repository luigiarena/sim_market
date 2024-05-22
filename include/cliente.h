#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <errno.h>

/* Struttura che definisce l'oggetto Cassa */
typedef struct Cliente {
    long id;            // identificativo del cliente

    int t_spesa         // tempo occupato dal cliente per fare la spesa
    int t_cassa;        // tempo che il cliente spende alla cassa
    int num_prodotti;   // numero di prodotti acquistati

} Cliente;

void* cliente_main(void* arg);