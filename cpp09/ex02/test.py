#!/usr/bin/env python3
import random
import subprocess
import re
import sys


def run_case(nums):
    cmd = ['./PmergeMe'] + list(map(str, nums))
    out = subprocess.check_output(cmd, text=True)
    m = re.search(r'^After:\s*(.*)$', out, re.M)
    if not m:
        return False, out
    after = list(map(int, m.group(1).split()))
    return after == sorted(nums), out


def main():
    ok = True

    edge_cases = [
        [1],
        [2, 1],
        [1, 2],
        [3, 2, 1],
        [1, 3, 2],
        [5, 4, 3, 2, 1],
        [1, 2, 3, 4, 5],
        [100, 1, 50, 2, 25, 3, 12, 4, 6, 5],
    ]

    for c in edge_cases:
        good, out = run_case(c)
        if not good:
            ok = False
            print('FAIL edge', c)
            print(out)
            break

    if ok:
        sizes = [2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 15, 20, 30, 40, 50, 75,
                 100, 150, 200, 300, 500, 750, 1000, 1500, 2000, 3000]
        for n in sizes:
            for _ in range(30):
                nums = random.sample(range(0, 100000), n)
                good, out = run_case(nums)
                if not good:
                    ok = False
                    print('FAIL random n=', n)
                    print('nums=', nums)
                    print(out)
                    break
            if not ok:
                break

    print('OK' if ok else 'NOT OK')
    return 0 if ok else 1


if __name__ == '__main__':
    sys.exit(main())
