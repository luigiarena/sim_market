#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "supermercato.h"
#include "utils.h"
#include "cassa.h"

int K;
Cassa *casse_list;

int main(int argc, char* argv[]){

    // Creazione casse
    casse_list = (Cassa*) malloc(sizeof(Cassa)*K);


}
