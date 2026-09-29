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
        getline(file, views);

        cout << number << ". "
             << title << " | "
             << platform ;

        number++;
    }

    file.close();
}

int main()
{
    displayContent();

}
