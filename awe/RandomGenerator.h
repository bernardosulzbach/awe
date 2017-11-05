#ifndef COMPILER_COMPARATOR_RANDOM_GENERATOR_H
#define COMPILER_COMPARATOR_RANDOM_GENERATOR_H

#include <algorithm>
#include <array>
#include <cstdlib>
#include <functional>
#include <random>
#include <vector>

namespace Awe {
template <typename T> class RandomGenerator {
private:
  std::mt19937 engine;

public:
  RandomGenerator() {
    std::array<std::mt19937::result_type, std::mt19937::state_size> random_data{};
    std::random_device source;
    std::generate(std::begin(random_data), std::end(random_data), std::ref(source));
    std::seed_seq seeds(std::begin(random_data), std::end(random_data));
    engine.seed(seeds);
  }
  T next();
};

template <> char RandomGenerator<char>::next() {
  return std::uniform_int_distribution<char>()(engine);
}

template <> int RandomGenerator<int>::next() {
  return std::uniform_int_distribution<int>()(engine);
}

template <> unsigned int RandomGenerator<unsigned int>::next() {
  return std::uniform_int_distribution<unsigned int>()(engine);
}

template <> long RandomGenerator<long>::next() {
  return std::uniform_int_distribution<long>()(engine);
}

template <> unsigned long RandomGenerator<unsigned long>::next() {
  return std::uniform_int_distribution<unsigned long>()(engine);
}

template <> float RandomGenerator<float>::next() {
  return std::uniform_real_distribution<float>()(engine);
}
}

#endif