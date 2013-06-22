/*

    test_benchmark.cpp

    Tests / examples for benchmark.hpp
*/

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <functional>
#include <thread>

#include "benchmark.hpp"

void foo_function() {
    std::chrono::milliseconds dura( 5 );
    std::this_thread::sleep_for( dura );
}
int main() {

    auto time_elapsed0 = util::benchmark(std::function<void()>(foo_function));
    auto time_elapsed1 = util::benchmark(std::function<void()>(foo_function), 200);

    std::cout << "Time elapsed: " <<  time_elapsed0.count() << " milli-seconds" << std::endl;
    std::cout << "Time elapsed: " <<  time_elapsed1.count() << " milli-seconds" << std::endl;

    return 0;
}