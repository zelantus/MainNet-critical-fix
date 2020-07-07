#!/bin/sh

TOPDIR=${TOPDIR:-$(git rev-parse --show-toplevel)}
SRCDIR=${SRCDIR:-$TOPDIR/src}
MANDIR=${MANDIR:-$TOPDIR/doc/man}

RAVEND=${RAVEND:-$SRCDIR/zelantusd}
RAVENCLI=${RAVENCLI:-$SRCDIR/zelantus-cli}
RAVENTX=${RAVENTX:-$SRCDIR/zelantus-tx}
RAVENQT=${RAVENQT:-$SRCDIR/qt/zelantus-qt}

[ ! -x $RAVEND ] && echo "$RAVEND not found or not executable." && exit 1

# The autodetected version git tag can screw up manpage output a little bit
ZELSVER=($($RAVENCLI --version | head -n1 | awk -F'[ -]' '{ print $6, $7 }'))

# Create a footer file with copyright content.
# This gets autodetected fine for zelantusd if --version-string is not set,
# but has different outcomes for zelantus-qt and zelantus-cli.
echo "[COPYRIGHT]" > footer.h2m
$RAVEND --version | sed -n '1!p' >> footer.h2m

for cmd in $RAVEND $RAVENCLI $RAVENTX $RAVENQT; do
  cmdname="${cmd##*/}"
  help2man -N --version-string=${ZELSVER[0]} --include=footer.h2m -o ${MANDIR}/${cmdname}.1 ${cmd}
  sed -i "s/\\\-${ZELSVER[1]}//g" ${MANDIR}/${cmdname}.1
done

rm -f footer.h2m
