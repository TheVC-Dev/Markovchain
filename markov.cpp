#include <iostream>
#include <fstream>
#include "markov.h"

void getInp(string& fileInp, int& orderInp, int& wordnumInp){
    cout << "Enter input filename: ";
    cin >> fileInp;

    cout << "Enter order (1, 2, or 3) : ";
    cin >> orderInp;

    cout << "Enter number of words to generate: ";
    cin >> wordnumInp;
}

string joinWords(const string words[], int startIndex, int count){
    string result;
    for(int i = startIndex; i < startIndex + count; i++){
        result += words[i];
    }
    
    return result;
}

int readWordsfromFile(string filename, string words[], int maxWords){
    ifstream inputFile;
    inputFile.open(filename);
    
    int Wordcount = -1;
    if(inputFile.is_open()){
        Wordcount++;
        while(Wordcount < maxWords && inputFile >> words[Wordcount]){Wordcount++;}
        inputFile.close();
    }
    
    return Wordcount;
}

int buildMarkovChain(const string words[], int numWords, int order, string prefixes[], string suffixes[], int maxChainSize){
    int count = 0;
    for(int i= 0; i <=(numWords - order - 1); i++){
        prefixes[count] += joinWords(words, i, order);
        cout << "Prefix: " << joinWords(words, i, order) << endl;

        suffixes[count] += words[i + order];
        cout << "Suffix: " << words[i + order] << endl;

        count++;
    }
    return count;
