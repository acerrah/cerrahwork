---
title: ssh
---
Port: 22

`SSH` stands for Secure Shell, and it is a cryptographic network protocol used for secure communication over a potentially unsecured network. SSH provides a secure channel between two devices, typically connecting a client (like your computer) to a server (a remote machine), allowing for secure remote access and command execution.

Here are some key aspects and common use cases of SSH:

1. **Secure Remote Access:**
   ```bash
   ssh username@remote-server
   ```
   This command initiates an SSH connection to a remote server, prompting the user to authenticate with a password or, preferably, an SSH key.

2. **Key-Based Authentication:**
   SSH supports key-based authentication, which is more secure than using passwords. Users generate a pair of cryptographic keys (public and private), and the public key is placed on the server. The private key remains on the user's machine, providing a secure means of authentication without transmitting passwords over the network.

3. **Secure File Transfer:**
   ```bash
   scp file.txt username@remote-server:/path/to/destination
   ```
   The Secure Copy Protocol (SCP) uses SSH for secure file transfer between a local and a remote host.

4. **Port Forwarding:**
   SSH supports port forwarding, allowing secure transmission of data between local and remote ports. This can be useful for securely accessing services on a remote machine.

5. **Tunneling:**
   SSH tunneling creates a secure connection between a local and a remote port, effectively encrypting the communication between the two. This can be used for various purposes, including accessing remote databases securely.

6. **Remote Command Execution:**
   ```bash
   ssh username@remote-server 'command'
   ```
   SSH allows users to execute commands on a remote server without the need for a full interactive session.

7. **Secure File Management:**
   SFTP (SSH File Transfer Protocol) allows secure file management on remote servers. Many file management tools support SFTP for secure file uploads and downloads.

SSH has become the standard for secure remote access and file transfer due to its strong encryption, authentication mechanisms, and versatility. It has largely replaced less secure protocols like [[telnet]] and unencrypted FTP for remote administration and data transfer.