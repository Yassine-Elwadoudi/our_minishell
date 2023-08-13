
# ** minishell problems** 

> - Builtins part 

 
### cd
when we unset HOME and we do "cd" it change the directory succesfully while it shouldn't

### echo 
echo -n -n -n -n -n -nnnnnnnn a lots of -nnn separeted by spaces should also work as it is only -n and not display a newlineecho -n -n -n -n -n -nnnnnnnn a lots of -nnn separeted by spaces should also work as it is only -n and not display a newline

### exit 
need to manually configure the exit status of each builtin because there's no execve() and no macro "WEXITSTATUS" is used in them

### export
export with no arguments should be fixed it segfaults 

