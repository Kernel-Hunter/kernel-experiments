#!/usr/bin/env bash
set -e
cd "$(dirname "$0")/../kernel"
echo "Removing module (requires sudo)..."
sudo rmmod hello_kmod || { echo "rmmod failed or not loaded"; }
echo "Cleaning build artifacts..."
make clean || true