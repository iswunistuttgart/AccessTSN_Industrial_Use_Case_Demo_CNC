# AccessTSN Industrial Use Case Demo - CNC
This is a demonstration to give an example on how to use Linux with the current support for Time Sensitive Networking (TSN) as an industrial endpoint. For this purpose the components of this demonstration form a converged network use case in an industrial setting. 

The Use Case Demonstration is aimed at the AccessTSN Endpoint Image and is tested with but should also work independently from the image.

This work is a result of the AccessTSN-Project. More information on the project as well as contact information are on the project's webpage: https://accesstsn.com

## Structure of the Industrial Use Case Demo Git-projects

The AccessTSN Industrial Use Case Demo consists of multiple Git-projects, each holding the code to one component of the demonstration. This is the repository for the CNC control. It includes a module for Machinekit which writes control values from the Machinekit-HAL to a shared memory and the other way around. It also includes a setup for a 3-Axis mill as a demo machine. This setup is based on an example mill offered my LinuxCNC.

The main repository for AccessTSN Industrial Use Case Demo can be found on Github: https://github.com/iswunistuttgart/AccessTSN_Industrial_Use_Case_Demo


## Installation
### Prerequisites
Currently only Debian or a debian derived Linux distribution is supported to run Machinekit and LinuxCNC. For correct execution and performance a real-time extension is also necessary. This project was tested with rt-preempt. It is recommended to use the AccessTSN Endpoint Image as a base. 

The supplied configuration for LinuxCNC, called "AccessTSN 3axis Demo machine" uses a graphical user interface. The AccessTSN Endpoint Image does not include support for GUIs or a window manager. This needs to be installed as prerequisite. To keep the setup lightweight the XFCE4 desktop environment is recommended. It can be installed using apt:  
```sudo apt install xfce4```

### Installation of Machinekit and LinuxCNC
1. Clone or download this project to the destination folder on your hard drive.
2. Install Machinekit-HAL for rt-preempt (and it's dependencies) either using the build package at https://cloudsmith.io/~machinekit/repos/machinekit-hal/packages/ or compile from source (https://github.com/machinekit/machinekit-hal)
3. Install the LinuxCNC-EMC from the Machinekit Repository (and it's dependencies) either using the build package at https://cloudsmith.io/~machinekit/repos/emcapplication/packages/ or compile from source (https://github.com/machinekit/EMCApplication). Make sure to use compatible versions of Machinekit-HAL and EMCApplication. Tests were conducted with Machinekit-HAL version _0.4.20868-1_ and EMCApplication version _pre0.23585_ installed from packages (https://dl.cloudsmith.io/public/machinekit/machinekit-hal/deb/debian/pool/buster/main/m/ma/machinekit-hal-rt-preempt_0.4.20868-1.gitca75c54aa~buster_amd64.deb and https://dl.cloudsmith.io/public/machinekit/emcapplication/deb/debian/pool/buster/main/e/em/emcapplication_2.9.0~pre0.23585.git42bf973af~buster_arm64.deb).
4. Copy the _accesstsn.3axis_ subdirectory to the _linuxcnc/configs/_ subdirectory in your home directory
5. Compile and install the Machinekit-Component _accesstsnshm.comp_  
   Change to this projects folder  
   Compile and install the AccessTSN-Machinekit-Component (this needs root privileges):  

   ```sudo comp --install accesstsnshm.comp```

## Starting the CNC application

The CNC Application can be started using the commandline. Either directly specify the AccessTSN 3Axis Demo Machine   
```linuxcnc ~/linuxcnc/accesstsn.3axis/accesstsn_3axis.ini```  
or start the CNC Application without arguments  
```linuxcnc ```  
and use the LinuxCNC Configuration Selector (GUI) to chose the AccessTSN 3Axis machine.

Note: It is not possible to run the CNC Application with root privileges.


