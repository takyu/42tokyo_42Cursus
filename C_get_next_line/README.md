# get_next_line

Write a function which returns a line read from a file descriptor, without the newline.
Calling function get_next_line in a loop will then allow you
to read the text available on a file descriptor one line at a time until the EOF.
Source files included the word "bonus" are the same them not included word "bonus".
The bonus is that using a single static variable and
to be able to manage multiple file descriptor.
this program must compile with the flag -D BUFFER_SIZE=xx.

## Detail

1. Prototype
```
int	get_next_line(int fd, char **line);
```

2. Parameters
```
1. file descriptor for reading
2. The value of what has been read
```

3. Return value
```
1  : A line has been read
0  : EOF has been reached
-1 : An error happened
```

4. External functions
```
read, malloc, free
```

## Note

If BUFFER_SIZE is not defined, BUFFER_SIZE=2000 will be defined for safe compilation.


