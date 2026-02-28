# FileManager

Console-based file manager inspired by Midnight Commander. Implemented in C++ as a semester project for the BI-PA2 course at CTU FIT.

It supports basic file and directory operations, regex-based multi-file selection, content search, text file concatenation, and deduplication using symbolic links.


## Navigation

- W/S – move selection
- E – open directory / confirm
- A/D – switch panel
- 1–7 – file operations
- K – toggle multiple selection

## Features

### 1. Basic File and Directory Operations

- Create
- Copy
- Move
- Delete
- Create symbolic links

Operations are applied to the currently selected file(s).


### 2. Regex-Based Selection

Apply file operations to multiple files selected using regular expressions.

### 3. Text Search

Search for a text string in the current directory and recursively in its subdirectories.

Results (file paths) are saved to:

```
founditems.txt
```


### 4. Concatenate Text Files

Merge selected text files into a single output file.


### 5. Deduplication

Detect duplicate files based on content.

The program scans the current directory and its subdirectories and replaces duplicates with symbolic links to the original file.


## How to Run
- Set appropriate permissions for the directory you want to operate in
- Run `make`