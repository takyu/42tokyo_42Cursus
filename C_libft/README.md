# libft

"libft" is a library of functions that are using assignments from now on.  
The allowed external functions are as follows.  

   - **write**
   - **malloc**
   - **free**

## Detail

1. already existing functions of library C
```
memset  bzero  memcpy  memccpy  memmove  memchr  memcmp
strlen  strlcpy  strlcat  strchr  strrchr  strnstr
strncmp  atoi  isalpha  isdigit  isalnum  isascii
isprint  toupper  tolower  calloc  strdup
```

2. functions are not included in the library C
   - substr
     ```
     Allocates and returns a substring from the string 's'.
     The substring begins at index 'start' and is of maximum size 'len'.
     ```

   - strjoin
     ```
     Allocates and returns a new string, which is the result of the
     concatenation of 's1' and 's2'.
     ```

   - strtrim
     ```
     Allocate sand returns a copy of ’s1’ with the charactersspecified in ’set’
     removed from the beginning and the end of the string.
     ```

   - split
     ```
     Allocates and returns an array of stringsobtained by splitting ’s’ 
     using the character ’c’ as a delimiter.
     The array must be ended by a NULL pointer.
     ```

   - itoa
     ```
     Allocates and returns a string representing the integer received as an argument.
     Negative numbers must be handled. 
     ```

   - strmapi
     ```
     Applies the function ’f’ to each character of the string ’s’
     to create a new string resulting from successive applications of ’f’.
     ```

   - putchar_fd
     ```
     Outputs the character ’c’ to the given file descriptor.
     ```

   - putstr_fd
     ```
     Outputs the string ’s’ to the given file descriptor.
     ```

   - putendl_fd
     ```
     Outputs the string ’s’ to the given file descriptor, followed by a newline.
     ```

   - putnbr_fd
     ```
     Outputs the integer ’n’ to the given file descriptor.
     ```

3. manipulating list structure functions are not included in the library C
   - lstnew
     ```
     Allocates and returns a new element. The variable ’content’ is initialized
     with the value of the parameter ’content’.
     The variable ’next’ is initialized to NULL.
     ```

   - lstadd_front
     ```
     Adds the element ’new’ at the beginning of the list.
     ```

   - lstsize
     ```
     Counts the number of elements in a list.
     ```

   - lstlast
     ```
     Returns the last element of the list.
     ```

   - lstadd_back
     ```
     Adds the element ’new’ at the end of the list.
     ```

   - lstdelone
     ```
     Takes as a parameter an element and frees the memory of the element’s content
     using the function ’del’ given as a parameter and free the element.
     The memory of ’next’ must not be freed.
     ```

   - lstclear
     ```
     Deletes and frees the given element and every successor of that element,
     using the function ’del’ and free.
     Finally, the pointer to the list must be set to NULL.
     ```

   - lstiter
     ```
     Iterates the list ’lst’ and applies the function ’f’ to the content of each element.
     ```

   - lstmap
     ```
     Iterates the list ’lst’ and applies the function ’f’ to the content of each element.
     Creates a new list resulting of the successive applications of the function ’f’.
     The ’del’ function is used to delete the content of an element if needed.
     ```

## Note

The function name is prefixed with "ft_".

