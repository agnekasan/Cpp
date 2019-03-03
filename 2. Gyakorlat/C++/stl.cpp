#include <iostream>
#include <unordered_set>
#include <set>
#include <map>
#include <list>
#include <vector>
#include <deque>

void memberVsAlgorithmFunctions();
void trickyReverseIterator();
void equivalenceVsEquality();
void removingElements();
void vectorVsDeque();

struct Lsb_Less
{
    bool operator() (int x, int y)
    {
        return x%10 < y%10;
    }
};

bool equalOne(int i, int p)
{
    if(i == p)
        return true;
    else
        return false;
}

void __size(int* p, int size_)
{
    for(int i = 0; i < size_; i++)
    {
        std::cout << *p++ << " ";
        
    }
}

int main(int argc, const char * argv[]) {
    
    //memberVsAlgorithmFunctions();
    //trickyReverseIterator();
    //equivalenceVsEquality();
    //removingElements();
    //vectorVsDeque();
    

    
    return 0;
}

void vectorVsDeque()
{
    /**
     Vector vs. Deque
     */
    // Which one to use?
    // need push front --> deque
    // performans is important? --> vector
    // when the elements are not of trivial type, deque is not much less efficient than vector
    //
    // could allocation of large contiguous memory be a problem?
    //  - limited memory size
    //  - large trunk of data
    //  - memory fragmentation
    
    
    /**
     VECTOR
     */
    std::vector<int> v = {1,2,3,4};
    
    std::cout << "v.size " << v.size() << std::endl;
    std::cout << "v.capacity " << v.capacity() << std::endl;
    
    v.push_back(5);
    std::cout << "v.size after pushback " << v.size() << std::endl;
    std::cout << "v.capacity after pushback " << v.capacity() << std::endl;
    // vectors capacity grows exponentially
    // Drawbacks:
    //
    // expensive reallocation
    // requires contigouos memory
    // strategy of minimazing reallocation
    // 1. if the maximum number of items is know,, reserve(MAX)
    // 2. if the end of grown, reserve as much memory as we can, once all data is inserted, trim off the rest
    
    std::vector<int> vec(6);
    std::cout << vec.size() << " " << vec.capacity() << std::endl; //  6 6
    vec.push_back(1);
    std::cout << vec.size() << " " << vec.capacity() << std::endl; // 7 12
    // vec2.resize(6); doing the same job
    
    std::vector<int> vec2;
    vec2.reserve(6);
    std::cout << vec2.size() << " " << vec2.capacity() << std::endl; // 0 6
    vec2.push_back(1);
    std::cout << vec2.size() << " " << vec2.capacity() << std::endl; // 1 6
    
    std::vector<int> someVec = {1,2,3};
    int* p = &someVec[1];
    someVec.push_back(5);
    std::cout << *p << std::endl; // Undefined behavior
    
    
    /**
     DEQUE
     */
    // grows lineary witha fixed size
    // no reallocation has no reserve() and capaccity()
    // sligtly slower than vector
    //  - more complex data structure
    //  - locality
    
    std::deque<int> d = {1,2,2,34};
    int* p1 = &d[1];
    d.push_back(5);
    std::cout << *p1 << std::endl; // OK
    // push_front() is OK too
    // deque: inserting at either end wont invalidate pointers
    // removing or inserting in the middle still will invalidate pointers/references/iterators
    
    int foo[] = {1,2,3,4};
    //std::cout << sizeof(foo)/sizeof(foo[0]);
    __size(foo, sizeof(foo)/sizeof(foo[0]));
    
    // summary
    //
    // frequesnt push_front     - deque
    // built in data type       - vector
    // not built in data type,  - deque
    // contigorous memory       - deque
    // unpredictable growth     - deque
    // pointer integrity        - deque
    // frequently passed to C   - vector
}

