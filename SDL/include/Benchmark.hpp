#ifndef BENCHMARK_HPP
#define BENCHMARK_HPP

#include <time.h>
#include <string>



class Benchmark 
{

    public:
        Benchmark(std::string name);
        void StartTimer();
        void StopTimer();
        void PrintStats();




    private:
        std::string benchmarkName;
        clock_t t;
        clock_t totalTime;
        clock_t tempTime;
        int totalIterations;
        enum BenchmarkState {START,STOP};
        BenchmarkState benchmarkState;

};

#endif
