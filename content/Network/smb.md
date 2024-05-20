---
title: smb
---
Port: 445

Server Message Block (SMB) is a network protocol used for file and printer sharing in a local area network (LAN) or across the internet. SMB operates at the application layer of the OSI model and facilitates communication between devices for resource sharing and communication.

**Key Characteristics of SMB:**

1. **File and Printer Sharing:**
   - SMB is primarily designed for sharing files, directories, and printers between networked computers. It allows users to access and manipulate files on remote servers as if they were local.

2. **Cross-Platform Support:**
   - SMB is a widely adopted protocol and is supported by various operating systems, including Windows, Linux, and macOS. This cross-platform compatibility enables seamless file sharing between devices running different operating systems.

3. **Versions:**
   - There are multiple versions of the SMB protocol, with each version introducing improvements in terms of security, performance, and features. Common SMB versions include SMB1, SMB2, SMB2.1, SMB3, and SMB3.1. The choice of version depends on the capabilities of the devices involved in file sharing.

4. **Authentication and Security:**
   - SMB supports various authentication mechanisms to ensure secure access to shared resources. Usernames and passwords are commonly used for authentication. SMB versions 2 and later include improvements in security features, such as encryption and better protection against certain types of attacks.

5. **Network Browsing:**
   - SMB supports network browsing, allowing users to discover and access shared resources on the network. This is often used in conjunction with the NetBIOS (Network Basic Input/Output System) protocol for name resolution.

6. **Workgroup and Domain Environments:**
   - SMB is commonly used in workgroup and domain environments. In a workgroup, devices share resources with each other, while in a domain, resources are centrally managed by a domain controller.

7. **Common Commands and Tools:**
   - Common commands and tools associated with SMB include:
     - `net use`: Command to connect or disconnect from a shared resource.
     - `smbclient`: A command-line tool for connecting to SMB/CIFS servers.
     - Windows File Explorer and macOS Finder: Graphical interfaces that support SMB for file browsing and sharing.

8. **CIFS (Common Internet File System):**
   - CIFS is an extension of the SMB protocol and is often used interchangeably with SMB. CIFS includes additional features and enhancements for compatibility with internet technologies.

SMB is a foundational protocol for file sharing in Windows-based networks and is widely used in mixed-platform environments. While it has been integral to local file sharing, newer technologies and protocols like [[nfs]] (Network File System) and cloud-based file-sharing services are becoming increasingly popular for broader network and internet file-sharing scenarios.