# CPP02 — Exercise breakdown

## ex00 — My First Class

OCF skeleton on a simple class. Evaluators verify you can declare and define all four special members.

---

## ex01 — adiós séñar

| | |
|---|---|
| **Goal** | Replace C casts with `static_cast`, `reinterpret_cast`, `const_cast`, `dynamic_cast` |
| **Trap** | `reinterpret_cast` is dangerous — use only where subject demo requires |

---

## ex02 — Fixed

| | |
|---|---|
| **Storage** | Typically `int _value` with 8 bits fraction: `raw = round(float * 256)` |
| **Operators** | Arithmetic and comparison; stream insertion |
| **Forbidden** | Using `float`/`double` as the stored value type |

### Evaluator checks

- `Fixed a(10.5);` / `Fixed b(42.42);`
- Copy and assign produce independent objects
- `operator<<` prints human-readable float

---

## ex03 — Orthodox Canonical Form

Resource-managing class — destructor must free owned memory; copy must duplicate, not alias.

---

## Traps

| Trap | Consequence |
|------|-------------|
| Shallow copy double-free | Crash / leak |
| Missing `return *this` | Fail assign chain |
| Float storage in Fixed | Subject violation |
