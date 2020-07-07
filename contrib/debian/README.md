
Debian
====================
This directory contains files used to package zelantusd/zelantus-qt
for Debian-based Linux systems. If you compile zelantusd/zelantus-qt yourself, there are some useful files here.

## zelantus: URI support ##


zelantus-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install zelantus-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your zelantus-qt binary to `/usr/bin`
and the `../../share/pixmaps/zelantus128.png` to `/usr/share/pixmaps`

zelantus-qt.protocol (KDE)

