#include <unistd.h>
#include <time.h>
#include <stdio.h>

void timer(int timeout) {
    time_t time_start = time(nullptr);
    time_t time_end;
    double time_diff;
    while (true) {
        sleep(1);
        time_end = time(nullptr);
        time_diff = difftime(time_end, time_start);
        printf("%d\n", (int) time_diff);
        if (time_diff >= timeout) {
            break;
        }
    }
}
