
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

## makefile 
make fclean clean libft files twice
```
➜  minishell git:(main) ✗ make fclean 
rm -rf src/env/env.o src/env/env_utils.o src/main.o src/token/tokenizing.o gc/ft_malloc.o gc/utils_malloc.o src/built_ins/cd.o src/built_ins/echo.o src/built_ins/env.o src/built_ins/exit.o src/built_ins/export.o src/built_ins/pwd.o src/built_ins/unset.o src/expander/expander.o 
make clean -C libft-42
rm -f ft_memset.o ft_bzero.o ft_memcpy.o ft_memmove.o ft_memchr.o ft_memcmp.o ft_strlen.o ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o ft_toupper.o ft_tolower.o ft_strchr.o ft_strrchr.o ft_strncmp.o ft_strlcpy.o ft_strlcat.o ft_strnstr.o ft_atoi.o ft_calloc.o ft_strdup.o ft_substr.o ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_strtrim.o ft_strjoin.o ft_itoa.o ft_putnbr_fd.o ft_strmapi.o ft_split.o ft_striteri.o ft_strcmp.o
rm -rf minishell 
make fclean -C libft-42
rm -f ft_memset.o ft_bzero.o ft_memcpy.o ft_memmove.o ft_memchr.o ft_memcmp.o ft_strlen.o ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o ft_toupper.o ft_tolower.o ft_strchr.o ft_strrchr.o ft_strncmp.o ft_strlcpy.o ft_strlcat.o ft_strnstr.o ft_atoi.o ft_calloc.o ft_strdup.o ft_substr.o ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_strtrim.o ft_strjoin.o ft_itoa.o ft_putnbr_fd.o ft_strmapi.o ft_split.o ft_striteri.o ft_strcmp.o
rm -f libft.a

```