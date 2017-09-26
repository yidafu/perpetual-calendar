//
// Created by yidafu on 2017/9/22.
//
/**
 * @encoding GBK
 */

#include "calendar.h"

void bootstrap () {
    char chars[4][4] = {"\\","|","/","--"};
    char chars2[6][8] = {".","..","...","... .","... ..","... ..."};
    char ch = '%';
    for (int i = 1 ; i < 100; i ++ ) {
        printf("root@lap-tap: ~$ program is loading!");
        printf(" %d %c  %s", i, ch, chars2[ i % 6] );

        refresh(10);
    }
}
void display(char *commod_in, month *specify_month) {
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

void show_month ( month *specify_month ) {

    int day_index = 0, day = 0;
    for ( ; day_index < (*specify_month).day_count ; day ++ ) {
        days weekday = (*specify_month).day_base[day_index];
        int today = weekday.today;
        int week_day = weekday.week_day;
        if (day % 7 == week_day) {
            printf("%d\t", today);
            day_index++;
        } else {
            printf("\t");
        }
        if (day % 7 == 0) {
            printf("\n");
        }
    }
}
void print_header() {
    printf("\tWelcome to use Cu Cao Pai calender !\n");
    printf("-------|***********************************|-------\n");
    printf("NOW: %s\n",current_time());
}
void print_nav (int year, int month) {
    printf("\n\n++++++++++ %d/%d ++++++++++ \n",year,month);
    for (int i = 0 ; i < 7 ; i ++ ) {
        printf("%s\t",week[i]);
    }
}
void print_footer() {
    printf("\nplase type command(like£º2017/09 or 2017. And type exit to exit):");
    printf("\nroot@lap-tap:~$ ");
}

void see_you() {
    printf("|-------------------------------|\n");
    printf("|\tsee you next time!\t|\n");
    printf("|-------------------------------|\n");
    Sleep(2000);
}


void refresh ( int time ) {
    Sleep(time);
    system("cls");
};
