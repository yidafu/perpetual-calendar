#include "calendar.h"


int month_code[12] = { 6, 2, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
char week[7][5] = {"sun","mon","tues","wed","thur","fri","sat"};

void show (char *commod_in , month *specify_month ) {
    print_header();

    int year,month;
    int *get;
    get = command( commod_in );
    year = *get ++;
    month = *get;
    if( month == 0 ) {
        for ( int i = 1 ; i < 13 ; i++ ) {
            print_nav( year, i );
            init_list(specify_month, year, i );
            bing_data(specify_month);
            show_month(specify_month);
        }
    } else {
        print_nav( year, month );
        init_list(specify_month, year, month );
        bing_data(specify_month);
        show_month(specify_month);
    }
    print_footer();
}


int main() {
    char command_in[50];
    month specify_month = {0,0,NULL} ;

//    bootstrap();

    show("2017/09",&specify_month);

    scanf( "%s", command_in );
    refresh(0);

    while ( strcmp( command_in, "exit") ) {

        if ( strlen( command_in ) < 1 || strlen( command_in ) > 49 ) {
            printf("error command!\n");
        }
        if ( specify_month.day_base != NULL ) {
            free(specify_month.day_base);
        }


        show( command_in,&specify_month );

        scanf( "%s", command_in );
        refresh(0);
    }

    see_you();
     return 0;
}
