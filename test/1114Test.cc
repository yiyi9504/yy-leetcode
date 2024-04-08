#include "../src/MultiThread/1114.hh"

void printFirst() { cout << "first" ;}
void printSecond() { cout << "second" ;}
void printThird() { cout << "third" ;}

int main() {  
    Foo foo;
    vector<int> ans;
    vector<thread> threads;
    for (int i=0; i<5; i++) {
        threads.emplace_back( [&foo]() { foo.first(printFirst); } );
        threads.emplace_back( [&foo]() { foo.second(printSecond); } );
        threads.emplace_back( [&foo]() { foo.third(printThird); }) ;
    }
    for (auto& t: threads) { t.join(); } 
    return 0;  
}