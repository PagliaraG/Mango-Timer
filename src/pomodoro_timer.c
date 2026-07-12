#include "timer.h"
#include "pomodoro_timer.h"

pomodoro_timer_t initialize_pomodoro(int work,int short_break,int long_break,int long_break_interval) {
    pomodoro_timer_t pomodoro;
    pomodoro.work_duration = work;
    pomodoro.short_break_duration = short_break;
    pomodoro.long_break_duration = long_break;
    pomodoro.long_break_interval = long_break_interval;
    pomodoro.current_working_sessions = 0;
    return pomodoro;
}

void start_working_session(pomodoro_timer_t pomodoro) {
    timer(pomodoro.work_duration);
    pomodoro.current_working_sessions++;
}

void start_short_break_session(pomodoro_timer_t pomodoro) {
    timer(pomodoro.short_break_duration);
}

void start_long_break_session(pomodoro_timer_t pomodoro) {
    timer(pomodoro.long_break_duration);
}

