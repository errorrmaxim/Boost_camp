#include <lru_cache.h>
#include <cassert>
#include <typeinfo>

using namespace std;




int main(int argc, char *argv[])
{


   // weak_ptr<Data_class> gw;


//    list<pair<int, weak_ptr<Data_class>>> some_lst;
//    some_lst.insert(some_lst.begin(),make_pair(1, make_shared<Data_class>("some_text1")));
//    some_lst.insert(some_lst.begin(),make_pair(2, make_shared<Data_class>("some_text2")));
//    some_lst.insert(some_lst.begin(),make_pair(3, make_shared<Data_class>("some_text3")));
//    some_lst.insert(some_lst.begin(),make_pair(4, make_shared<Data_class>("some_text4")));

   // shared_ptr<Data_class>some_tmp(new Data_class("pro"));
    //weak_ptr<Data_class>ww(some_tmp);
   // weak_ptr<Data_class>::element_type val = *ww.lock();

  // cout << val << endl;



//    for(auto it = some_lst.begin(); it != some_lst.end(); ++it)
//    {
//       shared_ptr<Data_class>some_tmp(it->second);
//        weak_ptr<Data_class>ww(some_tmp);
//          weak_ptr<Data_class>::element_type val = *ww.lock();
//          cout << it->first << ' ' << val << endl;
//    }

    Data_class a1("one");
    Data_class a2("two");
    Data_class a3("three");
    Data_class a4("four");
    Data_class a5("five");
    Data_class a6("six");
    Data_class a7("seven");
    Data_class a8("eight");


    LRU_Cache C1(5);

    C1.add_data(1,a1);
    C1.add_data(2,a2);
    C1.add_data(3,a3);
    //
    C1.add_data(4,a4);
    C1.add_data(5,a5);
    C1.add_data(6,a6);
    C1.add_data(7,a7);
    C1.add_data(8,a8);

    C1.call_data(4);
    C1.call_data(5);

    C1.show_cache();
    cout << "=============" << endl;

    assert(C1.call_data(4) == a4);
    assert(C1.call_data(5) == a5);
    assert(C1.call_data(6) == a6);
    assert(C1.call_data(7) == a7);

    assert(C1.call_data(1) == a1); //error situation


    //C1.call_data(1);
//    C1.call_data(3);
//    C1.call_data(4);
//   // C1.call_data(5);
   // C1.show_cache();


 \



//    list<pair<int,weak_ptr<Data_class>>> qwe;
//    string ex = "trololo";
//    qwe.insert(qwe.begin(), make_pair(1,weak_ptr<Data_class>(ex)));
//    qwe.insert(qwe.begin(), make_pair(2,Data_class("qweqwe")));
//    qwe.insert(qwe.begin(), make_pair(3,Data_class("zcxzcx")));
//    qwe.insert(qwe.begin(), make_pair(4,Data_class("rtytry")));
//    //qwe.pop_back();

//    //remove(qwe.begin(), qwe.end(), qwe)
//    list<int> tmp;
//    tmp.insert(tmp.begin(), 1);
//    tmp.insert(tmp.begin(), 2);
//    tmp.insert(tmp.begin(), 3);
//    tmp.insert(tmp.begin(), 4);




//    for(auto it = qwe.begin(); it != qwe.end(); ++it)
//    {
//        if(it->first == 1)
//        {
//            qwe.splice(qwe.begin(), qwe, it);
//        }
//    }

//    for(auto it = qwe.begin(); it != qwe.end(); ++it)
//    {
//        if(it->first == 3)
//        {
//            it = qwe.erase(it);
//        }
//    }

//    for(auto entry : qwe)
//    {
//        cout << entry.first << ' ' << entry.second << endl;
//    }




















    return 0;
}

//кешы
