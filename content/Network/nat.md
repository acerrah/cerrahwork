---
title: nat
---

# Network Address Translation

Before we dive into Network Address Translation (NAT), you need to understand the concept of IP addresses and the difference between public and private IP addresses. You can refer to the [[IPv4]] guide for a detailed explanation of IP addresses. But here's a quick overview:

- **IP Addresses:**

  - IP addresses are numerical labels assigned to devices on a network to identify and communicate with each other. They are essential for routing data packets across networks.
  - IPv4 addresses are 32-bit numerical labels, typically expressed in dotted-decimal format of four octets (x.x.x.x), where each octet represents 8 bits.

  IPv4 addresses are almost 4.3 billion unique addresses, which has led to address exhaustion concerns. 4.3 billion addresses may seem like a lot, but with the proliferation of devices and the growth of the Internet, this number is insufficient. This is where NAT comes into play. But before we get into NAT, let's understand the difference between public and private IP addresses.

- **Public IP Addresses:**
  Public IP addresses are globally unique and routable on the Internet. They are assigned by regional Internet registries (such as ARIN, RIPE, APNIC) and are used to identify devices directly connected to the Internet.

  Because of the limited number of public IPv4 addresses, not every device can have a unique public IP address.

- **Private IP Addresses:**
  Private IP addresses are reserved for use within private networks and are not routable on the public Internet. Basically, these addresses are used within a local network to identify devices and communicate with each other. Every local network can use the same private IP address ranges without conflict because they are not globally unique. The most commonly used private IP address ranges are:
  192.168.x.x
  172.16.x.x - 172.31.x.x
  10.x.x.x

Now that you understand the concept of public and private IP addresses, let's dive into Network Address Translation (NAT).

## What is NAT?

Network Address Translation (NAT) is a process used to modify network address information in the IP header of packets while they are in transit across a network. NAT allows multiple devices within a private network to share a single public IP address to access the Internet. It is commonly used in home and office networks to conserve public IP addresses and provide an additional layer of security.

NAT operates at the network layer (Layer 3) of the OSI model and can be implemented in various ways, such as:

- **Static NAT:** Maps a private IP address to a public IP address on a one-to-one basis. This is useful when a device within a private network needs to be accessible from the public Internet.

- **Dynamic NAT:** Maps multiple private IP addresses to a pool of public IP addresses. This allows multiple devices within a private network to share a limited number of public IP addresses.

- **Port Address Translation (PAT):** Also known as NAT Overload, PAT maps multiple private IP addresses to a single public IP address by using different source port numbers. This is the most common form of NAT used in home and office networks.

There are also different types of NAT, that are used to change between Ipv4 and Ipv6 addresses but we will not cover them in this guide. Check out the [[IPv6]] guide for more information on Ipv6 addresses.
