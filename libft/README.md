#How to use libft.a

-l Flag:
The -l flag is used to specify a library that the linker should include when linking your program.
You typically follow -l with the name of the library you want to link against, without the "lib" prefix or file extension. For example, if you want to link against the libexample.so library, you would use -lexample.
The linker will search for the specified library in its default library search paths (e.g., /usr/lib, /usr/local/lib) and in any additional paths specified using the -L flag.

-L Flag:
The -L flag is used to specify additional directories where the linker should search for libraries.
You follow -L with the path to the directory containing the libraries you want to link against. For example, -L/path/to/my/libs tells the linker to search for libraries in the /path/to/my/libs directory.
This flag allows you to specify custom library search paths in addition to the default search paths.

Run Make > generate static library libft.a (note that header is not compiled in static libraries)

assuming libft.a is in the current directory you want to compile your code:
cc main.c -L . libft.a && ./a.out
or
cc main.c -L . -lft.a && ./a.out [-lft is a shortform for libraries labelled as libXXX.a]

note that header file is not included because main.c define that libft.h is included and will search for current directory for libft.h
