#include  <iostream>
#include "markov.h"
#include "markov.cpp"
#include <cstdlib>
#include <ctime>

using namespace std; 

int main(){
    srand(time(0));
    string fileInp; 
    int orderInp, wordnumInp;
    string prefixes[10000], suffixes[10000], words[10000], result[10000];

    getInp(fileInp, orderInp, wordnumInp);

    int count{readWordsfromFile(fileInp, words, 50)};
    cout << "Read " << count << " words" << endl;
    for (int i = 0; i < 10 && i < count; i++){
        cout << words[i] << endl;
    }

    return 0;
}
