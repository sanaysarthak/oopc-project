// Random Password Generator in C++

#include <iostream>
#include <string>
#include<cstdlib>
#include<ctime>
using namespace std;

// word pool to choose characters from for the password
const char alphanum[] = "0123456789!@#$%^&*abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
int pool_len = sizeof(alphanum) - 1; // word pool length

int main() 
{
    // password length
    int pass_len;
    a: cout << "Enter length of password: ";
    cin >> pass_len;
    if(pass_len < 0){
        cout << "Enter valid length!";
        goto a;
    }
    srand(time(0));

    cout << "Generated Password: \t\t";
    for(int i=0; i<pass_len; i++) 
    {
        cout << alphanum[rand() % pool_len];
    }
    return 0;
}