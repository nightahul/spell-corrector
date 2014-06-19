#include "spellCorrector.h"
#include<iostream>
using namespace std;

int main()
{
    spellCorrector corrector;
    corrector.load_file("big.txt");


    string request;
    while (request != "quit")
    {
        cout << "Type one word\n";
        cin >> request;

        string correct(corrector.correct_word(request));

        if (correct != "")
            cout << "possible correction: " << correct << "\n\n\n";
        else
            cout << "No corrections available \n\n\n";
    }

    return 0;
}
