#ifndef COMPILER_COMPARATOR_REPORT_H
#define COMPILER_COMPARATOR_REPORT_H

#include "Benchmark.h"
#include "IntegerIdentifier.h"

#include <functional>
#include <string>
#include <utility>
#include <vector>

namespace Awe {
class Report {
private:
  std::string name;
  IntegerIdentifier identifier;
  std::vector<Benchmark> benchmarks;
  int integerStore = 0;

public:
  explicit Report(std::string name);
  void benchmark(const std::string &name, unsigned long executions, std::function<int(void)> function);
  void dump() const;
};
}

#endif