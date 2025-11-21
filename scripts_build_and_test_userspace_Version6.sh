#!/usr/bin/env bash
set -e
cd "$(dirname "$0")/.."
gcc -o userspace/test_read userspace/test_read.c
echo "Built userspace tester: userspace/test_read"
echo "Run userspace/test_read after module is installed."