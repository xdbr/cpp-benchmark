#ifndef BENCHMARK_HPP
#define BENCHMARK_HPP

#include <chrono>
#include <functional>

namespace util {

    /*
        D e c l a r a t i o n s
    */
    template<typename Unit = std::milli, typename Ret>
    std::chrono::duration<double, Unit>
    time_this(std::function< auto()->Ret > f);

    template<typename Unit = std::milli>
    std::chrono::duration<double, Unit>
    time_this(std::function< void() > f);

    template<typename Unit = std::milli, typename Ret>
    std::chrono::duration<double, Unit>
    benchmark(std::function< auto()->Ret > f, size_t iterations = 100);

    /*
        D e f i n i t i o n s
    */
    template<typename Unit, typename Ret>
    std::chrono::duration<double, Unit>
    time_this(std::function< auto()->Ret > f) {
        return benchmark(f, 1);
    }

    template<typename Unit>
    std::chrono::duration<double, Unit>
    time_this(std::function< void() > f) {
        return benchmark(f, 1);
    }

    template<typename Unit, typename Ret>
    std::chrono::duration<double, Unit>
    benchmark(std::function< auto()->Ret > f, size_t iterations) {

        auto start = std::chrono::steady_clock::now();
        while ( iterations --> 0 )
            f();

        auto stop  = std::chrono::steady_clock::now();

        return (stop - start);
    }


} /* namespace util */

#endif /* end of include guard: BENCHMARK_HPP */
