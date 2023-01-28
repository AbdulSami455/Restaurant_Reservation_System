#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "reservation.h"
#include "colors.h"

FILE *CART;      // Pointer for order input
FILE *ORDER;     // Pointer for reading menu
FILE *FEEDBACK;  // Pointer to open feedback text file
FILE *COMPLAINT; // Pointer to read complaint text file
FILE *MENU;      // Pointer to editing MENU file
// FILE *TEMP;  Temporary pointer to make a menu copy
// FILE* EXPENSES;
FILE *RESTAURANT; // Pointer for choosing Restaurant

int order_counter;
int data_int;
char data[256];
char res_data[256];
int complaint;
int counter = 1;
char order_num[64];
char decide[256];
char decide_total[256]=" ";
char newline[]="\n";
int item_number;
int restaurant_number;
int item_count = 1;
int current_line = 1;

int tablenum=1;

long total = 0;
int price_int = 0;
char number[3];
char price[8];
// char main_menu[32];
char restaurant_menu[32];
char coupon[16];

int customer_choice;
char c_choice[3];
// int admin;
char *p_order;
char *token;
char order[50] = "Order#";
char ordercpy[50] = "Order#";

char *a;
char *extension;

void restaurant();                                                                            // Prints list of Restaurants
void restaurant_input(int *restaurant_number);                                                // Takes restaurant Input
void menu(int *restaurant_num);                                                               // Prints the Menu
void ordernumber();                                                                           // Deciding order number.
void orderinput(char* customer_choice);                                                            // Takes Order Input + Generates a text file.
void func_payment(char* customer_choice);                                                                          // Responsible for Payment.
//void red();                                                                                   // prints red color
//void white();                                                                                 // prints white color
//void table_availability(int table, int *tablearray, int *availability, int *tablearraycount); // Displays the available tables
//void unoccupied_tables(int t1, int t2, int t3, int t4, int t5, int t6);
//void verify_resrvation(int *tablenum, int *tablearray);
void print_ticket(int* tablenum);
// void custcancel(); // Brings back to customer main menu.

