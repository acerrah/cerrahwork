---
title: server monitor script
---

Let's say we have a server that we want to monitor. We want to know how much CPU, memory, and disk space it is using. And if it is using too much, we want to be able to take action to fix it.

To do this, we will write a script that will run on the server and collect this information. The script will then send this information using telegrams api to a telegram bot. The bot will then send us a message if the server is using too much resources.

To create the script, first we need to get CPU load, memory usage, and disk space usage. Let's start with CPU load.

To get the CPU load we can use 'uptime' command. This command will give us the load average for the past 1, 5, and 15 minutes.

```bash
    $ uptime
     22:19:52 up 1 day, 11:30,  1 user,  load average: 0.00, 0.05, 0.02
```

As you can see, the load average is 0.00, 0.05, and 0.02 for the past 1, 5, and 15 minutes respectively. But we only need the load average for the past 1 minute. So we can use 'awk' command to extract this information.

```bash
    $ uptime | awk -F, '{print $4}' | awk -F" " '{print $3}'
    0.02
```

Great! Now we have the CPU load. Next, let's get the memory usage.

To get the memory usage we can use 'free' command. This command will give us the total memory, used memory, free memory, and the memory used by buffers/cache.

```bash
    $ free -m
               total        used        free      shared  buff/cache   available
Mem:        16209268     1922796    13212468       56624     1485548    14286472
Swap:        8388604           0     8388604
```

As you can see, the used memory is 1922796 MB. To get the 'Mem:' line only, we can use 'grep' command. And to get the used memory, we can use 'awk' command.

```bash
    $ free -m | grep Mem | awk '{print $3}'
    1922796
```

That's it! Now we have the memory usage. But wait a minute! The memory usage is in MB. We need to convert it to percentage. To do this, we can use 'awk' command again.

```bash
    $ free -m | grep Mem | awk '{print $3/$2 * 100}'
    11.86
```

Now that's better! We have the memory usage in percentage. Finally, let's get the disk space usage.

To get the disk space usage we can use 'df' command. This command will give us the total disk space, used disk space, and free disk space. '-h' option will give us the output in human readable format.
```bash
    $  df -h
   Filesystem            Size  Used Avail Use% Mounted on
   udev                  7.7G     0  7.7G   0% /dev
   tmpfs                 1.6G  1.4M  1.6G   1% /run
   /dev/mapper/pve-root   94G   11G   79G  12% /
   tmpfs                 7.8G   49M  7.7G   1% /dev/shm
   tmpfs                 5.0M     0  5.0M   0% /run/lock
   efivarfs              448K   52K  392K  12% /sys/firmware/efi/efivars
   /dev/nvme0n1p2       1022M   12M 1011M   2% /boot/efi
   /dev/fuse             128M   16K  128M   1% /etc/pve
   tmpfs                 1.6G     0  1.6G   0% /run/user/0
```

That might be a little overwhelming. Don't worry! It is looking bad because the example server that I use is my Proxmox server and it has a lot of partitions. But we only need the disk space usage for the root partition. Whatever the root partition is, it will be mounted on '/'. So we can use 'df' command with '/' as an argument to get the disk space usage for the root partition.

```bash
    $ df -h /
            Filesystem      Size  Used Avail Use% Mounted on
    /dev/mapper/pve-root   94G   11G   79G  12% /
```

As you can see the root partition has 94G total disk space, 11G used disk space, and 79G free disk space. To get the used disk space in percentage, we can use 'awk' command again.

```bash
    $ df -h / | awk '{print $5}'
    12%
```

Now we cooking! We have the disk space usage in percentage as well. Now that we have all the information we need, let's send this information to a telegram bot.

To send the information to a telegram bot, we need to use telegrams api. First, we create a telegram bot by talking to the 'BotFather'. Then we get the bot token. We will use this token to interact with the bot.

Secondly, we need to get the chat id of the user that we want to send the message to. To do this, we can use the 'getUpdates' method of the telegram api. This method will give us the chat id of the user that we want to send the message to. First text a message to the bot, then run the following command to get the chat id.

