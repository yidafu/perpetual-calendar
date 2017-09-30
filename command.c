//
// Created by yidafu on 2017/9/21.
//

#include "calendar.h"

/**
 * 截取出年份的字符串
 * @param str      char[]  需要解析的字符串
 * @param year_str char[]  解析出来的年份字符串
 */
void get_year ( char *str , char *year_str) {
    for ( int i = 0 ; i < 4 ; i ++) {
        year_str[i] = str[i];
    }
}

/**
 * 截取出月份的字符串
 * @param str      char[]  需要解析的字符串
 * @param year_str char[]  解析出来的月份字符串
 */
void get_month ( char *str, char *month_str ) {
    for ( int i = 5; i < 7; i ++ ) {
        month_str[ i - 5 ] = str[i];
    }
}
/**
 * 做命令行解析，假设输入的都是正确的命令
 * 因为这里需要返回两个整型，所以通过返回的是一个包含
 * 两个要返回的整型数值的数组指针来实现。
 * @param str   输入的命令
 * @return *int 返回一个 int[0] 对应 year， int[1]
 *              对应 month 的数组
 */
int *command (char str[]) {
    char year_str[5],month_str[3];
    int year = 0,
        month = 0,
        arr[2] = {0};

    get_month( str, month_str );
    get_year( str, year_str );

    year = atoi( year_str );
    month = atoi( month_str );

     arr[0] = year;
    arr[1] = month;
    int *p = arr;
    return p;
}
