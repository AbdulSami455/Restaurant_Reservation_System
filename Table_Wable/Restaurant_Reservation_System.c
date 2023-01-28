#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

FILE *CART; // Pointer for order input
FILE *ORDER; // Pointer for reading menu
FILE *FEEDBACK; // Pointer to open feedback text file
FILE *COMPLAINT;   // Pointer to read complaint text file
FILE* MENU;  // Pointer to editing MENU file
FILE* TEMP; // Temporary pointer to make a menu copy
FILE* EXPENSES;

int order_counter;
int data_int;
char data[256];
int complaint;
int counter = 1;
char order_num[64];
char decide[128];
int item_number;
int item_count = 1;
int current_line = 1;

long total = 0;
int price_int = 0;
char number[2];
char price[8];
char main_menu[32];
char coupon[16];

int customer, admin;
char *p_order;
char *token;
char order[50] = "Order#";
char ordercpy[50] = "Order#";


void menu(); //Prints the Menu
void ordernumber();  // Deciding order number.
void orderinput(); //Takes Order Input + Generates a text file.
void func_payment(); // Responsible for Payment.
void red(); // prints red color
void white(); //prints white color
void custcancel(); // Brings back to customer main menu.
void mancancel(); //Brings back to manager main menu.

int main()
{
char buffer[64];
char buffer2[64];
char com_data[64];
int rate;
char ratestr[4];

while (1)
{
    printf("\n\t\tWelcome to Faisalabadi Dhaba!\n");
    printf("\tDo you want to get fatter and unhealthier? Type Yes to proceed to Main Menu\n\n");
    printf("Press X to go to manager account. \n\n");
    scanf("%s", main_menu);

    for (int i = 0; i < strlen(main_menu); i++) //Converting all main menu functions to lowercase.
    {
        main_menu[i] = tolower(main_menu[i]);
    }

    if (strcmp(main_menu, "yes") == 0)
    {
        printf("\nEnter your desired extension\n\n");
        printf("1. Dine In\t\t2. Takeaway\n"
               "3. Delivery\t\t4. Reservation\n\n");
        printf("We welcome your precious feedback! Press 5 to give feedback and receive a free discount coupon.\n\n");
        printf("If you have any complaints, press 6.\n\n");

        scanf("%d", &customer);
        switch(customer)
        {
        case 1:
        system("cls");
        printf("\nThis is the menu. Please input the item number you would like to order.");
        printf(" \n Inputting 1 means you are selecting item number 1.\n");
        printf("Please input 0 at any time to finish your order.\n\n");

        menu(); 
        ordernumber();
        orderinput();

        printf("\nPlease press any key to continue.");
        getchar();
        getchar(); //Buffer getchar() for new line character
        system("cls");
        func_payment();

        p_order = strchr(order, '#');
        if (p_order != NULL) 
        {
            *p_order = '\0';
        }
        strncat(order, "#", 3);
        system("cls");
        break;

        case 2:
        printf("\nThis is the menu. Please input the item number you would like to order.");
        printf(" \n Inputting 1 means you are selecting item number 1.\nPress 0 anytime to finish your order.");
        menu();
        ordernumber();
        orderinput();
        printf("Press any key to proceed to payment: ");
        getchar();getchar();
        system("cls");
        func_payment();

        if (item_count <= 5 && item_count > 0)
        printf("The estimated order wait time is 20 minutes.");
        if (item_count > 5 && item_count <= 10)
        printf("The estimated order wait time is 30 minutes");
        if (item_count > 10)
        printf("The minimum wait time for your order is 45 minutes.\n");
        printf("Please collect your order when your order number is called.\n");
        printf("\nPress any key to go back to the main menu.");
        getchar();
        system("cls");
        break;

        case 3:
        printf("\nThis is the menu. Please input the item number you would like to order.");
        printf(" \n Inputting 1 means you are selecting item number 1.\n");
        printf("Please input 0 at any time to finish your order.\n\n");
        menu();
        ordernumber();
        orderinput();
        func_payment();

        system("cls");
        break;

        case 4:
        {
        FILE* SEAT;

        int t1,t2,t3,t4,t5,t6,seatnum;
        int avail1=1,avail2=1,avail3=1,avail4=1,avail5=1,avail6=1;
        int seatarray[6],seatarraycount=0;
        
        white();

        srand(time(NULL));

        int upper = 6;
        int lower = 1;

        t1 = (rand() % (upper - lower + 1)) + lower;
        t2 = (rand() % (upper - lower + 1)) + lower;
        t3 = (rand() % (upper - lower + 1)) + lower;
        t4 = (rand() % (upper - lower + 1)) + lower;
        t5 = (rand() % (upper - lower + 1)) + lower;
        t6 = (rand() % (upper - lower + 1)) + lower;

        printf("-------------------\n");  //BOX START

        printf("| ");
        if (t1==1 || t1==2 || t1==3)
        {   // FOR SEAT 1
        red();
        printf("1");
        white(); // FUNCTTION FOR CHANGING COLOR OF TEXT
        avail1=0;
        seatarray[seatarraycount]=1;
        seatarraycount++;
        
        }
        else 
        {
        printf("1");
        }

        if (t2==1 || t2==2 || t2==3)
        {
        printf("\t");      // FOR SEAT 2
        red();
        printf(" 2\t");
        white(); // FUNCTTION FOR CHANGING COLOR OF TEXT
        avail2=0;
        seatarray[seatarraycount]=2;
        seatarraycount++;
        }
        else 
        {
        printf("\t");
        printf(" 2\t");
        }     

        if (t3==1 || t3==2 || t3==3)
        {      // FOR SEAT 3
        red();
        printf("3");
        white(); // FUNCTTION FOR CHANGING COLOR OF TEXT
        printf(" |\n");
        avail3=0;
        seatarray[seatarraycount]=3;
        seatarraycount++;
        }
        else 
        {
        printf("3");
        printf(" |\n");
        }

        printf("| ");
        if (t4==1 || t4==2 || t4==3)
        {      // FOR SEAT 4
        red();
        printf("4");
        white(); // FUNCTTION FOR CHANGING COLOR OF TEXT
        avail4=0;
        seatarray[seatarraycount]=4;
        seatarraycount++;
        }
        else
        {
        printf("4");
        }


     if (t5==1 || t5==2 || t5==3){      // FOR SEAT 5
        printf("\t");      
        red();
        printf(" 5\t");
        white(); // FUNCTTION FOR CHANGING COLOR OF TEXT
        avail5=0;
        seatarray[seatarraycount]=5;
        seatarraycount++;
    }
    else {
        printf("\t");
        printf(" 5\t");
    }

    if (t6==1 || t6==2 || t6==3){      // FOR SEAT 3
        red();
        printf("6");
        white(); // FUNCTTION FOR CHANGING COLOR OF TEXT
        printf(" |\n");
        avail6=0;
        seatarray[seatarraycount]=6;
        seatarraycount++;       
    }
    else {
        printf("6");
        printf(" |\n");
    } 
    printf("-------------------\n");      //BOX END
    red();printf("RED ");white();printf("= occupied seats\n\n");

    printf("The available seats are:");  // PRINTING THE SEATS NOT OCCUPIED.

    if (avail1==1)
    {
        printf("1");
    }
     if (avail2==1)
    {
        printf(" 2");
    }  
     if (avail3==1)
    {
        printf(" 3");
    }  
     if (avail4==1)
    {
        printf(" 4");
    }  
     if (avail5==1)
    {
        printf(" 5");
    }      
     if (avail6==1)
    {
        printf(" 6");
    }
    printf("\n");

    printf("Enter your desired seat:"); // ENTERING SEAT NUMBER
    scanf("%d",&seatnum);

    while (1){          // LOOP FOR OUT OF RANGE INPUT
        if (seatnum >=1 && seatnum<=6)
        {
            break;
        }
        printf("invalid input.Enter again:");
        scanf("%d",&seatnum);
        
    }
    while (1)           //LOOP FOR OCCUPIED SEAT INPUT
    {
        int found=0;
        for (int occupycount=0;occupycount< 6 ;occupycount++)
        {
            if (seatnum==seatarray[occupycount])
            {
                found++;
            }
        }
        if (found>0){
            printf("This seat is occupied. Enter in an available seat: ");
        scanf("%d",&seatnum);
        found=0;
        }
        else{
            break;
        }

    }
    

    char seatnumstr[1024];      

    sprintf(seatnumstr, "%d", seatnum);

    SEAT= fopen("Seatnumber.txt","w");      //MAKING A TXT FILE FOR SEAT NUMBER
        fprintf(SEAT,"Seat#");
        fputs(seatnumstr,SEAT);
        
        fclose(SEAT);

    printf("Your seat has been reserved.");
printf("Press any key to go back to the Main Menu: ");
getchar();getchar();
system("cls");

            break;}
        case 5:
        printf("Hi! Your feedback is most welcome here\n\n");

    printf("Enter your order number:\n");
    scanf("%s", order_num);

    FEEDBACK = fopen("feedback.txt", "a+");

    fputs("Order Number: ", FEEDBACK);
    fputs(order_num, FEEDBACK);
    fputs("\n\n", FEEDBACK);

    printf("\nAnswer the following questions on a scale of 1 to 5\n\n");

    while(1)
    {
        printf("How would you rate the food?\n");
        scanf(" %d", &rate);
        if( rate > 0  && rate < 6)
        {
                  sprintf(ratestr, "%d", rate);
            fputs("Rating for the food is: ", FEEDBACK);
            fputs(ratestr, FEEDBACK);
            break;
        }
        printf("Invalid Input!! Please rate within a scale of 1-5\n");
    }

     while(1)
    {

        printf("How would you rate the customer service?\n");
        scanf(" %d", &rate);
        if(rate > 0 && rate < 6)
        {
                  sprintf(ratestr, "%d", rate);
            fputs("\nRating for the customer service is: ", FEEDBACK);
            fputs(ratestr, FEEDBACK);
            break;
        }
        printf("Invalid Input!! Please rate within a scale of 1-5\n");
    }

     while(1)
    {

        printf("How would you rate your overall experience?\n");
        scanf(" %d", &rate);
        if(rate > 0 && rate < 6)
        {
            fputs("\nRating for the whole experience is: ", FEEDBACK);
            fputs(ratestr, FEEDBACK);

            break;
        }
        printf("Invalid Input!! Please rate within a scale of 1-5\n");
    }

    printf("Any additional comments (Enter \"none\" if no):\n");
    scanf(" %[^\n]s", ratestr);
    fputs("\nComments: ", FEEDBACK);
    fputs(ratestr, FEEDBACK);
    fputs("\n", FEEDBACK);

       fclose(FEEDBACK);

    printf("Thank you so much for the feedback! As promised, here's a 10%% discount voucher on us.\n");
    printf(" Please enter it on your next order to redeem it.\n");
    printf("The code for the discount voucher is 'EffanBest'");
    printf("\nPlease press any key to proceed back to the main menu.");
    getchar();getchar();
    system("cls");

            break;
        case 6:
        printf("Hi! We take your complaints very seriously\n"
           "and will do our best to solve your problem.\n\n"
           "What is your order number: ");

    scanf(" %s", order_num);

    sprintf(buffer2, "%s", order_num);

    srand(time(NULL));
    complaint = (rand()%(32676+1-10000) + 10000);

    sprintf(buffer, "%d", complaint);

    COMPLAINT = fopen("complaint.txt", "a+");

    fputs("Order Number: ", COMPLAINT);
    fputs(buffer2, COMPLAINT);
    fputs("\n", COMPLAINT);
    fputs("Complaint Number: ", COMPLAINT);
    fputs(buffer, COMPLAINT);
    fputs("\n\n", COMPLAINT);

    printf("Enter your name:\n");
    scanf(" %[^\n]s", com_data);

    fputs("Name: ", COMPLAINT);
    fputs(com_data, COMPLAINT);
    fputs("\n", COMPLAINT);

    printf("Enter your email address:\n");
    scanf(" %[^\n]s", com_data);
    fputs("Email: ", COMPLAINT);
    fputs(com_data, COMPLAINT);
    fputs("\n", COMPLAINT);

    printf("Enter your phone number:\n");
    scanf(" %[^\n]s", com_data);
    fputs("Phone Number: ", COMPLAINT);
    fputs(com_data, COMPLAINT);
    fputs("\n", COMPLAINT);

    printf("Details of your complaint:\n");
    scanf(" %[^\n]s", com_data);
    fputs("Details:\n", COMPLAINT);
    fputs(com_data, COMPLAINT);

fclose(COMPLAINT);

    printf("\nPlease press any key to return back to the main menu.");
    getchar();getchar();
    system("cls");
            break;
        }

strncpy(order, ordercpy,50);

    }
else if (strcmp(main_menu, "x") == 0)
    {
        {
             char passmanager[]="wajahat";
    char passcheck[150];

    printf("|||||||||||||| MANAGER'S PORTAL |||||||||||||\n\n\n\n");
    
     printf("Enter password:");
      scanf("%s",passcheck);
      
      
  while (strcmp(passcheck,passmanager)!=0)
  {
    
      printf("Wrong password. Try again.\n");
      printf("Enter password:");
      scanf("%s", passcheck);
}
system("cls");
        }
        admin = 1;
        while (admin != 4)
        {
            system("cls");
        printf("Hello Manager! \nWhat would you like to do today?\n");

        printf("Enter the number for your desired  extension.\n\n");

        printf("1. Edit Menu\t\t2. Check monthly expenses\n"
               "3. See Feedback/Complaints\t\t4.Back to Home Screen\n");
        scanf("%d", &admin);

        switch(admin)
        {
        case 1:
        {
        char new_item[64], price_new_item[64];  // INSERT INTS AS NEEDED
    int var1,EOF1,var2,EOF2,countnumber=1;

    

    printf("Add new item to menu?(press 1)\nRemove item from menu?(press 2): ");
    scanf("%d", &var1);
if (var1 == 1) {  //ADDING ITEM TO MENU START. 
        while (EOF1 != 2) {
            
            EOF1=0;  //REINITIALIZE 

            MENU = fopen("Menu.txt", "r");
            countnumber=1;

         while (fgets(data, 64, MENU)) {  //PRINTS THE MENU FOR THE MANAGER

             printf("%d.\t",countnumber);
             printf("%s", data);
             countnumber++;

         }
         fclose(MENU);
        

            MENU = fopen("Menu.txt", "a"); //APPENDING THE TXT FILE (*)

            printf("Enter 'X' to go back to the main menu. \nEnter the name of new item: ");
            scanf("%s", new_item);
if (strcmp(new_item, "X" ) == 0 || strcmp(new_item, "x") == 0)
{
break;
}
            printf("Enter the price of the item:");
            scanf("%10s", price_new_item);  //INPUT NEW ITEM AND ITS PRICE

            fputs(new_item, MENU);
            fputs("\t\t\t",MENU);
            fputs(price_new_item,MENU);  //MAKES CHANGES TO THE MENU WITH PROPER SPACING.
            fputs("\n", MENU);
            
            fclose(MENU);

        while (EOF1!=1 && EOF1!=2){

            printf("Do you want to add another item?\nPress 1 for YES and 2 for NO:");
        scanf("%d", &EOF1);

        if (EOF1!=1 && EOF1!=2)
        {
            printf("Invalid input.Try again.");
        
        }

        } // LOOP FOR ADDING ITEMS AGAIN AND INVALID INPUTS.

        }  // ADDITEM END.
        
    }

    
     else if (var1 == 2) {

        while (EOF2!=2){ 

        EOF2=0;
        countnumber=1; //REINITIALIZE
        
         MENU = fopen("Menu.txt", "r");

         while (fgets(data, 64, MENU)) {  //PRINTS THE MENU FOR THE MANAGER

             printf("%d.\t",countnumber);
             printf("%s", data);
            countnumber++;
         }
         fclose(MENU);

         MENU = fopen("Menu.txt", "r");
         TEMP = fopen("menucopy.txt", "r+");
        
        rewind(MENU);

         printf("\nEnter item number to be removed:");
         scanf("%d", &var2);  // LINE NUMBER TO REMOVE

        int countremove=1;
        while (fgets(data, 64, MENU))  //gets data from menu
        {
            
            if (var2 != countremove)
            {
                
                fputs(data,TEMP);  //COPYS ALL THE DATA OTHER THAN THE SPECIFIED LINE
                
            }
            countremove++;
        }
        fclose(MENU);
        fclose(TEMP);

        remove("Menu.txt");     // REMOVES THE ORIGINAL FILE
        rename("menucopy.txt", "Menu.txt");  // RENAMES THE TEMP FILE TO THE ORIGINAL

         
        countnumber=1;
        
         MENU = fopen("Menu.txt", "r");

         while (fgets(data, 64, MENU)) {  //PRINTS THE NEW MENU FOR THE MANAGER

            printf("%d.\t",countnumber);
             printf("%s", data);
            countnumber++;

         }
         fclose(MENU);

        FILE * TEMP;
        TEMP = fopen("menucopy.txt","w"); // MAKES A NEW TEMP TXT FILE
        fclose(TEMP);

    while (EOF2!=1 && EOF2!=2)  // LOOP FOR REMOVING ITEMS AGAIN AND INVALID INPUTS.
    {
        printf("\nDo you want to remove another item?(press 1 for YES and 2 for NO):");
        scanf("%d",&EOF2);

        if (EOF2!=1 && EOF2!=2)
        {
            printf("Invalid input.Try again.\n");
        
        }
    }
        
        }

     }
            break;}
        case 2:
        {
    {
    FILE* EXPENSES;
    int options = 0,utility,ingredients,salary,total_bill=0,int_expensemain;
    char expensemain[1024];

    printf("\n\n1. Add utilities bill to expenses.\t\t2. Add ingredients cost to expenses.\n");  // MAIN UI
    printf("\n3. Add employee salaries to expenses.\t\t4. Check total revenue\n\nInput option number:");
    scanf("%d", &options);

    while(1)
    {
        if (options > 0 && options < 5)
        {
            break;
        }
        printf("Invalid Input. Please try again.\n");
        scanf("%d", &options);

    }

    switch(options){  // SWITCH START

        case 1:
        printf("Enter the total utility bill:");
        scanf(" %d",&utility);
        total_bill=total_bill+utility;
        break;

        case 2:
        printf("Enter the total ingredient cost:");
        scanf(" %d",&ingredients);
        total_bill=total_bill+ingredients;
        break;

        case 3:
        printf("Enter the total employees salaries:");
        scanf(" %d",&salary);
        total_bill=total_bill+salary;
        break;

        case 4:
        {
        char expenz[50];
       EXPENSES = fopen("Expenses.txt", "w+");
        while (1)
{
    if (feof(EXPENSES))
    break;
    fgets(expenz, 50, EXPENSES);
    printf(" the money is %s", expenz);
}

printf("The total revenue is %s", expenz);
fputs(expenz, EXPENSES);
fputs("\n", EXPENSES);
fclose(EXPENSES);
printf("\n\nPress any key to go back to the main menu: ");
getchar();getchar();
break;}

EXPENSES = fopen("Expenses.txt", "w+");
while (1)
{
    if (feof(EXPENSES))
    break;
    fgets(data, 50, EXPENSES);
}
data_int = atoi(data);
data_int = data_int - total_bill;
sprintf(data, "%d", data_int);
fputs(data, EXPENSES);
fputs("\n", EXPENSES);
fclose(EXPENSES);
    }  // SWITCH END

}
}
            break;
     case 3:
     {
        int var1;
        printf("1. Feedback\t\t2. Complaints\n");
        scanf("%d", &var1);
        if (var1 == 1)
        {
            FEEDBACK = fopen("feedback.txt", "a+");
            while (1)
            {
                fgets(data, 50, FEEDBACK);
                if (feof(FEEDBACK))
                break;

                printf("%s", data);
            }
            fclose(FEEDBACK);
               printf("Please enter any key to go back to the main menu");
        getchar();getchar();
        system("cls");
        }

        else if (var1 == 2)
        {
            printf("Here are all of the complaints ever made: ");
            COMPLAINT = fopen("complaint.txt", "a+");
            while (1)
            {
                fgets(data, 50, COMPLAINT);
                if (feof(COMPLAINT))
                break;

                printf("%s", data);
            }
            printf("\nPlease press any key to go back to the main menu: ");
            getchar();getchar();
            system("cls");
        }
          break;
          
        }
 } 
 system("cls");
    }
}}
return 0;

}

