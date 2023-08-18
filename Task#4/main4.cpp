#include <iostream>
using namespace std;

bool won(char symbol, string s1, string s2, string s3)
{
    if (
        s1[0] == symbol && s1[1] == symbol && s1[2] == symbol ||
        s2[0] == symbol && s2[1] == symbol && s2[2] == symbol ||
        s3[0] == symbol && s3[1] == symbol && s3[2] == symbol ||
        s1[0] == symbol && s2[0] == symbol && s3[0] == symbol ||
        s1[1] == symbol && s2[1] == symbol && s3[1] == symbol ||
        s1[2] == symbol && s2[2] == symbol && s3[2] == symbol ||
        s1[0] == symbol && s2[1] == symbol && s3[2] == symbol ||
        s1[2] == symbol && s2[1] == symbol && s3[0] == symbol)
    {
        return true;
    }
    else
    {
        return false;
    }
}

string who_won(string s1, string s2, string s3)
{
    int quantityX(0), quantityO(0);
    for (int i = 0; i < 3; i++)
    {
        quantityX += (bool)(s1[i] == 'X') + (bool)(s2[i] == 'X') + (bool)(s3[i] == 'X');
        quantityO += (bool)(s1[i] == 'O') + (bool)(s2[i] == 'O') + (bool)(s3[i] == 'O');
    }
    if ((quantityO + quantityX) == 9 && quantityO < quantityX)
        return "Nobody";
    // #2 потому что ноликов в конце игры не может быть больше, чем крестиков
    else if ((quantityO + quantityX) == 9 && quantityO > quantityX)
        return "Incorrect";

    else if (won('O', s1, s2, s3) && quantityO == quantityX)
        return "Vanya won";
    // потому что нолики выиграли за три хода, и на поле за это время не могло успеть появиться четыре крестика
    else if (won('O', s1, s2, s3) && quantityO != quantityX)
        return "Incorrect";

    else if (won('X', s1, s2, s3) && quantityO < quantityX)
        return "Petya won";
    //  крестики уже победили, и ноликов не может быть столько же
    else if (won('X', s1, s2, s3) && quantityO == quantityX || quantityO > quantityX)
        return "Incorrect";
    else
        return "Nobody";
}
bool correct_symbol(string s1, string s2, string s3)
{
    // #1 потому что допускаются только символы X, O и точка, а цифра 0 не является допустимым символом

    for (int i = 0; i < 3; i++)
    {
        if (
            (s1[i] == 'X' || s1[i] == 'O' || s1[i] == '.') &&
            (s2[i] == 'X' || s2[i] == 'O' || s2[i] == '.') &&
            (s3[i] == 'X' || s3[i] == 'O' || s3[i] == '.'))
        {
           true;
        }
        else
        {
            return false;
        }
    } return true;
}

int main()
{
    string str1, str2, str3;
    cout << "Enter battlefield:" << endl;
    cin >> str1 >> str2 >> str3;
    if (!correct_symbol(str1, str2, str3))
    {
        cout << "Incorrect";
    }
    else
    {
        cout << "Answer: " << who_won(str1, str2, str3);
    }
}