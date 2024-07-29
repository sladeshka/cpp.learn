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
    };

private:
    //int mutable hours;
    //int minutes;
    //int seconds;
};