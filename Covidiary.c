/* 
COVIDIARY
Group Pekanbaru

Hansel Matthew	- 1806194914
George			- 1806194883
*/

// Program COVIDIARY merupakan program yang diciptakan untuk mendukung penangangan pandemi 
// COVID-19 khususnya di Indonesia. Program ini memiliki keunggulan yaitu efisien dan ringan 
// untuk dijalankan sehingga cocok untuk diaplikasikan pada wilayah negara Indonesia.
// Rom used = 6.25KB || Ram used = 7.8MB 

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
#define MAX_LIMIT 100
#define MIDH 20
#define MIDV 5

//Global Variable
int i, totaldata = 0;

//Data struct
struct data{
	int tahun;
	int bulan;
	int tanggal;
	int jam;
	int menit;
	char tempat[MAX_LIMIT];
	struct data *next;
	};

struct data *start = NULL;

//Struct object for search
struct data search;

//function prototyping
int inputerror();
int yesorno();
void help();
void inputdata();
void googlemaps();
void display();
void exitt();
void searching();
void gotoxy(int x,int y);
void delay(unsigned int mseconds);
void sort();
void edit_data();
void deletedata();

int main(){
	//Transform cmd
	system("cls");
	system("color f0");

	//Main Menu Display
	gotoxy(MIDH,MIDV+2);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 COVIDIARY");
	printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(MIDH,MIDV+5);
	printf("\xDB\xDB\xDB\xDB\xB2 1. Data Input");
	gotoxy(MIDH,MIDV+7);
	printf("\xDB\xDB\xDB\xDB\xB2 2. Data Search");
	gotoxy(MIDH,MIDV+9);
	printf("\xDB\xDB\xDB\xDB\xB2 3. Display All Data");
	gotoxy(MIDH,MIDV+11);
	printf("\xDB\xDB\xDB\xDB\xB2 4. Edit Data");
	gotoxy(MIDH,MIDV+13);
	printf("\xDB\xDB\xDB\xDB\xB2 5. Remove Data");
	gotoxy(MIDH,MIDV+15);
	printf("\xDB\xDB\xDB\xDB\xB2 6. GoogleMaps Search");
	gotoxy(MIDH,MIDV+17);
	printf("\xDB\xDB\xDB\xDB\xB2 8. Help");
	gotoxy(MIDH,MIDV+19);
	printf("\xDB\xDB\xDB\xDB\xB2 9. Exit");
	gotoxy(MIDH,MIDV+21);
    printf("Input: ");
	switch(getch()){
	default:
		gotoxy(MIDH,MIDV+24);
		printf("Invalid Input. Press enter to continue...\n\n");
		if(getch()) system("cls");
		main();
	break;
	case '1':
		//Input data program
		inputdata();
	break;
	case '2':
		//Searching program
		searching();
	break;
	case '3':
		//display all program
		display();
	break;
	case '4':
		edit_data();
	break;
	case '5':
		deletedata();
	break;
	case '6':
		//google maps search program
		googlemaps();
	break;
	case '8':
		//display help program
		help();
	break;
	case '9':
		//exit program
		exitt();
	break;
	}
}

