#include <iostream>
#include <windows.h> // in windows: Sleep()
// #include <unistd.h> // in linux: sleep()

using namespace std;

void displayTime(int minutes, int seconds, int milliseconds) {
    system("cls"); // for windows 
    // system("clear"); // for linux
    cout << "STOPWATCH in C++\n" << endl;
    cout << minutes << ":" << seconds << ":" << milliseconds << endl;
}

int main() {
    int min, sec, m_sec = 0; // initializing with 0
    cout << "Stopwatch in C++\n" << endl;
    cout << "Press ENTER to START Stopwatch.\nPress Ctrl + C to STOP Stopwatch." << endl;
    cin.ignore();

    displayTime(min, sec, m_sec);

    while(true) {
        Sleep(1);

        m_sec++;

        if(m_sec > 59) {
            sec++;
            m_sec = 0;
        }

        if(sec > 59) {
            min++;
            m_sec = 0;
            sec = 0;
        }

        displayTime(min, sec, m_sec);
    }
    return 0;
}
