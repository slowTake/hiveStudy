# CPP02 — Theory and concepts

## Orthodox Canonical Form

```cpp
class Fixed {
public:
    Fixed();                          // default
    Fixed(const Fixed& other);        // copy ctor
    Fixed& operator=(const Fixed& rhs); // copy assign
    ~Fixed();                         // destructor
private:
    int _value;
    static const int _fractionalBits = 8;
};
```

## Fixed-point math

Represent real numbers as integers scaled by \(2^{8} = 256\):

```
rawValue = round(floatValue * 256)
floatValue = rawValue / 256.0f   // only for conversion output
```

Multiplication must rescale to avoid overflow:

```
(a.raw * b.raw) >> fractionalBits
```

## Copy assignment idiom

```cpp
Fixed& Fixed::operator=(const Fixed& rhs) {
    if (this != &rhs)
        _value = rhs._value;
    return *this;
}
```

## C++ casts vs C casts

C casts hide intent and disable compiler checks. Prefer:

- `static_cast` — numeric conversions
- `const_cast` — const removal (last resort)
- `reinterpret_cast` — pointer pun between unrelated types
- `dynamic_cast` — safe downcast with RTTI (CPP04+)

## When is OCF required?

Whenever a class **owns** a resource (heap memory, file handle, etc.). Compiler-generated copy is shallow — dangerous for pointers.
