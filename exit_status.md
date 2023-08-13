 ## ** The exit status for each builtin so it can be done manually **

## cd
0: The builtin was successful. The current working directory was changed to the specified directory.

1: An invalid argument was specified. The specified directory does not exist or is not a valid directory.

2: The builtin could not change the current working directory. The specified directory does not exist, is not a valid directory, or the user does not have permission to change to the directory.

3: The builtin could not access parent directories. The user does not have permission to access the parent directories of the specified directory.

4: A No such file or directory or Not a directory error occurred.

## pwd
0: The builtin was successful. The current working directory was retrieved successfully.

1: An invalid argument was specified.

## exit
0: The builtin was successful. The process was terminated successfully.

1: An invalid argument was specified.

2: The builtin could not terminate the process. The process is not responding or the user does not have permission to terminate the process.

## unset
0: The builtin was successful. The variable was unset successfully.

1: The variable does not exist.

## export
0: The builtin was successful. The variable was exported successfully.

1: The variable already exists.

## echo
0: The builtin was successful. The message was printed successfully.

1: An invalid argument was specified.

## env
0: The builtin was successful. The environment variables were printed successfully.

1: An invalid argument was specified.

2: The builtin could not access environment variables.