#include <iostream>
using namespace std;
bool corrected_first_symbol()
{
}
int corrected_part(int have_at, string part)
{
    if ((bool)have_at)
    
    for (int i = have_at; i < ((bool)have_at?have_at+63:64); i++)
    {
        if (part[i] == '.' && i - 1 == -1 ? true : part[i - 1] == '.')
        {
            return false;
        }
        else if (part[i] >= 'a' && part[i] <= 'z' || part[i] >= 'A' && part[i] <= 'Z')
        {
            break;
        }
        else if (!(bool)have_at)
        {

            if (part[i] == '@')
            {

                i>0?({return true;}):({return false;});
            }
        }
        else
        {
            if (part[i] == '@')
            {
                return false;
            }
            else
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
        }
    }
    return false;
}