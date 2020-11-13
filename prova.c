#include<stdio.h>
#include<string.h>
#include<time.h> //da includere per utilizzare time ()
#include<stdlib.h> //da includere per utilizzare rand() e srand() 

int main() 
 {
 	//Dichiarazione variabili
 	int Scelta=0;
 	time_t T;
 	char PlaintextM[128], KeyK[128], CypherC[128];
 	
    srand((unsigned)time(&T)); //Funzione da chiamare una sola volta nel programma

 	printf("Inserire un testo M (Lunghezza Massima: 128 caratteri) : ");
 	
 	//Stampa a schermo il contenuto del testo M e lunghezza di quest'ultimo
 	fgets(PlaintextM,128,stdin);
 	printf("Il contenuto del testo e': %s" ,PlaintextM);
 	printf("La lunghezza del testo inserito e': %d caratteri\n" , strlen(PlaintextM)-1);
 	
 	//Metodo per proseguire
 	printf("\nScegliere metodo per proseguire:\n");
 	printf("\n-Inserisci 1 se vuoi inserire la chiave K manualmente. (Questa dovra' essere lunga come il testo M)");
 	printf("\n-Inserisci 2 se vuoi che la chiave K venga generata casualmente.");
 	printf("\n-Inserisci 0 se vuoi uscire dal programma. \n");
 	
 	//Scelta
 	do 
	 {
	  printf("\nDigitare comando : ");	
 	  scanf("%d", &Scelta);
 	  if(Scelta == 1)
 	  {
 		//Inserimento manuale della chiave
 		printf("Inserire la chiave K : ");
 		while(getchar()!='\n');
 		do
 		{
 		   fgets(KeyK,128,stdin);
 		   if (strlen(KeyK)<strlen(PlaintextM))
 		   {
 		    printf("La chiave K e' minore del testo M. Reinserire la chiave : ");
 		   }
 		}
 		while(strlen(KeyK)<strlen(PlaintextM));

 	    printf("Il contenuto della chiave K e': %s" ,KeyK);
 	    printf("La lunghezza della chiave K e': %d caratteri\n", strlen(KeyK)-1);
 	    printf("Il testo M cifrato e visualizzato in esadecimale e' : ");

 	    //XOR M + K = C
 		for(int i = 0; i < strlen(PlaintextM)-1; i++) 
		{    
         CypherC[i] = PlaintextM[i] ^ KeyK[i];    
         printf("%X", CypherC[i]);     
        }
        printf("\nIl testo M in chiaro e' : ");
        for(int i = 0; i < strlen(PlaintextM)-1; i++) 
		{
	     //XOR C + K = M 
         PlaintextM[i] = CypherC[i] ^ KeyK[i];   
         printf("%c", PlaintextM[i]); 
        }
        printf("\n");
      }
	  else if(Scelta==2)
	  {
	  	//Generazione chiave casuale
 		printf("La chiava generata casualmente e' : ");
        for (int i = 0; i < strlen(PlaintextM)-1; ++i)
        {
         KeyK[i]=33+rand()%94;
         printf("%c", KeyK[i]);
        }
        printf("\nIl testo M cifrato e visualizzato in esadecimale e' : ");
        //XOR M + K = C
 		for(int i = 0; i < strlen(PlaintextM)-1; i++) 
		{    
         CypherC[i] = PlaintextM[i] ^ KeyK[i];    
         printf("%X", CypherC[i]);     
        }
        printf("\nIl testo M in chiaro e' : ");
        for(int i = 0; i < strlen(PlaintextM)-1; i++) 
		{
	     //XOR C + K = M 
         PlaintextM[i] = CypherC[i] ^ KeyK[i];   
         printf("%c", PlaintextM[i]); 
        }
        printf("\n");
	  }
	  else if(Scelta==0)
	  {
	  	printf("Chiusura in corso... \n");
	  }
	  else
	  	printf("Comando inesistente.\n");
	 }
	while(Scelta !=0);

	return 0;
 }