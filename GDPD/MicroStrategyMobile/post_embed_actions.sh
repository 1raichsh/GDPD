#!/bin/sh

APPCONNECT_BINARY_PATH="${TARGET_BUILD_DIR}/${FRAMEWORKS_FOLDER_PATH}/AppConnect.framework/AppConnect"
echo "$APPCONNECT_BINARY_PATH"

# Getting the archs list from -info command by truncating the string from the latest ':' occurrence
FAT_ARCHS="$(lipo -info "$APPCONNECT_BINARY_PATH" | cut -d : -f 3)"

for arch in $FAT_ARCHS; do
  if ! [[ "${ARCHS}" == *"$arch"* ]]; then
    lipo -remove "$arch" -output "$APPCONNECT_BINARY_PATH" "$APPCONNECT_BINARY_PATH" || exit 1
    echo "Stripping arch $arch"
  fi
done

if [[ -n "${EXPANDED_CODE_SIGN_IDENTITY}" && "${CODE_SIGNING_REQUIRED}" == "YES" && "${CODE_SIGNING_ALLOWED}" == "YES" ]]; then
	/usr/bin/codesign --force --sign "${EXPANDED_CODE_SIGN_IDENTITY}" ${OTHER_CODE_SIGN_FLAGS} --preserve-metadata=identifier,entitlements "${APPCONNECT_BINARY_PATH}"
fi
