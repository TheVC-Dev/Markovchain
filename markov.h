#ifndef MARKOV_H
#define MARKOV_H
using namespace std;

void getInp(string& fileInp,int& orderInp,int& wordnumInp);
int readWordsfromFile(string filename, string words[], int maxWords);
int buildMarkovChain(const string words[], int numWords, int order, string prefixes[], string suffixes[], int maxChainSize);
string joinWords(const string words[], int startIndex, int count);
string getRandomSuffix(const string prefixes[], const string suffixes[], int chainSize, string currentPrefix);
string getRandomPrefix(const string prefixes[], int chainSize);
string generateText(const string prefixes[], const string suffixes[], int chainSize, int order, int numWords);

#endif
