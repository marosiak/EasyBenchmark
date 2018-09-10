#ifndef EASYBENCHMARK_H
#define EASYBENCHMARK_H

#pragma once
#include <iostream>
#include <chrono>
#include <string>
#include <typeinfo>

namespace Benchmark {
    // Credits https://github.com/SteelPh0enix/EzBench
    template <typename T>
    const char* getTimeUnit() {
        if (typeid(T) == typeid(std::milli))
            return "ms";
        else if (typeid(T) == typeid(std::micro))
            return "us";
        else if (typeid(T) == typeid(std::nano))
            return "ns";

        return "";
    }
    // End of credits

    std::string m_info;
    std::chrono::time_point<std::chrono::system_clock> m_startTime;

    void start() { m_startTime = std::chrono::high_resolution_clock::now(); }
    void start(const std::string& name) {
        m_info = name;
        start();
    }
    template<typename period>
    period end() {
        if(m_info.length() > 0){
            std::cout << "[Benchmark] "<<"\""<<m_info<<"\" passed in " << std::chrono::duration<double, period>(std::chrono::high_resolution_clock::now() - m_startTime).count() << " " <<getTimeUnit<period>() << std::endl;
        } else {
            std::cout << "[Benchmark] "<< std::chrono::duration<double, period>(std::chrono::high_resolution_clock::now() - m_startTime).count() << " " <<getTimeUnit<period>() << std::endl;
        }
        m_info = std::string();
    }
    void end() {
        end<std::milli>();
    }
}

#endif // EASYBENCHMARK_H
