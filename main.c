#include "calendar.h"


int month_code[12] = { 6, 2, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
char week[7][5] = {"sun","mon","tues","wed","thur","fri","sat"};

void test () {
    month specify_month;
////    FIXME 为什么这里的 &specify_month 前后的地址变了？？
////    printf("\t%d||0",&specify_month);
////    printf("\t%d||0",&specify_month);
//    show_month( &specify_month );
//    printf("\n");

    int *get;
    get = command("2017/06");
    int year = *get ++;
    int month = *get;
    int test =1;
}

void show ( char *command_in ,month *specify_month) {
    print_header();
    int year,month;
    int *get;
//    printf("%s",command_in);
    get = command( command_in );
    year = *get ++;
    month = *get;

    init_list(specify_month, year, month );
    bing_data(specify_month);
    show_month(specify_month);
    print_footer();
}


int main() {
    char command_in[50];
    month specify_month;
//    bootstrap();
    show("2017/09", &specify_month );
    scanf( "%s", command_in );
    refresh(0);
    while ( strcmp( command_in, "exit") ) {

        if( strlen( command_in ) < 1 || strlen( command_in ) > 49 ) {
            printf("error command!\n");
        }
        free(&specify_month);
        show( command_in, &specify_month );

        scanf( "%s", command_in );
        refresh(0);
    }

     return 0;
}
