//
// Created by yidafu on 2017/9/22.
//
/**
 * @encoding GBK
 */

#include "calendar.h"

/**
 * 这是个假装程序很大的启（qi）动（pian）函数。
 * 主要是显示程序的加载进度，用来提升B格
 */
void bootstrap () {
    char chars2[6][8] = {".","..","...","... .","... ..","... ..."};
    char ch = '%';
    for (int i = 1 ; i < 100; i ++ ) {
        printf("root@lap-tap: ~$ program is loading!");
        printf(" %d %c  %s", i, ch, chars2[ i % 6] );

        refresh(10);
    }
}

/**
 * 这个是主要的展示函数。
 * 通过一系列的函数调用来实现页面的输出。
 * @param commod_in     传入的要被解析的命令
 * @param specify_month 这个是存放将要被输出的月份的日期信息的
 *                      结构体
 */
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

/**
 * 这个函数主要是将一个月的日期信息格式化输出。
 * 包括开头的一个月开头的非本月的空格输出。比如，一个月的第一天
 * 是周五的话，前面的周日到周四先打印 Tab 缩进。
 * @param specify_month 包含要输出的一个月的所有日期信息的结构体
 */
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

/**
 * 打印本程序的展示页面的头部
 */
void print_header() {
    printf("\tWelcome to use Cu Cao Pai calender !\n");
    printf("-------|***********************************|-------\n");
    printf("NOW: %s\n",current_time());
}

/**
 * 主要打印每个月份的说明头和星期几的英文缩写
 * @param year  [description]
 * @param month [description]
 */
void print_nav (int year, int month) {
    printf("\n\n++++++++++ %d/%d ++++++++++ \n",year,month);
    for (int i = 0 ; i < 7 ; i ++ ) {
        printf("%s\t",week[i]);
    }
}

/**
 * 打印命令提示行
 */
void print_footer() {
    printf("\nplase type command(like��2017/09 or 2017. And type exit to exit):");
    printf("\nroot@lap-tap:~$ ");
}

/**
 * 打印执行exit命令后的，离开页面，并且是使程序间隔两秒关闭
 */
void see_you() {
    printf("|-------------------------------|\n");
    printf("|\tsee you next time!\t|\n");
    printf("|-------------------------------|\n");
    Sleep(2000);
}

/**
 * 设置延时，刷新程序页面
 * @param time 刷新的延时时间
 */
void refresh ( int time ) {
    Sleep(time);
    system("cls");
};
