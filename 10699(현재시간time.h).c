#include <stdio.h>
#include <time.h>

int main()
{
    time_t now_time; // time_t Ÿ��, %lld�� ����ϸ� 1970�⵵���� ���ݱ��� �帥 �ð� �� ���� ���������� �������
    struct tm* now_time_info;

    now_time = time(NULL);
    now_time_info = localtime(&now_time);

    if(now_time_info->tm_mon < 9)
    printf("%d-0%d-%d", now_time_info->tm_year + 1900, now_time_info->tm_mon+1, now_time_info->tm_mday);
    else
    printf("%d-%d-%d", now_time_info->tm_year + 1900, now_time_info->tm_mon+1, now_time_info->tm_mday);
}
/*
struct?tm
{
    int?tm_sec;???//?seconds?after?the?minute?-?[0,?60]?including?leap?second
    int?tm_min;???//?minutes?after?the?hour?-?[0,?59]????
    int?tm_hour;??//?hours?since?midnight?-?[0,?23]????
    int?tm_mday;??//?day?of?the?month?-?[1,?31]????
    int?tm_mon;???//?months?since?January?-?[0,?11]?-> 1 ������� �̹����� ���� ����!!!!!!!
    int?tm_year;??//?years?since?1900????           -> 1900�� ���������!!!!!!
    int?tm_wday;??//?days?since?Sunday?-?[0,?6]????
    int?tm_yday;??//?days?since?January?1?-?[0,?365]????
    int?tm_isdst;?//?daylight?savings?time?flag};
��ó: https://blockdmask.tistory.com/417 [������ ������:Ƽ���丮]
*/