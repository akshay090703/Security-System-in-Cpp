#include <iostream>
#include <fstream> // used to open files (file handling)
#include <sstream> // provides templates and types that enable interoperation between string buffer and string objects
#include <string>
using namespace std;

int main()
{
    int a, i = 0;
    string text, old, password1, password2, pass, name, password0, age, user, word, word1;
    string creds[2], cp[2];

    cout << "<------------Security System------------>" << endl;

    cout << "_________________________________________" << endl
         << endl;
    cout << "              1. Register                " << endl;
    cout << "              2. Login                   " << endl;
    cout << "              3. Change password         " << endl;
    cout << "              4. End program             " << endl;
    cout << "_________________________________________" << endl
         << endl;

    do
    {
        cout << endl;
        cout << "Enter your choice:- ";
        cin >> a;
        switch (a)
        {
        case 1:
        {
            cout << "_________________________________________" << endl
                 << endl;
            cout << "|---------------Register----------------|" << endl;
            cout << "|_______________________________________|" << endl
                 << endl;
            cout << "Please enter username: ";
            cin >> name;
            cout << "Please enter the password: ";
            cin >> password0;
            cout << "Please enter your age: ";
            cin >> age;

            ofstream of1; // opening a file for storing data purposes
            // we use ifstream class if we want to open a file for reading purpose
            of1.open("file.txt");
            if (of1.is_open())
            {
                of1 << name << '\n';
                of1 << password0;
                cout << "Registration successful." << endl;
            }
            break;
        }
        case 2:
        {
            i = 0;
            cout << "_________________________________________" << endl
                 << endl;
            cout << "|-----------------Login-----------------|" << endl;
            cout << "|_______________________________________|" << endl
                 << endl;

            ifstream of2; // to read a file
            of2.open("file.txt");
            cout << "Please enter the username: ";
            cin >> user;
            cout << "Please enter the password: ";
            cin >> pass;

            if (of2.is_open())
            {
                while (!of2.eof())
                { // end of file function
                    while (getline(of2, text))
                    {                            // while loop with getline function is used to read a file line by line
                        istringstream iss(text); // stream the string and store it using the extraction operator
                        iss >> word;             // extraction operator
                        creds[i] = word;
                        i++;
                    }
                    if (user == creds[0] && pass == creds[1])
                    {
                        cout << "------------Login Successful-------------" << endl
                             << endl;

                        cout << "Details: " << endl;
                        cout << "Username: " + name << endl;
                        cout << "Password: " + pass << endl;
                        cout << "Age: " + age << endl;
                    }
                    else
                    {
                        cout << endl
                             << endl;
                        cout << "Invalid Username or Password!" << endl;
                        cout << "|         1. Press 2 to Login           |" << endl;
                        cout << "|    2. Press 3 to Change password      |" << endl;
                        break;
                    }
                }
            }
            break;
        }
        case 3:
        {
            i = 0;
            cout << "_________________________________________" << endl
                 << endl;
            cout << "|------------Change password------------|" << endl;
            cout << "|_______________________________________|" << endl
                 << endl;

            ifstream of0;
            of0.open("file.txt");
            cout << "Enter the old password: ";
            cin >> old;

            if (of0.is_open())
            {
                while (getline(of0, text))
                {
                    istringstream iss(text);
                    iss >> word1; // storing the word in word1 using extraction operator
                    cp[i] = word1;
                    i++;
                }

                if (old == cp[1])
                {
                    of0.close();
                    ofstream of1("file.txt");
                    if (of1.is_open())
                    {
                        cout << "Enter your new password: ";
                        cin >> password1;
                        cout << "Enter your new password again: ";
                        cin >> password2;
                        if (password1 == password2)
                        {
                            of1 << cp[0] << "\n";
                            of1 << password1;
                            cout << "Password changed successfully!" << endl;
                        }
                        else
                        {
                            of1 << cp[0] << '\n';
                            of1 << old;
                            cout << "Passwords do not match! Try Again." << endl;
                        }
                    }
                }
                else
                {
                    cout << "Incorrect Password! Please try again." << endl;
                }
            }
            break;
        }

        case 4:
        {
            cout << "|______________Thank You!_______________|" << endl;
            break;
        }
        default:
        {
            cout << "Enter a valid choice from the given menu!";
        }
        }
    } while (a != 4);

    return 0;
}