//Retter som skal med: Pizza, kebab, burger, cola, fanta, urge//Retter som skal med: Pizza, kebab, burger, cola, fanta, urge.

#include <stdio.h>
#include <conio.h>


int kommando = 0; //Tall for brukerinput, er en kommando. Brukes til valg av mat eller drikke, og hvilken vare man vil kjøpe.


//For kvitteringen. Vi trenger separate lister for priser og varer, for at alle prisene kan plusses sammen til slutt.
//Prisene på kvitteringslisten, tar med duplikater
int kvitteringsVarer [100]; //Varene på kvitteringslisten med duplikater, representert som nøkler. 2D array kan lagre flere strenger i listen. Selve strengene i én dimensjon, og bokstavene i strengene i den andre.
//kvitteringPris trengs ikke! Prisen regnes ut til slutt, basert på det som står i kvitteringsVare.

int antall [10]; //Hvor mange er det av hver type vare? 2 pizza, en kabab, ingen burger, 3 cola osv.


int teller = 0; //Teller for plassering av varenøklene i listen kvitteringsVarer. Brukes også til å finne lengden på listen.



const int matVarer = 5; //Antal matvarer
const int drikkeVarer = 4; //Antall drikkevarer

//Pizza = 20kr, kebab = 30kr, og burger = 25kr. Cola = 10kr, fanta = 15kr, og urge = 20kr.
const int priser [100] = {20, 30, 15, 30, 40, 20, 15, 10, 20}; //Liste med prisene til matrettene. Navnene hentes fram med elif og kommando-variabelen. Det er vanskelig å lagre flere strenger i en array.
const char varer [100] [20] = {"Pizza", "Kebab", "Burger", "Popcorn", "Salat", "Cola", "Fanta", "Farris", "Urge"};

const int spiseHerPris = 10; //Prisen for å spise på stedet.


