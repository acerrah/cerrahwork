---
title: ftp
---
Port: 20, 21

FTP, or File Transfer Protocol, is a standard network protocol used for the transfer of files between a client and a server on a computer network. FTP operates on a client-server model, enabling users to upload and download files as well as perform other file-related operations.

**How FTP Works:**

1. **Client-Server Interaction:**
     FTP involves a client (user's device) and a server (remote machine) for file transfer. The client initiates requests, and the server responds accordingly.

2. **Two Modes of Operation:**
    - **Active Mode:** The client opens a random port for data transfer, and the server connects to that port. This mode can be challenging when the client is behind a firewall.
    - **Passive Mode:** The server opens a random port for data transfer, and the client connects to that port. Passive mode is often used to avoid firewall issues.

3. **Commands:**
    FTP uses a set of commands to perform various operations. Some common commands include:
     - **USER/PASS:** Authentication with a username and password.
     - **PWD:** Print the current working directory.
     - **CWD:** Change the working directory.
     - **LIST:** List the files in the current directory.
     - **GET:** Retrieve a file from the server.
     - **PUT:** Upload a file to the server.
     - **DELETE:** Delete a file on the server.

4. **Authentication:**
     Users typically need to authenticate themselves with a username and password to access the FTP server. Anonymous FTP allows users to log in with a default username (often "anonymous" or "ftp") and their email address as the password.

5. **Data Channels:**
     FTP uses two channels for communication:
     - **Command Channel:** Handles commands and responses between the client and server.
     - **Data Channel:** Handles the actual transfer of files.

6. **Modes of Data Transfer:**
    - **ASCII Mode:** Suitable for text files, as it converts line endings to match the target system.
    - **Binary Mode:** Used for non-text files to ensure accurate and secure transfer.

7. **Security Considerations:**
     FTP transmits data, including usernames and passwords, in plain text, making it vulnerable to eavesdropping. FTPS (FTP Secure) and SFTP (SSH File Transfer Protocol) are more secure alternatives that encrypt the data during transmission.

FTP has been widely used for decades, providing a simple and efficient way to transfer files between computers. However, due to security concerns associated with plain-text transmission, secure alternatives like [[ftps]] and [[sftp]] are often preferred for more sensitive data transfers.