#!/bin/sh

#
# Detect the platform and output -D flags for use in compilion
#

if [ -z $CC ]; then
  CC=cc
fi

#
# Raspberry Pi check
#

# Is the bcmhost.h header file available?
if [ -e /opt/vc/include/bcm_host.h ]; then
    EXTRA_CFLAGS=-I/opt/vc/include
fi

#
# asdf check
#
if type asdf > /dev/null; then
    EXTRA_CFLAGS="$EXTRA_CFLAGS -std=c99 -D _POSIX_C_SOURCE=199309L"
fi

$CC $CFLAGS $EXTRA_CFLAGS -o /dev/null -xc - 2>/dev/null <<EOF
#include <bcm_host.h>

int main(int argc,char *argv[]) {
    return 0;
}
EOF
if [ "$?" = "0" ]; then
    printf -- "-DTARGET_RPI $EXTRA_CFLAGS -lbcm_host"
fi

