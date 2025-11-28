# Architecture / Notes

- kernel/ : contains the example kernel module hello_kmod.
  - The module creates a proc entry /proc/hello_kmod and exposes a short message.
  - It is intentionally trivial to illustrate module build/load/unload.

- userspace/ : small test helper in C to read the proc entry.

- tools/ : small pentest helper to run nmap and summarize results.

Safety & best practices:
- Use isolated VMs (snapshots) for kernel experiments.
- Keep kernel module development off production machines.
- Use static analysis and simple runtime checks before loading code.
