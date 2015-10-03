#include "Benchmark.hpp"

Benchmark::Benchmark(std::string name)
{
    benchmarkName = name;
    benchmarkState = START;
    totalIterations = 0;
    t1 = high_resolution_clock::now();
    t2 = high_resolution_clock::now(); 
    totalTime = duration_cast<duration<double>>(t2 - t1);
}

void Benchmark::StartTimer()
{
    switch(benchmarkState)
    {
        case STOP:
            benchmarkState = START;
            t1 = high_resolution_clock::now();
            break;
        default:
            //printf("Timer: %s cannot start without being stopped first\n", benchmarkName.c_str());
            break;
    }

}

void Benchmark::StopTimer()
{ 
    switch(benchmarkState)
    {
        case START:
            t2 = high_resolution_clock::now(); 
            totalTime += duration_cast<duration<double>>(t2 - t1);
            totalIterations++;
            benchmarkState = STOP;
            break;
        default:
            //printf("Timer: %s cannot stop without being started first\n", benchmarkName.c_str());
            break;
    }
}

void Benchmark::PrintStats()
{
    printf("-------- %s STATS --------\n", benchmarkName.c_str());
    printf("Total Time: %lf\n", totalTime.count());
    printf("Total Iterations: %lf\n", totalIterations);
    printf("Time per call %lf\n", totalTime.count()/totalIterations);
    printf("Called %lf per second\n", totalIterations/totalTime.count());
}
