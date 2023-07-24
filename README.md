# Get_Next_line

### Brief
+ This is a function used to read a text from a file line by line, the function takes the file descriptor of the file, returns a line from the given file,
to read the whole text from the file, you can can this function inside a loop, so it will return a line from the file on each iteration, the function returns
(null) when the file content ends.

### Clone

```
git clone https://github.com/ahammout/get_next_line.git
```

### Usage

+ To use this function you need to include the header file, and add a main function to call it inside.
* Compilation:

```
cd get_next_line
```

```
gcc main.c get_next_line.c get_next_line_utils.c -o GetNextLine
```

```
./GetNextLine
```