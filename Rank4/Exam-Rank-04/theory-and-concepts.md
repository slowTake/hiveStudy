# Exam Rank 04 — Theory and concepts

## argv and argc

`argc` counts arguments; `argv[0]` is program name. Always guard `argc` before accessing `argv[1]`.

## write syscall

```c
#include <unistd.h>
write(1, "hello\n", 6);
```

Return value: bytes written or -1 on error. Exam exercises often ignore error handling unless specified.

## String algorithms

| Pattern | Technique |
|---------|-----------|
| Intersection (`inter`) | Nested loop or frequency array for ASCII |
| Word split | Find spaces, null-terminate or copy slices |
| Trim | Skip leading/trailing whitespace |

## malloc discipline

```c
char *ft_strdup(const char *s) {
    size_t len = /* ... */;
    char *dup = malloc(len + 1);
    if (!dup) return NULL;
    /* copy */
    return dup;
}
```

Caller frees unless subject says otherwise.

## Linked lists

```c
t_list *ft_create_elem(void *data) {
    t_list *node = malloc(sizeof(t_list));
    if (!node) return NULL;
    node->data = data;
    node->next = NULL;
    return node;
}
```

Insertion, removal, and sort exercises need careful pointer updates:

```
prev -> curr -> next
```

When removing `curr`, `prev->next = curr->next`.

## Function pointers

```c
void ft_list_foreach(t_list *begin, void (*f)(void *)) {
    while (begin) {
        f(begin->data);
        begin = begin->next;
    }
}
```

## Integer to string

Handle special cases first:

- `n == 0` → `"0"`
- `n < 0` → place `'-'` and work with `long` to avoid `INT_MIN` overflow on `-n`

## brainfuck model

Tape array, pointer index, bracket matching for loops. Pre-scan brackets to jump efficiently (optimization) or match naively in loop.

## Exam strategy

1. Read entire subject before typing
2. Write allowed functions as comment header
3. Main + one helper max for clarity
4. Test with `gcc -Wall -Wextra -Werror` and subject examples
5. Submit only when first level tests pass — do not rush to higher level with bugs