void menu()
{
    FILE *MENU;
    counter = 1;
    MENU = fopen("Menu.txt", "r"); 
while (fgets(data, 256, MENU)) //PRINTING MENU
{
    printf("%d. ", counter);
    printf("%s", data);
    counter = counter + 1;
}
fclose(MENU);
}


void ordernumber() // FUNCTION TO CREATE ORDER NUMBER FILE + INCREASE ORDER NUMBER.
{
    FILE *NUMBER;
    FILE *NUMBER_CLOSE;

    NUMBER = fopen("number.txt", "r"); // READS THE CURRENT ORDER NUMBER.
while (fgets(number, 32, NUMBER))
{
    if (feof(NUMBER))
    break;
    printf("The order number is %s", number);
    strncat(order, number, 3); // Adds Order + Item number.

}
order_counter = atoi(number); //CONVERTS NUMBER STRING TO INTEGER SO WE CAN PERFORM +1 OPERATION ON IT.
order_counter = order_counter + 1;
sprintf(number, "%d", order_counter); // CONVERTS INTEGER BACK TO STRING SO WE CAN USE FPUTS ON IT.
NUMBER_CLOSE = fopen("number.txt", "w");
fputs(number, NUMBER_CLOSE);
fputs("\n", NUMBER_CLOSE);
fclose(NUMBER_CLOSE);
strncat(order, ".txt",50); // ADDS ORDER NUMBER + ITEM NUMBER
fclose(NUMBER);
}
void orderinput()
{
    printf("Enter your item number here: ");
scanf("%d", &item_number);

while (1)
{
    if (item_number >= counter)
    {
    printf("\nPlease enter a number that is within the menu: ");
    scanf("%d ", &item_number);
    }
    else
    break;
}
CART = fopen(order, "w");
ORDER = fopen("Menu.txt", "r");
while (item_number != 0 )
{
    ORDER = fopen("Menu.txt", "r");
while (1)
{
    fgets(decide, 256, ORDER);
    if (feof(ORDER))
    {
        break;
    }

    if (current_line == item_number) // WHEN THE SELECTED ITEM IS CHOSEN.
    {

        char c[30];
        strncpy(c, decide,30);
        char x[4];
        int int_x;
        token = strtok(c,"\t\t");
        int token_counter = 0;
        while (token != NULL)
        {
            token_counter = token_counter + 1;
            token = strtok(NULL, " ");
            if (token_counter == 1)
            {
            strncpy(x, token,4);
            int_x = atoi(x);
            price_int = price_int + int_x;
            }
        }
        printf("%s", decide);
        fputs(decide, CART); //PUTS ITEM INTO ORDER TEXT FILE.
        printf("Please enter another item: ");
        scanf("%d", &item_number);
        while (1)
{
    if (item_number >= counter)
    {
    printf("\nPlease enter a number that is within the menu:\n");
    scanf("%d", &item_number);
    }
    else
    break;
}
        item_count++;
        fclose(ORDER);
        current_line = 0;
        break;
            }
    current_line++; // ++ SO IF number == number on menu, it'll add to order box, else it'll keep looping
    // until menu is complete.

}
current_line = 1;

}
if (customer == 1)
fprintf(ORDER, "\nOrder Type: Dine in\n");
if (customer == 2)
fprintf(ORDER, "\nOrder Type: Takeaway\n");

if (customer == 3)
{
    // All the customer input is sent to the order file.
    char data[50];
        fputs("Order Type: Delivery", CART);
        fputs("\n\n", CART);
        getchar();
    printf("Enter your name here: ");
    fgets(data, 50, stdin);
    fputs("Name: ", CART);
    fputs(data, CART);
    printf("\nEnter your address here: ");
    fgets(data, 50, stdin);
    fputs("\n", CART);
    fputs("Address: ", CART);
    fputs(data, CART);
    printf("\nEnter your mobile number here: ");
    fgets(data, 50, stdin);
    fputs(data, CART);
}
if (customer == 1)
{
printf("Please enter a coupon code to receive a 10%% discount, else press 0: ");
scanf("%s", coupon);
if (strcmp(coupon, "EffanBest") == 0)

{
    printf("\nYou have received a 10%% Discount on your order. Congratulations!");
    price_int = price_int - (price_int / 10);
}
}
fputs("The total price is ", CART);
sprintf(price, "%d", price_int);

EXPENSES = fopen("Expenses.txt", "w+");
while (1)
{
    if (feof(EXPENSES))
    break;
    fgets(data, 50, EXPENSES);
}

int data_int;
data_int =  atoi(data);
data_int = data_int + price_int;
sprintf(data, "%d", data_int);
fputs(data, EXPENSES);
fclose(EXPENSES);

fputs(price, CART);
fclose(CART);
printf("\nYour order number is #%d.\n", order_counter - 1);

}
void func_payment()
{
      FILE *OTP;
    FILE *PAYMENT;
        int otp;
    int otp_user;
    int payment;
    int card;
    char card_num[64];
    char cvv[64];
    char expiry[64];
    char otp_str[64];
    char card_str[64];

        printf("How would you like to pay:\n\n"
           "1. Cash\t\t2. Card\n");
    scanf(" %d", &payment);
    switch (payment)
    {
    case 1:
    if (customer == 1 || customer == 2)
    {
        printf("Kindly pay the following amount at the counter.\n\n");
    }
    else if (customer == 3)
    {
     printf("Kindly pay the following amount to the rider. \n\n");
    }   
        printf("%s\n\n", price);
        printf("Please press any key to go back to the main menu.");
        getchar();getchar();
        break;

    case 2:

        PAYMENT = fopen("payment.txt", "w");

        printf("\nCard Type:\n"
               "1. VISA\t\t2. MASTERCARD\n\n");
        scanf(" %d", &card);

        if (card == 1)
        {
            strncpy(card_str,"VISA",64);
            fputs("Card = VISA\n", PAYMENT);
        }
        else
        {
            strncpy(card_str,"MASTERCARD",64);
            fputs("Card = MASTERCARD\n", PAYMENT);
        }
while(1)
{
        printf("\nEnter your card number:\n");
        scanf(" %[^\n]s", card_num);

        for(int i = 0; (i < strlen(card_num) && card_num[i] != '\0'); i++)
        {
            card_num[i] = card_num[i] + 7;
        }
if (strlen(card_num) != 16)
{
    printf("Please input your 16-digit VISA card number without any spacing.");
    continue;
}
else
break;
    }
        fputs(card_num, PAYMENT);
        fputs("\n", PAYMENT);

while(1)
{
            printf("\nEnter CVV:\n");
        scanf(" %[^\n]s", cvv);
        for(int i = 0; (i < strlen(cvv) && cvv[i] != '\0'); i++)
        {
            cvv[i] = cvv[i] + 7;
        }
if (strlen(cvv) != 3)
{
    printf("Please enter a proper 3-digit CVV: ");
    continue;
}
else
break;
}
        fputs(cvv, PAYMENT);
        fputs("\n", PAYMENT);

        printf("\nEnter your month and year of expiry (mm/yy):\n");
        scanf(" %[^\n]s", expiry);

        for(int i = 0; (i < strlen(expiry) && expiry[i] != '\0'); i++)
        {
            expiry[i] = expiry[i] + 7;
        } 

        fputs(expiry, PAYMENT);
        fputs("\n", PAYMENT);

        srand(time(NULL));
        otp = (rand()%(32676+1-10000) + 10000);
        sprintf(otp_str, "%d", otp);

        OTP = fopen("otp.txt", "w");

        fputs(otp_str, OTP);

        fclose(OTP);

        otp = atoi(otp_str);

        printf("\nYou will be returned to the main menu once you enter the OTP we have sent you: \n");
        scanf("%d", &otp_user);

        while (otp_user != otp)
        {
            printf("\nWrong! We have sent you another otp\n");
            srand(time(NULL));
            otp = (rand()%(32676+1-10000) + 10000);
            sprintf(otp_str, "%d", otp);

            OTP = fopen("otp.txt", "w");
            fputs(otp_str, OTP);
            fclose(OTP);

            otp = atoi(otp_str);
            printf("Enter the otp we have sent you: \n");
            scanf("%d", &otp_user);
        }

        break;
    }
}
 void red()
    {
        printf("\033[0;31m");   // FUNCTION FOR CHANGING COLOR TO RED
    }
    
    
 void white()
    {
        printf("\033[0;37m");   // FUNCTION FOR CHANGING COLOR TO WHITE // 37 for white  // 31 for red
    } 
