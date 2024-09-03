
SSH tunneling is a powerful technique to transport network data securely over an encrypted SSH connection. It helps secure insecure protocols, bypass firewalls, and access internal network services from outside. There are three main types of SSH tunneling: static port forwarding, dynamic port forwarding, and reverse tunneling. Let’s delve into each of them with more detail and real-life examples.

## Static Port Forwarding

Static port forwarding, or local port forwarding, involves forwarding a specific port on your local machine to a specific port on a remote machine. This is useful when you need to access a service running on a remote server that is not directly accessible.

For example, you are at work and you want to acces your home computer through SSH. But your work network blocks the 22 port. You can use static port forwarding to use a different port to connect to your home computer.

### How to Do It

At the example above, you can use the following command to connect to your home computer. Just type this command in your work computer:

```bash
ssh -L [LOCAL_PORT]:[REMOTE_HOST]:[REMOTE_PORT] [USER]@[SSH_SERVER]
```

- `[LOCAL_PORT]`: The local port you're forwarding or simply the port you want to use in your work network.
- `[REMOTE_HOST]`: The remote host you want to connect to.
- `[REMOTE_PORT]`: The port that is blocked in your work network.
- `[USER]`: Your SSH server username.
- `[SSH_SERVER]`: The SSH server you're connecting to.

### Real-Life Example

Suppose you have a web server running on port 80 on a remote machine `example.com`, but it’s only accessible from within the internal network. You can access it from your local machine on port 8080 by running:

```sh
ssh -L 8080:example.com:80 user@ssh-server.com
```

After this, you can open your browser and go to `http://localhost:8080`, and it will display the website hosted on `example.com`.

## Dynamic Port Forwarding

Dynamic port forwarding is more flexible. It uses the SOCKS protocol to create a proxy server that can forward any port dynamically. This is useful when you need to tunnel traffic from various applications through an SSH connection.

### How to Do It

Here’s the command:

```sh
ssh -D [LOCAL_PORT] [USER]@[SSH_SERVER]
```

- `[LOCAL_PORT]`: The local port for your SOCKS proxy.
- `[USER]`: Your SSH username.
- `[SSH_SERVER]`: The SSH server you're connecting to.

### Real-Life Example

Let’s say you want to browse the internet securely from a public Wi-Fi network. You can set up a SOCKS proxy on your local machine with:

```sh
ssh -D 1080 user@ssh-server.com
```

Then, configure your web browser to use `localhost:1080` as a SOCKS proxy. All your browser traffic will be encrypted and tunneled through the SSH server.

## Reverse Tunneling

Reverse tunneling forwards a port from the remote machine to your local machine, allowing access to a local service from a remote machine. This is useful when you need to access a service on your local machine from a remote location.

### How to Do It

Here’s the command:

```sh
ssh -R [REMOTE_PORT]:[LOCAL_HOST]:[LOCAL_PORT] [USER]@[SSH_SERVER]
```

- `[REMOTE_PORT]`: The port on the remote machine.
- `[LOCAL_HOST]`: Your local host.
- `[LOCAL_PORT]`: The local port you want to connect to.
- `[USER]`: Your SSH username.
- `[SSH_SERVER]`: The SSH server you're connecting to.
