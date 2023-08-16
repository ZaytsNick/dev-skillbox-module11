#include <iostream>
using namespace std;
char encrypt_symbol(char symbol, int shiftS, char alphabet)
{
  return (symbol - alphabet + shiftS) % 26 + ((symbol - alphabet + shiftS) >= 0 ? alphabet : alphabet + 26);
}

string encrypt_caesar(string textEC, int shiftEC)
{
  for (int i = 0; i < textEC.length(); i++)
  {
    if (textEC[i] >= 'a' && textEC[i] <= 'z')
      textEC[i] = encrypt_symbol(textEC[i], shiftEC, 'a');
    else if (textEC[i] >= 'A' && textEC[i] <= 'Z')
      textEC[i] = encrypt_symbol(textEC[i], shiftEC, 'A');
    else
    {
      cout << "Not correct symbol" << endl;
      return "Not correct symbol";
    }
  }
  return textEC;
}
string decrypt_caesar(string textDC, int shiftDC)
{
  return encrypt_caesar(textDC, -shiftDC);
}
int main()
{
  string text, text_encrypt_caesar, text_decrypt_caesar;
  int shift;
  cout << "Enter text: ";
  cin >> text;
  cout << "Enter shift: ";
  cin >> shift;
  text_encrypt_caesar = encrypt_caesar(text, shift);
  text_decrypt_caesar = decrypt_caesar(text_encrypt_caesar, shift);
  cout << "Text encrypt:\n"
       << text_encrypt_caesar << "\nText decrypt:\n"
       << text_decrypt_caesar << endl;
}