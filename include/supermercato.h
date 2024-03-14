/*  Struttura che contiene i parametri di configurazione    */
typedef struct param {
    int K;  // Numero max di casse aperte
    int Ki; // Numero di casse aperte inizialmente
    int C;  // Numero max di clienti
    int E;  // C-E è la soglia per far entrare nuovi clienti
    int P;  // Numero max di prodotti acquistabili
    int T;  // Tempo di acquisto per cliente
    int Tp; // Tempo di controllo per ogni prodotto alla cassa
    int Td; // (ms) intervallo aggiornamento del direttore dai cassieri
    int S;  // (ms) intervallo controllo coda per cliente
    int S1; // Soglia per la chiusura delle casse
    int S2; // Soglia per l'apertura delle casse
} param;
