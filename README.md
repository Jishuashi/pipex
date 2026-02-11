*This project has been created as part of the 42 curriculum by hchartie*

# PIPEX

## Description
The goal of this program is to recreate the behavior of 
```BASH
< infile cmd1 | cmd 2 > outfile
```
of the Linux system

## Instruction
> To compile the code you need to :\
```BASH
make all
```
> To use the programe you need to give array of int like 
this
```BASH
./pipex infile "cmd1 arg{...}" "cmd2 arg{...}" outfile
```
> If an error occur print the resaon of the error in the stderr output
## Ressources
Radix sort:\
https://www.ibm.com/docs/fr/aix/7.3.0?topic=volumes-using-file-descriptors
https://www.codequoi.com/manipuler-un-fichier-a-laide-de-son-descripteur-en-c/\
Man Page of functions

### IA usage
> AI was used in guided learning mode to explain file descriptors and pipes.