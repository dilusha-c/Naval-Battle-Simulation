#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define d 30  //canva size
#define seedValue 48

typedef struct{

	int id_E;
	char typeNotation_E;
	int x_E;
	int y_E;
	int maxAngle_E;
	int minAngle_E;
	int maxVelocity_E;
	int minVelocity_E;
	int maxRange_E;
	int minRange_E;
	float impactPower_E;
	int isDestroy; // check to e is distroyed or not, if E destroy return value 0
	int fireTime_E;// E ship time taken to between tow gun firing
	int n; //number of firings
	float gama;
}escortship;

typedef struct{
	char type_B;
	int id_B;
	int x_B;
	int y_B;
	int maxVelocity_B;
	int minVelocity_B;
	int minAngle_B;
	int maxRange_B;
	float health_B;
	float impactPower_B;
	int fireTime_B;// B ship time taken to between tow gun firing
	int n; //number of firings
	float gama;
}battleship;

// generate random number
int Random(int min,int max){
	return rand()%(max-min+1)+min;
}

//calculate the range
float range(float velocity, float angle){
	return ((pow(velocity,2)*fabs(sin(2*angle)))/10)/100; //convert 100 to 1 for maping
}

//define all the type of battleships values
void define_B_ship(battleship battle[]){

	int maxV = Random(115,130);
	for(int i=0; i<4; i++){
		switch(i+1){
			case 1:
				battle[i].type_B = 'U';
				battle[i].fireTime_B = Random(2,6);
				battle[i].gama =(float)Random(3,6)/100.0; // 3/100 for 3 convert to 0.03
				break;
			case 2:
				battle[i].type_B = 'M';
				battle[i].fireTime_B = Random(5,7);
				battle[i].gama =(float)Random(3,7)/100.0; // 3/100 for 3 convert to 0.03
				break;
			case 3:
				battle[i].type_B = 'R';
				battle[i].fireTime_B = Random(4,8);
				battle[i].gama =(float)Random(4,6)/100.0; // 3/100 for 3 convert to 0.03
				break;
			case 4:
				battle[i].type_B = 'S';
				battle[i].fireTime_B = Random(4,9);
				battle[i].gama =(float)Random(3,6)/100.0; // 3/100 for 3 convert to 0.03
				break;
		}
		battle[i].x_B = Random(10,20);
		battle[i].y_B = Random(10,20);
		battle[i].maxVelocity_B = maxV;
		battle[i].minVelocity_B = 0;
		battle[i].minVelocity_B = 0;
		battle[i].maxRange_B = range(battle->maxVelocity_B,M_PI/4); //maximun range at angle=45
		battle[i].minAngle_B = 0;
		battle[i].health_B = 1;
		battle[i].impactPower_B = 1;
		battle[i].n =0;
	}

}