void edit_data(){
	//variable declaration
	int i=1,j=8,edit_index;

	int input_tahun;
	int input_bulan;
	int input_tanggal;
	int input_jam;
	int input_menit;
	char input_tempat[MAX_LIMIT];

	//display menu
	system("cls");
	gotoxy(MIDH,MIDV+1);
	printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb DATA EDIT \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
	
	gotoxy(MIDH,MIDV+4);
	printf("\xDB\xDB\xDB\xDB\xB2 Which data you want to edit: ");

	gotoxy(MIDH,MIDV+7);
	printf("  DATE ========== TIME ========== LOCATION =========");
	gotoxy(MIDH+20,MIDV+8);

	struct data *t;
	t = start;

	if (t == NULL){
		printf("Linked list is empty\n");
		gotoxy(MIDH,MIDV+11);
		printf("Press enter to return to main menu...");
		getchar();
		main();
	}
	else{
		while (t->next != NULL){
			gotoxy(MIDH,MIDV+j);
			printf("%d. %d/%d/%d",i,t->tanggal, t->bulan, t->tahun);
			gotoxy(MIDH+18,MIDV+j);
			printf("%02d:%02d",t->jam, t->menit);
			gotoxy(MIDH+35,MIDV+j);
			printf("%s",t->tempat);
			gotoxy(MIDH+50,MIDV+j);
			printf("\n\n");
			i++;
			j++;
			t = t->next;
		}
		gotoxy(MIDH,MIDV+j);
		printf("%d. %d/%d/%d",i,t->tanggal, t->bulan, t->tahun);
		gotoxy(MIDH+18,MIDV+j);
		printf("%02d:%02d",t->jam, t->menit);
		gotoxy(MIDH+35,MIDV+j);
		printf("%s",t->tempat);
		gotoxy(MIDH+50,MIDV+j);
		printf("\n\n");
	}

	gotoxy(MIDH,MIDV+5);
	printf("Input data index: ");
	scanf("%d",&edit_index);

	if(!(edit_index == 0 || edit_index > totaldata)){
		system("cls");
		gotoxy(MIDH,MIDV+1);
		printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb DATA EDIT \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
		gotoxy(MIDH,MIDV+5);
		printf("Date (dd/mm/yyyy)\t\t: ");
		scanf(  "%02d/%02d/%04d", &input_tanggal, &input_bulan, &input_tahun);
		gotoxy(MIDH,MIDV+6);
		printf("Time (hh:mm)\t\t\t: ");
		scanf(  "%02d:%02d", &input_jam, &input_menit);
		gotoxy(MIDH,MIDV+7);
		printf("Location\t\t\t: ");
		getchar();
		fgets(input_tempat,MAX_LIMIT,stdin);

		t = start;
		for(i=0;i<edit_index-1;i++) t = t->next;
		t->tahun = input_tahun;
		t->bulan = input_bulan;
		t->tanggal = input_tanggal;
		t->jam = input_jam;
		t->menit = input_menit;
		strcpy(t->tempat,input_tempat);
	}
	else{
		getchar();
		gotoxy(MIDH,MIDV+j+2);
		printf("Invalid Input.");
	}
	gotoxy(MIDH,MIDV+9);
	printf("Press enter to return to main menu...");
	getchar();
	sort();
	main();
}

int inputerror(){
	//print error warning
	printf("Invalid Input\n");
}

int yesorno(){
	//yes or no question
	char ch;
	scanf(" %c",&ch);
	if (ch == 'y' || ch == 'Y'){
		return 1;
	}
	else if(ch == 'n' || ch == 'N'){
		return 0;
	}
	else{
		inputerror();
		printf("Type y for yes and n for no: ");
		yesorno();
	}
}

void help(){
	//print help information
	system("cls");
	gotoxy(MIDH,MIDV+3);
	printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb HELP \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
	gotoxy(0,MIDV+5);
	printf ("Covidiary is a program that acts as your diary to track where you've been and when you've been there.");
	gotoxy(0,MIDV+6);
	printf("This program has 4 features: ");
	gotoxy(0,MIDV+7);
	printf("1.) DATA INPUT, to input your activity into the system");
	gotoxy(0,MIDV+8);
	printf("2.) DATA SEARCH, to search your location and time at a specific location and time ");
	gotoxy(0,MIDV+9);
	printf("3.) DATA DISPLAY, to see where you've been, making contact tracing easier");
	gotoxy(0,MIDV+10);
	printf("4.) DATA EDIT, to edit a data on the database");
	gotoxy(0,MIDV+11);
	printf("5.) DATA REMOVE, to remove a data on the database");
	gotoxy(0,MIDV+12);
	printf("6.) GOOGLEMAPS SEARCH, to find your location at a certain time on google maps");
	gotoxy(0,MIDV+14);
	printf("How to use :");
	gotoxy(0,MIDV+15);
	printf("1.)Choose Data Input");
	gotoxy(0,MIDV+16);
	printf("\tInput your date,time and location. The value will be stored in the system.");
	gotoxy(0,MIDV+17);
	printf("2.)Choose Data Search");
	gotoxy(0,MIDV+18);
	printf("\tInput your search value, it could be a date or location.");
	gotoxy(0,MIDV+19);
	printf("\tThe system will print the existing data at that time or location ");
	gotoxy(0,MIDV+20);
	printf("3.)Choose Display All Data");
	gotoxy(0,MIDV+21);
	printf("\tThe system will print all stored data");
	gotoxy(0,MIDV+22);
	printf("4.)Choose Edit Data");
	gotoxy(0,MIDV+23);
	printf("\tChoose which entry you want to edit");
	gotoxy(0,MIDV+24);
	printf("\tThe system will edit your data on the database");
	gotoxy(0,MIDV+25);
	printf("5.)Choose Remove Data");
	gotoxy(0,MIDV+26);
	printf("\tChoose which entry you want to remove,");
	gotoxy(0,MIDV+27);
	printf("\tThe system will remove your data on the database");
	printf("6.)Choose GoogleMaps Search");
	gotoxy(0,MIDV+28);
	printf("\tChoose which entry you want to search,");
	gotoxy(0,MIDV+29);
	printf("\tThe system will search for the desired location on google maps");
	gotoxy(0,MIDV+31);
	printf("Date Format = dd/mm/yyyy");
	gotoxy(0,MIDV+32);
	printf("Time Format = hh:mm");
	gotoxy(0,MIDV+34);
	printf("Press enter to return to the main menu... ");
	getchar();
	main();
}

