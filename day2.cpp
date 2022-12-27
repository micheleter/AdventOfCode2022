#include <iostream>
#include <fstream>

using namespace std;

int EvalShape(char theirs, char outcome)
{
    int their = (int)theirs % 65;
    int outcomes = (int)outcome % 88;
    int score[3][3] = {{3, 1, 2}, {1, 2, 3}, {2, 3, 1}};
    return score[their][outcomes];
}

int EvalOutcome(char outcome)
{
    switch (outcome)
    {
    case 'X':
        return 0;
    case 'Y':
        return 3;
    case 'Z':
        return 6;
    }
    return 0;
}

void ParseLine(string strLine, char &theirs, char &mine)
{
    theirs = strLine[0];
    mine = strLine[2];
}

int main()
{
    ifstream HintFile;
    HintFile.open("./hints/HintFile2.txt");

    long score = 0;
    string strLine;
    char theirs, ours, outcome;

    while (getline(HintFile, strLine))
    {
        ParseLine(strLine, theirs, outcome);
        score += EvalShape(theirs, outcome) + EvalOutcome(outcome);
    }

    HintFile.close();
    cout << score;
}