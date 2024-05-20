---
title: https
---
Port: 443

**HTTPS**, or Hypertext Transfer Protocol Secure, is an extension of [[http]] designed to provide secure communication over a computer network. It adds a layer of encryption to the standard [[http]], making it more resistant to eavesdropping and tampering of data during transmission.

**How HTTPS Works:**

1. **Encryption (SSL/TLS):**
     HTTPS employs cryptographic protocols, typically SSL (Secure Sockets Layer) or its successor, TLS (Transport Layer Security), to encrypt data during transmission.
     Encryption ensures that the information exchanged between the client (browser) and the server remains confidential and secure from unauthorized access.

2. **Secure Handshake (SSL/TLS Handshake):**
     During the initial connection setup, a process known as the SSL/TLS handshake takes place.
     The client and server exchange information, including supported encryption algorithms and cryptographic keys, to establish a secure connection.

3. **Secure Data Transmission:**
     Once the secure connection is established, data exchanged between the client and server is encrypted. This includes HTTP requests and responses, ensuring the confidentiality and integrity of the transmitted information.

4. **Certificates and Public Key Infrastructure (PKI):**
     HTTPS relies on digital certificates issued by Certificate Authorities (CAs). These certificates validate the authenticity of the server.
     The server presents its digital certificate during the SSL/TLS handshake, and the client verifies it against a list of trusted CAs to ensure the server's legitimacy.

5. **URL Scheme and Port:**
     URLs using HTTPS have a different scheme (https://) compared to standard HTTP (http://), indicating a secure connection.
     While HTTP typically uses port 80, HTTPS uses port 443 by default.

6. **Benefits:**
    - **Data Integrity:** HTTPS ensures that data remains unchanged during transmission.
    - **Authentication:** Certificates verify the identity of the server, preventing man-in-the-middle attacks.
    - **Confidentiality:** Encryption protects sensitive information from being intercepted.

7. **Mixed Content:**
     Browsers may display a security warning if a webpage served over HTTPS includes resources (like images or scripts) loaded over unsecured HTTP. It's best to ensure that all resources are served securely.

HTTPS is crucial for securing sensitive information, such as login credentials and payment details, exchanged between users and websites. It has become a standard for secure communication on the internet, particularly for e-commerce, online banking, and other applications where data privacy and security are paramount.