void swap(int *a, int *b){
    int tukar = *a;
    *a = *b;
    *b = tukar;
}

void sort(){
	//Node current will point to head  
    // struct node *current = begin, *index = NULL;  
	struct data *current, *after = NULL;  
	current = start;
    // int temp;  
	char temp[100];
          
    if(start == NULL) {  
        printf("No Data Were Found");  
    }  
    else {  
        while(current != NULL) {  
            after = current->next;  
            while(after != NULL) {  
                if(current->tahun > after->tahun){
                    swap(&(current->tahun) 		, &(after->tahun));
                    swap(&(current->bulan) 		, &(after->bulan));
                    swap(&(current->tanggal) 	, &(after->tanggal));
                    swap(&(current->jam) 		, &(after->jam));
                    swap(&(current->menit) 		, &(after->menit));
                    
                    strcpy(temp,current->tempat);
                    strcpy(current->tempat,after->tempat);
                    strcpy(after->tempat,temp);  
				}
				else if(current->tahun == after->tahun){
					if(current->bulan > after->bulan){
						swap(&(current->tahun) 		, &(after->tahun));
						swap(&(current->bulan) 		, &(after->bulan));
						swap(&(current->tanggal) 	, &(after->tanggal));
						swap(&(current->jam) 		, &(after->jam));
						swap(&(current->menit) 		, &(after->menit));

						strcpy(temp,current->tempat);
						strcpy(current->tempat,after->tempat);
						strcpy(after->tempat,temp);  
					}
					else if(current->bulan == after->bulan){
						if(current->tanggal > after->tanggal){
							swap(&(current->tahun) 		, &(after->tahun));
							swap(&(current->bulan) 		, &(after->bulan));
							swap(&(current->tanggal) 	, &(after->tanggal));
							swap(&(current->jam) 		, &(after->jam));
							swap(&(current->menit) 		, &(after->menit));

							strcpy(temp,current->tempat);
							strcpy(current->tempat,after->tempat);
							strcpy(after->tempat,temp); 
						}
						else if(current->tanggal == after->tanggal){
							if(current->jam > after->jam){
								swap(&(current->tahun) 		, &(after->tahun));
								swap(&(current->bulan) 		, &(after->bulan));
								swap(&(current->tanggal) 	, &(after->tanggal));
								swap(&(current->jam) 		, &(after->jam));
								swap(&(current->menit) 		, &(after->menit));

								strcpy(temp,current->tempat);
								strcpy(current->tempat,after->tempat);
								strcpy(after->tempat,temp); 
							}
							else if(current->jam == after->jam){
								if(current->menit > after->menit){
									swap(&(current->tahun) 		, &(after->tahun));
									swap(&(current->bulan) 		, &(after->bulan));
									swap(&(current->tanggal) 	, &(after->tanggal));
									swap(&(current->jam) 		, &(after->jam));
									swap(&(current->menit) 		, &(after->menit));

									strcpy(temp,current->tempat);
									strcpy(current->tempat,after->tempat);
									strcpy(after->tempat,temp); 	
								}
							}
						}
					}
				}
			after = after->next;  
			}
		current = current->next;  
		}           
    }  
}

