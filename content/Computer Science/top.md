---
title: top
---
### Understanding the `top` Command in Linux

The `top` command in Linux is a powerful utility for monitoring system performance and processes in real-time. Below is an analysis and explanation of the `top` command output and its usage, along with examples to help you understand and learn how to use it effectively.

#### Basic `top` Command Output

When you run the `top` command, you see a real-time summary of system performance. Here's a breakdown of what each section means:

```bash
top - 21:40:44 up  4:12,  1 user,  load average: 0.07, 0.05, 0.01
Tasks: 141 total,   1 running, 140 sleeping,   0 stopped,   0 zombie
%Cpu0  :  1.0 us,  0.0 sy,  0.0 ni, 99.0 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 st
GiB Mem :      1.9 total,      0.9 free,      0.5 used,      0.5 buff/cache
GiB Swap:      1.0 total,      1.0 free,      0.0 used.      1.2 avail Mem
```

1. **System Uptime and Load Average**:

   - **Time**: `21:40:44` - Current system time.
   - **Uptime**: `up 4:12` - The system has been running for 4 hours and 12 minutes.
   - **Users**: `1 user` - Number of users currently logged in.
   - **Load Average**: `0.07, 0.05, 0.01` - Average system load over the last 1, 5, and 15 minutes.

2. **Tasks**:

   - **Total**: `141 total` - Total number of tasks.
   - **Running**: `1 running` - Number of tasks currently running.
   - **Sleeping**: `140 sleeping` - Number of tasks sleeping.
   - **Stopped**: `0 stopped` - Number of tasks stopped.
   - **Zombie**: `0 zombie` - Number of zombie tasks.

3. **CPU Usage**:

   - **us**: `1.0 us` - User space processes (non-kernel).
   - **sy**: `0.0 sy` - System/kernel processes.
   - **ni**: `0.0 ni` - Processes with a manually set nice value.
   - **id**: `99.0 id` - Idle CPU time.
   - **wa**: `0.0 wa` - Waiting for I/O operations.
   - **hi**: `0.0 hi` - Handling hardware interrupts.
   - **si**: `0.0 si` - Handling software interrupts.
   - **st**: `0.0 st` - Time stolen by virtual machines (steal time).

4. **Memory Usage**:

   - **Total Memory**: `1.9 GiB total` - Total physical memory.
   - **Free Memory**: `0.9 GiB free` - Free memory.
   - **Used Memory**: `0.5 GiB used` - Used memory.
   - **Buffer/Cache**: `0.5 GiB buff/cache` - Memory used for buffers/cache.

5. **Swap Memory**:
   - **Total Swap**: `1.0 GiB total` - Total swap space.
   - **Free Swap**: `1.0 GiB free` - Free swap space.
   - **Used Swap**: `0.0 GiB used` - Used swap space.
   - **Available Memory**: `1.2 GiB avail Mem` - Available memory for processes.

#### Process List

Below the summary, `top` displays a list of running processes:

```bash
PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND
711 cerrah    20   0   15396   8916   7372 S   0.0   0.4   0:00.16 systemd
712 cerrah    20   0  101664   3032     24 S   0.0   0.1   0:00.00 (sd-pam)
```

- **PID**: Process ID.
- **USER**: Username of the process owner.
- **PR**: Priority of the process.
- **NI**: Nice value, which affects process scheduling.
- **VIRT**: Virtual memory used by the process.
- **RES**: Resident memory (physical memory) used by the process.
- **SHR**: Shared memory used by the process.
- **S**: Process status (e.g., S for sleeping, R for running).
- **%CPU**: CPU usage percentage.
- **%MEM**: Memory usage percentage.
- **TIME+**: Total CPU time used by the process.
- **COMMAND**: Command name or path of the executable.

#### Interactive Commands in `top`

You can interact with `top` to change its display and behavior using keyboard shortcuts. Here are some useful ones:

1. **Change Numeric Units**: Press `E`.

   - Toggles between kibibytes (KiB), mebibytes (MiB), gibibytes (GiB), etc.

   ```bash
   Press "E" to change units from KiB to MiB, GiB, etc.
   ```

2. **Change CPU Display**: Press `t`.

   - Toggles the CPU display format.

   ```bash
   Press "t" to change the CPU display format.
   ```

3. **Change Memory Display**: Press `m`.

   - Toggles the memory display format.

   ```bash
   Press "m" to change the memory display format.
   ```

4. **Highlight CPU Column**: Press `x`.

   - Highlights the CPU usage column.

   ```bash
   Press "x" to highlight the CPU usage column.
   ```

5. **Full Command Line**: Press `c`.

   - Toggles between showing the command name and full command line.

   ```bash
   Press "c" to show the full command line.
   ```

6. **Filter by User**: Press `u`.

   - Filters processes by a specific user.

   ```bash
   Press "u" and type the username to filter processes by that user.
   ```

7. **Number of Processes to Display**: Press `n`.

   - Sets the number of processes to display.

   ```bash
   Press "n" and enter the number of processes to display.
   ```

8. **Kill a Process**: Press `k`.

   - Prompts for a PID to kill.

   ```bash
   Press "k" and enter the PID of the process you want to kill.
   ```

By understanding these interactive commands and how to read the `top` command output, you can effectively monitor and manage your Linux system's performance and processes.
