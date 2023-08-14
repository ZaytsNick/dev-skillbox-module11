#include <iostream>
using namespace std;
bool corrected_first_symbol()
{
}
int corrected_part(int have_at, string part)
{

    for (int i = have_at; i < ((bool)have_at ? have_at + 63 : 64); i++)
    {
        if (part[i] == '.' && i < 1 ? true : part[i - 1] == '.') // checking for the first '.' and for two '.' in a row.
        {
            return false;
        }
        else if (part[i] >= 'a' && part[i] <= 'z' || part[i] >= 'A' && part[i] <= 'Z') // checking for a character from the alphabet.
        {
            // break;
        }
        else if (!(bool)have_at) // c
        {
            if (part[i] == '@' && i > 0)
            {
                return true;
            }
            else if (part[i] == '@')
            {
                return false;
            }
            else if (true)
            {
                string correctedSymbol = "!#$%&'*+-/=?^_`{|}~";
                for (int j = 0; j < correctedSymbol.length(); j++)
                {
                    if (part[i] == correctedSymbol[j])
                    {
                        break;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            else
            {
                return false;
            }
        }
        return false;
    }
}