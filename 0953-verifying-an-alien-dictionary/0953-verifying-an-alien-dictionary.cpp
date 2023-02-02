class Solution {
public:
    // Function to compare two words word1 and word2 using the character mapping in unordered_map mp
    bool check(unordered_map<char, int> mp, string word1, string word2){
        int i=0, j=0;
        // Compare character by character until one of the words runs out of characters
        while(i < word1.size() && j < word2.size()){
            // If word1 has a greater character, return false
            if(mp[word1[i]] > mp[word2[j]]) return false;
            // If word2 has a greater character, return true
            else if(mp[word1[i]] < mp[word2[j]]) return true;
            i++;
            j++;
        }
        // If word1 has run out of characters, return true (word1 is less than or equal to word2)
        // If word2 has run out of characters, return false (word1 is greater than word2)
        return (word1.size() <= word2.size());
    }
    // Main function to check if the list of words is sorted lexicographically according to the given order of characters
    bool isAlienSorted(vector<string>& words, string order) {
        int pos=0;
        unordered_map<char, int> mp;
        // Create a mapping of characters to their positions in the given order
        for(char i : order){
            mp[i] = pos;
            pos++;
        }
        // Iterate over the list of words and compare each consecutive pair using the check function
        for(int i=0;i<words.size()-1;i++){
            if(!check(mp, words[i], words[i+1])) return false;
        }
        // If all pairs are in the correct order, return true
        return true;
    }
};