//define all the type of escort ships values
void define_E_ship(escortship escort[],int B_maxV){

	for(int i=0;i<5;i++){

		escort[i].isDestroy = 1;
		escort[i].n =0;
		escort[i].gama = (float)Random(10,15)/100.0;  // 1/100 FOR 1 conver to 0.01
		switch(i+1){
			case 1:
				escort[i].typeNotation_E = 'A';
				escort[i].minAngle_E = Random(40,60);
				escort[i].maxAngle_E = escort[i].minAngle_E+20;
				escort[i].maxVelocity_E = 1.2*B_maxV;
				escort[i].minVelocity_E = Random(60,90);
				escort[i].impactPower_E = 0.08;
				escort[i].fireTime_E = Random(6,11);
				break;
		       	case 2:
		       		escort[i].typeNotation_E = 'B';
				escort[i].minAngle_E = Random(35,50);
				escort[i].maxAngle_E = escort[i].minAngle_E+30;
				escort[i].maxVelocity_E = Random(100,120);
				escort[i].minVelocity_E = Random(60,85);
				escort[i].impactPower_E = 0.06;
				escort[i].fireTime_E = Random(10,20);
				break;
			case 3:
				escort[i].typeNotation_E = 'C';
				escort[i].minAngle_E = Random(35,60);
				escort[i].maxAngle_E = escort[i].minAngle_E+25;
				escort[i].maxVelocity_E = Random(90,110);
				escort[i].minVelocity_E = Random(70,80);
				escort[i].impactPower_E = 0.07;
				escort[i].fireTime_E = Random(15,20);
				break;
			case 4:
				escort[i].typeNotation_E = 'D';
				escort[i].minAngle_E = Random(20,40);
				escort[i].maxAngle_E = escort[i].minAngle_E+50;
				escort[i].maxVelocity_E = Random(95,100);
				escort[i].minVelocity_E = Random(60,90);
				escort[i].impactPower_E = 0.05;
				escort[i].fireTime_E = Random(12,17);
				break;
			case 5:
				escort[i].typeNotation_E = 'E';
				escort[i].minAngle_E = Random(10,15);
				escort[i].maxAngle_E = escort[i].minAngle_E+70;
				escort[i].maxVelocity_E = Random(100,110);
				escort[i].minVelocity_E = Random(55,85);
				escort[i].impactPower_E = 0.04;
				escort[i].fireTime_E = Random(10,18);
				break;
		}
		if(escort[i].minAngle_E <=45){
			escort[i].maxRange_E = range(escort[i].maxVelocity_E,M_PI/4); //maximum range at angle=45, 
			if(90-escort[i].maxAngle_E<escort[i].minAngle_E){
				escort[i].minRange_E = range(escort[i].minVelocity_E,escort[i].maxAngle_E*M_PI/180);
			}else{
				escort[i].minRange_E = range(escort[i].minVelocity_E,escort[i].minAngle_E*M_PI/180);
			}
		}else{
			escort[i].maxRange_E = range(escort[i].maxVelocity_E,escort[i].minAngle_E*M_PI/180);
			escort[i].minRange_E = range(escort[i].minVelocity_E,escort[i].maxAngle_E*M_PI/180);
		}

	}
}

// finding the E ship in range of B
void B_ship_range(escortship escort[],int x_B,int y_B,int maxRange,int E_ships_id_B[],int *B_range,int E_ship){

	int n = *B_range;
	for(int e = 0;e < E_ship;e++){
		if(escort[e].isDestroy){
			int x = escort[e].x_E - x_B; //different between E x and B x
			int y = escort[e].y_E - y_B; //different between E y and B y
			int r = sqrt(pow(x,2) + pow(y,2)); //distance between E and B
			//if B maximum range smalser than distance between E and B, E is in B attack range
			if(r <= maxRange){
				E_ships_id_B[n] = escort[e].id_E;
				n++;
			}
		}
	}
	*B_range = n;
}

// finding the B ship in range of E
void E_ship_range(escortship escort[],int x_B,int y_B,int E_ships_id_E[],int *E_range,int E_ship){

	int n = *E_range;

	for(int e = 0; e<E_ship;e++){
		if(escort[e].isDestroy){
			int x = x_B - escort[e].x_E; //different between E x and B x
			int y = y_B - escort[e].y_E; //different between E y and B y
			int r = sqrt(pow(x,2) + pow(y,2)); //distent between E and B
			//if E maxRange smaller than and E minRange gerter than distance between E and B, B in E attack range
			if((escort[e].minRange_E <= r) && (r <= escort[e].maxRange_E)){
				E_ships_id_E[n] = escort[e].id_E;
				n++;
			}
		}
	}
	*E_range = n;
}

// calculate the time
float cal_time(int range,int velocity){

	//time = velosity_y/g , angle = asin(range*g/u^2)/2
	float r = (float)range*100.0;
	float angle = asin((r*10)/pow(velocity,2))/2.0;
	return (velocity*sin(angle)/10.0);
}

