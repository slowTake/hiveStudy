# CPP05 — Syntax, libraries, and tools

Quick reference for **C++20** in Module 05. Do **not** use STL containers or `<algorithm>` until CPP08.

---

## Compiler and build

### Required flags

```makefile
CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++20
```

### Typical Makefile targets

| Target | Action |
|--------|--------|
| `all` | Build executable (often named after project or `bureaucrat`) |
| `clean` | Remove object files |
| `fclean` | `clean` + remove binary |
| `re` | `fclean` then `all` |

### Compile single exercise

```bash
cd ex00 && make && ./bureaucrat   # binary name per your Makefile
```

---

## Headers commonly used in CPP05

| Header | Purpose in this module |
|--------|-------------------------|
| `<iostream>` | `std::cout`, `std::cerr`, `std::endl` |
| `<string>` | `std::string` |
| `<exception>` | `std::exception` base class |
| `<fstream>` | `std::ofstream` — ShrubberyCreationForm file output |
| `<cstdlib>` | `std::rand`, `std::srand` — RobotomyRequestForm |
| `<ctime>` | `std::time` — seeding RNG |
| `<cstddef>` | `nullptr` for unknown-form returns |

### Forbidden until CPP08 (examples)

```cpp
// DO NOT USE in CPP05
#include <vector>
#include <map>
#include <list>
#include <algorithm>
```

---

## Exception syntax (C++20)

### Throwing

```cpp
if (grade < 1)
    throw GradeTooHighException();
```

### Catching

```cpp
try {
    doRiskyWork();
} catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
}
```

### Custom nested exception

```cpp
class Bureaucrat {
public:
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const noexcept override {
            return "Grade is too high";
        }
    };
};
```

Use `noexcept` on `what()` and `override` on virtual overrides (C++20 at The Hive).

### Optional: smart pointers in ex03

```cpp
#include <memory>

std::unique_ptr<AForm> form(intern.makeForm("robotomy request", "Bender"));
// no manual delete if you adopt unique_ptr at call site
```

Raw `new`/`delete` remains valid if you prefer matching older 42 examples.

---

### Re-throwing

```cpp
catch (const std::exception& e) {
    // log locally
    throw;  // re-throws current exception
}
```

---

## Class syntax reminders

### Constructor initializer list (required for const members)

```cpp
Bureaucrat::Bureaucrat(std::string name, unsigned int grade)
    : _name(name), _grade(grade) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}
```

### Orthodox Canonical Form skeleton

```cpp
class Form {
public:
    Form();
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();
};
```

Copy assignment often cannot reassign `const` members—many implementations copy only `_signed` or follow subject-specific guidance.

### operator<< (non-member friend or free function)

```cpp
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}
```

---

## Abstract class and polymorphism

```cpp
class AForm {
public:
    virtual ~AForm();
    virtual void execute(Bureaucrat const& executor) const;
protected:
    virtual void executeAction() const = 0;  // pure virtual
};
```

Calling virtual function through base reference:

```cpp
void Bureaucrat::executeForm(AForm const& form) {
    try {
        form.execute(*this);
        std::cout << form.getName() << " was executed." << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
```

---

## File I/O (ShrubberyCreationForm)

```cpp
#include <fstream>

std::string filename = _target + "_shrubbery";
std::ofstream out(filename);  // std::string accepted directly in C++20
if (!out.is_open()) {
    // handle error (throw or message)
    return;
}
out << "   *   " << std::endl
    << "  ***  " << std::endl
    << " ***** " << std::endl;
out.close();
```

---

## Random numbers (RobotomyRequestForm)

```cpp
#include <cstdlib>
#include <ctime>

std::srand(static_cast<unsigned int>(std::time(NULL)));
if (std::rand() % 2 == 0)
    // success
else
    // failure
```

`% 2` gives roughly 50% distribution if `rand()` is well-behaved enough for the exercise.

---

## Factory dispatch (Intern)

### Function pointer typedef

```cpp
typedef AForm* (*FormCreator)(std::string const& target);

static AForm* createShrubbery(std::string const& target) {
    return new ShrubberyCreationForm(target);
}
```

### Parallel arrays (no STL)

```cpp
static const char*    names[] = { "shrubbery creation", "robotomy request", "presidential pardon", NULL };
static FormCreator    creators[] = { createShrubbery, createRobotomy, createPardon, NULL };

for (int i = 0; names[i] != NULL; ++i) {
    if (formName == names[i])
        return creators[i](target);
}
```

---

## Debugging and quality tools

| Tool | Use |
|------|-----|
| `-g` (optional locally) | Debug symbols for GDB |
| `valgrind --leak-check=full ./bureaucrat` | Detect leaks from `new` in `Intern` / `makeForm` |
| `-fsanitize=address` (if allowed locally) | Buffer/heap issues — not always on 42 cluster |
| `c++filt` | Demangle symbols in crash output |

### GDB quick commands

```bash
g++ -g -std=c++20 -Wall -Wextra main.cpp Bureaucrat.cpp -o test
gdb ./test
# (gdb) break Bureaucrat::incrementGrade
# (gdb) run
# (gdb) catch throw
```

---

## Shell utilities for testing

```bash
# Verify shrubbery file created
ls -la *_shrubbery
cat Bender_shrubbery

# Multiple compile check
for d in ex00 ex01 ex02 ex03; do (cd "$d" && make re) || break; done
```

---

## C++20 features worth using in CPP05

| Feature | Example use |
|---------|-------------|
| `nullptr` | Unknown form from `makeForm` |
| `override` / `noexcept` | Exception `what()`, virtual `execute` |
| `[[nodiscard]]` | Return values that must not be ignored |
| Range-for | Iterate test arrays in `main` |
| `std::unique_ptr<AForm>` | Safer ownership after `Intern::makeForm` |

---

## Re-throwing

```cpp
catch (const std::exception& e) {
    // log locally
    throw;  // re-throws current exception
}
```

---

## Useful external references

- [cppreference — exceptions](https://en.cppreference.com/w/cpp/error/exception)
- [cppreference — ofstream](https://en.cppreference.com/w/cpp/io/basic_ofstream)
- [cppreference — rand](https://en.cppreference.com/w/cpp/numeric/random/rand)
- Official 42 subject PDF (intranet) — authoritative for output strings and evaluation

---

## Pre-submission checklist

- [ ] Compiles with `-Wall -Wextra -Werror -std=c++20`
- [ ] No forbidden STL headers
- [ ] OCF on all classes except ex00 `Bureaucrat`
- [ ] Virtual destructor on `AForm`
- [ ] All `new` matched with `delete` in tests
- [ ] Form name strings match subject exactly
- [ ] Grade direction verified with test cases at boundaries (1, 150)
