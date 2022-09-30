#include <stdio.h>
#include <string.h> //Bibliotek som tar seg av strenger

char navn [100] [100]; //2D-array som kan lagre hver karakter i en streng i �n dimensjon, og strengene i en annen. Asterix gj�r at array-en ikke kun blir read-only.
int poeng [100];
int karakterer[100];

//Sluttverdier som printes ut til slutt
int snittpoeng; //Gjennomsnittspoeng for klassen
int poengrekkefolge [100]; //Elever sine karakterer fra h�yest til lavest
char *navnrekkefolge [20]; //Navn fra h�yest til lavest, h�rer sammen med "poengrekkef�lge"
int hoyest; //"Stjerneeleven"
int lavest; //Eleven som gjorde det "d�rligst"

int antall; //Antall elever


int main(){
    int x = 0; //Teller til for-l�kken.
    
    //Elevantall
	printf("Hvor mange elever er det i klassen?\n");
    scanf("%d", &antall);

    for (x = 0; x < antall; x++){ //Kj�rer inntill registrering av alle elever er fullf�rt

        //Legger til navn
	    printf("\nHva heter elev %d?\n", x + 1); //Elevn p� index 0 er elev 1 osv
        scanf("%s", &navn[x]); //Navnet legges til p� gjeldende plass i listen
            
        //Legger til poeng
        printf("\nHvor mange poeng fikk %s?\n", navn[x]);
        scanf("%d", &poeng[x]); 
    }
    

    //Snittpoeng
    int y = 0; //Til l�kken
    
    //Gjennomsnitt er total sum/antall verdier, og denne l�kken regner ut summen.
    for (y = 0; y < antall; y++){
        snittpoeng = snittpoeng + poeng[y];
    }


    //Finner snittet
    snittpoeng = snittpoeng / antall;
    
    
    //Finner hver elev sin snittkarakter
    int z = 0; //Til l�kken
    for (z = 0; z < antall; z++){ //Kj�rer gjennom hver elev
        int karakter = 6.0 / 100.0 * poeng[z]; //Karakter for gjeldende elev. Poeng ble 0 fordi delestykket ikke fungerte med int. Derfor gjorde jeg den til float.
        karakterer[z] = karakter; //Legger til karakteren i listen
    }


    int a = 0;
    int b = 0; //En annen teller

    int plass = 0; //Hvilken plass eleven er p�

    //Setter elev og poeng i rekkef�lge, fra h�yest til lavest
    
    //Kj�rer gjennom �n gang for hver elev
    for (a = 0; a < antall; a++){
        plass = 0;
        
        //Sammenlikner med andre elever
        for (b = 0; b < antall; b++){ //a er eleven som forl�pig sammenliknes, og b er eleven som a sammenliknes med
            if (poeng[b] >= poeng[a]){ //Er det en annen elev med bedre karakter?
                plass++; //I s� fall detter eleven �n plass ned!
            }
        }
        //Setter de rette elevene p� rett plass i hirearkiet
        poengrekkefolge[plass - 1] = poeng[a];
        navnrekkefolge[plass - 1] = navn[a];
    }
    
    
    printf("\nSnittet ble %d.\n", snittpoeng); //Snitt
    
    //Printer ut hver elev sin karakter
    int i = 0; //Nok en teller
    for (i = 0; i < antall; i++){
        printf("\n%s fikk %d", navn[i], karakterer[i]);
    }

    printf("Elev som fikk flest poeng: \n%s, med %d poeng.", navnrekkefolge[0], poengrekkefolge[0]);
    printf("\nElev som fikk f�rrest poeng: \n%s, med %d poeng.", navnrekkefolge[antall - 1], poengrekkefolge[antall - 1]);
    
    //Elevene rangert
    int c = 0;
    printf("\n");
    for (c = 0; c < antall; c++){ //Er det her navnet C++ kommer fra?
        printf("\n%d.     %s: %d poeng.", c + 1, navnrekkefolge[c], poengrekkefolge[c]);
    }


    return 0;
}