void inputdata(){
	//print inputdata menu display
	system("cls");
	gotoxy(MIDH,MIDV+3);
	printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb DATA INPUT \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");

	//Variable Input
	int input_tahun;
	int input_bulan;
	int input_tanggal;
	int input_jam;
	int input_menit;
	char input_tempat[MAX_LIMIT];

	//input data
	gotoxy(MIDH,MIDV+5);
	printf("Date (dd/mm/yyyy)\t\t: ");
	scanf(  "%02d/%02d/%04d", &input_tanggal, &input_bulan, &input_tahun);
	gotoxy(MIDH,MIDV+6);
	printf("Time (hh:mm)\t\t\t: ");
	scanf(  "%02d:%02d", &input_jam, &input_menit);
	gotoxy(MIDH,MIDV+7);
	printf("Location\t\t\t: ");
	getchar();
	fgets(input_tempat,MAX_LIMIT,stdin);
	gotoxy(MIDH,MIDV+9);
	
	struct data *t, *temp;
	t = (struct data*)malloc(sizeof(struct data));
	t->tahun = input_tahun;
	t->bulan = input_bulan;
	t->tanggal = input_tanggal;
	t->jam = input_jam;
	t->menit = input_menit;
	strcpy(t->tempat,input_tempat);
	totaldata++;

	if (start == NULL) {//no data
	start = t;
	start->next = NULL;
	// return;
	}
	else{
		//There is data
		temp = start;
		while (temp->next != NULL) temp = temp->next;
		temp->next =t;
		t->next =NULL;
	}


	//repetitive input
	printf("Do you want to input again? (y/n): ");


	//check input again
	if(yesorno()){
		inputdata();
	}
	else{
		getchar();
		main();
	}
}

void searching(){
	//variable declaration
	int j,searchexit=0,found=0;
	char psearch;
	searchexit = 0;

	struct data *t;
	t = start;


	//searching program
	while (searchexit == 0){
		system("cls");
		gotoxy(MIDH,MIDV+2);
		printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb DATA SEARCH \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
		gotoxy(MIDH,MIDV+4);
		printf("Search by:");
		gotoxy(MIDH,MIDV+5);
		printf("1. Date");
		gotoxy(MIDH,MIDV+6);
		printf("2. Place");
		gotoxy(MIDH,MIDV+8);
		printf("Press anything else to return to main menu.");
		gotoxy(MIDH,MIDV+9);
		printf("Input: ");
		psearch=getch();
		switch (psearch){
			default:
				//go back to main menu
				main();
			break;
			case '1':
				//date search menu
				j=8;
				system("cls");
				gotoxy(MIDH,MIDV+2);
				printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb DATA SEARCH \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
				
				//date input
				gotoxy(MIDH,MIDV+5);
				printf("Input date (dd/mm/yyyy)\t\t: ");
				scanf("%02d/%02d/%04d", &search.tanggal, &search.bulan, &search.tahun);
				getchar();
				gotoxy(MIDH,MIDV+7);
				printf("  DATE ========== TIME ========== LOCATION =========");
				gotoxy(MIDH+20,MIDV+8);
				
				while (t != NULL){
					if (t->tahun == search.tahun && t->bulan == search.bulan && t->tanggal == search.tanggal){
						gotoxy(MIDH,MIDV+j);
						printf ("%d/%d/%d", t->tanggal, t->bulan, t->tahun);
						gotoxy(MIDH+18,MIDV+j);
						printf("%d:%d", t->jam, t->menit);
						gotoxy(MIDH+35,MIDV+j);
						printf("%s", t->tempat);
					}
					t = t->next;
				}
				
				//search again
				gotoxy(MIDH,MIDV+5+j);
				printf("Do you want to search again? (y/n): ");
				if(yesorno()){
					searchexit = 0;
				}else{
					searchexit = 1;
				}
				getchar();
				break;
			case '2':
				j=8;
				//location search menu
				system("cls");
				gotoxy(MIDH,MIDV+2);
				printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb DATA SEARCH \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
				
				//location input
				gotoxy(MIDH,MIDV+5);
				printf("Input location : ");
				fgets(search.tempat,MAX_LIMIT,stdin);
				gotoxy(MIDH,MIDV+7);
				printf("  DATE ========== TIME ========== LOCATION =========");
				gotoxy(MIDH+20,MIDV+8);

				while (t != NULL){
					if (strcmpi (t->tempat, search.tempat) == 0){
						gotoxy(MIDH,MIDV+j);
						printf ("%d/%d/%d", t->tanggal, t->bulan, t->tahun);
						gotoxy(MIDH+18,MIDV+j);
						printf("%d:%d", t->jam, t->menit);
						gotoxy(MIDH+35,MIDV+j);
						printf("%s", t->tempat);
						gotoxy(MIDH+50,MIDV+j);
						printf("\n\n");
						j++;
						found++;
					}
					t = t->next;
				}
		
				//search again
				gotoxy(MIDH,MIDV+5+j);
				printf("Do you want to search again? (y/n): ");
				if(yesorno()){
					searchexit = 0;
				}else{
					searchexit = 1;
				}
				getchar();			
			break;
		}
	}
	main();
}

