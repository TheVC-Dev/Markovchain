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
}

string getRandomSuffix(const string prefixes[], const string suffixes[], int chainSize, string currentPrefix){
    int matchcount = 0;
    cout << "cainsize: " << chainSize << endl;
    string matches[chainSize];

    for(int i = 0; i < (chainSize); i++){

        cout << "suffixes: " << suffixes[i] << endl;
        if (currentPrefix == prefixes[i]){
            cout << currentPrefix << "==" << prefixes[i] << "   adding:  " << suffixes[i] << endl;
            matches[matchcount] += suffixes[i];
            matchcount++;
        }
    }

    if(matchcount){
        int pick = rand() % matchcount;
        
        cout << "matches: ";
        for (int i = 0; i < matchcount; i++){
            cout << matches[i] << ", ";
        }
        cout << endl;

        cout << "Randum index: " << pick << endl;
        cout << "choosing:... "  << matches[pick] << endl;
        string random_matching_index = matches[pick];

        return random_matching_index;
    }else{return "no match";}
}

string getRandomPrefix(const string prefixes[], int chainSize){
    int randomIndex = rand() % chainSize;

    cout << "random prefix index: " << randomIndex << endl;
    cout << "random prefix: " << prefixes[randomIndex] << endl;

    return prefixes[randomIndex];
}
