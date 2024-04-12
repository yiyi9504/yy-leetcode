#include "../src/MultiThread/1195.hh"

void printFizz() { cout << "fizz" ;}
void printBuzz() { cout << "buzz" ;}
void printFizzBuzz() { cout << "fizzbuzz" ;}
void printNumber(int number) { cout << number ;}

int main() {  
    FizzBuzz fb(15);
    vector<thread> threads;
    threads.emplace_back( [&fb]() { fb.fizz(printFizz); } );
    threads.emplace_back( [&fb]() { fb.buzz(printBuzz); } );
    threads.emplace_back( [&fb]() { fb.fizzbuzz(printFizzBuzz); } );
    threads.emplace_back( [&fb]() { fb.number(printNumber); } );    
    for (auto& t: threads) { t.join(); } 
    return 0;  
}