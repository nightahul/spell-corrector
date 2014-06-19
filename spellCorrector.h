#ifndef SPELLCORRECTOR_H_INCLUDED
#define SPELLCORRECTOR_H_INCLUDED

#include<vector>
#include<unordered_map>
#include<string>

using namespace std;

class spellCorrector
{
private:
    unordered_map<string, int> dict;
    void edit1(string &word, vector<string> &words);// stores in words strings at an edit distance 1 from the word
    void known(vector<string> &words, unordered_map<string, int> &known_words);

public:
    void load_file(string filename);
    string correct_word(string &word);
};

#endif // SPELLCORRECTOR_H_INCLUDED
