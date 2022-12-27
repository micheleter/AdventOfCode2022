#include <iostream>
#include <fstream>
#include <unordered_map>
#include <set>

using namespace std;

void SplitPairs(string pair, int &leftStart, int &leftEnd, int &rightStart, int &rightEnd)
{
    int split = pair.find(',');
    string left = pair.substr(0, split);
    string right = pair.substr(split + 1, pair.length());

    leftStart = stoi(left.substr(0, left.find('-')));
    leftEnd = stoi(left.substr(left.find('-') + 1, left.size()));

    rightStart = stoi(right.substr(0, right.find('-')));
    rightEnd = stoi(right.substr(right.find('-') + 1, right.size()));
}

bool DetectOverlap(int leftStart, int leftEnd, int rightStart, int rightEnd)
{
    return (leftStart <= rightEnd && rightStart <= leftEnd);
}

int main()
{
    ifstream HintFile;
    HintFile.open("./hints/HintFile4.txt");

    string pair;
    int total = 0;
    while (getline(HintFile, pair))
    {
        int leftStart, leftEnd, rightStart, rightEnd;
        SplitPairs(pair, leftStart, leftEnd, rightStart, rightEnd);
        total += DetectOverlap(leftStart, leftEnd, rightStart, rightEnd);
    }
    cout << total;
}