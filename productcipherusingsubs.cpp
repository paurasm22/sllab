
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main()
{
  string text;
  int key;
  string encryptedText = "";
  string decryptedText = "";
  int tkey;

  cout << "Enter text to encrypt: ";
  getline(cin, text);

  cout << "Enter a key: ";
  cin >> key;

  // Encrypting the text
  cout << "The encrypted Substitution cipher is: " << endl;
  for (auto n : text)
  {
    if (n == ' ')
    {
      cout << '$';
      encryptedText += '$';
    }
    else
    {
      int cyp = (int)n + key;
      if (islower(n))
      {
        if (cyp > 'z')
        {
          cyp = 'a' + (cyp - 'z' - 1);
        }
      }
      else if (isupper(n))
      {
        if (cyp > 'Z')
        {
          cyp = 'A' + (cyp - 'Z' - 1);
        }
      }
      cout << (char)cyp;
      encryptedText += (char)cyp;
    }
  }
  cout << endl;

  cout << "Enter Transposition Key " << endl;
  cin >> tkey;
  int strindex = 0;
  vector<vector<char>> transvector(tkey, vector<char>(tkey, '*'));
  for (int i = 0; i < tkey; i++)
  {
    for (int j = 0; j < tkey; j++)
    {
      if (strindex < encryptedText.size())
      {
        transvector[i][j] = encryptedText[strindex];
        strindex++;
      }
    }
  }

  cout << "The transposition Matrix is" << endl;
  for (int i = 0; i < tkey; i++)
  {
    for (int j = 0; j < tkey; j++)
    {
      cout << transvector[i][j];
    }
    cout << " " << endl;
  }

  cout << "The transposition cipher  is" << endl;
  for (int i = 0; i < tkey; i++)
  {
    for (int j = 0; j < tkey; j++)
    {
      cout << transvector[j][i];
    }
    // cout<<" "<<endl;
  }
  cout << "" << endl;
  cout << "Decrypted Substitution Cipher is :  " << endl;
  for (int i = 0; i < tkey; i++)
  {
    for (int j = 0; j < tkey; j++)
    {
      if (strindex < encryptedText.size())
      {
        encryptedText[strindex] = transvector[i][j];

        strindex++;
      }
    }
  }
  cout << encryptedText << endl;

  cout << "The decrypted text is: " << endl;
  for (auto n : encryptedText)
  {
    if (n == '$')
    {
      cout << ' ';
      decryptedText += ' ';
    }
    else
    {
      int decyp = (int)n - key;
      if (islower(n))
      {
        if (decyp < 'a')
        {
          decyp = 'z' - ('a' - decyp - 1);
        }
      }
      else if (isupper(n))
      {
        if (decyp < 'A')
        {
          decyp = 'Z' - ('A' - decyp - 1);
        }
      }
      cout << (char)decyp;
      decryptedText += (char)decyp;
    }
  }
  cout << endl;
  return 0;
}