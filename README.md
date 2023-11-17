# Simple Shell Project

## DESCRIPTION

- This is a simple unix command interpreter that imitates the sh shell. 
- It was compiled on Ubuntu 22.04.2 LTS.

## FEATURES

- Displays a prompt and interpretes user commands.
- Executes user command entered using the full directory path, e.g `/bin/ls`.
- Handles command lines with arguments.
- Handles the PATH of executeables, e.g `ls` using the PATH environmental variable.
- Handles the `EOF` (`ctrl-D`) and `exit` built-in that exits the shell.
- Executes the `env` built-in that prints the current environment.
- Handles the `cd` functionality to change current working directory.

*NOTE: Some features like handling special characters (",',`,\,*,&,#), handling logical operators, alias builtin command, and variable replacement were not implemented.

## HOW TO USE

### copy and paste each highlighted command to your terminal and press `enter` one after the other

1. `git clone https://github.com/Mr-Michael-dev/simple_shell.git` clone this repo into your terminal
2. `cd simple_shell` navigate into the /simple_shell repo.
3. `mv hsh ../` move the hsh executeable into the home directory (you can aswell run in the simple_shell directory).
4. `./hsh` run the shell and impute your commands.

## FEEDBACK AND ISSUES

We welcome any feedback, suggestions, or bug reports related to our shell.

- [SEND A DM](https://twitter.com/michealoyedepo) 
