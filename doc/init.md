Sample init scripts and service configuration for zelantusd
==========================================================

Sample scripts and configuration files for systemd, Upstart and OpenRC
can be found in the contrib/init folder.

    contrib/init/zelantusd.service:    systemd service unit configuration
    contrib/init/zelantusd.openrc:     OpenRC compatible SysV style init script
    contrib/init/zelantusd.openrcconf: OpenRC conf.d file
    contrib/init/zelantusd.conf:       Upstart service configuration file
    contrib/init/zelantusd.init:       CentOS compatible SysV style init script

Service User
---------------------------------

All three Linux startup configurations assume the existence of a "zelantus" user
and group.  They must be created before attempting to use these scripts.
The OS X configuration assumes zelantusd will be set up for the current user.

Configuration
---------------------------------

At a bare minimum, zelantusd requires that the rpcpassword setting be set
when running as a daemon.  If the configuration file does not exist or this
setting is not set, zelantusd will shutdown promptly after startup.

This password does not have to be remembered or typed as it is mostly used
as a fixed token that zelantusd and client programs read from the configuration
file, however it is recommended that a strong and secure password be used
as this password is security critical to securing the wallet should the
wallet be enabled.

If zelantusd is run with the "-server" flag (set by default), and no rpcpassword is set,
it will use a special cookie file for authentication. The cookie is generated with random
content when the daemon starts, and deleted when it exits. Read access to this file
controls who can access it through RPC.

By default the cookie is stored in the data directory, but it's location can be overridden
with the option '-rpccookiefile'.

This allows for running zelantusd without having to do any manual configuration.

`conf`, `pid`, and `wallet` accept relative paths which are interpreted as
relative to the data directory. `wallet` *only* supports relative paths.

For an example configuration file that describes the configuration settings,
see `contrib/debian/examples/zelantus.conf`.

Paths
---------------------------------

### Linux

All three configurations assume several paths that might need to be adjusted.

Binary:              `/usr/bin/zelantusd`  
Configuration file:  `/etc/zelantus/zelantus.conf`  
Data directory:      `/var/lib/zelantusd`  
PID file:            `/var/run/zelantusd/zelantusd.pid` (OpenRC and Upstart) or `/var/lib/zelantusd/zelantusd.pid` (systemd)  
Lock file:           `/var/lock/subsys/zelantusd` (CentOS)  

The configuration file, PID directory (if applicable) and data directory
should all be owned by the zelantus user and group.  It is advised for security
reasons to make the configuration file and data directory only readable by the
zelantus user and group.  Access to zelantus-cli and other zelantusd rpc clients
can then be controlled by group membership.

### Mac OS X

Binary:              `/usr/local/bin/zelantusd`  
Configuration file:  `~/Library/Application Support/Zelantus/zelantus.conf`  
Data directory:      `~/Library/Application Support/Zelantus`  
Lock file:           `~/Library/Application Support/Zelantus/.lock`  

Installing Service Configuration
-----------------------------------

### systemd

Installing this .service file consists of just copying it to
/usr/lib/systemd/system directory, followed by the command
`systemctl daemon-reload` in order to update running systemd configuration.

To test, run `systemctl start zelantusd` and to enable for system startup run
`systemctl enable zelantusd`

### OpenRC

Rename zelantusd.openrc to zelantusd and drop it in /etc/init.d.  Double
check ownership and permissions and make it executable.  Test it with
`/etc/init.d/zelantusd start` and configure it to run on startup with
`rc-update add zelantusd`

### Upstart (for Debian/Ubuntu based distributions)

Drop zelantusd.conf in /etc/init.  Test by running `service zelantusd start`
it will automatically start on reboot.

NOTE: This script is incompatible with CentOS 5 and Amazon Linux 2014 as they
use old versions of Upstart and do not supply the start-stop-daemon utility.

### CentOS

Copy zelantusd.init to /etc/init.d/zelantusd. Test by running `service zelantusd start`.

Using this script, you can adjust the path and flags to the zelantusd program by
setting the RAVEND and FLAGS environment variables in the file
/etc/sysconfig/zelantusd. You can also use the DAEMONOPTS environment variable here.

### Mac OS X

Copy org.zelantus.zelantusd.plist into ~/Library/LaunchAgents. Load the launch agent by
running `launchctl load ~/Library/LaunchAgents/org.zelantus.zelantusd.plist`.

This Launch Agent will cause zelantusd to start whenever the user logs in.

NOTE: This approach is intended for those wanting to run zelantusd as the current user.
You will need to modify org.zelantus.zelantusd.plist if you intend to use it as a
Launch Daemon with a dedicated zelantus user.

Auto-respawn
-----------------------------------

Auto respawning is currently only configured for Upstart and systemd.
Reasonable defaults have been chosen but YMMV.
