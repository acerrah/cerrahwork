---
title: telnet
---
Port: 23

`Telnet` is a network protocol and a command-line tool that allows for communication with another computer or server over a TCP/IP network. It is often used for testing and troubleshooting network connectivity, as well as for remotely accessing and managing devices.

Here are some common uses of the `telnet` command:

1. **Checking Connectivity:**
   ```bash
   telnet example.com 80
   ```
  
   This command attempts to establish a TCP connection to the specified host (in this case, "example.com") on port 80. If successful, it indicates that there is connectivity to the destination on the specified port.

2. **Remote Access:**
   ```bash
   telnet remote-server
   ```
   
   This command opens a telnet session to a remote server, allowing you to log in and interact with the remote system's command line. However, note that telnet is not secure, and it transmits data, including login credentials, in plaintext, making it less secure than alternatives like [[ssh]].

3. **Testing SMTP Servers:**
   ```bash
   telnet mail.example.com 25
   ```
   
   This is often used to test Simple Mail Transfer Protocol (SMTP) servers. By connecting to the SMTP server on port 25, you can manually interact with the server and send email commands.

4. **HTTP Header Inspection:**
   ```bash
   telnet example.com 80
   GET / HTTP/1.1
   Host: example.com
   ```
   
   You can use telnet to manually send HTTP requests and inspect the headers. This example initiates a basic HTTP GET request.

While `telnet` is a useful tool for certain purposes, it has security drawbacks, as it transmits data in an unencrypted form. For secure remote access, it is recommended to use alternatives such as [[ssh]] (Secure Shell). Additionally, many modern services and protocols have moved away from using telnet in favor of more secure alternatives.