#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include <errno.h>
#include <pthread.h>

#include "supermercato.h"
#include "utils.h"
#include "cassa.h"

Param *config;
Cassa *casse_list;

/* Funzione main del progetto */
int main(int argc, char* argv[]){
    int opt, cflag = 0, vflag = 0;
    FILE *config_file;
    char* config_name;

    // cancello il file di log se esiste
    remove(LOGNAME);

    // Controllo gli argomenti
    while ((opt = getopt(argc, argv, "c:vh")) != -1) {
        switch (opt) {
            case 'c':
                cflag = 1; config_name = optarg; break;
            case 'v':
                vflag = 1; break;
            case 'h':
                fprintf(stderr, "Usage: %s [-h] [-v] [-c] [nomeFile]\n", argv[0]);
                exit(errno); break;
            default:
                fprintf(stderr, "No valid argument\n");
                exit(EXIT_FAILURE);
        }
    }

    if(cflag == 0) config_name = "config.txt";

    // TEST
    if(vflag==1) printf("nome file: %s\ncflag: %d\nvflag: %d\n", config_name, cflag, vflag);

    // Provo ad aprile il file di configurazione
    IFERROR((config_file = fopen(config_name, "r")),NULL,"Opening configuration file")

    // Leggo i valori dei parametri e li salvo nella struttura Param
    config = malloc(sizeof(Param));
    char buffer[BUF_SIZE];
    char* par; 
    int val, val_c;

    while (fgets(buffer, BUF_SIZE, config_file) != NULL) {
        remove_spaces(buffer);
        if (buffer[0] == '#' || buffer[0] == '\n') continue;
        printf("%s", buffer);
        
        par = strtok(buffer, ":");
        val = atoi(strtok(NULL, ":"));
        if      (strcmp(par, "K")  == 0 && (val_c=val_check(val, 1, 400))==0) {config->K = val;}
        else if (strcmp(par, "Ki") == 0 && (val_c=val_check(val, 1, 400))==0) {config->Ki = val;}
        else if (strcmp(par, "C")  == 0 && (val_c=val_check(val, 1, 400))==0) {config->C = val;}
        else if (strcmp(par, "E")  == 0 && (val_c=val_check(val, 1, 400))==0) {config->E = val;}
        else if (strcmp(par, "P")  == 0 && (val_c=val_check(val, 1, 400))==0) {config->P = val;}
        else if (strcmp(par, "T")  == 0 && (val_c=val_check(val, 1, 400))==0) {config->T = val;}
        else if (strcmp(par, "Tp") == 0 && (val_c=val_check(val, 1, 400))==0) {config->Tp = val;}
        else if (strcmp(par, "Td") == 0 && (val_c=val_check(val, 1, 400))==0) {config->Td = val;}
        else if (strcmp(par, "S")  == 0 && (val_c=val_check(val, 1, 400))==0) {config->S = val;}
        else if (strcmp(par, "S1") == 0 && (val_c=val_check(val, 1, 400))==0) {config->S1 = val;}
        else if (strcmp(par, "S2") == 0 && (val_c=val_check(val, 1, 400))==0) {config->S2 = val;}
        else {
            if (val_c == 1) fprintf(stderr, "Valore di %s: %d non valido.\n", par, val); 
            else fprintf(stderr, "Parametro di configurazione %s non riconosciuto.\n", par);
            exit(EXIT_FAILURE);
        }
    }

    // TEST
    printf("\n");
    printf("Test: Param K ha val: %d\n", config->K);

    // Chiusura del file di configurazione
    IFERROR(fclose(config_file),-1,"Closing configuration file")

    // Creazione casse
    casse_list = (Cassa*) malloc(sizeof(Cassa)*config->K);

    sleep(20);


}
