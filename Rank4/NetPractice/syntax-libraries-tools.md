# NetPractice — Tools and reference

## No codebase

There is no compiler or Makefile. Tools are mental math + the web UI.

## Quick calculators (study only)

```bash
# Python one-liner — verify subnet (study aid, not during eval)
python3 -c "ip='192.168.1.17'; m='255.255.255.0'; ..."
```

Use manual math for eval prep — you must explain without scripts.

## CIDR cheat sheet

| CIDR | Mask |
|------|------|
| /8 | 255.0.0.0 |
| /16 | 255.255.0.0 |
| /24 | 255.255.255.0 |
| /25 | 255.255.255.128 |
| /26 | 255.255.255.192 |
| /27 | 255.255.255.224 |
| /28 | 255.255.255.240 |
| /30 | 255.255.255.252 |

## Campus workflow

1. Intra → NetPractice → download save file
2. Upload/open in practice site
3. Complete level → download updated save file
4. Repeat until level 10
5. Register for evaluation slot

## Real-world commands (context, not graded)

```bash
ip addr
ip route
ping -c 3 10.0.0.1
```

Understanding these helps intuition; NetPractice UI is the graded artifact.
