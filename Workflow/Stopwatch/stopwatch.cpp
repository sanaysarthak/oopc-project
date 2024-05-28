#include <iostream>
#include <windows.h> // in windows: Sleep()
// #include <unistd.h> // in linux: sleep()

using namespace std;

void displayTime(int hours, int minutes, int seconds) {
    system("cls"); // for windows 
    // system("clear"); // for linux
    
    cout << hours << ":" << minutes << ":" << seconds << endl;
}

int main() {
    int hour, min, sec = 0; // initializing with 0
    cout << "Stopwatch in C++.\n" << endl;
    cout << "Press ENTER to START Stopwatch.\nPress Ctrl + C to STOP Stopwatch." << endl;
    cin.ignore();

    displayTime(hour, min, sec);

    while(true) {
        Sleep(1);

        sec++;

        if(sec > 59) {
            min++;
            sec = 0;
        }

        if(min > 59) {
            hour++;
            sec = 0;
            min = 0;
        }

        displayTime(hour, min, sec);
    }
    return 0;
}