#include <iostream>
#include <fstream>

using namespace std;

int GetPriority(char c)
{
    int cint = (int)c;
    if (cint >= 97 && cint <= 122)
    {
        return cint % 96;
    }
    return (cint % 64) + 26;
}

int main()
{
    ifstream HintFile;
    HintFile.open("./hints/HintFile3.txt");

    string strLine;
    long priority = 0;
    while (getline(HintFile, strLine))
    {
        char common;
        int halfLength = strLine.length() / 2;
        string compt1 = strLine.substr(0, halfLength);
        string compt2 = strLine.substr(halfLength, 2 * halfLength);

        for (int i = 0; i < compt2.size(); i++)
        {
            if (compt1.find(compt2[i]) != compt1.npos)
            {
                common = compt2[i];
                cout << strLine.size() << " " << compt1 << " | " << compt2 << " " << common << endl;
                break;
            }
        }
        priority += GetPriority(common);
    }
    cout << priority;
    // cout << strLine << " " << strLine.size() << " " << compt1 << " | " << compt2 << endl;
}
