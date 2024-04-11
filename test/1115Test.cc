#include "../src/MultiThread/1115.hh"

void printFoo() { cout << "foo" ;}
void printBar() { cout << "bar" ;}

int main() {  
    FooBar foo(3);
    vector<int> ans;
    vector<thread> threads;
    threads.emplace_back( [&foo]() { foo.foo(printFoo); } );
    threads.emplace_back( [&foo]() { foo.bar(printBar); } );
    for (auto& t: threads) { t.join(); } 
    return 0;  
}