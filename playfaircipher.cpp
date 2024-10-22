#include <bits/stdc++.h>
using namespace std;

// Function to prepare the Playfair cipher matrix
void prepareMatrix(const string &keyword, vector<vector<char>> &matrix)
{
  unordered_set<char> seen;
  int r = 0, c = 0;
  for (char ch : keyword)
  {
    if (ch == 'j')
      ch = 'i';
    if (ch >= 'a' && ch <= 'z' && seen.find(ch) == seen.end())
    {
      matrix[r][c++] = ch;
      seen.insert(ch);
      if (c == 5)
      {
        c = 0;
        r++;
      }
    }
  }
  string charset = "abcdefghiklmnopqrstuvwxyz";
  for (char ch : charset)
  {
    if (seen.find(ch) == seen.end())
    {
      matrix[r][c++] = ch;
      if (c == 5)
      {
        c = 0;
        r++;
      }
    }
  }
}

// Function to prepare the input text for encryption or decryption
string prepareText(string text)
{
  string preparedText;
  for (char ch : text)
  {
    if (ch == 'j')
      ch = 'i';
    if (ch >= 'a' && ch <= 'z')
      preparedText += ch;
  }

  string result;
  for (size_t i = 0; i < preparedText.length(); i++)
  {
    result += preparedText[i];
    if (i + 1 < preparedText.length() && preparedText[i] == preparedText[i + 1])
    {
      result += 'x'; // Insert 'x' between repeated characters
    }
  }
  if (result.length() % 2 != 0)
  {
    result += 'x'; // Add 'x' if the length is odd
  }
  return result;
}

// Function to find the position of a character in the matrix
pair<int, int> findPosition(char ch, const vector<vector<char>> &matrix)
{
  for (int i = 0; i < 5; ++i)
  {
    for (int j = 0; j < 5; ++j)
    {
      if (matrix[i][j] == ch)
        return make_pair(i, j);
    }
  }
  return make_pair(-1, -1); // Should never reach here
}

// Function to encrypt the text using the Playfair cipher
string encrypt(const string &text, const string &keyword)
{
  vector<vector<char>> matrix(5, vector<char>(5));
  prepareMatrix(keyword, matrix);

  string preparedText = prepareText(text);
  string encryptedText;

  for (size_t i = 0; i < preparedText.length(); i += 2)
  {
    char a = preparedText[i];
    char b = preparedText[i + 1];
    auto [rowA, colA] = findPosition(a, matrix);
    auto [rowB, colB] = findPosition(b, matrix);

    if (rowA == rowB)
    {
      // Same row, shift columns to the right
      encryptedText += matrix[rowA][(colA + 1) % 5];
      encryptedText += matrix[rowB][(colB + 1) % 5];
    }
    else if (colA == colB)
    {
      // Same column, shift rows down
      encryptedText += matrix[(rowA + 1) % 5][colA];
      encryptedText += matrix[(rowB + 1) % 5][colB];
    }
    else
    {
      // Rectangle swap columns
      encryptedText += matrix[rowA][colB];
      encryptedText += matrix[rowB][colA];
    }
  }

  return encryptedText;
}

// Function to decrypt the text using the Playfair cipher
string decrypt(const string &text, const string &keyword)
{
  vector<vector<char>> matrix(5, vector<char>(5));
  prepareMatrix(keyword, matrix);

  string preparedText = prepareText(text);
  string decryptedText;

  for (size_t i = 0; i < preparedText.length(); i += 2)
  {
    char a = preparedText[i];
    char b = preparedText[i + 1];
    auto [rowA, colA] = findPosition(a, matrix);
    auto [rowB, colB] = findPosition(b, matrix);

    if (rowA == rowB)
    {
      // Same row, shift columns to the left
      decryptedText += matrix[rowA][(colA + 4) % 5];
      decryptedText += matrix[rowB][(colB + 4) % 5];
    }
    else if (colA == colB)
    {
      // Same column, shift rows up
      decryptedText += matrix[(rowA + 4) % 5][colA];
      decryptedText += matrix[(rowB + 4) % 5][colB];
    }
    else
    {
      // Rectangle swap columns
      decryptedText += matrix[rowA][colB];
      decryptedText += matrix[rowB][colA];
    }
  }

  // Remove trailing 'x' if present (common padding)
  if (!decryptedText.empty() && decryptedText.back() == 'x')
  {
    decryptedText.pop_back();
  }

  return decryptedText;
}

int main()
{
  int choice;
  string text, keyword;

  while (true)
  {
    cout << "Playfair Cipher Menu\n";
    cout << "1. Encrypt\n";
    cout << "2. Decrypt\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore(); // Ignore newline after the choice

    switch (choice)
    {
    case 1:
      cout << "Enter the text to encrypt: ";
      getline(cin, text);
      cout << "Enter the keyword: ";
      getline(cin, keyword);
      cout << "Encrypted Text: " << encrypt(text, keyword) << endl;
      break;
    case 2:
      cout << "Enter the text to decrypt: ";
      getline(cin, text);
      cout << "Enter the keyword: ";
      getline(cin, keyword);
      cout << "Decrypted Text: " << decrypt(text, keyword) << endl;
      break;
    case 3:
      cout << "Exiting...\n";
      return 0;
    default:
      cout << "Invalid choice. Please enter 1, 2, or 3.\n";
      break;
    }
  }
}
