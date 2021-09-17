#!/usr/bin/env bash

set -euo pipefail

cmake -S .  \
  -B out/build \
  -DGLFW_BUILD_DOCS=OFF \
  -DBUILD_GTK_TESTS=OFF \
  -DBUILD_QT5_TESTS=OFF \
  -DBUILD_QT6_TESTS=OFF \
  -DENABLE_GLIB=OFF \
  -DENABLE_GTK_DOC=OFF