#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
  string text;
  int key;
  string encryptedText = "";
  string decryptedText = "";
  map<char, float> freq;

  cout << "Enter text to encrypt: ";
  getline(cin, text);

  cout << "Enter a key: ";
  cin >> key;

  // Encrypting the text
  cout << "The encrypted cipher is: ";
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

  // Calculate frequency of characters
  for (auto n : text)
  {
    if (n != ' ')
    { // Ignore spaces for frequency calculation
      freq[n]++;
    }
  }

  // Decrypting the encrypted text
  cout << "The decrypted text is: ";
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

  // Display character frequency with percentage
  cout << "Character frequencies:\n";
  for (auto it = freq.begin(); it != freq.end(); ++it)
  {
    char n = it->first;
    float m = it->second;
    cout << n << " appears " << m << " times with " << (m / text.size()) * 100 << "%\n";
  }

  return 0;
}
