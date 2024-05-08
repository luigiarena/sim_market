#include <direttore.h>
#include <utils.h>

void* direttore_main(void* arg) {
    // Creazione della maschera dei segnali
    sigset_t mask;
    sigemptyset(&mask);
    sigaddset(&mask, SIGHUP);
    sigaddset(&mask, SIGQUIT);
    IFERRORNOT(pthread_sigmask(SIG_SETMASK, &mask, NULL), 0, "sigmask supermercato")

    // Stampa di un messaggio di avvio del direttore
    printf("Il direttore è pronto.\n");

    // Ciclo di lavoro per il direttore
    while(0) {

    }

    return NULL;
}
