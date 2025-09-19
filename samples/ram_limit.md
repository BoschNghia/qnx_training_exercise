# Linux/QNX RAM Limit

### Memory information
```
cat /proc/meminfo
MemTotal:       32863356 kB
MemFree:        27413944 kB
MemAvailable:   28571492 kB
```

### Physical range
```
32863356 * 1024 = 33652076544 bytes 
Max Address: 33652076544 - 1
Max Address: 33652076543
Max Address: 0x07D5D1EFFF
Min Address: 0x0000000000
```

### Virtual range
* Example
    ```
    setarch $(uname -m) -R ./memory
    ....
    Buffer: 0x555555558040/1024
    ....
    ```
    Max virtual address: 0x00007fffffffffff (128 TB)
    ==> [Complete virtual memory map with 4-level page tables](https://www.kernel.org/doc/Documentation/x86/x86_64/mm.txt)

### Memory limit control
* In terminal session
    ```
    $ ulimit -a
    ....
    virtual memory              (kbytes, -v) unlimited
    ....
    $ ulimit -v 8887
    $ ulimit -v 8886
    $ ulimit -v 8888
    bash: ulimit: virtual memory: cannot modify limit: Operation not permitted
    $ ulimit -a
    ....
    virtual memory              (kbytes, -v) 8886
    ....
    ```
* In cgroups (Control Groups)
    ```
    sudo cgcreate -g memory:/mygroup
    echo 100M | sudo tee /sys/fs/cgroup/memory/mygroup/memory.limit_in_bytes
    sudo cgexec -g memory:mygroup ./memory_increasing
    ```
    ==> [Control Groups](https://docs.kernel.org/admin-guide/cgroup-v1/cgroups.html)
* In process internal / coding
    ....

