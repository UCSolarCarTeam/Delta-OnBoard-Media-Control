#include "Benchmark.hpp"

Benchmark::Benchmark(std::string name)
{
    benchmarkName = name;
    benchmarkState = START;
    totalIterations = 0;
    totalTime = 0;
}

void Benchmark::StartTimer()
{
    switch(benchmarkState)
    {
        case STOP:
            tempTime = clock();
            benchmarkState = START;
            t = clock();
            break;
        default:
            printf("Timer: %s cannot start without being stopped first\n", benchmarkName.c_str());
            break;
    }

}

void Benchmark::StopTimer()
{ 
    switch(benchmarkState)
    {
        case START:
            tempTime = clock() - tempTime;
            t = clock() - t;
            //printf ("It took me %d clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);
            totalTime += tempTime;
            //printf("Current Ticks:%d  Time(s):%f\n", totalTime, ((float)totalTime)/CLOCKS_PER_SEC);
            totalIterations++;
            tempTime = 0;
            benchmarkState = STOP;
            break;
        default:
            printf("Timer: %s cannot stop without being started first\n", benchmarkName.c_str());
            break;
    }
}

void Benchmark::PrintStats()
{
    printf("-------- %s STATS --------\n", benchmarkName.c_str());
    printf("Total Ticks:%d  Time(s):%f\n", totalTime, ((float)totalTime)/CLOCKS_PER_SEC);
    printf("Total Iterations: %d\n", totalIterations);
    printf("Time per call %f\n", (float)totalIterations/((float)totalTime)/CLOCKS_PER_SEC);
}
