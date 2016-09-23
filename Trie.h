//Ryan Williams 
//CS 3505
//A3: "Rule-of-Three and the Trie"
//Trie.h

#include <iostream>
#include <vector>

#include "Node.h"

class Trie
{
 private:
  Node * root;
  
 public:
  Trie();
  
  //copy constructor
  Trie(const Trie & other);
  
  //Assignment operator overload
  Trie& operator=(Trie other);

  void addWord(std::string word);

  bool isWord(std::string word);

  void allWordsWithPrefixHelper(std::vector<std::string> &vec, std::string prefix, Node* node);

  std::vector<std::string> allWordsWithPrefix(std::string prefix);

  std::vector<std::string> wordsWithWildcardPrefix(std::string word);

  //Destructor
  ~Trie();
};
