//
// Created by yidafu on 2017/9/21.
//
#include "calendar.h"

extern int month_code;
//
/**
 * 判断输入的年份是否是闰年
 * @param year 待判断的年份
 * @return bool 如果是闰年返回 true，否则返回 false
 * @calling
 * @called week_day_name();
 */
bool is_leap_year ( int year ) {
    if ( ( year % 4 == 0 && year % 100 != 0 ) || year % 400 == 0 ) {
        return true;
    } else {
        return false;
    }
}
/**
 * 通过调用 time.h 的函数，实现得到一个现在的具体时间字符串
 * @return char* 现在的具体时间字符串
 * @calling time(),ctime()
 * @called  main()
 */
char *current_time () {
    time_t current_time;
    time( &current_time );
    return ctime( &current_time );
}
/**
 * 返回 2000-2999 之间的年份码
 * @param year  想要得到年份码的年份
 * @return      年份码
 * @calling
 * @called week_day_name()
 */
int year_code_2000 ( int year ) {
    if ( year < 2000 ) {
        exit(0);
    }
    int year_remainder = year % 100 ;

    int year_code = ( ( year_remainder / 4 ) + year_remainder ) % 7;

    return year_code;
}
/**
 *  根据是否是闰年来修改月份码，参考 doc/参考.md
 * @param year          要判断是否为闰年的年份
 * @param month_code    要修改的年份码
 * @return void
 * @calling is_leap_year()
 * @called week_day_name()
 */
void right_month_code ( int year, int *month_code ) {
    if( is_leap_year( year ) ) {
        *month_code = 5,
        *( month_code + 1 )= 1;
    };
}

/**
 * 返回指定年月的 1 号是周几，使用数字代替
 * @param year int          指定的年份
 * @param month int         指定的月份
 * @param month_code int[]  保存月份码的数组
 * @return int              返回周几的指代码。1 为周一，2为周二 ...
 * @calling right_month_code(),year_code_200()
 * @called main()
 */
int week_day_name ( int year , int month ,int month_code[] ) {
    right_month_code( year, month_code );
    int year_code = 0,
        week_day  = 0;

    if( year > 1999 && year < 3000 ) {
        year_code = year_code_2000( year );
    }
    week_day = year_code + month_code[ month - 1 ] + 1 ;

    return week_day;

}