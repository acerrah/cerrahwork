---
title: IPv4
---
	
IPv4, or Internet Protocol Version 4, is the fourth version of the Internet Protocol, which is the set of rules governing how data is sent and received over the Internet. IPv4 is a foundational protocol of the Internet and is used to identify and locate devices on a network.

**Key Characteristics of IPv4:**

1. **Address Format:**
    - IPv4 addresses are 32-bit numerical labels, typically expressed in dotted-decimal format (e.g., 192.168.0.1). Each segment of the address represents 8 bits, allowing for a total of approximately 4.3 billion unique addresses.

2. **32-Bit Address Space:**
    - The 32-bit address space of IPv4 results in a limited number of unique addresses. With the growth of the Internet and the increasing number of connected devices, IPv4 address exhaustion has become a significant concern.

3. **Binary and Dotted-Decimal Notation:**
    - In binary, an IPv4 address looks like a sequence of 32 zeros and ones. Dotted-decimal notation breaks this binary sequence into four 8-bit segments and represents each segment in decimal form.
    
    Let's consider the IPv4 address `192.168.1.100`.
    
    In binary, this address is represented as:
    ```
    11000000.10101000.00000001.01100100
    ```
    
    Now, let's break it into four octets and convert it back to decimal notation:
    - Octet 1: `11000000` in binary is `192` in decimal.
    - Octet 2: `10101000` in binary is `168` in decimal.
    - Octet 3: `00000001` in binary is `1` in decimal.
    - Octet 4: `01100100` in binary is `100` in decimal.

1. **Subnetting:**
    - IPv4 allows for the subdivision of networks into smaller, more manageable units known as subnets. Subnetting helps in optimizing network performance and managing address allocation efficiently.
    Let's say we have the IP address `192.168.1.0` and we want to create subnets to accommodate different departments in an organization.
    
    - Subnet 1: `192.168.1.0/26`
      - This subnet includes IP addresses from `192.168.1.1` to `192.168.1.62` (with `192.168.1.63` reserved for broadcast).
     - Subnet 2: `192.168.1.64/26`
       - This subnet includes IP addresses from `192.168.1.65` to `192.168.1.126` (with `192.168.1.127` reserved for broadcast).
       
      In each subnet, the last 6 bits of the host portion are available for devices (2^6 = 64 hosts per subnet). This is an example of subnetting for more efficient use of IP addresses.


2. **Public and Private IP Addresses:**
    - IPv4 addresses are categorized as public or private. Public addresses are globally unique and routable on the Internet, while private addresses are reserved for use within private networks.
    
    **Public Addresses:**
      Public IP addresses are routable on the global Internet and are used to identify devices directly connected to the Internet.
      
      These addresses are assigned by regional Internet registries (such as ARIN, RIPE, APNIC) and are globally unique.
      
      Examples of public IP address ranges include:
      - Class A: 1.0.0.0 to 126.255.255.255
      - Class B: 128.0.0.0 to 191.255.255.255
      - Class C: 192.0.0.0 to 223.255.255.255
      
    **Private Addresses:**
      Private IP addresses are reserved for use within private networks and are not routable on the public Internet.
      
      They are defined in RFC 1918 and include three ranges:
      - Class A: 10.0.0.0 to 10.255.255.255
      - Class B: 172.16.0.0 to 172.31.255.255
      - Class C: 192.168.0.0 to 192.168.255.255
      
      Devices within a private network can use these addresses, and routers perform Network Address Translation (NAT) to allow these devices to communicate with the public Internet using a single public IP address.
    
    Understanding public and private addresses is crucial for network administrators when designing and managing networks, especially when dealing with issues like NAT, subnetting, and security.

3. **Classful and Classless Addressing:**
    - IPv4 initially followed a classful addressing scheme (Class A, B, C, D, E), but due to inefficiencies, Classless Inter-Domain Routing (CIDR) was introduced to allow more flexible allocation of IP addresses.

4. **Network Classes:**
    - IPv4 addresses were traditionally divided into different classes (A, B, C) based on the size of the network they could support. CIDR eliminated the strict boundaries between these classes.

5. **Protocol Stack:**
    - IPv4 operates at the network layer of the OSI model and is an integral part of the TCP/IP protocol stack. It is responsible for addressing, routing, and fragmenting and reassembling packets.

6. **IPv6 Transition:**
    - The limitations of IPv4 address space led to the development of [[IPv6]] (Internet Protocol Version 6), which uses a 128-bit address format and provides an immensely larger number of unique addresses.

Despite the widespread use of IPv4, the growing number of connected devices and the increasing demand for unique addresses have led to the adoption of [[IPv6]] as the long-term solution to address exhaustion. [[IPv6]] provides a significantly larger address space and is designed to replace IPv4 gradually.