// save escort ships and battleship ditails to data.txt file
void print_EB_ditails(escortship escort[],battleship *battle,int E_ship,int k,int k_x[],int k_y[]){
	FILE *data;
	data = fopen("data.dat","a");
	if(data == NULL){
		printf("File did not open");
	}
        
	//escort ship ditails
	fprintf(data,"\n\t Escort ship\n");
	fprintf(data,"Number of escort ship: %d\n",E_ship);
	for(int i=0;i<E_ship;i++){
		fprintf(data,"Escort ship id: %d, type: %c\n",escort[i].id_E,escort[i].typeNotation_E);
		fprintf(data,"Position coordinates x: %d, y: %d\n",escort[i].x_E,escort[i].y_E);
		fprintf(data,"Impact power: %.2f\n",escort[i].impactPower_E);
		fprintf(data,"Time take to between tow firing: %d\n",escort[i].fireTime_E);
		fprintf(data,"Shooting angle minimum: %d, maximum: %dn",escort[i].minAngle_E,escort[i].maxAngle_E);
		fprintf(data,"Velocity of shell minimum : %d, maximum: %d\n",escort[i].minVelocity_E,escort[i].maxVelocity_E);
		fprintf(data,"Minimum range: %d, maximum range: %d\n",escort[i].minRange_E*100,escort[i].maxRange_E*100); 
		fprintf(data,"Gama value: %.2f\n\n",escort[i].gama);
	}
        
	//battleship ditails
	fprintf(data,"\t Battleship\n");
	fprintf(data,"Battleship type : %c\n",battle->type_B);
	fprintf(data,"Battleship Time take to between tow firing, %d\n",battle->fireTime_B);
	fprintf(data,"Battleship initial position coordinates x: %d, y: %d\n",battle->x_B,battle->y_B);
	fprintf(data,"Battleship traveled point coordinate: \n");
	for(int m =1; m<k; m++){
		fprintf(data,"position %d coordinates x: %d, y: %d\n",m,k_x[m],k_y[m]);
	}
	fprintf(data,"Velocity of shell minimum: %d, maximum: %d\n",battle->minVelocity_B,battle->maxVelocity_B);
	fprintf(data,"Battle ship maximum Range: %d\n",battle->maxRange_B*100);
	fprintf(data,"Battleship gama value: %.2f\n",battle->gama);
	
	fclose(data);
}

//Canvas print to file and display to user
void printf_canvas(char canvas[d][d]){
	FILE *data;
	data = fopen("data.dat","a");
	for(int k = d-1;k>=0;k--){
		for(int j = 0;j<d;j++){
			printf("%c",canvas[k][j]);
			fprintf(data,"%c",canvas[k][j]);
		}
		printf("\n");
		fprintf(data,"\n");
	}
	printf("A,B,C,D,E represent Escort ship\n");
	fprintf(data,"A,B,C,D,E represent Escort ship\n");
	printf("\'# \'- Battle ship starting position\n");
	fprintf(data,"\'#\' represent Battle ship starting position\n");
	printf("\'*\' - Battle ship traveling point\n");
	fprintf(data,"\'*\' - Battle ship traveling point\n");
	fclose(data);
}

