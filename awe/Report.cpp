#include "Report.h"
#include <iostream>

#include "RandomGenerator.h"

namespace Awe {
static IntegerIdentifier randomIdentifier() {
  RandomGenerator<char> generator;
  std::array<char, 16> identifierData{};
  for (int i = 0; i < 16; i++) {
    identifierData[i] = generator.next();
  }
  return IntegerIdentifier{identifierData};
}

Report::Report(std::string name) : name(std::move(name)), identifier(randomIdentifier()) {
}

void Report::startBenchmark(const std::string &name) {
  if (!benchmarks.empty() && !benchmarks.back().isStopped()) {
    throw std::runtime_error("tried to start a benchmark before stopping the current one");
  }
  benchmarks.emplace_back(name);
  benchmarks.back().start();
}

void Report::stopBenchmark(unsigned long executions) {
  if (benchmarks.empty() || benchmarks.back().isStopped()) {
    throw std::runtime_error("tried to stop a benchmark but no benchmark is running");
  }
  benchmarks.back().stop(executions);
}

void Report::dump() const {
  std::cout << name << '\n';
  for (const auto &benchmark : benchmarks) {
    std::cout << benchmark.getName() << ": " << benchmark.getDuration().count() << " ns." << '\n';
  }
}

void Report::consume(const std::any &data) {
}
}