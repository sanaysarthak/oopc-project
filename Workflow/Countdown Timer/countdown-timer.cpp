#include <iostream>
#include <windows.h> // in windows: Sleep()
// #include <unistd.h> // in linux: sleep()

using namespace std;

void Timer(int hours, int minutes, int seconds)
{
    system("cls"); // for windows
    // system("clear"); // for linux

    cout << "TIMER in C++\n" << endl;
    cout << hours << ":" << minutes << ":" << seconds << endl;
}

// to do: add a pop up that timer is finished and also add a alert (beep) sound / audio.

int main()
{
    int hour, min, sec = 0; // initializing with 0
    cout << "Timer in C++\n" << endl;
    cout << "Enter hour: ";
    cin >> hour;
    cout << "Enter minute: ";
    cin >> min;
    cout << "Enter second: ";
    cin >> sec;

    Timer(hour, min, sec);

    while (true)
    {
        Sleep(1000);

        if (sec == 0) {
            if (min == 0) {
                if (hour == 0) {
                    cout << "Timer Finished!" << endl;
                    break; // Exit loop when timer finishes
                }
                hour--;
                min = 59;
            }
            else
                min--;
            sec = 59;
        }
        else
            sec--;

        Timer(hour, min, sec);
    }
    return 0;
}