void deletedata(){
	system("cls");
	struct data *t;
	t = start; 
	if(t==NULL){
		gotoxy(MIDH,MIDV+3);
		printf("Linked list is empty. Please input your data first.");
		gotoxy(MIDH,MIDV+9);
		printf("Press enter to return to main menu...");
		getchar();
	}
	else{
		int pos, i=0, j = 8;
		
		gotoxy(MIDH,MIDV+1);
		printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb REMOVE DATA \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
		gotoxy(MIDH,MIDV+7);
		printf("  DATE ========== TIME ========== LOCATION =========");
		gotoxy(MIDH+20,MIDV+8);

		

		if (t == NULL) {
		printf("Linked list is empty\n");
		}
		else{
			while (t->next != NULL){
				gotoxy(MIDH,MIDV+j);
				printf("%d. %d/%d/%d",i+1,t->tanggal, t->bulan, t->tahun);
				gotoxy(MIDH+18,MIDV+j);
				printf("%02d:%02d",t->jam, t->menit);
				gotoxy(MIDH+35,MIDV+j);
				printf("%s",t->tempat);
				gotoxy(MIDH+50,MIDV+j);
				printf("\n\n");
				i++;
				j++;
				t = t->next;
			}
			gotoxy(MIDH,MIDV+j);
			printf("%d. %d/%d/%d",i+1,t->tanggal, t->bulan, t->tahun);
			gotoxy(MIDH+18,MIDV+j);
			printf("%02d:%02d",t->jam, t->menit);
			gotoxy(MIDH+35,MIDV+j);
			printf("%s",t->tempat);
			gotoxy(MIDH+50,MIDV+j);
			printf("\n\n");
		}
		
		gotoxy(MIDH,MIDV+4);
		printf("\xDB\xDB\xDB\xDB\xB2 Which data you want to remove: ");
		gotoxy(MIDH,MIDV+5);
		printf("Input data index: ");
		scanf("%d", &pos);
		getchar();

		if(!(pos == 0 || pos > totaldata)){
			pos = pos-1;
			if (start == NULL) 
			return;

			struct data *temp = start;
			if (pos == 0) { 
				start = temp->next;
				free(temp);               
				main(); 
			} 

			for (i=0; temp!=NULL && i<pos-1; i++) temp = temp->next; 
			if (temp == NULL || temp->next == NULL) return; 

			struct data *next = temp->next->next; 
			free(temp->next);  
			temp->next = next; 
		}
		else{
			gotoxy(MIDH,MIDV+j+2);
			printf("Invalid Input.");
			gotoxy(MIDH,MIDV+j+3);
			printf("Press enter to return to main menu...");
			getchar();
		}
	}
    main();
} 

