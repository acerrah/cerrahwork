---
title: linux file system tools
---
### Filesystem Tools and Commands

This guide explains several essential tools and commands for managing ext-based filesystems in Linux. Each tool has specific uses and functions that help in maintaining and troubleshooting filesystems. Also, this guide expects a basic understanding of filesystem concepts and Linux commands.

#### **1. fsck. Command**

**Purpose**: To fix filesystem issues.

- **Context**: A filesystem can become corrupt if the operating system is improperly shut down, such as due to a power outage.
- **Example Usage**: `fsck -y /dev/sda1`
  - This command checks and repairs the filesystem on `/dev/sda1`.

**Key Points**:
- Do not run `fsck` on live filesystems. Only unmounted or improperly unmounted filesystems should be checked.

#### **2. dumpe2fs Command**

**Purpose**: To display detailed information about ext-based filesystems.

- **Example Usage**: `dumpe2fs -h /dev/sda1`
  - This command shows information such as filesystem features, default mount options, inode count, reserved block count, and block size.

**Key Fields**:
- **Filesystem Features**: Determines capabilities (e.g., journaling).
- **Default Mount Options**: Specifies default options embedded in the filesystem.
- **Inode Count**: Indicates the maximum number of files.
- **Reserved Block Count**: Blocks reserved for the superuser.
- **Block Size**: Size of each block.

#### **3. tune2fs Command**

**Purpose**: To make changes to the filesystem parameters.

- **Example Usage**: `tune2fs -m 0 /dev/sdb1`
  - This command sets the percentage of the filesystem reserved for the superuser to 0%.

#### **4. debugfs Command**

**Purpose**: To debug filesystems in an interactive environment.

- **Example Usage**: `$ debugfs /dev/sda1`
  - Use this command to interactively debug an unmounted filesystem.

#### **5. fuser Command**

**Purpose**: To identify processes using a filesystem.

- **Example Usage**: `fuser /boot`
  - Reveals the PID of the process using `/boot` (e.g., `4148c`).

**Output Codes**:
- **c**: Current directory.
- **e**: Executable being run.
- **f**: Open file (omitted in default display).
- **F**: Open file for writing (omitted in default display).
- **r**: Root directory.
- **m**: mmap'ed file or shared library.

#### **6. Managing Filesystems with /etc/fstab**

**Purpose**: To automate filesystem mounting at boot.

- **Example Usage**: `$ more /etc/fstab`
  - Displays the content of the `/etc/fstab` file.

**Fields in /etc/fstab**:
- **device_to_mount**: Specifies the device.
- **mount_point**: Directory where the filesystem is mounted.
- **fs_type**: Type of filesystem.
- **mount_options**: Options for mounting.
- **dump_level**: Used by dump command.
- **fsck_value**: Determines the order in which filesystems are checked.

**Labeling Partitions**:
- **Creating a Label**: `e2label /dev/sdb1 data`
- **Using Label in /etc/fstab**:
  ```sh
  LABEL="data" /data ext4 defaults 0 1
  ```
- **Displaying Labels**: `e2label /dev/sda2` or `blkid | grep sda2`

#### **7. Mounting and Unmounting Filesystems**

**Manual Mounting**:
- **Example Usage**:
  ```sh
  # mount /dev/sda1 /boot
  # mount | grep /dev/sda1
  ```
  - Mounts `/dev/sda1` to `/boot` and verifies it.

**Unmounting**:
- **Example Usage**: `umount /dev/sda1`
  - Unmounts the filesystem on `/dev/sda1`.

**Common Issues**:
- Cannot unmount if a file is open, a process is running, or a user shell is in the directory.

**Key Options for `mount` Command**:
- **device**: Specifies the location of the filesystem.
- **mount_point**: Directory where the filesystem is mounted.
- **fs_type**: Type of filesystem.
- **mount_options**: Controls behavior (e.g., `rw` for read-write).

**Commands Overview**:
- **`df`**: Displays disk space usage.
  - Example: `$ df -h` (human-readable)
- **`du`**: Shows disk usage of files and directories.
  - Example: `$ du -sh /usr/lib` (summary in human-readable form)
