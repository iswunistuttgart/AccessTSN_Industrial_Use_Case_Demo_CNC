#!/bin/bash
echo "Installation of CNC Component of the AccessTSN Industrial Use Case Demo"
echo "Checking for prerequisites"
which apt > /dev/null
rtn=$?
if [ $rtn -eq 0 ]
   then
      echo "apt found"
   else
      echo "Error: apt not found!"
      exit 1
fi
echo "Updating packed sources"
sudo apt update
which wget > /dev/null
rtn=$?
if [ $rtn -eq 0 ]
   then
      echo "wget found"
   else
      echo "Warning: wget not found; installing wget..."
      sudo apt install -y wget
fi

if [ -n "$DESKTOP_SESSION" ]
   then
      echo "Desktop session found"
   else
      echo "Warning: Desktop session not found; installing xfce4..."
      sudo apt install -y xfce4
fi

echo "Creating temporary folder"
if [ ! -d tmp_cnc ]
   then
      mkdir tmp_cnc
fi

echo "Get install packages for Machinekit and EMCApplication"
cd tmp_cnc
wget https://dl.cloudsmith.io/public/machinekit/machinekit-hal/deb/debian/pool/buster/main/m/ma/machinekit-hal_0.4.20868-1.gitca75c54aa~buster_amd64.deb
wget https://dl.cloudsmith.io/public/machinekit/machinekit-hal/deb/debian/pool/buster/main/m/ma/machinekit-hal-rt-preempt_0.4.20868-1.gitca75c54aa~buster_amd64.deb
wget https://dl.cloudsmith.io/public/machinekit/machinekit-hal/deb/debian/pool/buster/main/m/ma/machinekit-hal-dev_0.4.20868-1.gitca75c54aa~buster_amd64.deb
wget http://ftp.de.debian.org/debian/pool/main/p/pygtksourceview/python-gtksourceview2_2.10.1-3_amd64.deb
wget https://dl.cloudsmith.io/public/machinekit/emcapplication/deb/debian/pool/buster/main/e/em/emcapplication_2.9.0~pre0.23585.git42bf973af~buster_amd64.deb

echo "Installing packages"
sudo apt install -y ./machinekit-hal_0.4.20868-1.gitca75c54aa~buster_amd64.deb
sudo apt install -y ./machinekit-hal-dev_0.4.20868-1.gitca75c54aa~buster_amd64.deb
sudo apt install -y ./machinekit-hal-rt-preempt_0.4.20868-1.gitca75c54aa~buster_amd64.deb
sudo apt install -y ./python-gtksourceview2_2.10.1-3_amd64.deb
sudo apt install -y ./emcapplication_2.9.0~pre0.23585.git42bf973af~buster_amd64.deb


echo "cleanup temporary folder"
cd ..
rm -r tmp_cnc

echo "Copy AccessTSN 3Axis Demo Machine to LinuxCNC Configs"
if [ ! -d $1/accesstsn.3axis ]
   then
      echo "Demo configuration files not at specified location"
      exit 1
fi

if [ ! -d ~/linuxcnc/configs ]
   then
      echo "Linuxcnc configs directory missing, installation failed"
      exit 1
fi

cp -r $1/accesstsn.3axis ~/linuxcnc/configs/

echo "Compiling and installing  AccessTSN Machinkit Component"
if [ ! -f $1/accesstsnshm.comp ]
   then 
      echo "File: accesstsnshm.comp missing in specified directory"
fi
sudo comp --install $1/accesstsnshm.comp

echo "Finished Installation of CNC Component of the AccessTSN Industrial Use Case Demo sucessfully"
echo "Start the component using ’linuxcnc ~/linuxcnc/configs/accesstsn.3axis/accesstsn_3axis.ini"
exit 0