void startSimulation(escortship selectescort[],battleship selectbattle[]){

	FILE *data;
	data = fopen("data.dat","a");
	
	int E_ship; //number of E ship
	char canvas[d][d];
	int B_range=0; // number of E ship in B ship attack range
	int E_range=0; // number of E ship, B ship in E ship attack range
	float Endtime =0; // time take to end the battle

	//get the user input for number of escort ship
	printf("Enter the number of escort ship: ");
	while(1){
		if(!(scanf("%d",&E_ship) == 1) ){
			scanf("%*[^\n]");//creat new line for scanf
			
		}else if(E_ship > 0){
			break;
		}
		printf("Invalid input, Enter again:");
	}
	
	int E_ships_id_B[E_ship]; // E ship id  in B ship attack range
	int E_ships_id_E[E_ship]; // E ship id, B ship in E ship attack range
	int attackingOrder[E_ship]; // Attacking order of B
	
	int temp_order = 0; // number element store i attackingOrder[] arry

	//setup Battleship
	battleship battle;
	
	//get battleship type from the user
	int battleType;
	printf("\nBattle ship type\n1-(U)USS lowa(BB-51)\n2-(M)MS king George V\n3-(R)Richeelieu\n4-(S)Sovetsky Soyuz-class\n");
        printf("Enter the type of battle ship: ");
        while(1){
		if(!(scanf("%d",&battleType) == 1) ){
			scanf("%*[^\n]");//creat new line for scanf
			
		}else if(battleType > 0 && battleType < 5){
			break;
		}
		printf("Invalid input, Enter again:");
	}
	battle = selectbattle[battleType-1];
	
	//setup Escort ships
	escortship* escort = malloc(E_ship*sizeof(escortship));
	
	//select random escort ship type and define it to escort(E_ship]
	for(int i=0; i<E_ship; i++){
		int random_temp = Random(0,4); //genarate random value betwwen 0 and 4
		escort[i] = selectescort[random_temp];
		escort[i].id_E = i;
		escort[i].x_E = Random(0,d); //setup x coordinate randomly
		escort[i].y_E = Random(0,d); //setup y coordinate randomly
	}

	//find battleship number of point travel and coordinates
	int k = Random(3,5); // how many position will B travel
	int k_x[k+1]; // create array for store x value
	int k_y[k+1]; // create array for store y value
	k_x[0] = battle.x_B; 
	k_y[0] = battle.y_B; 
	for (int i=1; i<k+1; i++){
		k_x[i]= Random(10,20); // generate x value randomly
		k_y[i]= Random(10,20); // generate y value randomly
	}
	
	//display to user battleship coordinates
	printf("\nBattleship initial position coordinates x: %d, y: %d\n",battle.x_B,battle.y_B);
	printf("Battleship traveled point coordinate, \n");
	for(int m =1; m<k; m++){
		printf("position %d coordinates x: %d, y: %d\n",m,k_x[m],k_y[m]);
	}

	//save to file
	print_EB_ditails(escort,&battle,E_ship,k,k_x,k_y);

	//create battle filed;
	for(int i = 0;i<d;i++){
		for(int j = 0;j<d;j++){
			canvas[i][j] = '-';
		}
	}
	for(int i =0;i<E_ship;i++){
		canvas[escort[i].x_E][escort[i].y_E] = escort[i].typeNotation_E;
	}
	canvas[battle.x_B][battle.x_B] = '#';
	for(int j=0; j<k; j++){
		canvas[k_x[j]][k_y[j]] = '*';
	}
	
	//print the the canvas
	printf_canvas(canvas);

	if(k >= 2){ // if B in 2nd travel possion gun on B get jammed
		battle.minAngle_B = Random(0,30);
		printf("\nGun on the battle ship get jammed at second travel point of battleship. ");
		fprintf(data,"\nGun on the battle ship get jammed jammed at second travel point of battleship. ");
		printf("Now Battle ship minimum attacking angle is:%d\n",battle.minAngle_B);
		fprintf(data,"Now Battle ship minimum attacking angle is:%d\n",battle.minAngle_B);
	}

	for(int z=0; z<k+1; z++){

		//define temporary variable to check next gun fire of E
		int time_EA=0, time_EB=0,time_EC=0, time_ED=0, time_EE=0;

		// B ship attack range
		int temp_Brange = B_range;
		B_ship_range(escort,k_x[z],k_y[z],battle.maxRange_B,E_ships_id_B,&B_range,E_ship);	

		// E ship attack range
		int temp_Erange = E_range;
		E_ship_range(escort,k_x[z],k_y[z],E_ships_id_E,&E_range,E_ship);

		//Finding the B attakcking order
		for(int i=temp_Erange; i<E_range; i++){
			for(int j = temp_Brange; j < B_range; j++){
				if(E_ships_id_B[j] == E_ships_id_E[i]){
					attackingOrder[temp_order] = E_ships_id_B[j];
					E_ships_id_B[j] = -1;
					temp_order++;
				}
			}
		}
				
		for(int j = temp_Brange; j < B_range; j++){
			if(E_ships_id_B[j] != -1){
				attackingOrder[temp_order] = E_ships_id_B[j];
				E_ships_id_B[j] = -1;
				temp_order++;
			}
		}
		
		//Attack
		for(int h=temp_Brange; h<B_range; h++){
			int temp1 = attackingOrder[h];
			float IPn = 1.0;
			while(IPn >=0){
				for(int i=temp_Erange; i<E_range; i++){
				int temp = E_ships_id_E[i];
					if(escort[temp].isDestroy){
						switch(escort[temp].typeNotation_E){
							case 'A':
								if(time_EA <= battle.fireTime_B){//check type A ship can attack
									battle.health_B -= escort[temp].impactPower_E*exp(-escort[i].gama*escort[temp].n);
									escort[temp].n++;
									time_EA = escort[temp].fireTime_E;
								}
								time_EA -= battle.fireTime_B;
								break;
							case 'B':
								if(time_EB <= battle.fireTime_B){//check type B ship can attack
									battle.health_B -= escort[temp].impactPower_E*exp(-escort[i].gama*escort[temp].n);
									escort[temp].n++;
									time_EB = escort[temp].fireTime_E;
                                        	                }
								time_EB -= battle.fireTime_B;
								break;
							case 'C':
								if(time_EC <= battle.fireTime_B){//check type C ship can attack
									battle.health_B -= escort[temp].impactPower_E*exp(-escort[i].gama*escort[temp].n);
									escort[temp].n++;
									time_EC = escort[temp].fireTime_E;
								}
								break;
								time_EC -= battle.fireTime_B;
							case 'D':
								if(time_ED <= battle.fireTime_B){//check type D ship can attack
									battle.health_B -= escort[temp].impactPower_E*exp(-escort[i].gama*escort[temp].n);
									escort[temp].n++;
									time_ED = escort[temp].fireTime_E;
								}
								time_ED -= battle.fireTime_B;
								break;
							case 'E':
								if(time_EE <= battle.fireTime_B){//check type E ship can attack
									battle.health_B -= escort[temp].impactPower_E*exp(-escort[i].gama*escort[temp].n);
									escort[temp].n++;
									time_EE = escort[temp].fireTime_E;
								}
								time_EE -= battle.fireTime_B;
								break;
						}
					}
				}
				IPn -=battle.impactPower_B*exp(-battle.gama*battle.n);
				battle.n++;
				if(battle.health_B <= 0){
					break;
				}
			}
			escort[temp1].isDestroy = 0;
		}
		
		// calculate the time to end the battle
		Endtime += (battle.fireTime_B+cal_time(battle.maxRange_B,battle.maxVelocity_B));

		//check B is going shink or not
		if(battle.health_B <= 0){
			printf("\nB is shank\n");
			fprintf(data,"\nB is shank\n");
			printf("B shank at x: %d, y: %d\n",k_x[z],k_y[z]);
			fprintf(data,"B shink at x: %d, y %d\n",k_x[z],k_y[z]);
			printf("Battle end in:%.2f\n",Endtime);
			fprintf(data,"Battle end in:%.2f\n",Endtime);
			printf("Battleship attacking order, shank E id(type notation): ");
			fprintf(data,"Battleship attacking order, shank E id(type notation): ");
			int ship =0; //how many escort ships were detroyed
			for(int i=0;i<B_range;i++){
				int temp = attackingOrder[i];
				if(!(escort[temp].isDestroy)){
					printf("%d (%c),",attackingOrder[i],escort[temp].typeNotation_E);
					fprintf(data,"%d (%c),",attackingOrder[i],escort[temp].typeNotation_E);
					ship++;
				}
			}
			printf("\n%d escort ship get hit by battleship.\n",ship);
			fprintf(data,"\n%d escort ship get hit by battleship.\n",ship);
			break; //if B shank end the loop
		}

	}

	//check B and E ship range are emty
	if(B_range==0 && E_range==0){
		printf("\nBattle ship or Escort can't attack(B ship and E ship are out of the attack range\n)");
		fprintf(data,"\nBattle ship or Escort can't attack(B ship and E ship are out of the attack range\n");
	}
	//Check B wins
	else if(battle.health_B > 0){
		printf("\n%d escort ship get hit by battleship.\n",B_range);
		fprintf(data,"\n%d escort ship get hit by battleship.\n",B_range);
		printf("Battle end in:%.2f\n",Endtime);
		fprintf(data,"Battle end in:%.2f\n",Endtime);
		printf("Battle ship remaining health: %.0f\n",battle.health_B*100);
		fprintf(data,"Battle ship remaining health: %.0f\n",battle.health_B*100);
		printf("Battleship attacking order, shank E id(type notation): ");
		fprintf(data,"Battleship attacking order, shank E id(type notation): ");
		for(int i=0;i<B_range;i++){
			int temp = attackingOrder[i];
			printf("%d (%c),",attackingOrder[i],escort[temp].typeNotation_E);
			fprintf(data,"%d (%c),",attackingOrder[i],escort[temp].typeNotation_E);
		}
		printf("\n");
		fprintf(data,"\n");
	}
	
	free(escort);
	fclose(data);
}

