//Ryan Williams 
//CS 3505
//A3 "The-Rule-of-Three and the Trie"
//Trie.cpp

#include "Trie.h"
#include <vector>
#include <string>

using namespace std;

//Constructor that creates the root of the tree which is a Node object
Trie::Trie()
{
  root = new Node();
}

//Copy Constructor that takes in a Trie object and 
//performs a deep copy on a new trie and returns a new trie
//When the new trie is constructed, modifying it will NOT 
//modify the one that was used to copy 
Trie::Trie(const Trie& other)
{
    root = new Node(*other.root);
}

//Assignment operator overloaded function
Trie& Trie::operator=(Trie other)
{
  if(root != other.root)
    {
      delete root;
      root = new Node(*other.root);
    }
  return *this;
}

//Adds a word to a trie object, by placing the letters in the 
//array of nodePpointers. Not by putting the letter there, but by making that slot not null
//Once we have reached the leaf, we set the isWord flag to true to ensure isWord() works properly 
void Trie::addWord(string word)
{
  Node * current = root;//start at the root

  //iterate down the tree by updating pointers, 
  //if we find a nullptr, we make a new node and make 
  //slot in array point to that new node that we just created
  for(unsigned int i = 0; i < word.length(); i++)
    {

      if(current -> nodePointers[word.at(i) - 'a'] == nullptr)
	{
	  Node * newNode = new Node();
	  current -> nodePointers[word.at(i) - 'a'] = newNode;
	  current = newNode;
	}
      else
	{
	  current = current -> nodePointers[word.at(i) - 'a']; 
	}
    }
  
  current -> isWord = true; //at the bottom of the tree set the flag to true
}

//Takes in a word and returns true if the word is in the tree, 
//and false if the word is not in the tree
bool Trie::isWord(string word)
{
  Node * current = root; //start at the root
  
  for(unsigned int i = 0; i < word.length(); i++)
    {
      //if we ever find a nullptr as we work our way down the tree 
      //then we return false because we know the path for the given word is invalid
      if(current-> nodePointers[word.at(i) - 'a'] == nullptr)
	{
	  return false;
	}
      else 
	{
	  current = current -> nodePointers[word.at(i) - 'a'];
	}
    }
  return current -> isWord; 
}

//This method returns all the words in the tree with 
//the given prefix that is passed in
vector<string> Trie::allWordsWithPrefix(string prefix)
{
  Node* current = root; //start at the root
  vector<string> prefixedWords; //create a vector to hold all the prefixed words we find


  //first start by going down the tree to the level of the prefix
  for(unsigned int i = 0; i < prefix.length(); i++)
    {
      if(current -> nodePointers[((int) prefix.at(i) - 97)] == nullptr)
	{
	  return prefixedWords;
	}
      current = current -> nodePointers[((int) prefix.at(i) - 97)];
    }

  
  allWordsWithPrefixHelper(prefixedWords, prefix, current); //call the helper method to recursively find all the chars that are found 

  return prefixedWords;
  
}

//helper method to the allWordsWithPrefixHelper
void Trie::allWordsWithPrefixHelper(vector<string> &vec, string prefix, Node* node)
{
  for(unsigned int i = 0; i < 26; i++)
    {
      if(node -> nodePointers[i] != nullptr)
	{
	  Node* current = node -> nodePointers[i];
	  string addedString = prefix;
	  addedString += (char)(i + 97);

	  if(current -> isWord)
	    {
	      vec.push_back(addedString);
	    }
	  allWordsWithPrefixHelper(vec, addedString, current);
	}
    }
}

vector<string> Trie::wordsWithWildcardPrefix(string word)
{
   vector<string> wildCardVector;
   return wildCardVector;
}

//Trie object destructor
Trie::~Trie()
{
   delete root;
}
