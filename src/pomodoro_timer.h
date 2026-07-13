#ifndef MANGO_TIMER__POMODORO_TIMER_H
#define MANGO_TIMER__POMODORO_TIMER_H

#define DEFAULT_WORK_TIME 25
#define DEFAULT_SHORT_BREAK_TIME 5
#define DEFAULT_LONG_BREAK_TIME 10
#define DEFAULT_LONG_BREAK_INTERVAL 2

typedef struct {
    int work_duration;
    int short_break_duration;
    int long_break_duration;
    int long_break_interval;
    int current_working_sessions;
} pomodoro_timer_t;

pomodoro_timer_t initialize_pomodoro(int work,int short_break,int long_break,int long_break_interval);

void start_working_session(pomodoro_timer_t pomodoro);

void start_short_break_session(pomodoro_timer_t pomodoro);

void start_long_break_session(pomodoro_timer_t pomodoro);

#endif //MANGO_TIMER__POMODORO_TIMER_H
