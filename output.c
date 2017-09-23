//
// Created by yidafu on 2017/9/22.
//
/**
 * @encoding GBK
 */

#include "calendar.h"

void bootstrap () {
    // TODO
}

void show_month ( month *specify_month ) {
//    for (int i = 0 ; i < 7 ; i ++ ) {
//        printf("%s\t",week[i]);
//    }
    int day_index = 0, day = 0;
    for ( ; day_index < 30 ; day ++ ) {
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
    printf("\t欢迎使用粗糙牌万年历\n");
    printf("-------|*****************|-------\n");
    for (int i = 0 ; i < 7 ; i ++ ) {
        printf("%s\t",week[i]);
    }
}
void print_footer() {
    printf("\n请输入指定的年月（例如：2017/9)或者使用左右方向键：（退出请输入exit）");
    printf("\nroot@lap-tap:~$ ");
}
void refresh ( int time ) {
    Sleep(time);
    system("cls");
};
