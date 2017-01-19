#include <iostream>
#include <unordered_map>
#include <map>
#include <fstream>
#include <cctype>
#include <algorithm>
#include <set>
using namespace std;


set<string> MyRecord_foo() //funcrion for recording dates from file into SET container
{
    string verbs;
    set<string> words_lol;
    ifstream checking_file;
    checking_file.open("/home/pasquda/MyQtProj/build-words_counter-Desktop_Qt_5_7_0_GCC_64bit-Debug/verbs.txt");
    if(!checking_file)
    {
        cout << "Ebana vrot" << endl;
    }
    while (checking_file >> verbs)
    {
       words_lol.insert(verbs);

    }

    return words_lol;
}
const set<string>Word_list = MyRecord_foo(); //global SET container for words wich we wont write later
string check_words(string &checked_word) //verification for words
{
    string verbs;
    set<string> words_lol = Word_list;
   for(auto it = words_lol.begin(); it != words_lol.end(); ++it)
   {
       verbs = *it;
      if(checked_word == verbs)
      {
          return "lol";
      }
   }
   return checked_word;

}
string Cutting(string &inp_word) //cuting for any symbols by (myChar function)
{
    string ret_word;

    for(auto it = inp_word.begin(); it != inp_word.end(); ++it)
    {
        if(isalpha(*it))
        {
            ret_word.push_back(*it);
        }
    }

    return ret_word;
}

int main(int argc, char *argv[])
{


    unordered_map<string, int> words_count;
    multimap<int, string> useful_contain;
           ifstream file("/home/pasquda/Downloads/lab.txt");
           string word, comp_word;

           while (file >> word)
           {
                    comp_word = Cutting(word);
                    if(check_words(comp_word) == comp_word)
                    {
                        words_count[comp_word]++;
                    }
           }

           for(auto entry : words_count)
           {

                useful_contain.insert(pair<int, string>(entry.second, entry.first));
           }
           for(auto it = useful_contain.rbegin(); it != useful_contain.rend(); ++it)
           {
               cout << it->first << " : " << it->second << endl;
           }




    return 0;

}