```bash
    $ curl -s "https://api.telegram.org/bot<bot_token>/getUpdates"
```

Don't forget to change the <bot_token> with your bot token. Now that we have the bot token and the chat id, we can send the message to the bot using the 'sendMessage' method of the telegram api.

```bash
    $ message="CPU Load: $(uptime | awk -F, '{print $4}' | awk -F" " '{print $3}')\nMemory Usage: $(free -m | grep Mem | awk '{print $3/$2 * 100}')%\nDisk Space Usage: $(df -h / | awk '{print $5}')"
    $ curl -s -X POST "https://api.telegram.org/bot<bot_token>/sendMessage" -d "chat_id=<chat_id>&text=$message"
```

Now we have a script that sends the CPU load, memory usage, and disk space usage to a telegram bot. But firstly we don't want to see the message if the CPU load, memory usage, and disk space usage are below a certain threshold. So we can add a condition to the script to check if the CPU load, memory usage, and disk space usage are above the threshold. If they are above the threshold, then we send the message to the bot.

```bash
    #!/bin/bash

    cpu_load=$(uptime | awk -F, '{print $4}' | awk -F" " '{print $3}')
    memory_usage=$(free -m | grep Mem | awk '{print $3/$2 * 100}')
    disk_space_usage=$(df -h / | grep '/' | awk '{print $5}' | tr -d '%')

    cpu_check=$(echo "$cpu_load > 6.0" | bc -l)
    memory_check=$(echo "$memory_usage > 80" | bc -l)
    disk_check=$(echo "$disk_space_usage > 80" | bc -l)

    if [ "$cpu_check" -eq 1 ] || [ "$memory_check" -eq 1 ] || [ "$disk_check" -eq 1 ]; then
        message="CPU Load: $cpu_load Memory Usage: $memory_usage% Disk Space Usage: $disk_space_usage%"
        curl -s -X POST "https://api.telegram.org/bot<bot_token>/sendMessage" -d "chat_id=<chat_id>&text=$message"
    fi
```

Secondly we don't want to run this script manually. We want to run this script automatically. To do this, we can use 'cron'. 'Cron' is a time-based job scheduler in Unix-like operating systems. We can use 'cron' to run the script every 5 minutes.

To add a job to 'cron', we can use 'crontab -e' command. This command will open the 'crontab' file in the default text editor. We can add the following line to the 'crontab' file to run the script every 5 minutes.

```bash
    */5 * * * * /path/to/script.sh
```

Now we have a script that sends the CPU load, memory usage, and disk space usage to a telegram bot every 5 minutes. We can use this script to monitor the server and get notified if the CPU load, memory usage, and disk space usage are above a certain threshold. If you don't want to see all the information, but the one that is above the threshold. You can split the code into three if blocks.


```bash
    #!/bin/bash

    cpu_load=$(uptime | awk -F, '{print $4}' | awk -F" " '{print $3}')
    memory_usage=$(free -m | grep Mem | awk '{print $3/$2 * 100}')
    disk_space_usage=$(df -h / | grep '/' | awk '{print $5}' | tr -d '%')

    cpu_check=$(echo "$cpu_load > 6.0" | bc -l)
    memory_check=$(echo "$memory_usage > 80" | bc -l)
    disk_check=$(echo "$disk_space_usage > 80" | bc -l)

    if [ "$cpu_check" -eq 1 ]; then
        message="Warning CPU Load: $cpu_load"
        curl -s -X POST "https://api.telegram.org/bot<bot_token>/sendMessage" -d "chat_id=<chat_id>&text=$message"
    fi

    if [ "$memory_check" -eq 1 ]; then
        message="Warning Memory Usage: $memory_usage%"
        curl -s -X POST "https://api.telegram.org/bot<bot_token>/sendMessage" -d "chat_id=<chat_id>&text=$message"
    fi

    if [ "$disk_check" -eq 1 ]; then
        message="Warning Disk Space Usage: $disk_space_usage%"
        curl -s -X POST "https://api.telegram.org/bot<bot_token>/sendMessage" -d "chat_id=<chat_id>&text=$message"
    fi
```