void simulationStatistics(){

	FILE *data;
	data = fopen("data.dat","r");
	if(data == NULL){
		printf("File did not open");
	}

	while(1){
		int c;
		c = fgetc(data);
		if(feof(data)){
			break;
		}
		printf("%c",c);
	}
}

//print the Battleships properties
void battleshipProperties(battleship battle[]){
	
	printf("\n\n\tBattleship properties\n");
	for(int i=0; i<4; i++){
		switch(i+1){
			case 1:
				printf("\nNotation Used-U\nBattleship Name- USSS lowa(BB-61)\nGun Name- 50-caliber Mark 7 gun\n");
				break;
			case 2:
				printf("\nNotation Used-M\nBattleship Name- MS King George V\nGun Name- (356 mm) Mark VII gun\n");
				break;
			case 3:
				printf("\nNotation Used-R\nBattleship Name- Richelieu\nGun Name- (15 inch) Ml 1935 gun\n");
				break;
			case 4:
				printf("\nNotation Used-S\nBattleship Name- Sovetsky Soyuz-class\nGun Name- (16 inch) B-37 gun\n");
				break;
		}
		printf("Battleship \'%c\' Time take to between tow firing: %d\n",battle[i].type_B,battle[i].fireTime_B);
		printf("Battleship \'%c\' minimum velocity of shell: %d\n",battle[i].type_B,battle[i].minVelocity_B);
		printf("Battleship \'%c\' maximum velocity of shell: %d\n",battle[i].type_B,battle[i].maxVelocity_B);
		printf("Battleship \'%c\' maximum Range: %d\n",battle[i].type_B,battle[i].maxRange_B*100);
		printf("Battleship \'%c\' gama value: %.2f\n",battle[i].type_B,battle[i].gama);
	}
}

