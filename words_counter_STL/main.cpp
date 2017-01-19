#include <iostream>
#include <unordered_map>
#include <map>
#include <fstream>
#include <cctype>
#include <algorithm>
#include <set>

using namespace std;


multiset<string> MyRecord_foo() //funcrion for recording dates from file into SET container
{
    string verbs;
    multiset<string> tmp_set;
    ifstream checking_file("/home/pasquda/MyQtProj/build-words_counter-Desktop_Qt_5_7_0_GCC_64bit-Debug/verbs.txt");//path to file for deleting words;
    if(!checking_file)
    {
        cout << "Ebana vrot" << endl;
    }
    while (checking_file >> verbs)
    {
       tmp_set.insert(verbs);
    }
    return tmp_set;
}
const multiset<string>word_list = MyRecord_foo(); //global SET container for words wich we wont write later
bool check_words(string &checked_word) //verification for words
{
   for(auto it : word_list)
   {
      if(checked_word == it)
      {
          return false;
      }
   }
   return true;

}
string Cutting(string &inp_word) //cuting for any symbols by (myChar function)
{
    inp_word.erase(remove_if(inp_word.begin(), inp_word.end(),[](char &elem){return (!isalpha(elem));}), inp_word.end());
    return inp_word;
}

int main(int argc, char *argv[])
{


    unordered_map<string, int> words_count;
    multimap<int, string> useful_contain;
           ifstream file("/home/pasquda/Downloads/lab.txt"); //path to file with text for pursing
           string word, comp_word;

           while (file >> word)
           {
                    comp_word = Cutting(word);
                    if(check_words(comp_word))
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

