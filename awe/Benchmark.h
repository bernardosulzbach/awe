#ifndef COMPILER_COMPARATOR_BENCHMARK_H
#define COMPILER_COMPARATOR_BENCHMARK_H

#include <chrono>
#include <string>

namespace Awe {
class Benchmark {
private:
  std::string name;
  bool started = false;
  bool stopped = false;
  unsigned long executions = 0;
  std::chrono::high_resolution_clock::time_point timeA;
  std::chrono::high_resolution_clock::time_point timeB;

public:
  explicit Benchmark(const std::string &name);
  void start();
  void stop(unsigned long executions);
  unsigned long getExecutions() const;
  bool isStopped() const;
  std::string getName() const;
  std::chrono::high_resolution_clock::duration getDuration() const;
};
}

#endif