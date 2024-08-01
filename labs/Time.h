#pragma once
#include <string> 
#include <iostream>
using namespace std;

class Time
{
public:
    int hours;
    int minutes;
    int seconds;
    Time();
    Time(double hours);
    Time(int, int, int);
    void set_hours(int);
    int get_hours() const;
    void set_minutes(int);
    int get_minutes() const;
    void set_seconds(int);
    int get_seconds() const;
    void ShowTime() const;
    void AddTime(const Time*, const Time*);
    int getTime();
    Time AddTime(Time);
    Time SubTime(Time);
    int calc_seconds() const
    {
        return this->hours * 3600 + this->minutes * 60 + this->seconds;
    }
    Time operator+ (const Time& t2) const
    {
        int s = seconds + t2.seconds;
        int m = minutes + t2.minutes;
        int h = hours + t2.hours;
        return Time(h, m, s);
    }
    Time operator+ (double hrs)
    {
        Time time2(hrs);
        Time newTime = *this + time2;
        return newTime;
    }
    Time operator+ (Time time2)
    {
        Time time3;
        Time time1(hours);
        return time3 = time1 + time2;
    }
    Time operator- (const Time& t2) const
    {
        int s = 0;  int m = 0; int h = 0;
        bool flag = true;
        int sec1 = 0; int sec2 = 0; int min1 = 0; int min2 = 0;
        int hours1 = 0; int hours2 = 0;
        if (hours - t2.hours < 0 || (hours - t2.hours == 0 && minutes - t2.minutes < 0) ||
            (hours - t2.hours == 0 && minutes - t2.minutes == 0 && seconds - t2.seconds < 0))
        {
            hours1 = t2.hours;
            hours2 = hours;
            min1 = t2.minutes;
            min2 = minutes;
            sec1 = t2.seconds;
            sec2 = seconds;
            flag = false;
        }
        else
        {
            hours1 = hours;
            hours2 = t2.hours;
            min1 = minutes;
            min2 = t2.minutes;
            sec1 = seconds;
            sec2 = t2.seconds;
        }
        s = sec1 - sec2;
        m = min1 - min2;
        if (flag == false)
            h = -(hours1 - hours2);
        else
            h = hours1 - hours2;
        return Time(h, m, s);
    }
    bool operator < (const Time& t2)
    {
        return this->calc_seconds() < t2.calc_seconds();
    }
    bool operator > (const Time& t2)
    {
        return this->calc_seconds() > t2.calc_seconds();
    }
    class TimeError
    {
    public:
        TimeError(int minutes, int seconds)
        {
            if (minutes < 0 && seconds < 0)
                message = "Incorrect minutes and seconds entered";
            else if (seconds < 0)
                message = "Incorrect seconds entered";
            else if (minutes < 0)
                message = "Incorrect minutes entered";
        }
        void printMessage() const { 
            cout << message << endl; 
        }
    private:
        string message;
        friend Time operator+ (double hours, Time t2);
    };

private:
    //int mutable hours;
    //int minutes;
    //int seconds;
};