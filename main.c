#include <stdio.h>
#include <string.h>

// Function to calculate the factorial of a number
int factorial(int n) {
    int fact = 1;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Function to calculate the count of anagrams
int countAnagrams(char word[]) {
    int length = strlen(word);
    int count[26] = {0}; // Array to count the occurrence of each letter

    // Count the occurrence of each letter in the word
    for (int i = 0; i < length; i++) {
        count[word[i] - 'A']++;
    }

    // Calculate the count of anagrams
    int totalAnagrams = factorial(length);
    for (int i = 0; i < 26; i++) {
        if (count[i] > 1) {
            totalAnagrams /= factorial(count[i]);
        }
    }

    return totalAnagrams;
}

int main() {
    char word[15];

    // Read the word
    scanf("%s", word);

    // Print the count of anagrams
    printf("%d\n", countAnagrams(word));

    return 0;
}
