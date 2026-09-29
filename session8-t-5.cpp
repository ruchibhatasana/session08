#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void displayContent()
{
    ifstream file("content_list.txt");

    string title, platform, views, status;
    int number = 1;

    cout << "\n--- Content List ---";

    while (getline(file, title))
    {
        getline(file, platform);
        getline(file, views);
        getline(file, status);

        string separator;
        getline(file, separator);

        cout << number << ". "
             << title << " | "
             << platform << " | "
             << status;

        number++;
    }

    file.close();
}

void deleteContent()
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
             << platform[i] << " | "
             << status[i];
    }

    int choice;

    cout << "\nEnter content number to delete: ";
    cin >> choice;

    if (choice < 1 || choice > count)
    {
        cout << "Invalid content number!";
        return;
    }
    ofstream outFile("content_list.txt");

    for (int i = 0; i < count; i++)
    {
        if (i != choice - 1)
        {
            outFile << title[i];
            outFile << platform[i];
            outFile << views[i];
            outFile << status[i];
            outFile << "----------------------";
        }
    }

    outFile.close();

    cout << "\nContent deleted successfully!";

    displayContent();
}

int main()
{
    deleteContent();

}