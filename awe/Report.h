#ifndef COMPILER_COMPARATOR_REPORT_H
#define COMPILER_COMPARATOR_REPORT_H

#include "Benchmark.h"
#include "IntegerIdentifier.h"

#include <any>
#include <string>
#include <utility>
#include <vector>

namespace Awe {
class Report {
private:
  std::string name;
  IntegerIdentifier identifier;
  std::vector<Benchmark> benchmarks;
  unsigned long executions = 0;

public:
  explicit Report(std::string name);

  void startBenchmark(const std::string &name);

  void stopBenchmark(unsigned long executions = 1);

  void consume(const std::any &data);

  void dump() const;
};
}

#endif