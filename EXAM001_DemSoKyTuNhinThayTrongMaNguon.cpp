#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream F;
    F.open("./main.cpp", ios::in);
    int charCount = 0;
    bool insideComment = false;
    char currentChar, nextChar;

    while (F.get(currentChar))
    {
        // Loai bo comment //
        if (currentChar == '/' && F.peek() == '/')
        {
            F.ignore(10000, '\n');
            continue;
        }

        // Lo?i bo comment /*
        if (currentChar == '/' && F.peek() == '*')
        {
            insideComment = true;
            continue;
        }
        if (insideComment && currentChar == '*' && F.peek() == '/')
        {
            insideComment = false;
            F.get(nextChar);
            continue;
        }
        if (insideComment)
        {
            continue;
        }

        // Loai bo khoang trang va ky tu xuong dong
        if (currentChar == ' ' || currentChar == '\t' || currentChar == '\n')
        {
            continue;
        }

        charCount++;
    }

    F.close();
    F.open("./output.txt", ios::out);
    F << charCount;
    F.close();
    return 0;
}
