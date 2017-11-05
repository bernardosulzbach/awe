#include <string>

#include "../awe/RandomGenerator.h"
#include "../awe/Report.h"

double stringAverage(const std::string &s) {
  double x = 0.0;
  for (char c : s) {
    x += c;
  }
  return x / s.size();
}

int main() {
  Awe::RandomGenerator<char> charGenerator;
  std::string string;
  for (int i = 0; i < 10 * 1000 * 1000; i++) {
    string += charGenerator.next();
  }
  Awe::Report report("10,000,000 Random Characters");
  const auto function = [&string]() { return static_cast<int>(stringAverage(string)); };
  report.benchmark("stringAverage([10 * 1000 * 1000])", 1, function);
  report.dump();
  return 0;
}