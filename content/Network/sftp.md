---
title: sftp
---
Port: 22

SFTP, or SSH File Transfer Protocol, is a secure file transfer protocol that operates over the Secure Shell (SSH) protocol. It provides encrypted communication for secure and reliable file transfers between a client and a server.

**How SFTP Works:**

1. **Secure Connection via SSH:**
   - SFTP operates over an SSH connection, ensuring secure authentication and encrypted data transmission. It uses the same port (typically 22) as SSH for communication.

2. **Authentication:**
   - Users authenticate themselves using SSH key pairs or a username/password combination. The authentication process is secured by the robust cryptographic mechanisms of SSH.

3. **Command and Data Channels:**
   - SFTP uses a single secure channel for both command and data transmission. This simplifies firewall configurations compared to FTP, which often requires separate channels.

4. **File Operations:**
   - SFTP supports various file operations, including uploading, downloading, renaming, deleting, and listing files and directories. The client can interact with the remote file system through a set of commands similar to those used in traditional FTP.

5. **Packet Encryption:**
   - All data transmitted over the SFTP connection, including file content and commands, is encrypted. This ensures the confidentiality and integrity of the transferred data.

6. **Binary and Text Modes:**
   - SFTP provides binary and text transfer modes similar to FTP. Binary mode ensures accurate transfer of non-text files, while text mode adjusts line endings to match the target system.

7. **Directory Listing:**
   - Unlike FTP, SFTP handles directory listings through a standardized protocol, avoiding the need for separate data connections.

8. **Firewall Friendliness:**
   - SFTP is firewall-friendly, as it requires only a single port (usually 22) for communication. This simplifies the configuration of firewalls and is advantageous in restrictive network environments.

9. **Platform Independence:**
   - SFTP is platform-independent, meaning it can be used to transfer files between different operating systems seamlessly.

SFTP is widely used for secure file transfers, especially in scenarios where data integrity and confidentiality are crucial. It is a preferred choice for system administrators, software developers, and organizations needing a secure and reliable method for exchanging files over networks.