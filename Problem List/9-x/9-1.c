#include <stdio.h>

struct Time
{
    int hour;
    int minute;
    int second;
};

void addSeconds(struct Time *t, int seconds) {
    int totalSeconds = t->hour * 3600 + t->minute * 60 + t->second + seconds;
    totalSeconds = totalSeconds % 86400; // 处理超过一天的秒数
    t->hour = totalSeconds / 3600;
    t->minute = (totalSeconds % 3600) / 60;
    t->second = (totalSeconds % 3600) % 60;
}

int main()
{
    struct Time t;
    scanf("%d:%d:%d", &t.hour, &t.minute, &t.second);
    int ssplus;
    scanf("%d",&ssplus);
    
    addSeconds(&t, ssplus);

    printf("%02d:%02d:%02d",t.hour,t.minute,t.second);

}