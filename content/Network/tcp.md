---
title: tcp
---

TCP, or Transmission Control Protocol, is a fundamental building block of the Internet Protocol suite. It operates at the transport layer, providing a reliable and ordered communication service between devices over a network.

**How TCP Works:**

1. **Connection Establishment (Three-Way Handshake):**
   - **Step 1 - SYN (Synchronize):** The client initiates a connection by sending a TCP segment with the SYN flag set to the server.
   - **Step 2 - SYN-ACK (Synchronize-Acknowledge):** The server responds with a TCP segment acknowledging the SYN and sending its own SYN to the client.
   - **Step 3 - ACK (Acknowledge):** The client acknowledges the server's SYN, and the connection is established. Now both sides are synchronized.

2. **Data Transfer:**
   - Once the connection is established, data can be sent in both directions. Each segment of data includes a sequence number for ordering and acknowledgment to confirm receipt.
   - Flow control mechanisms prevent fast senders from overwhelming slower receivers.

3. **Acknowledgment and Retransmission:**
   - After receiving data, the receiver sends an acknowledgment (ACK) back to the sender, confirming the successful receipt.
   - If the sender doesn't receive an ACK within a specified time, it assumes the data was lost and retransmits it.

4. **Ordered Delivery:**
   - TCP ensures that data is delivered to the receiver in the same order it was sent. Sequence numbers are used to achieve ordered delivery.

5. **Connection Termination (Four-Way Handshake):**
   - **Step 1 - FIN (Finish):** One side initiates termination by sending a TCP segment with the FIN flag set.
   - **Step 2 - ACK:** The other side acknowledges the FIN.
   - **Step 3 - Second FIN:** The acknowledging side may also want to close the connection and sends its own FIN.
   - **Step 4 - Final ACK:** The initiator acknowledges the second FIN, and the connection is fully terminated.

TCP is commonly used for a wide range of applications on the internet, including web browsing ([[http]]), email (SMTP, POP3, IMAP), file transfers ([[ftp]]), and many other protocols. It is considered a reliable and robust protocol for applications that require assured and ordered delivery of data.