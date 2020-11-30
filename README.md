# AccessTSN Industrial Use Case Demo - CNC
This is a demonstration to give an example on how to use Linux with the current support for Time Sensitive Networking (TSN) as an industrial endpoint. For this purpose the components of this demonstration form a converged network use case in an industrial setting. 

The Use Case Demonstration is aimed at the AccessTSN Endpoint Image and is tested with but should also work independently from the image.

This work is a result of the AccessTSN-Project. More information on the project as well as contact information are on the project's webpage: https://accesstsn.com

## Structure of the Industrial Use Case Demo Git-projects

The AccessTSN Industrial Use Case Demo consists of multiple Git-projects, each holding the code to one component of the demonstration. This is the repository for the CNC control. It includes a module for Machinekit which writes control values from the Machinekit-HAL to a shared memory and the other way around. It also includes a setup for a 3-Axis mill as a demo machine. This setup is based on an example mill offered my LinuxCNC.

The main repository for AccessTSN Industrial Use Case Demo can be found on Github: https://github.com/iswunistuttgart/AccessTSN_Industrial_Use_Case_Demo


## Installation (Documentation is work in progress)

1. Install Machinekit-HAL
2. Install the LinuxCNC-EMC from the Machinekit Repository
3. Copy the _accesstsn.3axis_ subdirectory to the _linuxcnc/configs/_ subdirectory in your home directory
4. Compile and install the Machinekti-Component _accesstsnshm.comp_

