#include <iostream>
#include <fstream>
#include <unordered_map>
#include <set>

using namespace std;

char FindCommon(string s1, string s2, string s3)
{
    unordered_map<char, int> counts;
    set<char> set1(s1.begin(), s1.end()), set2(s2.begin(), s2.end()), set3(s3.begin(), s3.end());

    for (char c : set1)
    {
        if (counts[c] < 1)
            counts[c] += 1;
    }
    for (char c : set2)
    {
        if (counts[c] < 2)
            counts[c] += 1;
    }
    for (char c : set3)
    {
        if (counts[c] < 3)
            counts[c] += 1;
        cout << c << counts[c] << endl;
    }

    for (auto i : counts)
    {
        if (i.second == 3)
            return i.first;
    }
    return 0;
}

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

    string elf1, elf2, elf3;
    long priority = 0;
    while (HintFile >> elf1 >> elf2 >> elf3)
    {
        cout << elf1 << endl
             << elf2 << endl
             << elf3 << endl
             << endl;
        char common = FindCommon(elf1, elf2, elf3);
        priority += GetPriority(common);
    }
    cout << priority;
}