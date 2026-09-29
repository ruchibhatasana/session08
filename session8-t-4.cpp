#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void updateStatus()
{
    ifstream file("content_list.txt");

    string title[100];
    string platform[100];
    string views[100];
    string status[100];

    int count = 0;

    while (getline(file, title[count]))
    {
        getline(file, platform[count]);
        getline(file, views[count]);
        getline(file, status[count]);

        string separator;
        getline(file, separator);

        count++;
    }

    file.close();

    cout << "\n--- Content List ---";

    for (int i = 0; i < count; i++)
    {
        cout << i + 1 << ". "
             << title[i] << " | "
             << platform[i]
             << " | " << status[i];
    }

    int choice;

    cout << "\nEnter content number to update: ";
    cin >> choice;
    cin.ignore();

    if (choice >= 1 && choice <= count)
    {
        cout << "Enter new status: ";
        getline(cin, status[choice - 1]);

        ofstream outFile("content_list.txt");

        for (int i = 0; i < count; i++)
        {
            outFile << title[i];
            outFile << platform[i];
            outFile << views[i];
            outFile << status[i];
            outFile << "----------------------";
        }

        outFile.close();

        cout << "Status updated successfully!";
    }
    else
    {
        cout << "Invalid content number!";
    }
}

int main()
{
    updateStatus();

}

