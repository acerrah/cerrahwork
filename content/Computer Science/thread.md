---
title: thread
---
# What are threads?

A thread is a sequence of instructions that can be executed independently of other threads. Threads are lightweight processes that share the same memory space. This means that threads can access the same data and resources, which can be both an advantage and a disadvantage.

When two or more threads access the same data or resource at the same time, it can lead to race condition. Race condition is a situation where the outcome of a program depends on the order in which the threads are executed. This can lead to unpredictable behavior and bugs in the program.

Example C program:

```c
  #include <stdio.h>
  #include <pthread.h>

  int main(){
      int counter = 0;
      pthread_t thread1, thread2;

      void *increment(void *arg){
          for(int i = 0; i < 1000000; i++){
              counter++;
          }
          return NULL;
      }

      pthread_create(&thread1, NULL, increment, NULL);
      pthread_create(&thread2, NULL, increment, NULL);

      pthread_join(thread1, NULL);
      pthread_join(thread2, NULL);

      printf("Counter: %d\n", counter);

      return 0;
  }
```

In this program we have two threads that increment a counter variable 1,000,000 times each. The expected output of this program is 2,000,000, but because the threads are accessing the same data(counter) at the same time, the output is unpredictable and wrong. (You can try running this program and see the output for yourself.)

To solve this we use synchronization. Synchronization is the process of coordinating the execution of threads to ensure that they do not access the same data or resource at the same time. There are different synchronization mechanisms such as locks, semaphores, and monitors that can be used to achieve correct results in a multithreaded program.

Eample C program with synchronization:

```c
  #include <stdio.h>
  #include <pthread.h>

  int counter = 0;
  pthread_mutex_t mutex;

  int main(){
      pthread_t thread1, thread2;

      pthread_mutex_init(&mutex, NULL);

      void *increment(void *arg){
          for(int i = 0; i < 1000000; i++){
              pthread_mutex_lock(&mutex);
              counter++;
              pthread_mutex_unlock(&mutex);
          }
          return NULL;
      }

      pthread_create(&thread1, NULL, increment, NULL);
      pthread_create(&thread2, NULL, increment, NULL);

      pthread_join(thread1, NULL);
      pthread_join(thread2, NULL);

      printf("Counter: %d\n", counter);

      pthread_mutex_destroy(&mutex);

      return 0;
  }
```

In this example we used mutex locks to synchronize the access to the counter variable. A mutex is a synchronization primitive that allows only one thread to access a shared resource at a time. By using mutex locks, we simply tell thread to stop if mutex is locked and wait until it is unlocked. This ensures that only one thread can access between the mutex locks at a time, and the output of the program is correct. (Try running this program and see the output for yourself.)

## Difference between Process and Thread

A process is an instance of a program that is being executed. To start a new process, the operating system creates a new memory space, file descriptors, and other resources for the process. To start a new thread, the operating system creates a new sequence of instructions that can be executed independently of other threads, but shares the same memory space, file descriptors, and other resources of the process.

In a C program we can create child proccesses using the fork() system call. The fork() system call creates a new process that is an exact copy of the parent process. The child process has its own memory space, file descriptors, and other resources, and can execute independently of the parent process.

Example C program.

```c
    #include <stdio.h>
    #include <unistd.h>

    int main(){
        int counter = 0;
        pid_t pid;

        pid = fork();

        if(pid == 0){
            for(int i = 0; i < 1000000; i++){
                counter++;
            }
            printf("Child Counter: %d\n", counter);
        }else{
            for(int i = 0; i < 1000000; i++){
                counter++;
            }
            printf("Parent Counter: %d\n", counter);
        }

        return 0;
    }
```

The reason we used pid == 0 to check if the process is a child process is because the fork() system call returns 0 to the child process and the process id of the child process to the parent process which is one more than the process id of the parent process. (If it is not occupied by another process.)

In this program we have a parent process and a child process that increment a counter variable 1,000,000 times each. The expected output of this program is 1,000,000 for the parent process and 1,000,000 for the child process. (You can try running this program and see the output for yourself.)
