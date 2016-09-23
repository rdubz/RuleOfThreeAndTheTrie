//Ryan Williams
//CS 3505
//A3: "The Rule-of-Three and the Trie"
//TrieTest.cpp

#include <iostream>
#include <fstream>
#include <string>
#include "Trie.h"

using namespace std;

//a test program that makes a trie, adds words to it, and queries them
int main(int argc, char **argv)
{  
  string word;
  Trie trie = Trie();
  
  if(argc < 3)
    {
      cout << "Sorry, you didn't enter the correct number of file names" << endl;
      return 0;
    }

  //Once we know we have the correct number of arguments, we can take all the words from the first file and put them in the Trie one by one

  ifstream addWordFile(argv[1]);
  
  if(addWordFile.is_open())
    {
      
      while(getline(addWordFile, word)) //read in each line to get each word
	{
	  
	  trie.addWord(word); //add the word
	}
      addWordFile.close(); //once we have read all the words close the file
    }
  else
    {
      cout << "Couldn't open the first file: now terminating" << endl;
      return 0;
    }
  cout<< "done adding words" <<endl;
  //Now that all the words are added, we check the second file to see if those words are in the Trie one by one

  ifstream isWordFile(argv[2]);

  if(isWordFile.is_open())//try to open the file
    {
      while(getline(isWordFile, word))
	{
	  if(trie.isWord(word))
	    {
	      cout << word << " is found" << endl;
	    }
	   else
	    {
	      //if it can't find the word, call the prefix method to get all possbile did you mean words
	      cout << word << " is not found, did you mean:" << endl;
	      vector<string> vec = trie.allWordsWithPrefix(word);
	      
	      if(vec.size() == 0)
		{
		  cout << "   no alternatives found" << endl;
		}
	      else 
		{
		  for(vector<string>::iterator it = vec.begin(); it != vec.end(); it++)
		    {
		      cout << "   " << *it << endl;
		    }
		}
	    }
	}
      isWordFile.close();
    }
   else
     {
       cout<< "Couldn't open the second input file: now terminating" << endl;
       return 0;
     }
  {}
  return 0;
}
