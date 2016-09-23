CCFLAGS = -std=c++11 -O2 -Wall

test: Trie.o Node.o TrieTest.o
	g++ $(CCFLAGS) -o TrieTest Trie.o Node.o TrieTest.o
	./TrieTest "addWordFile.txt" "isWordFile.txt"

Trie.o: Trie.cpp Trie.h
	g++ $(CCFLAGS) -c Trie.cpp

Node.o: Node.cpp Node.h
	g++ $(CCFLAGS) -c Node.cpp

TrieTest.o: TrieTest.cpp Node.h Trie.h
	g++ $(CCFLAGS) -c TrieTest.cpp

clean:
	-rm *.o $(objects) TrieTest
