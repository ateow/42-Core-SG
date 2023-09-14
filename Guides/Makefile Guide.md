# Makefile Guide


ALIAS: Name, CC, CFLAG Sources, Bsources, objects and bobjects\
COMMANDS: all, $(NAME), bonus, %.o, clean, fclean, re

    NAME = libft.a
    Defines the name of the library to be created as libft.a.

    all: $(NAME): 
    The default target all depends on $(NAME). It's the default goal when you run make without specifying a target.
    Technially ok if you dont include. Make and Make all is the same in this case. but common convention

    OBJECTS = $(SOURCES:.c=.o)
    BOBJECTS = $(BSOURCES:.c=.o)
    these 2 are alias for all the .o files. 

    $(NAME): $(OBJECTS):
        $(AR) -r $@ $?
    Specifies that the $(NAME) target depends on the object files in $(OBJECTS).
    This line creates the library $(NAME) using the ar archiving utility. -r means to insert files into the library, $@ is the target name (libft.a), and $? is the list of dependencies (object files).
    
    bonus: $(OBJECTS) $(BOBJECTS)
        $(AR) -r $(NAME) $?
    A custom target named bonus that depends on both regular and bonus object files.
    Similar to the regular target but also includes the bonus object files in the library.
    
    %.o: %.c: 
        $(CC) -c $(CFLAGS) $?
    A pattern rule for creating object files from corresponding C source files.
    This rule compiles each .c file into a .o file using the C compiler and specified flags.
    
    clean: 
        rm -f $(OBJECTS) $(BOBJECTS): Removes the object files.
    A target for removing object files and bonus object files.

    fclean: clean
        rm -f $(NAME): Removes the library file.
    execute command make clean then remover libft.a file.

    re: fclean all
    execute command make fclean then make all.

    .PHONY: all bonus clean fclean re
    Defines certain targets as "phony," which means they don't represent actual files. This ensures that these targets are always executed, even if there are files with the same names.


NORM V4

Makefiles aren’t checked by the Norm, and must be checked during evaluation by the student.\
• The $(NAME), clean, fclean, re and all rules are mandatory.\
• If the makefile relinks, the project will be considered non-functional.\
• In the case of a multibinary project, in addition to the above rules, you must have a rule that compiles both binaries as well as a specific rule for each binary compiled.\
• In the case of a project that calls a function from a non-system library (e.g.: libft), your makefile must compile this library automatically.\
• All source files you need to compile your project must be explicitly named in your Makefile.\



SAMPLE:

    NAME = libft.a

    SOURCES = \
        ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
        ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
        ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
        ft_strrchr.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
        ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
        ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
        ft_putendl_fd.c ft_putnbr_fd.c

    BSOURCES = \
        ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
        ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

    OBJECTS = $(SOURCES:.c=.o)
    BOBJECTS = $(BSOURCES:.c=.o)

    CC = gcc
    CFLAGS = -Wall -Wextra -Werror

    all: $(NAME)

    $(NAME): $(OBJECTS)
        $(AR) -r $@ $?

    bonus: $(OBJECTS) $(BOBJECTS)
        $(AR) -r $(NAME) $?

    %.o: %.c
        $(CC) -c $(CFLAGS) $?

    clean:
        rm -f $(OBJECTS) $(BOBJECTS)

    fclean: clean
        rm -f $(NAME)

    re: fclean all

    .PHONY: all bonus clean fclean re