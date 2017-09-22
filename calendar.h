//
// Created by yidafu on 2017/9/21.
//

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//TODO 这里注意一下 ifndef 这种情况
#ifndef PERPETUAL_CALENDAR_CALENDAR_H
#define PERPETUAL_CALENDAR_CALENDAR_H
int command (char str[]);

// 基于链表实现
struct days {
    int today;
    int week_day;
    struct days *next_day;
};

struct month {
    int day_count ;
    struct days day_list;
};
#endif //PERPETUAL_CALENDAR_CALENDAR_H

typedef int bool;

#define false 0;
#define true 1;
#define ERROR_CODE 0;

// in date.c
bool is_leap_year( int year );
int week_day_name( int year, int month , int month_code[] );

// in output.c
void show_month();
void refresh( int time );
char *current_time();
