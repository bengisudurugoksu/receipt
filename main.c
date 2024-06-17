#include <stdio.h>
#include <time.h>//Including time.h to use the strftime function.
#include <stdlib.h>//Including stdlib.h to use the rand function without a warning.
int themenu();//Declaring the functions I used in the code.
float student(char, float, float);
int userchoice();
float VATfunc(float);
float ddiscount(float);
int rockpaperscissors();
int main(){
FILE *fp;
char ch;
int choice;
time_t rawtime;//This part is for the time and date strftime function.This is the only part I used arrays and structs.
   struct tm *info;
   char buffer[80];
   time( &rawtime );
   info = localtime( &rawtime );
   strftime(buffer,80,"%x - %I:%M%p", info);
themenu();
userchoice();
printf("220104004902        ");//I use the receipt.txt file created after the given order to print the receipt on the output.
printf("|%s|\n", buffer );
printf("----------------------------------------");
printf("\n");
printf(" Product                      Price (TL)");
printf("\n");
printf("----------------------------------------");
fp = fopen("receipt.txt", "r");
if (NULL == fp){
	printf("Receipt file can't be opened \n");
	}
	do{
		ch = fgetc(fp);//This part is to get all the characters in the file one by one and printing them.
		printf("%c", ch);
	}
	while (ch != EOF);
fclose(fp);
rockpaperscissors();//This function is for Part2 of the homework.
return 0;
}
int themenu(){//The menu function opens the menu.txt file and prints the food options without the prices.I used ASCII values for this part.
int choice,count=1,i,j=1;
FILE *fp;
char ch;
fp = fopen("menu.txt", "r");
printf("Food List: ");
if (NULL == fp) {
	printf("File can't be opened.\n");
}
while(fgetc(fp)!='\n'){
}
while((i = fgetc(fp)) != EOF)
{

	if(i<45 || i>57)//
	{      
		putchar(i);
	}
	
	if(i == '\n' && j<13)
	{
		printf("%d. ", count);//This part prints the rank of the food before the food name.j variable is for avoiding printing one more number since function prints a number when there is a new line.
		count++;
		j++;
	}
	
}
fclose(fp);
return 0;
}
int userchoice(){//The userchoice function asks the user to choose a product and serving.
int serving,choice,exit=0;
float receipt=0.00,totalreceipt=0.00,studentd,discount,VAT,finalreceipt=0.00;
char answer;
FILE *fp;
fp = fopen ("receipt.txt", "w");//Creating receipt.txt to write inside it.
while (exit==0){
printf("\nPlease choose a product (1-12): ");
scanf("%d", &choice);
printf("How many servings do you want?: ");
scanf("%d", &serving);
if(serving==0){//If user enters 0 for serving function stops asking for a product and prints the receipt.
exit = 1;
}
totalreceipt+=receipt;//To increase the totalreceipt everytime a new product is added.
switch(choice){


case 1://receipt variable is serving times the foods price.For example for sushi receipt variable is serving times 150.99.
receipt = serving * 150.99;
if (serving>1){
fprintf(fp, "\n %d* Sushi                     %.2fTL", serving, receipt);
}
else if(serving==1){
fprintf(fp, "\n Sushi                        %.2fTL", receipt);
}
else if(serving!=0){//Asks the user to enter an appropiate amount of serving except when serving==0 since that is the indication for exit.
printf("\nPlease enter an appropiate amount of serving.");
}
fprintf(fp, "\n");
break;

case 2:
receipt = serving * 95.99;
if (serving>1){
fprintf(fp, "\n %d* Kebap                     %.2fTL", serving, receipt);
}
else if(serving==1){
fprintf(fp, "\n Kebap                         %.2fTL", receipt);
}
else if(serving!=0){
printf("\nPlease enter an appropiate amount of serving.");
}
fprintf(fp, "\n");
break;

case 3:
receipt = serving * 20.25;
if (serving>1){
fprintf(fp, "\n %d* Lahmacun                   %.2fTL", serving, receipt);
}
else if(serving==1){
fprintf(fp, "\n Lahmacun                      %.2fTL", receipt);
}
else if(serving!=0){
printf("\nPlease enter an appropiate amount of serving.");
}
fprintf(fp, "\n");
break;

case 4:
receipt = serving * 58.90;
if (serving>1){
fprintf(fp, "\n %d* Pide                      %.2fTL", serving, receipt);
}
else if(serving==1){
fprintf(fp, "\n Pide                          %.2fTL", receipt);
}
else if(serving!=0){
printf("\nPlease enter an appropiate amount of serving.");
}
fprintf(fp, "\n");
break;

case 5:
receipt = serving * 55.90;
if (serving>1){
fprintf(fp, "\n %d* Döner                     %.2fTL", serving, receipt);
}
else if(serving==1){
fprintf(fp, "\n Döner                         %.2fTL", receipt);
}
else if(serving!=0){
printf("\nPlease enter an appropiate amount of serving.");
}
fprintf(fp, "\n");
break;

case 6:
receipt = serving * 18.50;
if (serving>1){
fprintf(fp, "\n %d* Kola                       %.2fTL", serving, receipt);
}
else if(serving==1){
fprintf(fp, "\n Kola                          %.2fTL", receipt);
}
else if(serving!=0){
printf("\nPlease enter an appropiate amount of serving.");
}
fprintf(fp, "\n");
break;

case 7:
receipt = serving * 18.50;
if (serving>1){
fprintf(fp, "\n %d* Fanta                      %.2fTL", serving, receipt);
}
else if(serving==1){
fprintf(fp, "\n Fanta                         %.2fTL", receipt);
}
else if(serving!=0){
printf("\nPlease enter an appropiate amount of serving.");
}
fprintf(fp, "\n");
break;

case 8:
receipt = serving * 15.00;
if (serving>1){
fprintf(fp, "\n %d* Ayran                      %.2fTL", serving, receipt);
}
else if(serving==1){
fprintf(fp, "\n Ayran                         %.2fTL", receipt);
}
else if(serving!=0){
printf("\nPlease enter an appropiate amount of serving.");
}
fprintf(fp, "\n");
break;

case 9:
receipt = serving * 5.00;
if (serving>1){
fprintf(fp, "\n %d* Su                         %.2fTL", serving, receipt);
}
else if(serving==1){
fprintf(fp, "\n Su                             %.2fTL", receipt);
}
else if(serving!=0){
printf("\nPlease enter an appropiate amount of serving.");
}
fprintf(fp, "\n");
break;

case 10:
receipt = serving * 45.50;
if (serving>1){
fprintf(fp, "\n %d* Sufle                      %.2fTL", serving, receipt);
}
else if(serving==1){
fprintf(fp, "\n Sufle                         %.2fTL", receipt);
}
else if(serving!=0){
printf("\nPlease enter an appropiate amount of serving.");
}
fprintf(fp, "\n");
break;

case 11:
receipt = serving * 40.25;
if (serving>1){
fprintf(fp, "\n %d* Cheesecake                 %.2fTL", serving, receipt);
}
else if(serving==1){
fprintf(fp, "\n Cheesecake                    %.2fTL", receipt);
}
else if(serving!=0){
printf("\nPlease enter an appropiate amount of serving.");
}
fprintf(fp, "\n");
break;

case 12:
receipt = serving * 40.25;
if (serving>1){
fprintf(fp, "\n %d* Tiramisu                   %.2fTL", serving, receipt);
}
else if(serving==1){
fprintf(fp, "\n Tiramisu                      %.2fTL", receipt);
}
else if(serving!=0){
printf("\nPlease enter an appropiate amount of serving.");
}
fprintf(fp, "\n");
break;

default://Asks the user to enter a valid number.
printf("\nPlease enter a valid number.\n");
}
}
studentd = student(answer, totalreceipt, studentd);//student function is explained below.
if (studentd>0){//Adds the student discount to the receipt if the discount is greater than 0.
fprintf(fp, "\n Student discount             -%.2fTL", studentd);
} 
VAT=VATfunc(totalreceipt);//VATfunc function is explained below.
if(totalreceipt>=150){//If totalreceipt is equal to and greater than 150 we apply the discount function and print that into the file and receipt aswell.
discount = ddiscount(totalreceipt);//discount function is explained below.
fprintf(fp, "\n Discount                     -%.2fTL", discount);
}
else{
discount=0;
}
totalreceipt=totalreceipt-studentd-discount;//Finding the final totalreceipt.
finalreceipt=totalreceipt+VAT;//Adding VAT to the final totalreceipt and adding these on the receipt.txt file.
fprintf(fp, "\n----------------------------------------");
fprintf(fp, "\n Price:                       %.2fTL", totalreceipt);
fprintf(fp, "\n");
fprintf(fp, "\n Price + VAT:                 %.2fTL\n", finalreceipt);
fclose(fp);
return 0;
}


