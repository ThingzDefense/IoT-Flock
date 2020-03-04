
# IoT-Flock #
IoT-Flock is an open-source tool for IoT traffic generation which supports the two widely used IoT
application layer protocols, i.e., MQTT and CoAP. IoT-Flock allows a user to create an IoT use case,
add customized IoT devices into it and generate normal and malicious IoT traffic over a real-time
network.
# Sponsors #
![](iril-mini.png)
![](kics_logo_png-mini.png)


# Uses #
* IoT-Flock allows a user to generate the detailed custom packets.
* IoT-Flock can also be used in stress testing of different IoT-based network utilities like switches, routers, etc., by generating a large amount of IoT device traffic.
* It can be used for the designing and testing of IoT security providing entities like IDS, IPS, etc.
* IoT-Flock can help the researchers in IoT Security Research. The researchers can easily build their own use case, model IoT devices into it and then generate & analyse the traffic of the use case in order to develop better security solutions for IoT.
* The Network Engineers can use IoT-Flock for benchmarking the network features and to troubleshoot the network problems.

# IoT Attacks included in IoT-Flock #
Currently, we included four recent IoT application layer vulnerability attacks in the IoT-Flock: 
* MQTT Packet Crafting Attack (CVE-2016-10523)
* MQTT Publish Flood (CVE-2018-1684)
* CoAP Segmentation Fault Attack (CVE-2019-12101) 
* CoAP Memory Leak Attack (CVE-2019-9004)

# How to Install & Use #
## 1) Install Dependencies ##
#### QT Creater ####
Link: https://www.qt.io/download <br/>
File Name used in project is: qt-opensource-linux-x64-5.12.3_2.run
#### Libtins ####
  sudo apt-get update -y
  sudo apt-get install -y libtins-dev
#### libcap ####
  sudo apt-get install libpcap-dev libssl-dev cmake
#### Boost ####
  sudo apt-get install libboost-all-dev
#### OpenGL ####
  sudo apt-get install mesa-utils
#### FreeGlut ####
  sudo apt-get install freeglut3-dev
#### QTCompiler ####
  sudo apt-get install qt5-default
#### Wireshark ####
sudo add-apt-repository ppa:wireshark-dev/stable<br/>
sudo apt-get update<br/>
sudo apt-get install wireshark<br/>
sudo wireshark<br/>

#### MQTT - Protocol ####
##### Mosquitto Broker #####
sudo apt-get update<br/>
sudo apt-get install mosquitto
##### Mosquitto Client #####
sudo apt-get install mosquitto-clients

#### CoAP - Protocol ####
##### CoAPthon (implementation of CoAP Protocol in Python) #####
pip install CoAPthon<br/>
<br/>Link for Code: https://github.com/Tanganelli/CoAPthon<br/>

## 2) Download the Source Code ##
Source Code is download from : https://github.com/ThingzDefense/IoT-Flock
## 3) Build the Source Code ##
import the 'IoTFlock' Project file into the QTCreator 5 as
![](pic6.png)<br/>
after successfully import the project file as below
![](pro-file.png)<br/>
click on the build-all from the build tab to successfuly build the code to the target system as<br/>
![](pic8.png)<br/>
after that click on Run Button to run the program as<br/>
![](pic9.png)<br/>
## 4) Add the Use Case ##
![](build-usecase.png)<br/>
after add new use case click on edit to add devices as
## 5) Add IoT Devices ##
![](iot-device-add.png)<br/>
then fill the fields of device attributes as<br/>
![](dev1.png)<br/>
![](mqtt.png)<br/>
then device successfully added<br/>
![](added-dev.png)<br/>
then save the device cong as XML as<br/>
![](export.png)<br/>
<br/>
## 5) Run the Use Case and Generate Use Case Traffic ##
### Command to Rune the xml File and gernerate the Traffic ###
<br/>
IoT-Flock-Binaries$ sudo ./IoTFlock-Console ./path of xml file/kitchencare.xml

Then the results is

![](run-xml.png)
----
## Publication ##
https://www.kics.edu.pk/labs/about/iril 
****
##### Powered by: #####
![](iril-logo.png)
