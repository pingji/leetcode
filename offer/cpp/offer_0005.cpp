#include <string>
using namespace std;

class Solution
{
public:
    string replaceSpace(string s)
    {
        int oldLength = s.length();
        int spaceCount = 0;
        for (int i = 0; i < oldLength; i++)
        {
            if (s[i] == ' ')
            {
                spaceCount++;
            }
        }
        int newLength = oldLength + 2 * spaceCount;
        s.resize(newLength);
        int i = oldLength - 1;
        int j = newLength - 1;
        while (i >= 0 && i != j)
        {
            if(s[i] == ' ') {
                s[j] = '0';
                s[j-1] = '2';
                s[j-2] = '%';
                i--;
                j -= 3;
            } else {
                s[j] = s[i];
                i--;
                j--;
            }
        }
        return s;
    }
};