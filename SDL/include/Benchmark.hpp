#ifndef BENCHMARK_HPP
#define BENCHMARK_HPP

//#include <ctime>
#include <chrono>
#include <string>

using namespace std::chrono;


class Benchmark 
{

    public:
        Benchmark(std::string name);
        void StartTimer();
        void StopTimer();
        void PrintStats();

    private:
        std::string benchmarkName;
        high_resolution_clock::time_point t1;
        high_resolution_clock::time_point t2; 
        double totalIterations;
        duration<double> totalTime;
        enum BenchmarkState {START,STOP};
        BenchmarkState benchmarkState;

};

#endif
