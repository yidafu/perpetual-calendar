//
// Created by yidafu on 2017/9/21.
//

#include "calendar.h"

void get_year ( char *str , char *year_str) {
    for ( int i = 0 ; i < 4 ; i ++) {
        year_str[i] = str[i];
    }
}
void get_month ( char *str, char *month_str ) {
    for ( int i = 5; i < 7; i ++ ) {
        month_str[ i - 5 ] = str[i];
    }

}
/**
 * 做命令行解析，假设输入的都是正确的名利
 * @param str 输入的命令
 * @return *int 返回一个 int[0] 对应 year， int[1]
 *              对应 month 的数组
 */
int *command (char str[]) {
//    if ( strlen(str) != 7) {
//        exit(1);
//    }
    char year_str[5],month_str[3];
    int year,
        month,
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
