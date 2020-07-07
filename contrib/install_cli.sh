 #!/usr/bin/env bash

 # Execute this file to install the zelantus cli tools into your path on OS X

 CURRENT_LOC="$( cd "$(dirname "$0")" ; pwd -P )"
 LOCATION=${CURRENT_LOC%Zelantus-Qt.app*}

 # Ensure that the directory to symlink to exists
 sudo mkdir -p /usr/local/bin

 # Create symlinks to the cli tools
 sudo ln -s ${LOCATION}/Zelantus-Qt.app/Contents/MacOS/zelantusd /usr/local/bin/zelantusd
 sudo ln -s ${LOCATION}/Zelantus-Qt.app/Contents/MacOS/zelantus-cli /usr/local/bin/zelantus-cli
