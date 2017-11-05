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

void Report::dump() const {
  std::cout << name << '\n';
  std::cout << integerStore << '\n';
  for (const auto &benchmark : benchmarks) {
    const auto averageDuration = benchmark.getDuration().count() / benchmark.getExecutions();
    std::cout << benchmark.getName() << ": " << averageDuration << " ns." << '\n';
  }
}

void Report::benchmark(const std::string &name, unsigned long executions, std::function<int(void)> function) {
  Benchmark benchmark(name);
  benchmark.start();
  integerStore = function();
  benchmark.stop(executions);
  benchmarks.push_back(benchmark);
}
}