# Test Plan

Run these only against your own lab target. Record the real result of each.

| # | Test | Expected | Actual |
|---|---|---|---|
| 1 | No arguments | Usage message, exit code 1 | |
| 2 | Port `0` or `70000` | Error message, exit code 1 | |
| 3 | Port `abc` | Error message, exit code 1 | |
| 4 | Start port greater than end port | Error message, exit code 1 | |
| 5 | Scan a known-open port in your lab (e.g. 22 or 80) | Reported as open | |
| 6 | Scan a closed port | Not reported as open | |
| 7 | Scan an unreachable IP with timeout 1 | Finishes without hanging | |
| 8 | Run `make debug` build on a full range | No AddressSanitizer errors | |
| 9 | Compare results with `nmap -p <range> <host>` | Same open ports | |

Comparing against Nmap (test 9) is a good thing to mention in your README.
