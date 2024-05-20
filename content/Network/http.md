---
title: http
---
Port: 80

HTTP, or Hypertext Transfer Protocol, is a fundamental protocol used for communication on the World Wide Web. It serves as the foundation for data communication on the internet, allowing for the transfer of text, images, files, and other resources between a client (typically a web browser) and a server.

**How HTTP Works:**

1. **Client-Server Interaction:**
     HTTP operates on a client-server model where a client (usually a web browser) sends requests to a server, and the server responds with the requested data.

2. **Stateless Protocol:**
     HTTP is stateless, meaning each request from a client to a server is independent and unrelated to previous requests. The server doesn't retain information about the client's previous interactions.

3. **Request-Response Cycle:**
     A client initiates communication by sending an HTTP request to a server. The request includes a method (GET, POST, etc.), a Uniform Resource Identifier (URI) specifying the resource, and additional headers.
     The server processes the request and sends back an HTTP response. The response includes a status code indicating the outcome (e.g., success, redirection, client error) and the requested data.

4. **Methods:**
    HTTP defines various request methods, including:
     - **GET:** Retrieve data from the server.
     - **POST:** Send data to the server to be processed.
     - **PUT:** Update a resource on the server.
     - **DELETE:** Remove a resource on the server.

5. **Headers:**
       HTTP headers provide additional information about the request or response. Common headers include:
     - **Content-Type:** Specifies the type of data being sent or received.
     - **Content-Length:** Indicates the size of the content in the message.

6. **Status Codes:**
       HTTP responses include status codes that indicate the result of the request. Examples include:
     - **200 OK:** The request was successful.
     - **404 Not Found:** The requested resource could not be found.
     - **500 Internal Server Error:** The server encountered an error.

7. **State Management:**
     While HTTP is stateless, developers often use mechanisms like cookies and sessions to maintain stateful interactions between a client and a server over multiple requests.

HTTP is a foundational protocol for the web, facilitating the transfer of information and resources between clients and servers. Over time, security enhancements like [[https]] (HTTP Secure) have been introduced to encrypt data during transmission, ensuring secure communication over the internet.