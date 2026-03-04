*This project was created as part of the 42 curriculum by hchartie.*

# PIPEX

## Description
The `pipex` program reproduces the basic behavior of a shell pipeline of the
form:

```BASH
< infile cmd1 | cmd2 > outfile
```

It opens `infile`, executes `cmd1` with its stdin redirected from `infile`,
pipes the stdout of `cmd1` into the stdin of `cmd2`, and writes the final
output into `outfile` (creating or truncating it). The implementation is a
small exercise in process creation, file descriptor manipulation, and using
UNIX pipes.

This project intentionally implements the minimal features required by the
42 assignment: handling exactly two commands and basic redirections.

## Instruction

### Clone the project
```BASH
git clone https://github.com/Jishuashi/pipex.git
```
And go in the folder

```BASH
cd pipex
```

### Build
To compile the program run:

```bash
make all
```

This will produce an executable named `pipex` in the project root.

### Usage
The program expects exactly four arguments (infile, cmd1, cmd2, outfile):

```bash
./pipex infile "cmd1 arg1 arg2" "cmd2 argA argB" outfile
```

Examples:

```bash
./pipex input.txt "grep hello" "wc -l" output.txt
./pipex /etc/passwd "cut -d: -f1" "sort" users_sorted.txt
```

Notes and assumptions:
- Commands are provided as a single string and should be parsed into argv
	tokens by the program (space-separated; quoted arguments are supported in
	the shell but the program receives a single string to parse).
- Only two commands are supported (no chaining of more than two commands).
- `outfile` is created or truncated; file permissions follow the system
	defaults used when creating a file with `open(2)`.

## Ressources
- Using file descriptors and pipes (reference):
	https://www.ibm.com/docs/fr/aix/7.3.0?topic=volumes-using-file-descriptors
- Guide to manipulating files via their file descriptors (French):
	https://www.codequoi.com/manipuler-un-fichier-a-laide-de-son-descripteur-en-c/
- Standard man pages for system calls used: `pipe(2)`, `fork(2)`, `dup2(2)`,
	`execve(2)`, `open(2)`, `waitpid(2)`.

### IA usage
AI was used in guided learning mode to explain file descriptors and pipes.
