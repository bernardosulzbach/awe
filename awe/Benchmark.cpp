#include "Benchmark.h"

#include <stdexcept>

namespace Awe {
Benchmark::Benchmark(const std::string &name) : name(name) {
}

void Benchmark::start() {
  if (started) {
    throw std::runtime_error("called start in a benchmark that has already been started");
  }
  if (stopped) {
    throw std::runtime_error("called start in an already stopped benchmark");
  }
  timeA = std::chrono::high_resolution_clock::now();
  started = true;
}

void Benchmark::stop(unsigned long executions) {
  if (!started) {
    throw std::runtime_error("called stop in a benchmark that has not been started");
  }
  if (stopped) {
    throw std::runtime_error("called stop in an already stopped benchmark");
  }
  if (executions == 0) {
    throw std::runtime_error("called stop with zero executions");
  }
  timeB = std::chrono::high_resolution_clock::now();
  Benchmark::executions = executions;
  stopped = true;
}

bool Benchmark::isStopped() const {
  return stopped;
}

std::string Benchmark::getName() const {
  return name;
}

std::chrono::high_resolution_clock::duration Benchmark::getDuration() const {
  return timeB - timeA;
}
}