int main()
{
    char buffer[64];
    char buffer2[64];
    char com_data[64];
    char ratestr[50];
    int rate;

    while (1)
    {
        printf("\t*******************************************************\t");
        printf("\n\t\tWelcome to the Table Wable App!\n");
        printf("\t*******************************************************\t\n\n");
    start:
        printf("\tWould you like to order or make a reservation? Type Yes to proceed to Restaurant Menu\n");
        printf("\tType No if you want to exit the App.\n\n");
        // printf("Press X to go to manager account. \n\n");
        printf("Type here: ");
        scanf("%s", restaurant_menu);

        for (int i = 0; i < strlen(restaurant_menu); i++) // Converting all restaurant_menu characters to lowercase.
        {
            restaurant_menu[i] = tolower(restaurant_menu[i]);
        }

        if (strcmp(restaurant_menu, "yes") == 0)
        {
            restaurant();
            restaurant_input(&restaurant_number);

            printf("\nEnter your desired service\n\n");
            printf("1. Dine In\t\t2. Takeaway\n"
                   "3. Delivery\t\t4. Reservation\n\n");
            printf("We welcome your precious feedback! Press 5 to give feedback and receive a free discount coupon.\n\n");
            printf("If you have any complaints, press 6.\n\n");

            scanf("%d", &customer_choice);
            sprintf(c_choice,"%d",customer_choice);
            switch (customer_choice)
            {
            case 1:                                                 //Dine-in

                menu(&restaurant_number);
                ordernumber();
                orderinput(c_choice);

                printf("\nPlease press any key to continue.");
                getchar();
                getchar(); // Buffer getchar() for new line character
                system("cls");
                func_payment(c_choice);

                p_order = strchr(order, '#');
                if (p_order != NULL)
                {
                    *p_order = '\0';
                }
                strncat(order, "#", 3);
                system("cls");
                break;

            case 2:
                menu(&restaurant_number);                       //Take away
                ordernumber();

                

                orderinput(c_choice);
                printf("Press any key to proceed to payment: ");
                getchar();
                getchar();
                system("cls");
                func_payment(c_choice);

                if (item_count <= 5 && item_count > 0)
                    printf("The estimated order wait time is 20 minutes.");
                if (item_count > 5 && item_count <= 10)
                    printf("The estimated order wait time is 30 minutes");
                if (item_count > 10)
                    printf("The minimum wait time for your order is 45 minutes.\n");
                printf("Please collect your order when your order number is called.\n");
                print_ticket(&tablenum);
                printf("\nPress any key to go back to the main menu.");
                getchar();
                system("cls");
                break;

            case 3:                             // DELIVERY
                menu(&restaurant_number);
                ordernumber();
                orderinput(c_choice);
                func_payment(c_choice);
                print_ticket(&tablenum);
                getchar();
                system("cls");
                break;

            case 4:
            {                                       //RESERVATION
                FILE *TABLE;

                int t1, t2, t3, t4, t5, t6;
                int avail1 = 1, avail2 = 1, avail3 = 1, avail4 = 1, avail5 = 1, avail6 = 1;
                int tablearray[6], tablearraycount = 0;

                white();

                srand(time(NULL)); // rand() is being called inside of table_availability

                printf("-------------------\n"); // BOX START

                // Function used to show user for table availability
                table_availability(t1, tablearray, &avail1, &tablearraycount);
                table_availability(t2, tablearray, &avail2, &tablearraycount);
                table_availability(t3, tablearray, &avail3, &tablearraycount);
                table_availability(t4, tablearray, &avail4, &tablearraycount);
                table_availability(t5, tablearray, &avail5, &tablearraycount);
                table_availability(t6, tablearray, &avail6, &tablearraycount);

                printf("-------------------\n"); // BOX END

                red();
                printf("RED ");
                white();
                printf("= occupied tables\n\n");

                printf("The available tables are:"); // PRINTING THE tableS NOT OCCUPIED.

                unoccupied_tables(avail1, avail2, avail3, avail4, avail5, avail6);

                
                printf("Enter your desired table:"); // ENTERING table NUMBER
                scanf("%d", &tablenum);

                verify_resrvation(&tablenum, tablearray); // FOR MAKING SURE THAT USER IS ONLY RESERVING AVAILABLE TABLE

                char tablenumstr[1024];

                sprintf(tablenumstr, "%d", tablenum);

                TABLE = fopen("Tablenumber.txt", "w"); // MAKING A TXT FILE FOR table NUMBER
                fprintf(TABLE, "Table#");
                fputs(tablenumstr, TABLE);

                fclose(TABLE);

                printf("Your table has been reserved.");
                print_ticket(&tablenum);
                printf("Press any key to go back to the Main Menu: ");
                getchar();
                getchar();  
                system("cls");

                break;
            }
            case 5:
                printf("Hi! Your feedback is most welcome here\n\n");

                printf("Enter your order number:\n");
                scanf("%s", order_num);

                FEEDBACK = fopen("feedback.txt", "a+");

                fputs("Order Number: ", FEEDBACK);
                fputs(order_num, FEEDBACK);
                fputs("\n\n", FEEDBACK);

                printf("\nAnswer the following questions on a scale of 1 to 5\n\n");

                while (1)
                {
                    printf("How would you rate the food?\n");
                    scanf(" %d", &rate);
                    if (rate > 0 && rate < 6)
                    {
                        sprintf(ratestr, "%d", rate);
                        fputs("Rating for the food is: ", FEEDBACK);
                        fputs(ratestr, FEEDBACK);
                        break;
                    }
                    printf("Invalid Input!! Please rate within a scale of 1-5\n");
                }

                while (1)
                {

                    printf("How would you rate the customer service?\n");
                    scanf(" %d", &rate);
                    if (rate > 0 && rate < 6)
                    {
                        sprintf(ratestr, "%d", rate);
                        fputs("\nRating for the customer service is: ", FEEDBACK);
                        fputs(ratestr, FEEDBACK);
                        break;
                    }
                    printf("Invalid Input!! Please rate within a scale of 1-5\n");
                }

                while (1)
                {

                    printf("How would you rate your overall experience?\n");
                    scanf(" %d", &rate);
                    if (rate > 0 && rate < 6)
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
                printf("The code for the discount voucher is 'TableWable'");
                printf("\nPlease press any key to proceed back to the main menu.");
                getchar();
                getchar();
                system("cls");

                break;
            case 6:
                printf("Hi! We take your complaints very seriously\n"
                       "and will do our best to solve your problem.\n\n"
                       "What is your order number: ");

                scanf(" %s", order_num);

                sprintf(buffer2, "%s", order_num);

                srand(time(NULL));
                complaint = (rand() % (32676 + 1 - 10000) + 10000);

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
                getchar();
                getchar();
                system("cls");
                break;
            }

            strncpy(order, ordercpy, 50);
        }
        else if (strcmp(restaurant_menu, "no") == 0)
        {
            printf("The program has terminated");
            break;
        }
        else
        {
            printf("\nEnter correct input");
            goto start;
        }
        // Put here

        // Before this
    }
    return 0;
}

void restaurant()
{
    system("cls");
    printf("\nThis is the restaurant_menu. Please input the restaurant number you would like to eat at.");
    printf("\n Inputting 1 means you are selecting restaurant number 1.\n");
    printf("Please input 0 at any time to finish your order.\n\n");
    FILE *RESTAURANT;
    counter = 1;
    RESTAURANT = fopen("restaurant_list.txt", "r");
    while (fgets(res_data, 256, RESTAURANT)) // PRINTING RESTAURANTS
    {
        printf("%d. ", counter);
        printf("%s", res_data);
        counter = counter + 1;
    }
    fclose(RESTAURANT);
    printf("\n");
}

void restaurant_input(int *restaurant_number)
{
    printf("Enter your restaurant number here: ");
    scanf("%d", &(*restaurant_number));

    while (1)
    {
        if (*restaurant_number >= counter)
        {
            printf("\nPlease enter a number that is within the menu: ");
            scanf("%d ", &(*restaurant_number));
        }
        else
            break;
    }
}

void menu(int *restaurant_number)
{
    system("cls");
    printf("\nThis is the menu. Please input the item number you would like to order.");
    printf("\nInputting 1 means you are selecting item number 1.\n");
    printf("Please input 0 at any time to finish your order.\n\n");

    FILE *MENU;

    switch (*restaurant_number)
    {
    case 1:
    {
        a = "cafe_macawc_menu";
        extension = ".txt";
        char filename[strlen(a) + strlen(extension) + 1]; // Buffer for filename

        snprintf(filename, sizeof(filename), "%s%s", a, extension);
        MENU = fopen(filename, "r");
    }
    break;
    case 2:
    {
        a = "shah_noorani_restaurant_menu";
        extension = ".txt";
        char filename[strlen(a) + strlen(extension) + 1]; // Buffer for filename

        snprintf(filename, sizeof(filename), "%s%s", a, extension);
        MENU = fopen(filename, "r");
        // strncpy(filename_global,filename,strlen(a)+strlen(extension)+1);
    }
    break;
    case 3:
    {
        a = "pizza_originale_menu";
        extension = ".txt";
        char filename[strlen(a) + strlen(extension) + 1]; // Buffer for filename

        snprintf(filename, sizeof(filename), "%s%s", a, extension);
        MENU = fopen(filename, "r");
    }
    break;
    case 4:
    {
        a = "cheezious_menu";
        extension = ".txt";
        char filename[strlen(a) + strlen(extension) + 1]; // Buffer for filename

        snprintf(filename, sizeof(filename), "%s%s", a, extension);
        MENU = fopen(filename, "r");
    }
    break;
    case 5:
    {
        a = "yumto_menu";
        extension = ".txt";
        char filename[strlen(a) + strlen(extension) + 1]; // Buffer for filename

        snprintf(filename, sizeof(filename), "%s%s", a, extension);
        MENU = fopen(filename, "r");
    }
    break;
    case 6:
    {
        a = "kraves_menu";
        extension = ".txt";
        char filename[strlen(a) + strlen(extension) + 1]; // Buffer for filename

        snprintf(filename, sizeof(filename), "%s%s", a, extension);
        MENU = fopen(filename, "r");
    }
    break;
    case 7:
    {
        a = "casa_rice_menu";
        extension = ".txt";
        char filename[strlen(a) + strlen(extension) + 1]; // Buffer for filename

        snprintf(filename, sizeof(filename), "%s%s", a, extension);
        MENU = fopen(filename, "r");
    }
    break;
    default:
        break;
    }

    counter = 1;
    while (fgets(data, 256, MENU)) // PRINTING MENU
    {
        printf("%d. ", counter);
        printf("%s", data);
        counter = counter + 1;
    }
    fclose(MENU);
    printf("\n");
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

    order_counter = atoi(number); // CONVERTS NUMBER STRING TO INTEGER SO WE CAN PERFORM +1 OPERATION ON IT.
    order_counter = order_counter + 1;
    sprintf(number, "%d", order_counter); // CONVERTS INTEGER BACK TO STRING SO WE CAN USE FPUTS ON IT.
    NUMBER_CLOSE = fopen("number.txt", "w");
    fputs(number, NUMBER_CLOSE);
    fputs("\n", NUMBER_CLOSE);
    fclose(NUMBER_CLOSE);
    strncat(order, ".txt", 50); // ADDS ORDER NUMBER + ITEM NUMBER
    fclose(NUMBER);
}

void orderinput(char* customer_choice)
{
    printf("Enter your item number here: ");
    scanf("%d", &item_number);
    int cus_choice=atoi(customer_choice);
    char file_name[strlen(a) + strlen(extension) + 1];
    snprintf(file_name, sizeof(file_name), "%s%s", a, extension);
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
    while (item_number != 0)
    {
        ORDER = fopen(file_name, "r");
        //ORDER = fopen("cheezious_menu.txt", "r");
        while (1)
        {
            fgets(decide, 256, ORDER);
            
            if (feof(ORDER))
            {
                break;
            }
            if (current_line == item_number) // WHEN THE SELECTED ITEM IS CHOSEN.
            {
                strncat(decide_total,decide,256);
                strncat(decide_total,newline,3);
                char c[50];
                strncpy(c, decide, 50);
                char x[6];
                int int_x;
                token = strtok(c,"\t\t");
                int token_counter = 0;
                while (token != NULL)
                {
                    token_counter = token_counter + 1;
                    token = strtok(NULL, "\n");
                    if (token_counter == 1)
                    {
                        strncpy(x, token, 6);
                        int_x = atoi(x);
                        price_int = price_int + int_x;
                        break;
                    }
                };
                printf("%s", decide);
                fputs(decide, CART); // PUTS ITEM INTO ORDER TEXT FILE.
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
    printf("\n");
    if (cus_choice == 1)
        fprintf(CART, "\nOrder Type: Dine in\n");
    if (cus_choice == 2)
        fprintf(CART, "\nOrder Type: Takeaway\n");

    if (cus_choice == 3)
    {
        // All the customer input is sent to the order file.
        char data[50];
        char num[20];
        fprintf(CART,"\nOrder Type: Delivery\n");
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
        number: printf("\nEnter your mobile number here: ");
        fgets(num,20,stdin);
        if (strlen(num) != 12)
            {
                printf("Please enter a proper 11-digit mobile number: ");
                goto number;
            }
        fputs(num, CART);
    }
    if (cus_choice == 1 || cus_choice == 2 || cus_choice == 3)
    {
        printf("Please enter a coupon code to receive a 10%% discount, else press 0: ");
        scanf("%s", coupon);
        if (strcmp(coupon, "TableWable") == 0)

        {
            printf("\nYou have received a 10%% Discount on your order. Congratulations!");
            price_int = price_int - (price_int / 10);
        }
    }
    fputs("The total price is ", CART);
    sprintf(price, "%d", price_int);

    // Put here

    // Before here

    fputs(price, CART);
    fclose(CART);
    printf("\nYour order number is #%d.\n", order_counter - 1);
}

void func_payment(char* customer_choice)
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

    int cus_choice=atoi(customer_choice);

    printf("How would you like to pay:\n\n"
           "1. Cash\t\t2. Card\n");
    scanf("%d", &payment);
    switch (payment)
    {
    case 1:                                                 //CASH PAYMENT
        if (cus_choice == 1 || cus_choice == 2)
        {
            printf("Kindly pay the following amount at the counter.\n\n");
        }
        else if (cus_choice == 3)
        {
            printf("Kindly pay the following amount to the rider. \n\n");
        }
        printf("The total is:%s\n\n", price);
        printf("Press any character to continue:");
        getchar();
        getchar();
        break;

    case 2:                            

        PAYMENT = fopen("payment.txt", "w");                    //CARD PAYMENT

        printf("\nCard Type:\n"
               "1. VISA\t\t2. MASTERCARD\n\n");
        scanf(" %d", &card);

        if (card == 1)
        {
            strncpy(card_str, "VISA", 64);
            fputs("Card = VISA\n", PAYMENT);
        }
        else
        {
            strncpy(card_str, "MASTERCARD", 64);
            fputs("Card = MASTERCARD\n", PAYMENT);
        }
        while (1)
        {
            printf("\nEnter your card number:\n");
            scanf(" %[^\n]s", card_num);

            for (int i = 0; (i < strlen(card_num) && card_num[i] != '\0'); i++)
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

        while (1)
        {
            printf("\nEnter CVV:\n");
            scanf(" %[^\n]s", cvv);
            for (int i = 0; (i < strlen(cvv) && cvv[i] != '\0'); i++)
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

        while (1)
        {
            int month_int, year_int;
            char month[2];
            char year[2];
            printf("\nEnter your month and year of expiry (mm/yy):\n");
            scanf(" %[^\n]s", expiry);
            sscanf(expiry, "%[^/]s/%[^/]s", month, year);
            month_int = atoi(month);
            year_int = atoi(year);

            
            if (month_int > 12)
            {
                printf("Please input correct month number.");
                continue;
            }
            else
                break;
        }

        fputs(expiry, PAYMENT);
        fputs("\n", PAYMENT);

        srand(time(NULL));                                  //OTP GENERATION+CHECKING
        otp = (rand() % (32676 + 1 - 10000) + 10000);
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
            otp = (rand() % (32676 + 1 - 10000) + 10000);
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


void print_ticket(int* tablenum)                //Prints ticket
    {
    printf("\n");
    printf("****************\n");
    printf("*   TICKET   *\n");
    printf("****************\n");
    printf("\n");
    printf("****************\n");
    if (customer_choice == 4){ // reservation don't have order numbers 
    printf("Table %d has been reserved for you.\nThank you for using our services.",*tablenum);
    }
    else {
    printf("Order Counter: %d\n", order_counter-1);
    printf("********");
    printf("\n");
    printf("Order: %s\n", decide_total);
    printf("Item Count: %d\n", item_count-1);
    printf("Total: %d\n", price_int);
    printf("Thank you for using our services.\n");
    printf("\n");}
    }