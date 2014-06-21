#include "spellCorrector.h"
#include<iostream>
using namespace std;

int main()
{
    spellCorrector corrector;
    corrector.load_file("big.txt");


    string request;
   for(int i=0;i<10;i++)
   {
        cout << "\nenter word to correct\n";
        cin >> request;

        string correct(corrector.correct_word(request));

        if (correct != "")
            cout << "possible correction: " << correct << "\n\n";
        else
            cout << "Sorry, no correction available \n\n";
    }

    return 0;
}
