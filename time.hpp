#ifndef TIME_HPP
#define TIME_HPP

#include <chrono>
#include <functional>

namespace util {

    template<typename Unit = std::milli, typename Ret = void>
    std::chrono::duration<double, Unit>
    time_this(std::function< auto()->Ret > f) {
        auto start = std::chrono::steady_clock::now();
        f();
        auto stop  = std::chrono::steady_clock::now();
        return (stop - start);
    }

    template<typename Unit = std::milli>
    std::chrono::duration<double, Unit>
    time_this(std::function< void() > f) {
        auto start = std::chrono::steady_clock::now();
        f();
        auto stop  = std::chrono::steady_clock::now();
        return (stop - start);
    }

} /* namespace util */

#endif /* end of include guard: TIME_HPP */
