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
    std::chrono::milliseconds dura( 500 );
    std::this_thread::sleep_for( dura );
}

int bar_function(int i = 0) {
    std::chrono::milliseconds dura( 1000 );
    std::this_thread::sleep_for( dura );
    return i;
}

int main() {

    auto time_elapsed0 = util::time_this(foo_function);
    auto time_elapsed1 = util::time_this(std::function<void()>(foo_function));
    auto time_elapsed2 = util::time_this<>(std::function<void()>(foo_function));
    auto time_elapsed3 = util::time_this<std::micro>(std::function<void()>(foo_function));
    auto time_elapsed4 = util::time_this<std::milli, void>(foo_function);
    auto time_elapsed5 = util::time_this<std::micro, int>(std::bind(bar_function, 31337));
    auto time_elapsed6 = util::time_this<std::nano, void>([]{ std::cout << "Hello World!" << std::endl;});
    auto time_elapsed7 = util::time_this<std::nano, void>([](){ std::cout << "Hello World!" << std::endl;});
    auto time_elapsed8 = util::time_this<std::nano, void>([] () -> void { std::cout << "Hello World!" << std::endl;});
    auto time_elapsed9 = util::time_this<std::nano, int>([]() -> int{ return bar_function(42); } );
    auto time_elapsed10 = util::time_this(std::function<int()>(std::bind(bar_function, 31337)));
    
    std::cout << "Time elapsed: " <<  std::chrono::duration_cast<std::chrono::seconds>(time_elapsed0).count() << " seconds" << std::endl;
    std::cout << "Time elapsed: " <<  time_elapsed0.count() << " milli-seconds" << std::endl;
    std::cout << "Time elapsed: " <<  time_elapsed1.count() << " milli-seconds" << std::endl;
    std::cout << "Time elapsed: " <<  time_elapsed2.count() << " milli-seconds" << std::endl;
    std::cout << "Time elapsed: " <<  time_elapsed3.count() << " milli-seconds" << std::endl;
    std::cout << "Time elapsed: " <<  time_elapsed4.count() << " micro-seconds" << std::endl;
    std::cout << "Time elapsed: " <<  time_elapsed5.count() << " micro-seconds" << std::endl;
    std::cout << "Time elapsed: " <<  time_elapsed6.count() << " nano-seconds" << std::endl;
    std::cout << "Time elapsed: " <<  time_elapsed7.count() << " nano-seconds" << std::endl;
    std::cout << "Time elapsed: " <<  time_elapsed8.count() << " nano-seconds" << std::endl;
    std::cout << "Time elapsed: " <<  time_elapsed9.count() << " nano-seconds" << std::endl;
    std::cout << "Time elapsed: " <<  time_elapsed10.count() << " nano-seconds" << std::endl;


    return 0;
}