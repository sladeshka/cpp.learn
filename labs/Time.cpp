#include <string>
#include <fstream>
#include "Time.h" 
#include <iostream>

using namespace std;

int hours;
int minutes;
int seconds;

Time::Time()
{
    Time::hours = 0;
    Time::minutes = 0;
    Time::seconds = 0;
}
Time::Time(int hours, int minutes, int seconds)
{
    if (minutes < 0 || seconds < 0)
        throw TimeError(minutes, seconds);
    else
    {
        Time::set_seconds(seconds);
        Time::set_minutes(minutes);
        Time::set_hours(hours);
    }
}
void Time::set_hours(int time_hours)
{
    Time::hours += time_hours;
}
int Time::get_hours() const
{
    return Time::hours;
}
void Time::set_minutes(int time_minutes)
{
    Time::hours = 0;
    while (Time::minutes + time_minutes > 59)
    {
        time_minutes -= 60;
        Time::hours++;
    }
    Time::minutes += time_minutes;
}
int Time::get_minutes() const
{
    return Time::minutes;
}
void Time::set_seconds(int time_seconds)
{
    Time::minutes = 0;
    while (time_seconds > 59)
    {
        time_seconds -= 60;
        Time::minutes++;
    }
    Time::seconds = time_seconds;
}
int Time::get_seconds() const
{
    return Time::seconds;
}
void Time::ShowTime() const
{
    string str_h = "";
    string str_m = "";
    string str_s = "";
    if (Time::hours < 10 && Time::hours > -1)
        str_h = "0" + to_string(Time::hours);
    else if (Time::hours < 0 && Time::hours > -10)
        str_h = "-0" + to_string(abs(Time::hours));
    else
        str_h = to_string(Time::hours);
    if (Time::minutes < 10)
        str_m = "0" + to_string(Time::minutes);
    else
        str_m = to_string(Time::minutes);
    if (Time::seconds < 10)
        str_s = "0" + to_string(Time::seconds);
    else
        str_s = to_string(Time::seconds);
    cout << str_h << ":" << str_m << ":" << str_s << endl;
}
void Time::AddTime(const Time* time1, const Time* time2)
{
    Time::set_seconds(time1->get_seconds() + time2->get_seconds());
    Time::set_minutes(time1->get_minutes() + time2->get_minutes());
    Time::set_hours(time1->get_hours() + time2->get_hours());
}
int Time::getTime()
{
    return hours * 3600 + minutes * 60 + seconds;
}
Time Time::AddTime(Time t1)
{
    Time t;
    t.hours = 0;
    t.minutes = 0;
    t.seconds = 0;
    if (seconds + t1.seconds > 59)
    {
        t.seconds = seconds + t1.seconds - 60;
        t.minutes++;
    }
    else
        t.seconds = seconds + t1.seconds;
    if (t.minutes + minutes + t1.minutes > 59)
    {
        t.minutes = t.minutes + minutes + t1.minutes - 60;
        t.hours++;
    }
    else
        t.minutes += minutes + t1.minutes;
    t.hours += hours + t1.hours;
    return t;
}

Time Time::SubTime(Time t1)
{
    Time t;
    t.hours = 0;
    t.minutes = 0;
    t.seconds = 0;
    if (seconds - t1.seconds < 0)
    {
        t.seconds = 60 + seconds - t1.seconds;
        t.minutes--;
    }
    else
        t.seconds = seconds - t1.seconds;
    if (t.minutes + minutes - t1.minutes < 0)
    {
        t.minutes = 60 + t.minutes + minutes - t1.minutes;
        t.hours--;
    }
    else
        t.minutes += minutes - t1.minutes;
    t.hours += hours - t1.hours;
    return t;
}
