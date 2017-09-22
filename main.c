#include "calendar.h"


static int month_code[12] = { 6, 2, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };

int main() {
    command("hello");
//    month_code[test];
    int res = week_day_name( 2017, 6, month_code );
    printf("\n%d",res);
//    char *p = NULL;
//    p = current_time();
//    puts(p);
    return 0;
}