Okay, much better now. But let's say if it went over the threshold I got a message every 5 minutes. That's a bit annoying. To solve this problem let's change the code so it sends message if a value goes above the threshold and sends another one if it goes back below the threshold. To do this we need to keep the previous state of the values. We can use a file to keep the previous state of the values. We can write the current state of the values to the file and read the previous state of the values from the file. If the current state of the values is above the threshold and the previous state of the values is below the threshold, then we send a message to the bot. If the current state of the values is below the threshold and the previous state of the values is above the threshold, then we send another message to the bot.

```bash
    #!/bin/bash

    cpu_load=$(uptime | awk -F, '{print $4}' | awk -F" " '{print $3}')
    memory_usage=$(free -m | grep Mem | awk '{print $3/$2 * 100}')
    disk_space_usage=$(df -h / | grep '/' | awk '{print $5}' | tr -d '%')

    cpu_check=$(echo "$cpu_load > 6.0" | bc -l)
    memory_check=$(echo "$memory_usage > 80" | bc -l)
    disk_check=$(echo "$disk_space_usage > 80" | bc -l)

    if [ -f /tmp/cpu_state ]; then
        cpu_state=$(cat /tmp/cpu_state)
    else
        cpu_state=0
    fi

    if [ -f /tmp/memory_state ]; then
        memory_state=$(cat /tmp/memory_state)
    else
        memory_state=0
    fi

    if [ -f /tmp/disk_state ]; then
        disk_state=$(cat /tmp/disk_state)
    else
        disk_state=0
    fi

    if [ "$cpu_check" -eq 1 ] && [ "$cpu_state" -eq 0 ]; then
        message="Warning CPU Load: $cpu_load"
        curl -s -X POST "https://api.telegram.org/bot<bot_token>/sendMessage" -d "chat_id=<chat_id>&text=$message"
        echo 1 > /tmp/cpu_state
    fi

    if [ "$cpu_check" -eq 0 ] && [ "$cpu_state" -eq 1 ]; then
        message="CPU Load: $cpu_load"
        curl -s -X POST "https://api.telegram.org/bot<bot_token>/sendMessage" -d "chat_id=<chat_id>&text=$message"
        echo 0 > /tmp/cpu_state
    fi

    if [ "$memory_check" -eq 1 ] && [ "$memory_state" -eq 0 ]; then
        message="Warning Memory Usage: $memory_usage%"
        curl -s -X POST "https://api.telegram.org/bot<bot_token>/sendMessage" -d "chat_id=<chat_id>&text=$message"
        echo 1 > /tmp/memory_state
    fi

    if [ "$memory_check" -eq 0 ] && [ "$memory_state" -eq 1 ]; then
        message="Memory Usage: $memory_usage%"
        curl -s -X POST "https://api.telegram.org/bot<bot_token>/sendMessage" -d "chat_id=<chat_id>&text=$message"
        echo 0 > /tmp/memory_state
    fi

    if [ "$disk_check" -eq 1 ] && [ "$disk_state" -eq 0 ]; then
        message="Warning Disk Space Usage: $disk_space_usage%"
        curl -s -X POST "https://api.telegram.org/bot<bot_token>/sendMessage" -d "chat_id=<chat_id>&text=$message"
        echo 1 > /tmp/disk_state
    fi

    if [ "$disk_check" -eq 0 ] && [ "$disk_state" -eq 1 ]; then
        message="Disk Space Usage: $disk_space_usage%"
        curl -s -X POST "https://api.telegram.org/bot<bot_token>/sendMessage" -d "chat_id=<chat_id>&text=$message"
        echo 0 > /tmp/disk_state
    fi
 ```

Much better am I right? Just keep that in mind I didn't test the code. I just wrote it. So you may need to make some changes.

If you have anything to ask or suggest, please feel free to ask through my LinkedIn account. I will be happy to help you.
