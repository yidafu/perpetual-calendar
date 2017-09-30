//
// Created by yidafu on 2017/9/23.
//

#include "calendar.h"

/**
 * 初始化顺序不表
 * @param specify_month 包含要输出的一个月的所有日期信息的结构体
 * @param  year          年份
 * @param  month         月份
 * @return               如果初始化成功返回 true，直接退出程序
 */
bool init_list ( month *specify_month, int year, int month ) {
    days *new_day_base;

    // 调用 get_month_days() 函数的到一个月的天数
    (*specify_month).day_count = get_month_days( year , month );

    // 调用 week_day_name() 函数得到一个月第一天是星期几
    (*specify_month).week_name = week_day_name( year, month , month_code );

    // 释放之前的内存
    if( (*specify_month).day_base != NULL ) {
        free( (*specify_month).day_base );
    }
    // 再分配空间
    new_day_base = (days*) malloc( (*specify_month).day_count * sizeof( days ) );
    new_day_base->today = 1;
    new_day_base->week_day = 2;
    (*specify_month).day_base = new_day_base;
    if ( (*specify_month).day_base == NULL ) {
        exit(1);
    }
//    FIXME 为什么这里的 &specify_month 的地址不对了？？
    return true;
}

/**
 * 主要给 specify_month 变量绑定数据
 * @param specify_month 包含要输出的一个月的所有日期信息的结构体
 * @return               绑定成功返回 true
 */
bool bing_data ( month *specify_month ) {

    int begin_week_name = (*specify_month).week_name;

    for (int day = 0 ; day < (*specify_month).day_count ; day ++ ) {
        days *day_p;
        day_p = &(*specify_month).day_base[day];
        (*day_p).today = day + 1 ;
        (*day_p).week_day = ( day + begin_week_name ) % 7;
    }
    return true;
}
