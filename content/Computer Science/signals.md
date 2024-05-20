---
title: signals
---

# How does the proccess communicate with each other?

## Introduction

There is a program that is in a infinite loop and it needs to recieve _something_ from another program to stop the loop. The something is called a signal. The signal is a message that is sent from one program to another to notify that something has happened. The signal can be sent from the operating system or from another program or even from the user with input devices like keyboard or mouse. Let's create a simple example to understand how this communication can be done.

```c
//include librarys

void foo(){
// do something
}

int main(){
while(signalnotrecieved){
// do something
}
}
```

In the above code, the main function is in a infinite loop and it will only stop when the signal is recieved. The signal can be anything like a keyboard input or a signal from the operating system. But how it actually works? How the signal is sent and recieved? Let's dive into it.

## Signals

Signals are a way to send messages between many things such as kernel and user space, between processes, between threads, and between the kernel and hardware. Signals are a way to notify a process that a particular event has occured. The event can be anything like a user pressing a key, a process finishing its execution, or a hardware interrupt. But today we will only focus on the signals that are sent between processes.

We can send a signal by kill command. Don't let the name fool you, the kill command is not only used to send a signal. The syntax of the kill command is:

```c
kill(pid, signal);
```

Pid is the process id of the process to which the signal is to be sent. Signal is the signal that is to be sent. The signal is a number that represents the signal. For example, 9 represents the SIGKILL signal. The kill command can be used to send any signal to any process. But how the signal is recieved by the process? Let's see.

## Signal Handling

When a signal is sent to a process, the process needs to handle the signal. The process can handle the signal by using the signal function. The syntax of the signal function is:

```c
signal(signal, handler);
```

Signal is the signal that is to be handled. Handler is the function that is to be called when the signal is recieved. The handler function can be any function that takes an integer as an argument and returns void.

```c
void handler(int signal){
// do something
}
```

Now back to beginning example, we can modify the code to handle the signal.

```c
void handler(int signal){
// do something
}

int main(){
signal(SIGINT, handler);
while(1){
// do something
}
}
```

In the above code, the handler function is called when the SIGINT signal is recieved. The SIGINT signal is sent when the user presses the Ctrl+C key. When the user presses the Ctrl+C key, the handler function is called and the infinite loop is stopped until the handler function is finished. To understand this concept more clearly and more deeply you can watch the video below. It explains the concept in the lower level.

https://youtu.be/d0gS5TXarXc

If you were interested in this note, you should check the [[concurrency]] as well.
