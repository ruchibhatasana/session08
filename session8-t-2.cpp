#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    int choice;
    string title, platform, status;
    int views;

    do
    {
        cout << "\n--- Creator Dashboard Lite ---";
        cout << "1. Add New Content";
        cout << "2. Exit";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1)
        {
            cout << "Enter content title: ";
            getline(cin, title);

            cout << "Enter platform: ";
            getline(cin, platform);

            cout << "Enter views: ";
            cin >> views;
            cin.ignore();

            cout << "Enter status: ";
            getline(cin, status);

            ofstream file("content_list.txt", ios::app);

            file << "Title: " << title;
            file << "Platform: " << platform;
            file << "Views: " << views;
            file << "Status: " << status;
            file << "----------------------";

            file.close();

            cout << "Content saved successfully!";
        }
        else if (choice == 2)
        {
            cout << "Program ended.";
        }
        else
        {
            cout << "Invalid choice!";
        }

    } while (choice != 2);

}
