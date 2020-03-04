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
Link: https://www.qt.io/download 
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
sudo apt-get update
sudo apt-get install mosquitto
##### Mosquitto Client #####
sudo apt-get install mosquitto-clients

#### CoAP - Protocol ####
##### CoAPthon (implementation of CoAP Protocol in Python) #####
pip install CoAPthon<br/>
