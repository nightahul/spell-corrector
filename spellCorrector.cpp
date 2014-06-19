#include<iostream>
#include<fstream>
#include<sstream>
#include<algorithm>
#include "spellCorrector.h"

using namespace std;

void spellCorrector::load_file(string filename)
{
    ifstream file(filename.c_str());
    if(!file.is_open())
    {
        cout<<"error";
        return;
    }
    file.seekg(0, ios::end);
    int len = file.tellg();
    file.seekg(0, ios::beg);
    file.seekg(0, ios::beg);

    string eng(len,' ');
    file.read(&eng[0], len);

    for(int i=0;i<len;i++)
    {
        if(isalpha(eng[i]))
        {
            eng[i]=tolower(eng[i]);
        }
        else
        {
            eng[i]=' ';
        }
    }
    stringstream eng_words(eng);

    string s;
    while(getline(eng_words, s, ' '))
    {
        if(!s.empty())
            dict[s]++;
    }


    file.close();
}

void spellCorrector::edit1(string &word, vector<string> &words)
{
    int l = word.size();
    //deletions l
    for(int i=0;i<l;i++)
    {
        words.push_back(word.substr(0,i) + word.substr(i+1));

    }
    //insertion 26(i+1)
    for(int i=0;i<l+1;i++)
    {
        for(char ch ='a';ch<='z';ch++)
        {
            words.push_back(word.substr(0,i) + ch + word.substr(i));
        }
    }
    //transposition
    for(int i=0;i<l-1;i++)
    {
        words.push_back(word.substr(0,i) + word[i+1] + word[i] +word.substr(i+2));
    }
    //alteration
    for(int i=0;i<l;i++)
    {
        for(char ch ='a';ch<='z';ch++)
        {
            words.push_back(word.substr(0,i) + ch + word.substr(i+1));
        }
    }
}

void spellCorrector::known(vector<string> &words, unordered_map<string, int> &known_words)
{
    int n = words.size();
    unordered_map<string, int>::iterator it;
    for(int i=0;i<n;i++)
    {
        it = dict.find(words[i]);
        if(it!=dict.end())
        {
            known_words[it->first] = it->second;
        }
    }
}

bool compare_freq(pair<const string, int> & a, pair<const string, int>& b)
{
    return a.second < b.second ;
}

string spellCorrector::correct_word(string &word)
{
    vector<string> words;
    unordered_map<string, int> known_words;

    if(dict.find(word)!=dict.end())
        return word;

    edit1(word, words);
    known(words, known_words);

    if(!known_words.empty())
        return max_element(known_words.begin(), known_words.end(), compare_freq)->first;

    for(int i=0;i<words.size();i++)
    {
        vector<string> edit2;
        edit1(words[i], edit2);
        known(edit2, known_words);
    }

    if(!known_words.empty())
        return max_element(known_words.begin(), known_words.end(), compare_freq)->first;

    return "";
}
