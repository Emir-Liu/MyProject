#!/bin/sh
# ------------------------------------------------------
# JetBrains Rider formatting script.
# ------------------------------------------------------

IDE_BIN_HOME="${0%/*}"
exec "$IDE_BIN_HOME/rider.sh" format "$@"
