/*

    test_time.cpp

    Tests for time.hpp
*/

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>

#include "time.hpp"

void foo_function() {
    std::chrono::milliseconds dura( 1000 );
    std::this_thread::sleep_for( dura );
}

void bar_function(int i) {
    i = 3;
    std::chrono::milliseconds dura( 1000 );
    std::this_thread::sleep_for( dura );
    // return i;
}

int main() {

    auto time_elapsed = util::time_this(foo_function);
    auto time_elapsed2 = util::time_this<std::micro>(foo_function);
    std::function<decltype(bar_function)> x = std::bind(bar_function, 31337);
    // auto time_elapsed3 = util::time_this3<std::micro, decltype(x)>(x);
    // auto time_elapsed3 = util::time_this3<std::micro, decltype(x), 5>(x);
    
    std::cout << "Time elapsed: " <<  std::chrono::duration_cast<std::chrono::seconds>(time_elapsed).count() << " seconds" << std::endl;
    std::cout << "Time elapsed: " <<  time_elapsed.count() << " milli-seconds" << std::endl;
    std::cout << "Time elapsed: " <<  time_elapsed2.count() << " micro-seconds" << std::endl;
    // std::cout << "Time elapsed: " <<  time_elapsed3.count() << " micro-seconds" << std::endl;

    return 0;
}