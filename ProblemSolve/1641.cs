/******************************
 * Count Sorted Vowel Strings *
 ******************************/

public class Solution {
    public int CountVowelStrings(int n) {
        return (n + 1) * (n + 2) * (n + 3) * (n + 4) / 24;
    }
}