---
title: nmap
---
  
The `nmap` utility, an abbreviation for "Network Mapper," serves as a potent open-source tool integral for network exploration and security assessments. Its primary function revolves around the identification of hosts and services within a computer network, essentially creating a comprehensive map of the network architecture. The operation of `nmap` involves the transmission of packets to designated target hosts, followed by a meticulous analysis of the ensuing responses.

Here are a few key applications of the `nmap` command:

1. **Host Discovery:**

``` bash
nmap -sn 192.168.1.0/24
```

  This command, employing a ping scan, endeavors to ascertain active hosts within the specified network, denoted here as the 192.168.1.0/24 subnet.

2. **Port Scanning:**

``` bash
nmap -p 1-100 192.168.1.1
```

  This particular command systematically scans ports 1 through 100 on the host identified by the IP address 192.168.1.1, facilitating the determination of open ports and the associated services.    
3. **Service Version Detection:**

```bash
nmap -sV 192.168.1.1
```

  This command, focused on service version detection, seeks to identify the specific versions of services operational on open ports.  
  
4. **OS Fingerprinting:**

``` bash
nmap -O 192.168.1.1
```
  
  In this instance, the command is designed to discern the operating system in use by the target host.
  
5. **Aggressive Scan:**
``` bash
nmap -A 192.168.1.1
```
  
  An aggressive scan, encompassing host discovery, port scanning, service version detection, and OS fingerprinting, is executed with this command.

6. **All Port Scanning:**
``` bash
 nmap -p- 192.168.1.1
```
  
  This command performs a scan of all 65,535 ports on the specified host, providing a comprehensive overview of open ports.