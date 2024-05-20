---
title: ftps
---
Port:989, 990

FTPS, or FTP Secure, is an extension of the traditional [[ftp]] (File Transfer Protocol) that adds a layer of security through encryption. It employs either SSL (Secure Sockets Layer) or its successor, TLS (Transport Layer Security), to secure the data transmitted between the client and the server during file transfers.

**How FTPS Works:**

1. **Secure FTP Sessions:**
     FTPS operates over two secure channels: a command channel and a data channel. The command channel handles the authentication and commands, while the data channel is used for the actual file transfers.

2. **SSL/TLS Handshake:**
     During the initiation of an FTPS session, a secure handshake process occurs, similar to HTTPS. The client and server negotiate encryption parameters, exchange digital certificates, and establish a secure connection.

3. **Explicit and Implicit Modes:**
    - **Explicit Mode:** The client explicitly requests security by sending a command (such as "AUTH TLS" or "AUTH SSL") after connecting to the server.
    - **Implicit Mode:** Security is assumed from the beginning, with the client connecting to a dedicated port for secure FTP (typically port 990).

4. **Data Encryption:**
     Both the command and data channels in FTPS are encrypted, ensuring that sensitive information, including usernames, passwords, and file content, is protected from eavesdropping.

5. **Authentication:**
     Users typically authenticate themselves with a username and password, similar to traditional FTP. In addition to username/password authentication, FTPS can utilize client certificates for enhanced security.

6. **Port Configuration:**
     FTPS commonly uses port 21 for the command channel and port 990 for the data channel in Implicit mode. In Explicit mode, the data channel port is negotiated dynamically.

7. **Firewall Considerations:**
     FTPS can encounter firewall issues, especially in Passive mode. Properly configuring firewalls to allow secure data connections is essential for smooth FTPS operation.

FTPS is a secure alternative to traditional [[ftp]], providing encrypted communication to protect sensitive data during file transfers. It is commonly used in scenarios where secure and reliable file exchange is required, such as in corporate environments, data backup processes, and secure data sharing over networks.