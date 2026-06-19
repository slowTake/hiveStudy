# CPP05 — Exercise breakdown

## How module validation works

At 42 / The Hive, **every exercise in the subject is mandatory** for a full module pass:

| Status | Meaning |
|--------|---------|
| **Mandatory** | Required for **100/100** on CPP05. Submitted and evaluated separately in `ex00/` … `ex03/`. |
| **Bonus** | Optional extra in an exercise — not required to pass. |

CPP05 has **no optional exercises**. All four must pass peer evaluation and behave per the subject.

**Progression rule:** Each exercise folder must contain everything from previous exercises plus the new files (cumulative turn-in).

---

## ex00 — Mommy, when I grow up, I want to be a bureaucrat!

| | |
|---|---|
| **Mandatory** | Yes |
| **Turn-in** | `ex00/` |
| **Files** | `Makefile`, `main.cpp`, `Bureaucrat.{h,hpp,cpp}` |

### What you build

A `Bureaucrat` class representing an official with a **grade** from **1** (best) to **150** (worst).

### Expected behaviour

| Requirement | Detail |
|-------------|--------|
| Attributes | `const std::string` name; `unsigned int` grade |
| Constructor | Invalid grade (`< 1` or `> 150`) → throw exception |
| `incrementGrade()` | Decrease grade number by 1; at grade **1** → `GradeTooHighException` |
| `decrementGrade()` | Increase grade number by 1; at grade **150** → `GradeTooLowException` |
| Exceptions | Nested classes inheriting `std::exception` with `what()` |
| `operator<<` | Output: `name, bureaucrat grade X.` |
| Getters | `getName()`, `getGrade()` — const |

### Special rules

- **OCF not required** for `Bureaucrat` in ex00 only (subject exemption).
- Use **try/catch** in `main` to demonstrate exceptions.

### Evaluator will check

- Boundary grades 1 and 150
- Constructor throws on 0, 151, etc.
- Output format exact
- No memory leaks

---

## ex01 — Form up, maggots!

| | |
|---|---|
| **Mandatory** | Yes |
| **Turn-in** | `ex01/` |
| **Files** | ex00 files + `Form.{h,hpp,cpp}` |

### What you build

A `Form` class that bureaucrats can **sign** if their grade is good enough.

### Expected behaviour

| Requirement | Detail |
|-------------|--------|
| Form attributes | `const` name; `bool` signed (default false); `const` grade to sign; `const` grade to execute |
| Form constructor | Invalid grade constants → throw (same 1–150 rules) |
| `beSigned(Bureaucrat const&)` | If bureaucrat grade ≤ grade to sign → `_signed = true`; else throw |
| `Bureaucrat::signForm(Form&)` | Calls `beSigned`; prints success or failure message (with reason on failure) |
| Exceptions | `GradeTooHighException`, `GradeTooLowException` on `Form` (for invalid form grades) |
| OCF | **Required** on `Form` |

### Signing rule

```text
bureaucrat.getGrade() <= form.getGradeToSign()  →  can sign
```

(Lower number = higher authority.)

### Evaluator will check

- Low-grade bureaucrat cannot sign high-requirement form
- `signForm` output messages
- Form stays signed after successful sign
- OCF on `Form`

---

## ex02 — No, you need form 28B, not 28C...

| | |
|---|---|
| **Mandatory** | Yes |
| **Turn-in** | `ex02/` |
| **Files** | Previous + rename `Form` → `AForm`; add `ShrubberyCreationForm`, `RobotomyRequestForm`, `PresidentialPardonForm` |

### What you build

Abstract `AForm` with three **concrete** form types and an **execute** workflow.

### Expected behaviour

| Requirement | Detail |
|-------------|--------|
| `AForm` | Abstract base; pure virtual or template-method `execute(Bureaucrat const&)` |
| Pre-execute checks | Form must be **signed**; executor grade ≤ grade to execute |
| `FormNotSignedException` | Thrown when executing unsigned form |
| `Bureaucrat::executeForm(AForm const&)` | Try execute; print success/failure |
| Virtual destructor | On `AForm` |

### Concrete forms (subject grades)

| Form | Sign grade | Execute grade | Action |
|------|------------|---------------|--------|
| `ShrubberyCreationForm` | 145 | 137 | Create `<target>_shrubbery` with ASCII trees |
| `RobotomyRequestForm` | 72 | 45 | Drilling noise; **50%** robotomy success |
| `PresidentialPardonForm` | 25 | 5 | Pardon message from Zaphod Beeblebrox |

Each form takes a **target** string at construction.

### Evaluator will check

- Cannot execute unsigned form
- Insufficient grade throws
- Each form’s unique behaviour
- File created for shrubbery
- Polymorphism through `AForm const&`

---

## ex03 — At least this beats coffee-making

| | |
|---|---|
| **Mandatory** | Yes |
| **Turn-in** | `ex03/` |
| **Files** | Previous + `Intern.{h,hpp,cpp}` |

### What you build

An `Intern` that **manufactures** forms by name (factory pattern).

### Expected behaviour

| Requirement | Detail |
|-------------|--------|
| `makeForm(name, target)` | Returns `AForm*` to new form on match |
| Valid names | `"shrubbery creation"`, `"robotomy request"`, `"presidential pardon"` (exact strings) |
| Unknown name | Print error; return `nullptr` **or** throw (no custom exception required) |
| OCF | Required on `Intern` |
| Design | Prefer function-pointer table over long if/else chains |

### Evaluator will check

- Correct form type for each name
- Memory: caller can `delete` returned pointer
- Unknown form handled gracefully
- Full flow: create → sign → execute

---

## Module checklist

- [ ] All four exercises in separate directories
- [ ] `-std=c++20 -Wall -Wextra -Werror`
- [ ] No STL containers / `<algorithm>`
- [ ] OCF everywhere except ex00 `Bureaucrat`
