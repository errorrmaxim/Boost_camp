#include "lru_cache.h"



LRU_Cache::LRU_Cache(int size_cache_): m_cache_size(size_cache_),m_idElem(0)
{
    try
    {
        if(size_cache_ < 0)
          throw "Cache size, must be bigest than NULL";

    }
    catch(char *error)
    {
        std::cout << error << std::endl;
    }
}

void LRU_Cache::add_data(int key, Data_class& rhs)
{
    if(m_cache_size == m_idElem)
    {
        main_cache.pop_back();
        --m_idElem;
    }
    ++m_idElem;
   main_cache.insert(main_cache.begin(), std::make_pair(key, std::make_shared<Data_class>(rhs)));

}

void LRU_Cache::remove_data()
{
    if(m_idElem > 0)
    {
        main_cache.pop_back();
        --m_idElem;
    }
    if(m_idElem == 0)
    {
        std::cout << "Cache is empty!" << std::endl;
    }
}

void LRU_Cache::show_cache()
{
    for(auto entry : main_cache)
    {
        std::cout << entry.first << ' ' << (*entry.second) << std::endl;
    }
}

Data_class LRU_Cache::call_data(int key)
{
    try
    {
    clock_t time = clock();
    for(auto it = main_cache.begin(); it != main_cache.end(); ++it)
    {
        if(it->first == key)
        {
            main_cache.splice(main_cache.begin(), main_cache, it);
            time = clock() - time;
            printf("%s", "Time of searching: ");
            printf("%f", (double)time/CLOCKS_PER_SEC);
            std::cout << std::endl;
            return *it->second;
        }
    }
        throw 404;
    }
    catch(int error)
    {
    std::cout << "Error " << error << "\nElement is undefined!" << std::endl;
    }
}













