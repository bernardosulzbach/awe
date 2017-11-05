#include <iostream>
#include <string>

#include "../awe/RandomGenerator.h"
#include "../awe/Report.h"

long sumUpTo(long n) {
  long a = 0;
  for (long i = 1; i <= n; i++) {
    a += i;
  }
  return a;
}

int main() {
  Awe::Report report("1 + 2 + 3 + ... + 100,000,000");
  const auto function = []() { return static_cast<int>(sumUpTo(100 * 1000 * 1000)); };
  report.benchmark("sumUpTo([100 * 1000 * 1000])", 1, function);
  report.dump();
  return 0;
}