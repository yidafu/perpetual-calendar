#include "calendar.h"


int month_code[12] = { 6, 2, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
char week[7][5] = {"sun","mon","tues","wed","thur","fri","sat"};



int main() {
    char command_in[50];
    month specify_month = {0,0,NULL} ;

    bootstrap();

    display("2017/09", &specify_month);

    scanf( "%s", command_in );
    refresh(0);

    while ( strcmp( command_in, "exit") ) {

        if ( strlen( command_in ) < 1 || strlen( command_in ) > 49 ) {
            printf("error command!\n");
        }

        display(command_in, &specify_month);

        scanf( "%s", command_in );
        refresh(0);
    }

    see_you();

     return 0;
}
