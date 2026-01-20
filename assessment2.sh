#!/usr/bin/env bash
set -euo pipefail

# Ensure required environment variables exist
: "${BuildNum:?Environment variable BuildNum is not set}"
: "${SourcePath:?Environment variable SourcePath is not set}"

BASE_DIR="$SourcePath/develop/global/src"
SCONSTRUCT="$BASE_DIR/SConstruct"
VERSION_FILE="$BASE_DIR/VERSION"

# Make files writable (permission)
# owner: read, write, execute; 
# group + others: read, execute;
chmod 755 "$SCONSTRUCT" "$VERSION_FILE"

# Update point=<number> in SConstruct
sed -i.bak -E "s/(point=)[0-9]+/\1${BuildNum}/" "$SCONSTRUCT"

# Update ADLMSDK_VERSION_POINT=<number> in VERSION
sed -i.bak -E "s/(ADLMSDK_VERSION_POINT=)[0-9]+/\1${BuildNum}/" "$VERSION_FILE"

# Remove backup files created by sed
rm -f "$SCONSTRUCT.bak" "$VERSION_FILE.bak"

echo "Build number updated to ${BuildNum}"
