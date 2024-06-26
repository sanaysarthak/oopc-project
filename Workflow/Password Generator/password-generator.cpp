// Random Password Generator in C++

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// word pool to choose characters from for the password
const char alphanum[] = "0123456789!@#$%^&*abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
int pool_len = sizeof(alphanum) - 1; // word pool length

int main()
{
    // password length
    int pass_len;

inputLength: // label
    cout << "Enter length of password: ";
    cin >> pass_len;

    if (pass_len < 8)
    {
        cout << "For better security, enter length of password to be greater than or equal to 8!\n" << endl;
        goto inputLength;
    }

    srand(time(0));

    cout << "Generated Password: \t\t";
    for (int i = 0; i < pass_len; i++)
    {
        cout << alphanum[rand() % pool_len];
    }

    return 0;
}
