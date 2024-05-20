# How Concurrency Work?

When a CPU wants to do multiple tasks at the same time, it doesn't actually do them at the same time. Instead, it switches between tasks in a way that makes it seem like they are being executed simultaneously. This is called concurrency.

What actually does the switching is the operating system. But how does the Operating System work? Operating System itself is a task as well. When a task interupts the operating system to write, open file etc, before it can continue with the next task, the operating system has to save the current state of the task, and then load the state of the next task. This is called a context switch.

It does the switching by jumping between addresses in memory. The CPU has a register called the Program Counter (PC) that points to the current instruction being executed. When the CPU wants to switch tasks, it saves the current value of the PC, and then loads the value of the PC for the next task. This is how the CPU knows where to resume the task.

But the context switch is not free. It takes time to save and load the state of a task. So, the more tasks you have, the more time is spent on context switching, and the less time is spent on actual tasks. But the computer is so fast that it doesn't matter and seems like the tasks are being executed at the same time.

But what if the program continues without any interupts. Jumping is also used to conditions and loops. When the CPU encounters a condition or a loop, it jumps to a different address in memory. This is how the CPU knows where to go next. What if there is a infinite loop? The CPU will be stuck in the loop and won't send interupt to Operating System. This is called a deadlock. This can't be solved by programming because the CPU is stuck in the loop. The only way to solve this is hardware interupt. The CPU has a timer that sends an interupt to the Operating System after a certain amount of time. This is how the Operating System can kill the task that is stuck in a loop. This is called a timeout.

Yes, the computer is fast but even the CPU has its own limits. The solution to this is multicore systems. A multicore system has multiple cores that can execute tasks in parallel. This is called parallelism. But even with multicore systems, the CPU can only execute a limited number of tasks at the same time. The more tasks you have, the more time is spent on context switching, and the less time is spent on actual tasks.

## Source

- https://youtu.be/8rEGu20Uw4g
- https://youtu.be/d0gS5TXarXc
