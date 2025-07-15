// 3136. Valid Word
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// A word is considered valid if:

// It contains a minimum of 3 characters.
// It contains only digits (0-9), and English letters (uppercase and lowercase).
// It includes at least one vowel.
// It includes at least one consonant.
// You are given a string word.

// Return true if word is valid, otherwise, return false.

// Notes:

// 'a', 'e', 'i', 'o', 'u', and their uppercases are vowels.
// A consonant is an English letter that is not a vowel.
 

// Example 1:

// Input: word = "234Adas"

// Output: true

// Explanation:

// This word satisfies the conditions.

// Example 2:

// Input: word = "b3"

// Output: false

// Explanation:

// The length of this word is fewer than 3, and does not have a vowel.

// Example 3:

// Input: word = "a3$e"

// Output: false

// Explanation:

// This word contains a '$' character and does not have a consonant.

 

// Constraints:

// 1 <= word.length <= 20
// word consists of English uppercase and lowercase letters, digits, '@', '#', and '$'.

#include <iostream>
#include <cctype>  // for isalpha and isdigit
using namespace std;

class WordValidator {
public:
    bool isValid(string word) {
        if (word.length() < 3)
            return false;

        bool hasVowel = false;
        bool hasConsonant = false;

        for (char ch : word) {
            if (!isalnum(ch)) {
                // Invalid character (not digit or letter)
                return false;
            }

            if (isalpha(ch)) {
                char lower = tolower(ch);
                if (isVowel(lower))
                    hasVowel = true;
                else
                    hasConsonant = true;
            }
        }

        return hasVowel && hasConsonant;
    }

private:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
};

// ---------- Test the Class ----------
int main() {
    WordValidator validator;

    string word1 = "234Adas";
    string word2 = "b3";
    string word3 = "a3$e";

    cout << boolalpha;  // Print bools as true/false
    cout << "Is '" << word1 << "' valid? " << validator.isValid(word1) << endl;
    cout << "Is '" << word2 << "' valid? " << validator.isValid(word2) << endl;
    cout << "Is '" << word3 << "' valid? " << validator.isValid(word3) << endl;

    return 0;
}