void removingElements()
{
    /**
     remove elements from vector
     */
    std::vector<int> vec = {1,2,3,4,5,1,1,1,1,12};
    std::vector<int> vec1 = {1,2,3,4,5,1,1,1,1,12};
    
    for(int i : vec) std::cout << i << " ";
    std::cout << std::endl;
    for(std::vector<int>::iterator itr = vec.begin(); itr != vec.end(); itr++)
    {
        if(*itr == 1)
            itr = vec.erase(itr);
        else
            itr++;
    }   // complexity O(n*m)
    
    for(int i : vec) std::cout << i << " ";
    std::cout << std::endl;
    
    auto itr_ = std::remove(vec1.begin(), vec1.end(), 1);   // complexity O(n) linear
    // remove function has no idea about how tha data is stored for ex. in dynamic array or hashtable
    vec1.erase(itr_, vec1.end());
    for(int i : vec1) std::cout << i << " ";
    std::cout << std::endl;
    std::cout << vec1.capacity() << std::endl;
    vec1.shrink_to_fit(); // c++11 release the unused mamory to the system
    //older cpp version use the swap trick ==>> std::vector<int>(vec1).swap(vec1);
    std::cout << vec1.capacity() << std::endl;
    
    /**
     remove elements from list
     */
    std::list<int> list = {1,2,3,4,5,1,1,1,1,12};
    
    list.remove(1);
    // the remove and erase part from vector still do the job but not the most efficient
    // list have remove function
    for(int i : list) std::cout << i << " ";
    std::cout << std::endl;
    
    /**
     remove elements from an associative or unordered container
     */
    std::multiset<int> mset = {1,2,3,4,5,1,1,1,1,12};
    // does not have a dedicated remove function
    mset.erase(1); //only need O(log(n)) instead of O(n)
    for(int i : mset) std::cout << i << " ";
    std::cout << std::endl;
    
    /**
     summary of removing elements
     1. vector or deque : algorithm remove() followed by erase()
     2. list : member fucntion remove()
     3. associative or unordered containers : erase()
     */
    
    std::multiset<int> mulSet = {1,2,3,5,1,1,1,3,4,5};
    for (std::multiset<int>::iterator msItr = mulSet.begin(); msItr != mulSet.end(); )
    {
        if(*msItr == 1) mulSet.erase(msItr++);
        else msItr++;
    }
    
    /**
     erase elements from vector with hand crafted algorithm
     */
    std::vector<int> vector = {1,2,3,5,1,1,1,3,4,5};
    for (std::vector<int>::iterator msItr = vector.begin(); msItr != vector.end(); )
    {
        if(*msItr == 1)
            msItr = vector.erase(msItr);
        else
            msItr++;
    }
    
    // Summary
    //
    // sequence and unordered container : itr = c.erase(itr)
    // associative container:             c.erase(itr++)
    
    std::vector<int> v = {1,1,1,2,3,1,1,14};
    auto autoItr = std::remove_if(v.begin(), v.end(), std::bind(equalOne, std::placeholders::_1, 1));
    v.erase(autoItr, v.end());
    
    // do the same with lambda function
    auto myItr = std::remove_if(v.begin(), v.end(),
                                [](int i)
                                {
                                    if(i == 12)
                                        return true;
                                    else
                                        return false;
                                });
    v.erase(myItr, v.end());
    
    for(int i : v) std::cout << i << " ";
    std::cout << std::endl;
}

void equivalenceVsEquality()
{
    std::set<int, Lsb_Less> s = {21,23,26,27};
    std::set<int, Lsb_Less>::iterator itr1, itr2;
    
    // Algorithm find() look for equality: if (x == y)
    itr1 = std::find(s.begin(), s.end(), 36); // s.end()
    // set<int>::find() looks for equivalence: if(!(x<y) && !(y<x))
    itr2 = s.find(36); // 26
    
    std::cout << *itr2;
    
    // Algorithms of equality
    // search
    // find_end
    // find_first_of
    // adjancent_search
    
    // Algorithms of equivalence
    // binary_search
    // includes
    // lower_bound
    // upper_bound
}

