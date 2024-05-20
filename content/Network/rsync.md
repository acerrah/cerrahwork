---
title: rsync
---

`rsync` is a powerful and widely used command-line utility for efficiently copying and synchronizing files and directories between two locations, either on the same machine or over a network. It is particularly popular for its ability to perform incremental backups and transfers, only copying the differences between source and destination to minimize data transfer.

**Key Features of rsync:**

1. **Efficient File Copying:**
   - rsync copies only the differences between source and destination files, reducing the amount of data transferred and making it highly efficient for large datasets.

2. **Support for Copying Over SSH:**
   - rsync can securely copy files over SSH, providing encrypted communication for data transfer. This makes it suitable for remote file synchronization.

3. **Incremental Backups:**
   - rsync is often used for creating incremental backups. It can copy only the changes made to files since the last backup, saving time and bandwidth.

4. **Preservation of File Metadata:**
   - rsync preserves file metadata such as timestamps, permissions, and ownership during the copying process. This ensures that the copied files maintain their original attributes.

5. **Resume Interrupted Transfers:**
   - If a file transfer is interrupted, rsync can resume from where it left off, thanks to its efficient delta-transfer algorithm.

6. **Cross-Platform Support:**
   - rsync is available on various Unix-like operating systems, including Linux and macOS. There are also ports and third-party versions for Windows.

7. **Filtering and Exclusion:**
   - rsync provides options for including or excluding files based on patterns or filters. This allows users to customize the files and directories to be included in the synchronization process.

8. **Bandwidth Limitation:**
   - Users can control the bandwidth used by rsync during data transfer, ensuring that other network activities are not adversely affected.

9. **Dry Run (Simulation):**
   - rsync can perform a dry run to simulate the synchronization process without actually making any changes. This is useful for previewing the changes that will be made.

**Basic Usage:**

The basic syntax of rsync is as follows:

```bash
rsync [options] source destination
```

**Example Commands:**

1. **Copy files from one directory to another:**
   ```bash
   rsync -av /path/to/source/ /path/to/destination/
   ```

2. **Copy files over SSH:**
   ```bash
   rsync -av -e ssh user@remote:/path/to/source/ /path/to/destination/
   ```

3. **Incremental Backup:**
   ```bash
   rsync -av --backup --backup-dir=/path/to/backup/ /path/to/source/ /path/to/destination/
   ```

4. **Dry Run (Simulation):**
   ```bash
   rsync -av --dry-run /path/to/source/ /path/to/destination/
   ```

rsync provides a multitude of options and configurations, allowing users to tailor the synchronization process to their specific needs. For more detailed information and a comprehensive list of options, refer to the rsync manual (`man rsync`) or online documentation.