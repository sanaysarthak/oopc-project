#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h> // in windows: Sleep()
// #include <unistd.h> // in linux: sleep()
using namespace std;

// word pool to choose characters from for the password
const char alphanum[] = "0123456789!@#$%^&*abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
int pool_len = sizeof(alphanum) - 1; // word pool length

void showASCII();
void showToolInfo();

void encryptFile(const string &inputFilePath, const string &outputFilePath, int key)
{
    ifstream inputFile(inputFilePath, ios::binary);
    ofstream outputFile(outputFilePath, ios::binary);

    char ch;
    while (inputFile.get(ch))
    {
        outputFile.put(ch + key);
    }

    inputFile.close();
    outputFile.close();
    cout << "\nFile encrypted successfully." << endl;
}

void decryptFile(const string &inputFilePath, const string &outputFilePath, int key)
{
    ifstream inputFile(inputFilePath, ios::binary);
    ofstream outputFile(outputFilePath, ios::binary);

    char ch;
    while (inputFile.get(ch))
    {
        outputFile.put(ch - key);
    }

    inputFile.close();
    outputFile.close();
    cout << "\nFile decrypted successfully." << endl;
}

void displayTime(int minutes, int seconds, int milliseconds)
{
    system("cls"); // for windows
    // system("clear"); // for linux

    cout << "STOPWATCH in C++\n" << endl;
    cout << minutes << ":" << seconds << ":" << milliseconds << endl;
}

void Timer(int hours, int minutes, int seconds)
{
    system("cls"); // for windows
    // system("clear"); // for linux

    cout << "TIMER in C++\n" << endl;
    cout << hours << ":" << minutes << ":" << seconds << endl;
}

int main()
{
    int ch;
    string inputFilePath, outputFilePath; // for file encryptor and decryptor
    int pass_len; // for password generator
    int choice, key; // for file encryptor and decryptor
    int hour, min, sec, m_sec = 0; // initializing with 0

    showASCII();

    do {
        showToolInfo();
        cin >> ch;
        switch (ch) {

            case 1:
                cout << endl;
                cout << "File Encryptor and Decryptor.\n" << endl;
                cout << "1. Encrypt File" << endl;
                cout << "2. Decrypt File" << endl;
                cout << "Enter your choice: ";
                cin >> choice;

                cout << "Enter key (integer): ";
                cin >> key;

                cout << "Enter input file path: ";
                cin >> inputFilePath;
                cout << "Enter output file path: ";
                cin >> outputFilePath;

                if (choice == 1)
                    encryptFile(inputFilePath, outputFilePath, key);
                else if (choice == 2)
                    decryptFile(inputFilePath, outputFilePath, key);
                else
                    cout << "Invalid choice." << endl;
                cout << "\n" << endl;
                break;


            case 2:
                cout << endl;
                cout << "Password Generator.\n" << endl;
                inputLength: // label
                cout << "Enter length of password: ";
                cin >> pass_len;
                if (pass_len < 8)
                {
                    cout << "For better security, enter length of password to be greater than or equal to 8!\n" << endl;
                    goto inputLength;
                }
                srand(time(0));
                cout << "Generating Password......." << endl;
                Sleep(2000); 
                cout << "Generated Password: \t\t";
                for (int i = 0; i < pass_len; i++)
                {
                    cout << alphanum[rand() % pool_len];
                }
                cout << "\n" << endl;               
                break;


            case 3:
                cout << endl;
                cout << "Stopwatch in C++\n" << endl;
                cout << "Press ENTER to START Stopwatch.\nPress Ctrl + C to STOP Stopwatch." << endl;
                cin.ignore(); // to take Enter as input
                displayTime(min, sec, m_sec);
                while (true)
                {
                    Sleep(1);
                    m_sec++;
                    if (m_sec > 59)
                    {
                        sec++;
                        m_sec = 0;
                    }
                    if (sec > 59)
                    {
                        min++;
                        m_sec = 0;
                        sec = 0;
                    }
                    displayTime(min, sec, m_sec);
                }
                cout << "\n" << endl; 
                break;


            case 4:
                cout << endl;
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
                cout << "\n" << endl; 
                break;
        }
    } while(ch != 0);

    return 0;
}

void showASCII() {
    cout << "                                                                                                        " << endl;
    cout << "             ________  ________  ________  ________                                                     " << endl;
    cout << "            |\\   __  \\|\\   __  \\|\\   __  \\|\\   ____\\                                            " << endl;
    cout << "            \\ \\  \\|\\  \\ \\  \\|\\  \\ \\  \\|\\  \\ \\  \\___|                                     " << endl;
    cout << "             \\ \\  \\\\\\  \\ \\  \\\\\\  \\ \\   ____\\ \\  \\                                        " << endl;
    cout << "              \\ \\  \\\\\\  \\ \\  \\\\\\  \\ \\  \\___|\\ \\  \\____                                  " << endl;
    cout << "               \\ \\_______\\ \\_______\\ \\__\\    \\ \\_______\\                                      " << endl;
    cout << "                \\|_______|\\|_______|\\|__|     \\|_______|                                            " << endl;
    cout << "                                                                                                        " << endl;
    cout << "                                                                                                        " << endl;
    cout << "  ________  ________  ________        ___  _______   ________ _________                                 " << endl;
    cout << " |\\   __  \\|\\   __  \\|\\   __  \\      |\\  \\|\\  ___ \\ |\\   ____\\\\___   ___\\                 " << endl;
    cout << " \\ \\  \\|\\  \\ \\  \\|\\  \\ \\  \\|\\  \\     \\ \\  \\ \\   __/|\\ \\  \\___\\|___ \\  \\_|        " << endl;
    cout << "  \\ \\   ____\\ \\   _  _\\ \\  \\\\\\  \\  __ \\ \\  \\ \\  \\_|/_\\ \\  \\       \\ \\  \\           " << endl;
    cout << "   \\ \\  \\___|\\ \\  \\\\  \\\\ \\  \\\\\\  \\|\\  \\\\_\\  \\ \\  \\_|\\ \\ \\  \\____   \\ \\  \\   " << endl;
    cout << "    \\ \\__\\    \\ \\__\\\\ _\\\\ \\_______\\ \\________\\ \\_______\\ \\_______\\  \\ \\__\\          " << endl;
    cout << "     \\|__|     \\|__|\\|__|\\|_______|\\|________|\\|_______|\\|_______|   \\|__|                      " << endl;
    cout << "                                                                                                        " << endl;

    cout << "\n\nCreated By :- " << endl;
    cout << "Sarthak Sanay \t\t 230031101611051" << endl;
    cout << "Ashwani Gupta \t\t 230031101611049" << endl;
    cout << "Mudit Srivastav \t 230031101611053\n\n" << endl;
}

void showToolInfo() {
    cout << "\n======================================" << endl;
    cout << "||        Multi-Tool Program        ||" << endl;
    cout << "======================================" << endl;
    cout << "||  1. File Encryptor & Decryptor   ||" << endl;
    cout << "||  2. Password Generator           ||" << endl;
    cout << "||  3. Stopwatch                    ||" << endl;
    cout << "||  4. Countdown Timer              ||" << endl;
    cout << "||  0. Quit                         ||" << endl;
    cout << "======================================" << endl;
    cout << "\nEnter your choice: ";
}
