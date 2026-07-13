# CPP04 — Theory and concepts

## Dynamic polymorphism

```cpp
class Animal {
public:
    virtual void makeSound() const;
    virtual ~Animal();
};

class Dog : public Animal {
public:
    void makeSound() const override;
};
```

Calling `makeSound()` through `Animal*` invokes `Dog::makeSound` **if** function is `virtual`.

## Without virtual (Wrong* classes)

Binding is **static** — decided at compile time from pointer type, not object type. Educational anti-pattern.

## Virtual destructor

```cpp
Animal* a = new Dog();
delete a;  // calls ~Dog then ~Animal only if virtual ~Animal()
```

## Deep copy pattern

```cpp
Dog::Dog(const Dog& other) : Animal(other) {
    _brain = new Brain(*other._brain);
}

Dog& Dog::operator=(const Dog& rhs) {
    if (this != &rhs) {
        Animal::operator=(rhs);
        delete _brain;
        _brain = new Brain(*rhs._brain);
    }
    return *this;
}
```

## Abstract classes

Pure virtual function:

```cpp
virtual void use(ICharacter& target) = 0;
```

Cannot instantiate `AMateria` directly — only concrete subclasses.

## Clone pattern

```cpp
virtual AMateria* clone() const = 0;
```

`MateriaSource::createMateria` returns **new** clone — caller owns it.

## Interface vs implementation

`ICharacter` defines contract; `Character` implements inventory. Separation prepares you for CPP05 `AForm` hierarchy.
