#ifndef RESERVATION_H
#define RESERVATION_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

void table_availability(int table, int *tablearray, int *availability, int *tablearraycount);
void unoccupied_tables(int avail1, int avail2, int avail3, int avail4, int avail5, int avail6);
void verify_resrvation(int *tablenum, int *tablearray);
void white();
void red();
#endif