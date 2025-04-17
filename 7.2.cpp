#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

int main()
{
    ifstream file("7.2.txt", ios::in);

    if (!file)
    {
        cout << "Could not open the file." << endl;
        return 1;
    }

    char ch;
    int lines = 0, chars = 0, words = 0;
    bool inWord = false;

    while (file.get(ch))
    {
        chars++;

        if (ch == '\n')
        {
            lines++;
        }

        if (isspace(ch))
        {
            inWord = false;
        }
        else if (!inWord)
        {
            words++;
            inWord = true;
        }
    }

    if (chars > 0 && ch != '\n')
    {
        lines++;
    }

    cout << "Lines: " << lines << endl;
    cout << "Words: " << words << endl;
    cout << "Characters: " << chars << endl;

    file.close();
    return 0;
}
