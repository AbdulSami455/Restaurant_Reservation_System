#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#include "colors.h"


void table_availability(int table, int *tablearray, int *availability, int *tablearraycount)        //shows unoccupied tables
{

    table = (rand() % 2) + 1;

    static int table_number = 1;
    if (table_number == 1 || table_number == 4)
    {
        printf("| ");
    }

    if (table == 1)
    {
        red();
        if (table_number == 3 || table_number == 6)
        {
            printf("%d |\n", table_number);
        }
        else
        {
            printf("%d\t", table_number);
        }
        white(); // FUNCTTION FOR CHANGING COLOR OF TEXT
        *availability = 0;
        tablearray[*tablearraycount] = 1;
        *tablearraycount = *tablearraycount + 1;
    }
    else
    {
        if (table_number == 3 || table_number == 6)
        {
            printf("%d", table_number);
            printf(" |\n");
        }
        else
        {
            printf("%d\t", table_number);
        }
    }
    table_number++;
}

void unoccupied_tables(int avail1, int avail2, int avail3, int avail4, int avail5, int avail6) //Writes unoccupied tables
{
    if (avail1 == 1)
    {
        printf("1");
    }
    if (avail2 == 1)
    {
        printf(" 2");
    }
    if (avail3 == 1)
    {
        printf(" 3");
    }
    if (avail4 == 1)
    {
        printf(" 4");
    }
    if (avail5 == 1)
    {
        printf(" 5");
    }
    if (avail6 == 1)
    {
        printf(" 6");
    }
    printf("\n");
}

void verify_resrvation(int *tablenum, int *tablearray)      //Makes sure that user inputs correct table
{
    // int table_temp=*tablenum;
    while (1)
    { // LOOP FOR OUT OF RANGE INPUT
        if (*tablenum >= 1 && *tablenum <= 6)
        {
            break;
        }
        printf("invalid input.Enter again:");
        scanf("%d", &(*tablenum));
    }
    while (1) // LOOP FOR OCCUPIED TABLE INPUT
    {
        int found = 0;
        for (int occupycount = 0; occupycount < 6; occupycount++)
        {
            if (*tablenum == tablearray[occupycount])
            {
                found++;
            }
        }
        if (found > 0)
        {
            printf("This table is occupied. Enter in an available table: ");
            scanf("%d", &(*tablenum));
            found = 0;
        }
        else
        {
            break;
        }
    }
}