int main(){
	
		int typer = matVarer + drikkeVarer; //Finner totalen antall typer varer. Brukes når programmet skal se etter duplikater i kvitteringen, og til bestilling av varer.
	
        while (1){ //Gir mulighet for flere kunder.
            
            //Neste kunden må ikke betale forrige kunders regning!    
            int i = 0;

            for (i = 0; i < teller; i++){ //Går gjennom og tømmer listene
                kvitteringsVarer[i] = 0;
                antall[i] = 0;
            }

            teller = 0;


            printf("Velkommen til Kuben fast food!\n\n\n");
           
            while (1)//Kunden gjør bestillingen. Her velger jeg å bruke break-statement, som avslutter løkken den kjører i.
                        //Dette gjør det lettere å holde styr på hvilke løkker som skal avsluttes, i stedet for at alle gjør det når brukeren skriver inn 0. While-løkken vil kjøre inntil videre.
            {
                printf("Vil du kjøpe mat eller drikke?\n\n");
                printf("Skriv 1 for mat, 2 for drikke. Trykk 0 for å gjøre ferdig bestilling.\n");
                scanf("%d", &kommando); //"%d" forteller at et siffer skal skrives inn. "& brukes i neste argument til å fortelle at verdien skal lagres i variabelen "command".
     			system("cls"); //Tømmer vinduet, mye ryddigere
     			
     
                //Matprosedyre
                if (kommando == 1){ //Kjører prosedyren for mat hvis bruker velger "1"
                    printf("Kjøper mat.\n");
                 
                    //Kunden legger til varer
                    while (1)
                    {  
                        int a = 0; //Teller for printing av matvaremeny  
                        
                        //Printer ut menyen for matvarene
                        printf("\nMenyen er: ");
                        for (a = 0; a < matVarer; a++){
                            printf("%s: %dkr (trykk %d)    ", varer[a], priser[a], a + 1); //Henter og printer varenavn, priser, og nøklene til varene, én for én
                        }
                        printf("\n\n");
                        
                        printf("Trykk 0 for å gå videre.\n");
                       
                       
                        //Ny vare legges til
                        scanf("%d", &kommando); //Hvilken vare?
                       
                        //Avslutter løkken hvis kunden går videre
                        if (kommando == 0){
                            kommando = -1; //Unngår forveksling med kommando i den ytre løkken
                            system("cls"); //Tømmer terminalvinduet, for ryddighetens skyld
                            break; //Avslutter løkken
                        }
                             
                        else{
                             //Legger til varer på kvitteringen, representert av en "nøkkel". Varen legges til nederst på listen takket være teller, som øker med én hver gang.
                            kvitteringsVarer[teller] = kommando;
                            printf("\n%s lagt til\n\n", varer[kommando]);
                            teller++; //Neste vare på listen. Holder også styr på lengden.
                        }
                    }
                }
                //Drikkeprosedyre
                if (kommando == 2){ //Kjører prosedyren for drikke hvis bruker velger "2"
                    printf("Kjøper drikke.\n");
                 
                    //Kunden legger til varer
                    while (1)
                    {
                        int b = 0; //Teller for printing av drikkevaremeny  
                        //int test = matVarer;
                        //for (test = matVarer; test < typer; test++){
                        //    printf("%d", b - matVarer + 1);
                        //}

                        //Printer ut menyen for drikkevarene
                        printf("\nMenyen er: ");
                        for (b = matVarer; b < typer; b++){ //Starter på drikkevarene. Stopper når siste drikke varen, altså med plasseringen typer i listen, er printet ut.
                            printf("%s: %dkr (trykk %d)    ", varer[b], priser[b], b - matVarer + 1); //- matVarer kompanserer for at b starter på matVarer
                        }
                        printf("\n\n");
                        printf("Trykk 0 for å gå videre.\n");
                       
                       
                        //Ny vare legges til
                        scanf("%d", &kommando); //Hvilken vare?
                       
                        //Avslutter løkken hvis kunden går videre
                        if (kommando == 0){
                            kommando = -1; //Unngår forveksling med kommando i den ytre løkken
                            system("cls"); //Tømmer vinduet for ryddighet
                            break; //Avslutter løkken
                        }
                             
                        else{
                            //Legger til varer på kvitteringen, representert av en "nøkkel". Varen legges til nederst på listen takket være teller, som øker med én hver gang.
                            kvitteringsVarer[teller] = kommando + matVarer; //Kunde-input + drikkeVarer, fordi alt derfra og opp er drikke.
                            printf("\n%s lagt til\n\n", varer[kommando + matVarer - 1]); //Listen begynner på 0 og ikke én.
							teller++; //Neste vare på listen.
                        }
                    }
                }
                if (kommando == 0){ //Bestillingen er ferdig
                	system("cls");
                    break;
                }
            }
            

            //Finner antall av hver vare
            int kvantitet = 0; //Hvor mange kunden har bestilt av den varen som foreløpig sjekkes

            int y = 0; //Til løkken som tester for hver varetype
            int z = 0; //Til løkken som tester for hver enkelt vare
			int type = 0;
			

			//y er varetypen som sammenliknes, z er varen på kvitteringen som y sammenliknes med
            for (y = 0; y < typer; y++){ //Ser hvor mange vi har av hver vare, type for type. Y er varetypen som sees gjennom, og første varetypen har nøkkel 1. Derfor starter Y på 1.
                type = y + 1; //Neste varetype som sjekkes

                for (z = 0; z < teller; z++){ //Søker gjennom kvitteringen for duplikater
                    if (kvitteringsVarer[z] == type){ //Har vi en match?
                        kvantitet++;
                    }
				}
			    z = 0;
                
            	//Vi har "kvantitet" anntall av varen
            	antall[y] = kvantitet; //Legger til kvantiteten av gjeldende type vare i listen antall. y er nøkkelen for typen, så antallet vil legges på rett plassering avhengig av den.
            	kvantitet = 0; //Neste vare sin kvantitet starter på 0, før den tekkes opp.
            
            }


            //Spise på stedet?
            int spiseHer = 0;

            printf("Trykk 1 for å spise her: %dkr\n", spiseHerPris);
            scanf("%d", &spiseHer);


            //Printe kvitteringen
            int totalPris = 0; //Sluttsum

            int x = 0;
            
            //Oversetter varer til navn og pris, og printer ut kvitteringen linje for linje
            int pris = 0; //Total pris for antall varer av en varetype.

            for (x = 0; x < typer; x++){ //Søker gjennom de ulike varetypene. X blir varetypen.
                
                int pris = priser[x] * antall[x]; //Henter fram riktig pris på varen fra prislisten, og ganger med anntall varer av typen man har kjøpt.
                
                if (antall[x] != 0){ //Null av en vare i listen "antall" er ikke kjøpt. Disse skal ikke med på kvitteringen.
                    printf("%d x %s: %dkr\n", antall[x], varer[x], pris); //Printer vare og pris på kvitteringen
                    totalPris = totalPris + pris; //Teller opp sluttsummen
                }
        	}

            if (spiseHer == 1){
                printf("Spise her: %dkr", spiseHerPris);
                totalPris = totalPris + spiseHerPris;
            }

            printf("\nTotal pris: %d\n\n", totalPris);
           // printf("Trykk en hvilken som helst tast");
           // scanf("");
            printf("\n\nHa en fin dag videre!");
            sleep(15);
            system("cls");
        }
      return 0;
}
