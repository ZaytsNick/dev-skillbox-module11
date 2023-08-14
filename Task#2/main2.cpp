#include <iostream>
using namespace std;

int corrected_part(int have_at, string part)
{
    if (part[part.length() - 1] == '.')
    {
        return false;
    }
    else
    {
        int s = (bool)have_at ? have_at + 63 : 64;
        for (int i = have_at; i < s; i++)
        {
            if (part[i] == '.' && i < 1 ? true : part[i - 1] == '.') // checking for the first '.' and for two '.' in a row.
            {
                return false;
            }
            else if (part[i] >= 'a' && part[i] <= 'z' || part[i] >= 'A' && part[i] <= 'Z') // checking for a character from the alphabet.
            {
                // break;
            }
            else if (!(bool)have_at) //
            {
                if (part[i] == '@' && i > 0 && part[i - 1] == '.')
                {
                    return i;
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
            else
            {
                return false;
            }
        }
    }
}
int main()
{
    int integerIndex(0);
    string e_mail;
    cout << "Enter E-mail: ";
    cin >> e_mail;
    if (corrected_part(integerIndex, e_mail))
    {
        integerIndex = corrected_part(integerIndex, e_mail);
        if (corrected_part(integerIndex, e_mail))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

}