#include <iostream>
#include <math.h>
using namespace std;

bool Valid_part(string value)
{
    int intValue(0);
    for (int j = value.length() - 2; j >= 0; j--)
    {
        int a = (10 * (value.length() - 2 - j));

        intValue += (value[j] - '0') * pow(10, (value.length() - 2 - j));
    }
    if (intValue > 0 && intValue <= 255 && value[0] != '0')
        return true;
    else if (intValue == 0 && value == "0." || value == "0")
        return true;
    else
        return false;
}

string Valid_ip(string ip)
{
    if (ip.length() > 15 || ip[ip.length() - 1] == '.' || ip[0] == '.')
        return "Invalid";
    string ip_part;
    int dot(0), quantityDot(0);
    for (int i = 0; i < ip.length(); i++)
    {
        if (ip[i] == '.' && ip[i - 1] == '.' || ip[i] < '0' && ip[i] > '9')
        {
            return "Invalid";
        }
        else if (ip[i] == '.' || (i == ip.length() - 1))
        {
            string part;
            for (dot; dot <= i; dot++)
            {
                part += ip[dot];
            }
            ip[i] == '.' ?quantityDot++:0;
            if (ip[i] == '.' ? (!Valid_part(part)) : (!Valid_part(part + '.')))
                return "Invalid";
        }
    }
    if (quantityDot == 3)
    {
        return "Valid";
    }
    else
    {
        return "Invalid";
    }
}

int main()
{
    string ip_address;
    cout << "Enter ip address: ";
    cin >> ip_address;
    cout << Valid_ip(ip_address);
}
