//
// Created by yidafu on 2017/9/23.
//

#include "calendar.h"

bool init_list ( month *specify_month, int year, int month ) {
    days *new_day_base;
    (*specify_month).day_count = get_month_days( year , month );
    (*specify_month).week_name = week_day_name( year, month , month_code );
    new_day_base = (days*) malloc( (*specify_month).day_count * sizeof( days ) );
    new_day_base->today = 1;
    new_day_base->week_day = 2;
    (*specify_month).day_base = new_day_base;
//    printf("\n%d\n",sizeof(specify_month->day_base[1]));
    if ( (*specify_month).day_base == NULL ) {
        exit(1);
    }
//    FIXME 为什么这里的 &specify_month 的地址不对了？？
//    printf("%d",&specify_month);
    return true;
//    return 0;
}
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