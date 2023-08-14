#include <iostream>
using namespace std;
string encrypt_caesar(string textEC, int shiftEC)
{
  //task
  for(int i=0; i<textEC.length(); i++)
  {
    if      (textEC[i]>='a' && textEC[i]<='z') {textEC[i]+=(textEC[i]%'a'+shiftEC)%26+'a';}
    else if (textEC[i]>='A' && textEC[i]<='Z') {textEC[i]+=(textEC[i]%'A'+shiftEC)%26+'A';}
    else if (textEC[i]>='0' && textEC[i]<='9') {textEC[i]+=(textEC[i]%'0'+shiftEC)%26+'0';}
    else 
    {
      cout<<"Not correct symbol"<<endl;
      return; 
    }
  }
  return textEC;
}
string decrypt_caesar(string textDC, int shiftDC)
{
  return encrypt_caesar(textDC,-shiftDC);
}
void main()
{
  string text,text_encrypt_caesar, text_decrypt_caesar;
  int shift;
  cout<<"Enter text: "<<endl;
  cin>>text;
  cout<<"Enter shift: ";
  cin>>shift;
  text_encrypt_caesar=encrypt_caesar(text,shift);
  text_decrypt_caesar=decrypt_caesar(text_encrypt_caesar,shift);
}