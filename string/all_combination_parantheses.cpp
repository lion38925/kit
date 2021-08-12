// C program to Print all combinations
// of balanced parentheses
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 100

void _printParenthesis(int pos, int n, int open, int close);

// Wrapper over _printParenthesis()
void printParenthesis(int n)
{
    if (n < 2)
        return;

    queue<string> q;

    q.push("()");
    int i;
    while (!q.empty())
    {
        string temp;
        temp = q.front();
        q.pop();
        if (temp.length() == 2 * n)
            cout << temp << "\n";

        else
        {
            q.push("(" + temp + ")");

            if ("()" + temp == temp + "()")
                q.push("()" + temp);
            else
            {
                q.push("()" + temp);
                q.push(temp + "()");
            }
        }
    }
    return;
}

// Driver program to test above functions
int main()
{
    int n = 3;
    printParenthesis(n);
    getchar();
    return 0;
}
