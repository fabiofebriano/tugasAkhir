#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

int HasilSkor;
char Area[40][80];

void printBoard();
void StartGame();
//void debris();
void menu();
void delay();
void timer();


int gotoxy(int x,int y)
{
    COORD coord = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

int gotoxy(int,int);

void board(){
//untuk ngeprint board
        for (int i = 0; i < 40; i++) {
        for(int j = 0; j < 80; j++){
            if(i==0 || i==39 || j==0 || j==79){
                Area[i][j] = '#';
            }
            else Area[i][j] = ' ';

            printf("%c", Area[i][j]);
        }
        printf("\n");
    }

}

int pswt = 0; //dijadiin variabel global biar setiap loop return scorenya ngga kembali 0
void spaceShip(){

	int a,b,c,i;
	char obj = 'X';
		
	puts("# # # # # # # # # # # # # # #     SCOREBOARD    # # # # # # # # # # # # # # # #");
	puts("~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~");
	printf(" - - - - - - - - - - - - - - - - - -  %d  - - - - - - - - - - - - - - - - - - - \n",pswt);
	puts("~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~");
	// print scoreboardnya
    board();
    
    a=38;
    b=42;
	//lokasi start pswt
    gotoxy(a,b);
    printf("%c",obj);
    
while( pswt < 2 ) //bila batas poin tercukupi maka stop loop smntr aku buat 2 biar test lbh cpt
{
	int k = 0;
    if(kbhit())
    {
    c=getch();
        if(c==72){
        	// untuk maju
        	++k;
			b -= k;
			if (Area[38][42-k]){
				printf("\b "); 
				// "\b" = backspace
			}
			if (b == 4){
				pswt = pswt + 1; // menambahkan score
				system("cls"); // for clear screen
				return spaceShip();
			}
		}
        

        if(c==80){
        	// untuk mundur
        	++k;
			b+=k;
			if (Area[38][42+k]){
				printf("\b ");
			}
			if (b == 43){
				system("cls");
				return spaceShip();
			}
		}
        

	 obj = 'X'; // pesawatnya
     gotoxy(a,b);
     printf("%c",obj);

     }
}

   //rencana mau buat if press enter maka return menu tp masih malas
   system("cls");
   printf("YOU WIN !!!\n");delay();delay();
   
   system("cls");
   return menu();
}


void StartGame(){
	
    spaceShip();
//    debris(Area); susah kalo blm nemu sampek waktu deadline gausa di inputin aja
	timer();
    
}

void menu(){
	pswt = 0;
    puts("Welcome to Space Race, Have Fun!");
    puts("================================");
    puts(" ");
    puts("1. Lets Race!");
    puts("2. I'm done.\n");
    
    int choice=0;
    do{
        printf("Select -> ");
        scanf("%d", &choice); getchar();
    } while (choice < 1 || choice > 2);
    
    switch (choice){
        case 1:
			system("cls");
            StartGame();
            break;
        case 2:
			system("cls");
            printf("Adios!\n");
            break;
    }
    
}

void delay() {
	// memberi jeda
  for(int i = 0; i < 1000000000; i++) {
    ;
  }
}

void timer(){
	// masih belum mau muncul di board nya kalau void timer di taruh di dlm void spaceship malah error mungkin karna tabrakan sama function gotoxy
    for(int i=10; i>=1; i--){
        printf("\r SISA WAKTU TERSISA : %d", i);
        Sleep(1000);
        if (i == 1){
        	system("cls");
            printf("HASIL SKOR : %d (NANTI DI CONNECT KE PUNYA HANS) \n", HasilSkor);
            menu();
            break;
        } 
    }    
}

int main(){
    HasilSkor=10;
    menu();
    
    return 0;
    
}
