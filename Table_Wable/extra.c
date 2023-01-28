/*else if (strcmp(main_menu, "x") == 0)
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
}*/

/*EXPENSES = fopen("Expenses.txt", "w+");
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
fclose(EXPENSES);*/