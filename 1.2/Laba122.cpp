#include <iostream>
 
struct Time {
    int hours;
    int minutes;
    int seconds;
};
 
 
Time NextTime(Time now, int dt) 
{
    Time next=now;
    next.seconds = 3600*now.hours + 60*now.minutes + now.seconds+dt;
    next.hours = next.seconds/3600;
    if(next.hours>24) 
    {
        next.hours=next.hours-24;
    }
    next.minutes = (next.seconds - next.hours*3600)/60;
    next.seconds = next.seconds - 3600*next.hours - 60*next.minutes;
    return next;
}
 
 
int main() {
    Time t, t_next;
    t.hours =3;
    t.minutes= 25;
    t.seconds =11;
    int dt = 100; //seconds
 
    t_next =NextTime(t, dt);
    std::cout << "Время сейчас: " << t.hours<< " "<<  t.minutes << " "<<t.seconds  << endl;
    std::cout << "Следующее время: " << t_next.hours<< " "<<  t_next.minutes << " "<<t_next.seconds  << endl;
    return 0;
}
