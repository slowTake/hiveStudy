# Exam Rank 04 — Study plan

## Phase 0 — Exam mechanics (½ day)

| Topic | Action |
|-------|--------|
| Registration | Exam slot on intra |
| Workflow | Read subject → code → pass automated tests → next level |
| Allowed functions | Copy subject list into comment block before coding |
| Time | Practice 3h simulated sessions |

---

## Phase 1 — Level 00 drills (2–3 days)

Master argv, `write`, simple loops.

| Exercise | Skill |
|----------|-------|
| `aff_first_param` | `argv[1]` only |
| `ft_putstr` | String output |
| `first_word` | Parse until space |

**Checkpoint:** 3 level-00 subjects in 45 minutes each.

---

## Phase 2 — Level 01–02 (3–4 days)

| Skill | Exercises |
|-------|-----------|
| String copy/compare | `ft_strcpy`, `ft_strcmp` variants |
| Character class | `is_alpha`, `repeat_alpha` |
| Set operations | `inter`, `union` |
| Pattern | `wdmatch`, `ulstr` |

---

## Phase 3 — Level 03 (3–4 days)

| Skill | Exercises |
|-------|-----------|
| `malloc` / `free` | `ft_strdup`, `ft_range` |
| Number theory | `fprime`, `add_prime` |
| 2D arrays | `ft_atoi_base` |

Always check `malloc` return.

---

## Phase 4 — Level 04 (3–4 days)

| Skill | Exercises |
|-------|-----------|
| Linked lists | `ft_list_size`, `ft_list_remove_if` |
| Function pointers | `ft_list_foreach`, `ft_list_sort` |
| Apply fn to list | `ft_list_map` |

Review `t_list` struct from subject:

```c
typedef struct s_list {
    void            *data;
    struct s_list   *next;
}   t_list;
```

---

## Phase 5 — Level 05 peek (2 days)

| Exercise | Skill |
|----------|-------|
| `ft_itoa` | int → allocated string |
| `ft_itoa_base` | arbitrary base 2–16 |
| `brainfuck` | Interpreter loop |

Even if you only need level 04 to pass, level 05 practice builds confidence.

---

## Week-before checklist

- [ ] 2 full timed mock exams
- [ ] Hand-copy allowed functions from memory for top 10 exercises
- [ ] Zero leak on all `malloc` exercises (test with small inputs)
- [ ] Sleep before exam day
