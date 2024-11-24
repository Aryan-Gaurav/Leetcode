/*
Problem Link: https://www.lintcode.com/problem/3729/
Description
A Trie is a tree-like data structure used to efficiently store and retrieve prefixes of a collection of strings.

In this problem, you are required to create a Trie class and implement the following functionalities:

Trie(): Initializes a Trie object
void insert(String word): Inserts the string word into the Trie
int countWordsEqualTo(String word): Returns the number of instances of the string word in the Trie
int countWordsStartingWith(String prefix): Returns the number of strings in the Trie that start with the prefix prefix
void erase(String word): Removes the string word from the Trie

1≤word.length,prefix.length≤2000

word and prefix only contain lowercase English letters.

The functions insert(), countWordsEqualTo(), countWordsStartingWith(), and erase() are called a maximum of 
3
×
1
0
4
3×10 
4
  times in total.

It is guaranteed that the string word always exists in the trie when the erase() function is called.

Example
Example 1

Input

[
  "insert("apple")",
  "insert("apple")",
  "countWordsEqualTo("apple")",
  "countWordsStartingWith("app")",
  "erase("apple")",
  "countWordsEqualTo("apple")",
  "countWordsStartingWith("app")",
  "erase("apple")",
  "countWordsStartingWith("app")"
]
Output

[void, void, 2, 2, void, 1, 1, void, 0]
Explanation

trie.insert("apple");               // Insert "apple".
trie.insert("apple");               // Insert anothor "apple".
trie.countWordsEqualTo("apple");    // There is two instance of "apple", return 2.
trie.countWordsStartingWith("app"); // "app" is the prefix of "apple", return 2.
trie.erase("apple");                // Remove one "apple".
trie.countWordsEqualTo("apple");    // There is only one instance of "apple", return 1.
trie.countWordsStartingWith("app"); // Return 1.
trie.erase("apple");                // Remove "apple", and Trie is empty now.
trie.countWordsStartingWith("app"); // Return 0.
*/


class Trie {
    class Node{
        public:
        int wordCount,prefixCount;
        vector<Node*> nextNode;
        Node(){
            wordCount=0;
            prefixCount=0;
            nextNode.resize(26,NULL);
        }
    };
    Node *root;
public:
    Trie(){
        root=new Node();
    }
    /**
     * @param word: The string to be inserted into the Trie.
     * @return: nothing
     */
    void insert(string &word) {
        auto current=root;
        for(auto &character:word){
            int index=character-'a';
            if(current->nextNode[index]==NULL){
                current->nextNode[index]=new Node();
            }
            current=current->nextNode[index];
            current->prefixCount++;
            // cout<<"inserttion complete for "<<character<<endl;
        }
        current->wordCount++;
        // cout<<word<<" "<<current->wordCount<<endl;
    }

    /**
     * @param word: The word to be searched for.
     * @return: The number of words in the Trie that are equal to the given word.
     */
    int countWordsEqualTo(string &word) {
        // cout<<"count words for "<<word<<endl;
        auto current=root;
        for(auto &character:word){
            int index=character-'a';
            if(current->nextNode[index]==NULL){
                return 0;
            }
            current=current->nextNode[index];
        }
        return current->wordCount;
    }

    /**
     * @param prefix: The prefix to be searched for.
     * @return: The words in the Trie that have the same prefix as the given word.
     */
    int countWordsStartingWith(string &prefix) {
        auto current=root;
        for(auto &character:prefix){
            int index=character-'a';
            if(current->nextNode[index]==NULL){
                return 0;
            }
            current=current->nextNode[index];
        }
        return current->prefixCount;
    }

    /**
     * @param word: The word to be removed.
     * @return: nothing
     */
    void erase(string &word) {
        // int wordCount=countWordsEqualTo(word);
        auto current=root;
        for(auto &character:word){
            int index=character-'a';
            current=current->nextNode[index];
            current->prefixCount--;
        }
        current->wordCount--;
    }
};