//print the Escort ships properties
void escortshipProperties(escortship escort[]){
	printf("\n\tEscortship Propertie\n");
	for(int i=0; i<5; i++){
		switch(i+1){
			case 1:
				printf("\nNotation Used- A\nType Name- 1936A-class destroyer\n");
				printf("Gun Name-SK C/34 naval gun \nAngle Range-20\n");
				break;
			case 2:
				printf("\nNotation Used- B \nType Name- Gabbiano-class corvette\n");
				printf("Gun Name- L/47 dual-purpose gun \nAngle Range- 30\n");
				break;
			case 3:
				printf("\nNotation Used- C \nType Name- Matsu-class Destoyer\n");
				printf("Gun Name- Type 89 dual-purpose gun\nAngle Range- 25\n");
				break;
			case 4:
				printf("\nNotation Used- D \nType Name- F-class Escort Ships\n");
				printf("Gun Name- SK C/32 naval gun\nAngle Range- 50\n");
				break;
			case 5:
				printf("\nNotation Used- E \nType Name- Japanese Kailbokan\n");
				printf("Gun Name- (4.7 inch) naval guns\nAngle Range- 70\n");
		}
		printf("Escort ship maximum velocity of shell: %d\n",escort[i].maxVelocity_E);
		printf("Escort ship minimum velocity of shell: %d\n",escort[i].minVelocity_E);
		printf("Escort ship \'%c\' minimum shooting angle: %d\n",escort[i].typeNotation_E,escort[i].minAngle_E);
		printf("Escort ship \'%c\' maximum shooting angle: %d\n",escort[i].typeNotation_E,escort[i].maxAngle_E);
		printf("Escort ship \'%c\' impact power: %.2f\n",escort[i].typeNotation_E,escort[i].impactPower_E);
		printf("Escort ship \'%c\' Time take to between tow firing: %d\n",escort[i].typeNotation_E,escort[i].fireTime_E);
		printf("Escort ship \'%c\' minimum range: %d\n",escort[i].typeNotation_E,escort[i].minRange_E*100);
		printf("Escort ship \'%c\' maximum range: %d\n",escort[i].typeNotation_E,escort[i].maxRange_E*100);
		printf("Escort ship \'%c\' gama value: %.2f\n",escort[i].typeNotation_E,escort[i].gama);
	}
}