void trickyReverseIterator()
{
    // Two ways to declare reverse iterator
    std::reverse_iterator<std::vector<int>::iterator> rItr1;
    std::vector<int>::reverse_iterator rItr2;
    std::vector<int>::iterator itr;
    
    // Traversing with reverse iterator
    std::vector<int> myVec = {4,5,6,7};
    for(rItr1 = myVec.rbegin(); rItr1 != myVec.rend(); rItr1++)
        std::cout << *rItr1 << ",";
    std::cout << std::endl;
    
    rItr2 = std::vector<int>::reverse_iterator(itr); // makes reverse iterator from normal iterator
    //itr = std::vector<int>::iterator(rItr2); // compile error
    itr = rItr2.base(); // returns current iterator
    
    std::vector<int> myVec_1 = {1,2,3,4,5};
    std::vector<int>::reverse_iterator rItr3 = std::find(myVec_1.rbegin(), myVec_1.rend(), 3);
    
    std::cout << *rItr3 << std::endl; // 3
    
    std::vector<int>::const_iterator itr_1 = rItr3.base();
    
    std::cout << *itr_1 << std::endl; // 4
    
    
    std::vector<int>::const_iterator cItr = std::find(myVec_1.cbegin(), myVec_1.cend(), 3);
    // Inserting
    myVec_1.insert(cItr, 9); // myVec_1: {1,2,9,4,5}
    
    // insert and erase will invalidate pointers in vector, use instead list or associative containers
    
}

void memberVsAlgorithmFunctions()
{
    /**
     SET
     */
    std::unordered_multiset<int> s = {2,4,1,8,6,9};
    std::unordered_multiset<int>::const_iterator sItr;
    
    // Using member function
    sItr = s.find(4); // O(1) constant time
    
    std::cout << *sItr << std::endl;
    
    // Using algorithm
    sItr = std::find(s.begin(), s.end(), 4);  // O(n) linear time
    
    std::cout << *sItr << std::endl;
    
    /**
     MAP/MULTIMAP
     */
    std::map<char, std::string> myMap = {
        {'S', "Sunday"},
        {'M', "Monday"},
        {'W', "Wednesday"}
    };
    
    std::map<char, std::string>::const_iterator mItr;
    
    // Using member function
    mItr = myMap.find('S'); // O(log(n))
    
    std::cout << mItr->first << " " << mItr->second << std::endl;
    // Using algorithm
    //mItr = std::find(myMap.begin(), myMap.end(), std::make_pair<const char, std::string>('M', "Monday"));
    
    /**
     LIST
     */
    std::list<int> myList = {2,4,6,8,1,5,9};
    
    std::list<int>::const_iterator lItr;
    
    // Using member function
    myList.remove(2); // O(n) linear time takes const time to remove
    // myList: {4,6,8,1,5,9}
    myList.remove_if( [](int n){return n == 6; } );
    
    myList.sort();
    
    // Using algorithm
    lItr = std::find(myList.begin(), myList.end(), 4);
    lItr = std::find_if(myList.begin(), myList.end(), [](const int v) { return v == 4; });
    
    std::remove(myList.begin(), myList.end(), 2); // O(n) linear time takes linear time to remove
    // myList: {4,6,8,1,5,9,9} insert a new 9 on the end of the list
    
    auto itr = std::remove(myList.begin(), myList.end(), 2);
    myList.erase(itr, myList.end());
    // myList: {4,6,8,1,5,9}
    
    // std::sort(myList.begin(), myList.end()); -> undefined behavior because sort needs randomAccessIterator
    // but list only have biDirectionIterator
    
    for(int i : myList)
        std::cout << i << ",";
    std::cout << std::endl;
    
    std::cout << *lItr << std::endl;
}
