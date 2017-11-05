#ifndef COMPILER_COMPARATOR_IDENTIFIER_H
#define COMPILER_COMPARATOR_IDENTIFIER_H

#include <array>

namespace Awe {
class IntegerIdentifier {
private:
  std::array<char, 16> data{};

public:
  explicit IntegerIdentifier(const std::array<char, 16> &data);
  std::string toString() const;
};
}

#endif