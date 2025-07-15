// 1790. Check if One String Swap Can Make Strings Equal
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// You are given two strings s1 and s2 of equal length. A string swap is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.

// Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings. Otherwise, return false.

 

// Example 1:

// Input: s1 = "bank", s2 = "kanb"
// Output: true
// Explanation: For example, swap the first character with the last character of s2 to make "bank".
// Example 2:

// Input: s1 = "attack", s2 = "defend"
// Output: false
// Explanation: It is impossible to make them equal with one string swap.
// Example 3:

// Input: s1 = "kelb", s2 = "kelb"
// Output: true
// Explanation: The two strings are already equal, so no string swap operation is required.
 

// Constraints:

// 1 <= s1.length, s2.length <= 100
// s1.length == s2.length
// s1 and s2 consist of only lowercase English letters.
// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 298,220/602.9K
// Acceptance Rate
// 49.5%
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool areAlmostEqual(char* s1, char* s2) {
    int n = strlen(s1);
    
    // If lengths differ, not possible
    if (n != strlen(s2)) {
        return false;
    }

    int first = -1, second = -1;

    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i]) {
            if (first == -1) {
                first = i;
            } else if (second == -1) {
                second = i;
            } else {
                // More than two mismatches
                return false;
            }
        }
    }

    if (first == -1) {
        // Strings are already equal
        return true;
    }

    // Check if swapping makes them equal
    return (second != -1 && s1[first] == s2[second] && s1[second] == s2[first]);
}

int main() {
    // Test cases
    char s1[] = "bank";
    char s2[] = "kanb";
    printf("Test 1: %s\n", areAlmostEqual(s1, s2) ? "true" : "false"); // true

    char s3[] = "attack";
    char s4[] = "defend";
    printf("Test 2: %s\n", areAlmostEqual(s3, s4) ? "true" : "false"); // false

    char s5[] = "kelb";
    char s6[] = "kelb";
    printf("Test 3: %s\n", areAlmostEqual(s5, s6) ? "true" : "false"); // true

    char s7[] = "abcd";
    char s8[] = "abdc";
    printf("Test 4: %s\n", areAlmostEqual(s7, s8) ? "true" : "false"); // true

    char s9[] = "abcd";
    char s10[] = "abcd";
    printf("Test 5: %s\n", areAlmostEqual(s9, s10) ? "true" : "false"); // true

    char s11[] = "aaaa";
    char s12[] = "aaab";
    printf("Test 6: %s\n", areAlmostEqual(s11, s12) ? "true" : "false"); // false

    return 0;
}
