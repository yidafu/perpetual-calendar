//
// Created by yidafu on 2017/9/21.
//

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>

//TODO 这里注意一下 ifndef 这种情况
#ifndef PERPETUAL_CALENDAR_CALENDAR_H
#define PERPETUAL_CALENDAR_CALENDAR_H

// 基于顺序表来实现
typedef  struct {
    int today;
    int week_day;
} days ;

typedef struct {
    int day_count ;
    // 一个月第一天的是周几的指代码
    int week_name;
    days *day_base;
} month;
#endif //PERPETUAL_CALENDAR_CALENDAR_H

// 全局变量
extern char week[7][5];
extern int month_code[];

typedef int bool;

#define false 0;
#define true 1;
#define ERROR_CODE 0;

// in date.c
bool is_leap_year( int year );
int week_day_name( int year, int month , int month_code[] );
int get_month_days (int year, int month );

// in output.c
void bootstrap();
void show_month( month *specify_month );
void refresh( int time );
void print_header();
void print_nav(int year, int month);
void print_footer();
void see_you();
char *current_time();

// in sq_list.c
bool bing_data(month *specify_month );
bool init_list( month *specify_month, int year, int month );

// in command.c
int *command (char str[]);

