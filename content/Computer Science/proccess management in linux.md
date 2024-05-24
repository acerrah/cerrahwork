### Understanding Process Management in Linux

Process management is a crucial aspect of Linux system administration. This guide will explain key concepts and commands for managing processes effectively in command line.

#### Viewing Processes with `ps`

The `ps` command is used to view information about processes running on a system. There are several options to customize the output but we will see only the most common one which is `ps aux`.

- **`ps aux`**: Displays all processes with detailed information in BSD format.

  - **`USER`**: The user who owns the process.
  - **`PID`**: Process ID.
  - **`%CPU`**: CPU usage.
  - **`%MEM`**: Memory usage.
  - **`VSZ`**: Virtual memory size.
  - **`RSS`**: Resident Set Size (physical memory used).
  - **`TTY`**: Terminal associated with the process.
  - **`STAT`**: Process status.
  - **`START`**: Time the process started.
  - **`TIME`**: CPU time consumed by the process.
  - **`COMMAND`**: Command that started the process.

You can also use [[top]] command to see the processes in real time. Check the [[top]] snippet for more information.

#### Changing Priority with `nice`

The `nice` command allows you to set the priority of a process. In Linux, the priority of a process determines how much CPU time it gets. Here's a summary:

- **Nice Values**: Range from -20 (highest priority) to 19 (lowest priority).

  - **High Nice Value**: Low priority.
  - **Low Nice Value**: High priority.

- **Permissions**:
  - Regular users can lower the priority (increase the nice value).
  - Only the superuser (root) can raise the priority (decrease the nice value).

**Example**:

```bash
$ nice -n 10 myprocess
```

This command starts `myprocess` with a nice value of 10, giving it lower priority.

#### Changing Priority with `renice`

The `renice` command changes the priority of an already running process.

- **Nice Values**: Absolute values between -20 and 19.
- **Requires PID**: You need the Process ID (PID) to change the priority.

**Example**:

```bash
$ renice -n 5 -p 1234
```

This command sets the nice value of the process with PID 1234 to 5. If you don't know the pid of the process you can use the proccess name.

**Example**:

```bash
$ renice -n 5 /bin/myprocess
```

- **Interactive `top` Adjustment**:
  - While running `top`, press `r` and enter the PID to change its nice value interactively.

#### Handling Zombie Processes

A zombie process is one that has completed execution but still has an entry in the process table. This typically occurs when the process's parent hasn't read its exit status.

- **Identifying Zombies**: In `top`, zombie processes are marked as `Z`.
- **Killing Processes**: You can use the `kill` command to terminate processes exhibiting unusual behavior or consuming too many resources.

#### Terminating Processes with `kill`

The `kill` command sends signals to processes, allowing you to manage them effectively. There are 64 signals available, but the most common ones are:

- **`SIGTERM` (15)**: Default signal sent by `kill`. Allows the process to clean up before termination.
- **`SIGKILL` (9)**: Forces the process to terminate immediately.
- **`SIGHUP` (1)**: Hangup signal, often used to restart processes.
- **`SIGINT` (2)**: Interrupt signal, typically sent by pressing `Ctrl+C`.
- **`SIGSTOP` (19)**: Stops the process.

**Example**:

```bash
$ kill -9 1234
```

This sends the `SIGKILL` signal to forcefully terminate the process with PID 1234.

If you don't know the pid of the process you can use killall command to kill the process by name.

**Example**:

```bash
$ killall -9 myprocess
```

You can use 'kill' command to send signals to processes. The default signal is `SIGTERM` (15) which allows the process to clean up before termination. If the process doesn't respond to `SIGTERM`, you can use `SIGKILL` (9) to force termination. These 2 signals are the ones you will use most of the time.

#### Running Processes in the Background

You can run processes in the background, which allows you to execute other commands while a task runs.

**Example**:

```bash
$ tar cvf wfiles.tar /usr/sbin/w* &
```

This command creates an archive `wfiles.tar` from files matching `/usr/sbin/w*` and runs it in the background.

- **Checking Background Jobs**:
  - Use `jobs` to list background jobs.
  - Use `bg` to resume a stopped job in the background.
  - Use `fg` to bring a background job to the foreground.

**Example**:

```bash
$ vi newfile.txt
```

While editing a file in `vi`, the background job continues. You can list files afterward to confirm `wfiles.tar` is created.

**Moving Background Processes to Foreground**:

This command brings the background job with PID 1234 to the foreground:

```bash
$ fg 1234
```

### Summary

- **Changing Priority**:

  - Use `nice` to start processes with a set priority.
  - Use `renice` to change the priority of running processes.
  - Only the root user can set higher priorities (negative nice values).

- **Handling Processes**:

  - Use `kill` to terminate processes.
  - Recognize and manage zombie processes.

- **Background Processes**:
  - Use `&` to run a process in the background.
  - Use `fg` and `bg` to manage background jobs.