float ddiscount(float total){//This function is for the discount calculation when the price>=150.Returns the discount value.
float discount;
discount = (total * 10)/100;
return discount;
}

float VATfunc(float total){//This function is the VAT calculation.Returns the VAT value.
float VAT;
VAT = (total * 18)/100;
return VAT;
}

float student(char answer,float total,float studentd){//This function asks the user if they are a student and calculates the student discount if they are a student.Returns the studentd value.
printf("Are you a student?(Y/N) ");
scanf(" %c", &answer);
printf("\n");
studentd=0;
switch(answer){
case 'Y':
studentd = (total * 12.5)/100;
break;

case 'N':
studentd=0;
break;

default:
printf("Please enter a valid answer.\n");
studentd=student(answer,total,studentd);//Recursively calling student function once again if the letter input is invalid.
printf("\n");

}
return studentd;
}
//rockpaperscissors function is for the Part2 of the homework.
int rockpaperscissors(){
int exit=0,choice,computerchoice;
char play;
printf("\n");
printf("\nWelcome to rock-paper-scissors!\nLet's play!\n");//Firstly we welcome the user.
while(exit==0){
printf("Please make a choice!\n");//When exit=0,player can play again.
printf("1: Stone, 2: Paper, 3: Scissors\n");
scanf("%d", &choice);
switch(choice){
case 1://Computer chooses a random number between 1 and 3.
computerchoice = (rand() % 3) + 1;
if(computerchoice==1){//I have used switch case for the user input and used if-else blocks for the computer choice.
printf("\nYou chose Stone. I chose Stone. It is a Tie!\n");//For example in case the user chooses 1(Stone) when the computer chooses 1(Stone) it is a tie.
}
if(computerchoice==2){
printf("\nYou chose Stone. I chose Paper. I won!\n");//In case user chooses 1(Stone) when the computer chooses 2(Paper) the computer wins.
}
if(computerchoice==3){
printf("\nYou chose Stone. I chose Scissors. You won!\n");//In case user chooses 1(Stone) when the computer chooses 3(Scissors) user wins.
}
break;

case 2:
computerchoice = (rand() % 3) + 1;
if(computerchoice==1){
printf("\nYou chose Paper. I chose Stone. You won!\n");
}
if(computerchoice==2){
printf("\nYou chose Paper. I chose Paper. It is a Tie!\n");
}
if(computerchoice==3){
printf("\nYou chose Paper. I chose Scissors. I won!\n");
}
break;

case 3:
computerchoice = (rand() % 3) + 1;
if(computerchoice==1){
printf("\nYou chose Scissors. I chose Stone. I won!\n");
}
if(computerchoice==2){
printf("\nYou chose Scissors. I chose Paper. You won!\n");
}
if(computerchoice==3){
printf("\nYou chose Scissors. I chose Scissors. It is a Tie!\n");
}
break;

default:
printf("\nPlease enter a valid choice (1-2-3).\n");//If the user enters an invalid number the program gives a warning and calls the rockpaperscissors once again recursively.
rockpaperscissors();
}

printf("\nDo you want to play again? (Y/N): ");//After the game is over we ask the user if they want to play again.
scanf(" %c", &play);
switch(play){

case 'Y':
exit=0;//If the user inputs 'Y' exit=0,so the game starts once again and asks the user for a choice. 
break;

case 'N':
printf("\nThanks for playing with me!\nHave a wonderful day!\n");//If the user inputs 'N' exit=1,program gives a goodbye message and terminates.
exit=1;
break;

default:
printf("\nPlease enter a valid letter (Y/N): ");//If the user enters an invalid letter the program gives a warning message and receives the letter input once again.
scanf(" %c", &play);
}
}
return 0;
}
































