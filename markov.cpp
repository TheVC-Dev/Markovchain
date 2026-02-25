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
