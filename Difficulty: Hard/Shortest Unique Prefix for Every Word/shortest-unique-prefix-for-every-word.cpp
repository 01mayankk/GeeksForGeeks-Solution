class Solution {
    // Trie Node definition
    struct TrieNode {
        TrieNode* child[26]; // Stores pointers to child nodes (a-z)
        int freq;            // Number of words passing through this node

        TrieNode() {
            freq = 0;
            for (int i = 0; i < 26; i++) {
                child[i] = nullptr;
            }
        }
    };

    // Inserts a word into the Trie
    void insert(TrieNode* root, const string& word) {
        TrieNode* curr = root;

        // Traverse each character of the word
        for (char ch : word) {
            int index = ch - 'a';

            // Create a new node if it doesn't exist
            if (curr->child[index] == nullptr) {
                curr->child[index] = new TrieNode();
            }

            // Move to the child node
            curr = curr->child[index];

            // Increase frequency for this prefix
            curr->freq++;
        }
    }

    // Returns the shortest unique prefix of a word
    string getUniquePrefix(TrieNode* root, const string& word) {
        TrieNode* curr = root;
        string prefix = "";

        // Traverse the Trie following the word
        for (char ch : word) {
            int index = ch - 'a';
            curr = curr->child[index];

            // Add current character to the prefix
            prefix += ch;

            // Frequency 1 means only this word uses this prefix
            if (curr->freq == 1) {
                break;
            }
        }

        return prefix;
    }

public:
    vector<string> findPrefixes(vector<string>& arr) {
        // Create the Trie
        TrieNode* root = new TrieNode();

        // Insert all words into the Trie
        for (const string& word : arr) {
            insert(root, word);
        }

        vector<string> result;

        // Find the shortest unique prefix for each word
        for (const string& word : arr) {
            result.push_back(getUniquePrefix(root, word));
        }

        return result;
    }
};