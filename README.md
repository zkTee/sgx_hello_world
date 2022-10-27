# sgx_hello_world

Where SGX amazing happens.

### How to use
```shell
make
./app
```

Output
```shell
trusted   value  : 123456789
untrusted value  : 987654321
```

---

### Use scanmem tool to modify value
* find app process id
```shell
ps aux | grep app

ztgx       97650  1.5  0.0  26432  6068 pts/3    S+   21:55   0:00 ./app

```

* run scanmem
```shell
sudo scanmem 97650
```

* modify untrust value to 1

* back to terminal A, press enter
```shell
trusted   value  : 123456789
untrusted value  : 1
```
