#!/usr/bin/env bash

set -euo pipefail

cmake -S .  \
  -DGLFW_BUILD_DOCS=OFF -DUSE_ADDER=OFF \
  -B out/build   