void googlemaps(){
	//variable declaration
	int i=1,j=10,maps_index;
	system("cls");
	struct data *t;
	t = start;
	//googlemaps menu display
	gotoxy(MIDH,MIDV+1);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 powered by GOOGLEMAPS");
	printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

	//empty data handling
	if(t==NULL){
		gotoxy(MIDH,MIDV+3);
		printf("Linked list is empty. Please input your data first.");
	}
	else{
		//base address
		char str[100],address[100]="https://www.google.com/maps/search/?api=1&query=";
		//location search
		gotoxy(MIDH,MIDV+4);
		printf("\xDB\xDB\xDB\xDB\xB2 Which data you want to search on google maps: ");
		gotoxy(MIDH,MIDV+9);
		printf("  DATE ========== TIME ========== LOCATION =========");
		gotoxy(MIDH+20,MIDV+8);
		while (t->next != NULL){
			gotoxy(MIDH,MIDV+j);
			printf("%d. %d/%d/%d",i,t->tanggal, t->bulan, t->tahun);
			gotoxy(MIDH+18,MIDV+j);
			printf("%02d:%02d",t->jam, t->menit);
			gotoxy(MIDH+35,MIDV+j);
			printf("%s",t->tempat);
			gotoxy(MIDH+50,MIDV+j);
			printf("\n\n");
			i++;
			j++;
			t = t->next;
		}
		gotoxy(MIDH,MIDV+j);
		printf("%d. %d/%d/%d",i,t->tanggal, t->bulan, t->tahun);
		gotoxy(MIDH+18,MIDV+j);
		printf("%02d:%02d",t->jam, t->menit);
		gotoxy(MIDH+35,MIDV+j);
		printf("%s",t->tempat);
		gotoxy(MIDH+50,MIDV+j);
		printf("\n\n");

		//input location index
		gotoxy(MIDH,MIDV+6);
		printf("Input data index: ");
		scanf("%d",&maps_index);

		
			getchar();
			maps_index-=1;

			t = start;
			for(i=0;i<maps_index;i++) t = t->next;
		
			//change location string into address format
			strcpy(str,t->tempat);
			while (str[i]){
				if (isspace(str[i])) 
				str[i]='+';
				i++;
			}
			
			//address making
			strcat(address,str);

			//open address on default browser
			ShellExecute(NULL, "open", address, NULL, NULL, SW_SHOWNORMAL);
			gotoxy(MIDH,MIDV+j+2);
			printf("Opening Google Maps.........");
	
	}
	//return to main menu
	gotoxy(MIDH,MIDV+j+3);
	printf("Press enter to return to main menu...");
	getchar();
	main();
}

void gotoxy(int x,int y)
{
	//change cursor location
	printf("%c[%d;%df",0x1B,y,x);
}

void display(){
	//variable declaration
	int i=1,j=8;

	//display menu
	system("cls");
	gotoxy(MIDH,MIDV+5);
	printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb DATA DISPLAY \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
	gotoxy(MIDH,MIDV+7);
	printf("  DATE ========== TIME ========== LOCATION =========");
	gotoxy(MIDH+20,MIDV+8);

	//empty data handling
	// if(totaldata==0) printf("No Data Were Found");

	struct data *t;
	t = start;

	if (t == NULL) {
	printf("Linked list is empty\n");
	}
	else{
		while (t->next != NULL){
			gotoxy(MIDH,MIDV+j);
			printf("%d. %d/%d/%d",i,t->tanggal, t->bulan, t->tahun);
			gotoxy(MIDH+18,MIDV+j);
			printf("%02d:%02d",t->jam, t->menit);
			gotoxy(MIDH+35,MIDV+j);
			printf("%s",t->tempat);
			gotoxy(MIDH+50,MIDV+j);
			printf("\n\n");
			i++;
			j++;
			t = t->next;
		}
		gotoxy(MIDH,MIDV+j);
		printf("%d. %d/%d/%d",i,t->tanggal, t->bulan, t->tahun);
		gotoxy(MIDH+18,MIDV+j);
		printf("%02d:%02d",t->jam, t->menit);
		gotoxy(MIDH+35,MIDV+j);
		printf("%s",t->tempat);
		gotoxy(MIDH+50,MIDV+j);
		printf("\n\n");
	}
	
	//return to main menu
	gotoxy(MIDH,MIDV+j+2);
	printf("Press enter to return to main menu...");
	getchar();
	main();
}

void delay(unsigned int mseconds)
{
	//execute delay
    clock_t goal = mseconds + clock();
    while (goal > clock());
}	

void exitt(){
	//print exit menu
	system("cls");
	gotoxy(MIDH,MIDV+3);
    printf("Thank you for using this program and dont forget to");
	gotoxy(MIDH+20,MIDV+4);
	printf("STAY AT HOME!");
	gotoxy(MIDH,MIDV+7);
	printf("Exiting.....\n\n\n");
	delay(3000);

	//exit program
	exit(0);
}