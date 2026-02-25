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

    getInp(fileInp, orderInp, wordnumInp);

    return 0;
}
