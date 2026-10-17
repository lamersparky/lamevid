#!/bin/sh
set -eu
./lamevid --help >/dev/null
./lamevid --version | grep -q '^lamevid 0\.1\.0$'
if ./lamevid >/dev/null 2>&1; then echo "FAIL: no-argument invocation should fail" >&2; exit 1; fi
echo "PASS: lamevid basic CLI tests"
