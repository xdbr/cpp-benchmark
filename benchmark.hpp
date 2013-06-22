#ifndef BENCHMARK_HPP
#define BENCHMARK_HPP

#include <chrono>
#include <functional>

namespace util {

    template<typename Unit = std::milli, typename Ret>
    std::chrono::duration<double, Unit>
    benchmark(std::function< auto()->Ret > f, size_t iterations = 100) {
        
        auto start = std::chrono::steady_clock::now();
        while ( iterations --> 0 )
            f();

        auto stop  = std::chrono::steady_clock::now();
        
        return (stop - start);
    }

} /* namespace util */

#endif /* end of include guard: BENCHMARK_HPP */
