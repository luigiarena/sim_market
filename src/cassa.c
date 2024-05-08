#define _POSIX_C_SOURCE 200112L

#include <cassa.h>
#include <utils.h>

void* cassa_main(void* arg) {
    // Creazione della maschera dei segnali
    sigset_t mask;
    sigemptyset(&mask);
    sigaddset(&mask, SIGHUP);
    sigaddset(&mask, SIGQUIT);
    IFERRORNOT(pthread_sigmask(SIG_SETMASK, &mask, NULL), 0, "sigmask cassiere")

    Cassa* cassa = (Cassa*) arg; 
    printf("Cassa %ld pronta.\n", cassa->id);

    return NULL;
}