void viewInstructio(){
	printf("\nThe simulator start after the user input number of escort ship and type of battle ship.\n");
	printf("Programme process and analysis the data. Then display how many escort ship can be attacked by battleship and details of those ship.\n");
	printf("The arm of this simulator is to trin navy and get same experience about navy battlefield.\n");
}

int main(){
	srand(seedValue);
	
	int E_ship; // NUMBER OF E SHIP

	battleship selectbattle[4]; // create array for store B ship data
	//define B ship value
	define_B_ship(selectbattle);
	
	escortship selectescort[5];// create array for store E ships data
	//define E ship value
	define_E_ship(selectescort,selectbattle[0].maxVelocity_B);

	int choiceMenu;	
	while(1){
		printf("\n\tMenu\n");
		printf("1- Start Simulation\n");
		printf("2- View Instructions\n");
		printf("3- Simulation Statistics\n");
		printf("4- Sub Menu\n");
		printf("5- Exit\n");
		printf("Enter your choice: ");
		while(1){
			if(!(scanf("%d",&choiceMenu) == 1) ){
				scanf("%*[^\n]"); //creat new line for scanf		
			}else if(choiceMenu > 0 && choiceMenu < 6){
				break;
			}
			printf("Invalid input, Enter again:");
		}

		switch(choiceMenu){
			case 1:
				startSimulation(selectescort,selectbattle);
			break;
			case 2:
				viewInstructio();
				break;
			case 3:
				simulationStatistics();
				break;
			case 4:
				while(1){
					int choiceSubMenu;
					printf("\n1- Battleship Propertise\n");
					printf("2- Ecortship Propertise\n");
					printf("3- Seed value\n");
					printf("4- Return to Main Menu\n");
					printf("Enter your choice: ");
					while(1){
						if(!(scanf("%d",&choiceSubMenu) == 1) ){
							scanf("%*[^\n]");//creat new line for scanf		
						}else{
							if(choiceSubMenu > 0 && choiceSubMenu < 5){
								break;
							}
						}
					printf("Invalid input, Enter again:");
					}
				
					if(choiceSubMenu == 4){
						break;
					}
					switch(choiceSubMenu){
						case 1:
							battleshipProperties(selectbattle);
							break;
						case 2:
							escortshipProperties(selectescort);
							break;
						case 3:
							printf("Seed value used: %d\n",seedValue);
							break;			
					}
				}
				break;
			case 5:	
				int confirm;
				printf("\nAre you want to exit: \n");
				printf("Enter 1 confirm and any other number to stay: ");
				scanf("%d",&confirm);
					if(confirm == 1){
						printf("Exit\n");
						return 0;
				}
		}
	}
	return 0;
}

/*
	*** Name - D.M.D.C Dissanayake
	*** IT23782518
*/
