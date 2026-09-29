#include <iostream>
#include <string>
using namespace std;

class Content
{
public:
    string title;
    string platform;
    int views;
    string status;

    void display()
    {
        cout << "\n--- Content Details ---";
        cout << "Title: " << title;
        cout << "Platform: " << platform;
        cout << "Views: " << views;
        cout << "Status: " << status;
    }
};

int main()
{
    Content c;

    cout << "Enter content title: ";
    getline(cin, c.title);

    cout << "Enter platform: ";
    getline(cin, c.platform);

    cout << "Enter views: ";
    cin >> c.views;
    cin.ignore();

    cout << "Enter status: ";
    getline(cin, c.status);

    c.display();

}
