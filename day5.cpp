#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>

using namespace std;

void ParseInstruction(string strLine, int &count, int &from, int &to)
{
    string dumby;
    stringstream ss;
    ss << strLine;

    while (!ss.eof())
    {
        ss >> dumby >> count >> dumby >> from >> dumby >> to;
    }
}

void Move(stack<char> stacks[], int count, int from, int to)
{
    stack<char> mid;
    for (int i = 0; i < count; i++)
    {
        mid.push(stacks[from].top());
        stacks[from].pop();
    }
    while (count > 0)
    {
        stacks[to].push(mid.top());
        mid.pop();
        count -= 1;
    }
}

int main()
{
    ifstream HintFile;
    HintFile.open("./hints/HintFile5.txt");

    string strLine;
    bool instructions = false;
    getline(HintFile, strLine);
    int queueCount = (strLine.length() + 1) / 4;
    stack<char> stax[queueCount];
    stack<char> stacks[queueCount];

    do
    {
        if (strLine.empty())
        {
            // moving on to instructions
            instructions = true;

            // empty queues into stacks
            for (int i = 0; i < queueCount; i++)
            {
                while (!stax[i].empty())
                {
                    stacks[i].push(stax[i].top());
                    stax[i].pop();
                }
            }
            continue;
        }

        if (!instructions)
        {
            for (int i = 0; i < strLine.size(); i++)
            {
                if (isalpha(strLine[i]))
                {
                    stax[i / 4].push(strLine[i]);
                }
            }
        }
        else
        {
            int count = 0, from = 0, to = 0;
            ParseInstruction(strLine, count, from, to);
            // cout << "Top of (FROM) " << from << " is: " << stacks[from - 1].top() << endl;
            // cout << "Top of (TO) " << to << " is: " << stacks[to - 1].top() << endl;

            Move(stacks, count, from - 1, to - 1);
            // cout << "FROM: " << from << stacks[from - 1].top() << " TO: " << stacks[to - 1].top() << endl;
        }
    } while (getline(HintFile, strLine));

    for (auto st : stacks)
    {
        cout << st.top();
    }
}