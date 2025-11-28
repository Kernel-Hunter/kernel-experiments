#!/usr/bin/env bash
set -e
cd "$(dirname "$0")/../kernel"
echo "Building kernel module..."
make
echo "Installing module (requires sudo)..."
sudo insmod hello_kmod.ko || { echo "insmod failed"; exit 1; }
echo "Installed. Check: cat /proc/hello_kmod"
