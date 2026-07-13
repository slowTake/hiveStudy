# CPP02 — Syntax, libraries, and tools

## Fixed-point constants

```cpp
static const int _fractionalBits = 8;
static const int _rawOne = 1 << _fractionalBits;  // 256
```

## Bitwise helpers

```cpp
#include <cmath>   // roundf for conversion only — confirm allowed on campus
```

Some campuses allow `round()` only in constructors, not as stored floats.

## Operator overloading pattern

```cpp
Fixed Fixed::operator+(const Fixed& rhs) const {
    Fixed result;
    result._value = _value + rhs._value;  // same scale — add raw
    return result;
}
```

## Testing

```bash
./fixed
# Compare output to subject examples
valgrind --leak-check=full ./fixed
```

## Headers

`<iostream>`, `<string>`, `<cmath>` (conversion), `<fstream>` if needed — no STL containers.
