# kernel-experiments

Kernel-experiments is a lightweight project with example kernel code, helper user-space tools, pentest automation helpers and docs - intended as a safe, well-documented starting point for kernel/module exploration and security tooling.

Warning: kernel modules run in kernel space. Only build/load these on test machines or VMs you control. Do not run on production hosts.

Features
- hello_kmod: small example Linux kernel module (proc entry) with simple user-space test program
- Makefile to build the module
- scripts to build/install/uninstall the module
- pentest helper (Python) to run and summarize nmap scans
- CI configuration for static checks (flake8, shellcheck)

Quick start (on a Linux development VM with kernel headers)
1. Clone repo:
   git clone https://github.com/<your-username>/kernel-experiments.git
2. Build module:
   cd kernel-experiments/kernel
   make
3. Install:
   sudo ./build_and_install.sh
4. Read proc entry:
   cat /proc/hello_kmod
5. Cleanup:
   sudo ./uninstall.sh

Repository layout
- kernel/hello_kmod.c - kernel module
- kernel/Makefile - build rules
- userspace/test_read.c - small C program to read the proc file
- scripts/*.sh - helpers to build/install/uninstall and run tests
- tools/pentest_helper.py - small Python wrapper to run nmap and summarize results
- docs/ARCHITECTURE.md - high-level notes and safety
- .github/workflows/ci.yml - static checks CI

Contributing
See CONTRIBUTING.md. Please use VMs and test environments for kernel work.

License
MIT - see LICENSE
```
