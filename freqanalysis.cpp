#include <iostream>
#include <map>

using namespace std;

int main()
{
  map<char, int> freq;
  string text;
  int total = 0;

  cout << "Enter a string: ";
  getline(cin, text);

  // Count frequency of each alphabetic character
  for (char n : text)
  {
    if (isalpha(n))
    {
      freq[tolower(n)]++; // Count in lowercase to avoid case sensitivity
      total++;            // Increment total only for alphabetic characters
    }
  }

  // Display frequency analysis
  for (const auto &[n, m] : freq)
  {
    // Calculate the percentage without using static_cast
    double percentage = (m * 100.0) / total; // Multiplying by 100.0 ensures floating-point division
    cout << n << " occurs " << percentage << " % of the times" << endl;
  }

  return 0;
}
