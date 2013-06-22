#ifndef TIME_HPP
#define TIME_HPP

#include <chrono>
#include <functional>

namespace util {
    // std::chrono::steady_clock::time_point
    // std::chrono::duration<std::chrono::milliseconds>
    std::chrono::duration<double, std::milli>
    time_this(std::function<void()> f) {
        auto start = std::chrono::steady_clock::now();
        f();
        auto stop  = std::chrono::steady_clock::now();
        return (stop - start);
    }
    
    template<typename Unit>
    std::chrono::duration<double, Unit>
    time_this(std::function<void()> f) {
        auto start = std::chrono::steady_clock::now();
        f();
        auto stop  = std::chrono::steady_clock::now();
        return (stop - start);
    }

// template< class R, class... Args >
// class function<R(Args...)>

    // template<typename Unit, class F, class ... Args>
    // std::chrono::duration<double, Unit>
    // time_this3(F f) {
    //     auto start = std::chrono::steady_clock::now();
    //     f(Args...);
    //     auto stop  = std::chrono::steady_clock::now();
    //     return (stop - start);
    // }
} /* namespace util */

#endif /* end of include guard: TIME_HPP */
