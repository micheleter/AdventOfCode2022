#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

bool ValidMarker(string marker)
{
    unordered_map<char, int> m;
    for (char c : marker)
        m[c] += 1;

    for (auto i : m)
    {
        if (i.second > 1)
            return false;
    }
    return true;
}

int main()
{
    ifstream HintFile;
    HintFile.open("./hints/HintFile6.txt");

    string strLine;
    while (getline(HintFile, strLine))
    {
        for (int i = 0; i < strLine.length(); i++)
        {
            string marker = strLine.substr(i, 14);
            cout << marker << endl;
            if (ValidMarker(marker))
            {
                cout << i + 14;
                break;
            }
        }
    }
}