# C Port Scanner

A TCP port scanner written in C using POSIX sockets. Built as a learning project for network programming and security tooling.

> **Status:** In progress. Update this line as you go.

## Legal and ethical use

Scan only systems you own or have written permission to test (for example your own VirtualBox lab or `scanme.nmap.org`). Unauthorized scanning may be illegal.

## Features

- [x] Command-line argument parsing with input validation
- [ ] TCP connect scan with timeout (`scan_port`)
- [ ] Banner grabbing (`grab_banner`)
- [ ] Multi-threaded scanning with `pthread`
- [ ] Output export (CSV or JSON)

Tick the boxes as you finish each feature, and delete any you don't build.

## Build

```
make            # normal build
make debug      # build with AddressSanitizer for development
make clean
```

Requires `gcc` and `make` (Linux or WSL).

## Usage

```
./portscan <host> <start_port> <end_port> [timeout_sec]
./portscan 192.168.56.101 1 1024 2
```

## Example output

Paste a real run from your own lab here once it works.

## Project structure

```
c-port-scanner/
├── Makefile
├── README.md
├── src/
│   ├── main.c       (argument parsing, scan loop)
│   ├── scanner.c    (scan_port, grab_banner)
│   └── scanner.h
└── tests/
    └── test_plan.md
```

## What I learned

Write 3-5 honest bullets after finishing: how non-blocking connect works, the closed versus filtered difference, what went wrong while debugging, and what you would improve.

## Author

Kaushik Kumar | [GitHub](https://github.com/ZeroDayFORGE-Lab) | [TryHackMe](https://tryhackme.com/p/ZeroDayFORGE)
