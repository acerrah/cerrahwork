---
title: scp
---
## What is SCP?

Let's say you need to transfer a file from one machine to another. You could use a USB drive, but that's not always convenient. You could also use a cloud service, but that's not always secure. Instead, you can use SCP, which stands for Secure Copy Protocol. SCP is a network protocol that allows you to securely transfer files between two machines over a network. It uses SSH (Secure Shell) to encrypt the data being transferred, so it's safe from prying eyes. SCP is a simple and secure way to transfer files between machines, and it's built into most Unix-like operating systems, including Linux and macOS.

## How to Use SCP

To use SCP, you need to have SSH installed on both machines. Once you have SSH installed, you can use SCP to transfer files between machines. Here's how it works:

1. If you are transferring a file from a local machine to a remote machine, use the following command:

```bash
scp file.txt username@remotehost:/path/to/destination
```

2. If you are transferring a file from a remote machine to a local machine, use the following command:

```bash
scp username@remotehost:/path/to/file.txt /path/to/destination
```

Is it the fastest way to transfer files? No. But is it a secure way to transfer files? Yes. Also I find it convenient to use. No need to install any additional software, no need for a USB drive, and no need for a cloud service. Just SCP.
