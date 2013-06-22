#ifndef TIME_HPP
#define TIME_HPP

#include <chrono>
#include <functional>

namespace util {

    template<typename Unit = std::milli, typename Ret>
    std::chrono::duration<double, Unit>
    benchmark(std::function< auto()->Ret > f, size_t iterations = 100) {
        
        auto start = std::chrono::steady_clock::now();
        for (auto i = iterations; i > 0; i--) {
            f();
        }
        auto stop  = std::chrono::steady_clock::now();
        
        return (stop - start);
    }

} /* namespace util */

#endif /* end of include guard: TIME_HPP */
