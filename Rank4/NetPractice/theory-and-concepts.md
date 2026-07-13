# NetPractice — Theory and concepts

## IPv4 address structure

32-bit value written as four octets: `a.b.c.d`

Each octet: 0–255.

## Subnet mask

Mask has contiguous `1` bits (network) then `0` bits (host).

| CIDR | Mask | Hosts (usable) |
|------|------|----------------|
| /24 | 255.255.255.0 | 254 |
| /16 | 255.255.0.0 | 65534 |
| /30 | 255.255.255.252 | 2 (point-to-point) |

**Network address:** `IP & mask`  
**Broadcast:** network | ~mask  
**Usable hosts:** network+1 … broadcast-1

## Same-subnet test

Two hosts communicate directly if:

```
(hostA & mask) == (hostB & mask)
```

## Default gateway

Host sends off-subnet packets to gateway MAC (ARP) at gateway IP on **same subnet**.

## Routing table

Router entry: `(destination_network, mask, next_hop)`

Longest prefix match wins.

## Example

```
Host A: 192.168.1.10 /255.255.255.0, gateway 192.168.1.1
Host B: 10.0.0.5 /255.255.255.0, gateway 10.0.0.1
Router R1: 192.168.1.1/24 and 10.0.0.1/24 on two interfaces
```

`A → B`: A sends to gateway `192.168.1.1`; R1 forwards to `10.0.0.5` via `10.0.0.1` interface.

## Binary shortcut

For /24, only last octet changes between hosts. For /16, last two octets are host space.

## OSI context (light)

NetPractice is layer 3 (IP). ARP resolves layer 3 → layer 2 on local links — simulator may abstract this.
