#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>


void red()
{
    printf("\033[0;31m"); // FUNCTION FOR CHANGING COLOR TO RED
}

void white()
{
    printf("\033[0;37m"); // FUNCTION FOR CHANGING COLOR TO WHITE // 37 for white  // 31 for red
}