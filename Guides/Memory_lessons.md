# Impt lessons when handling Heap Memory

Static Variables are automatically initalise to NULL. Normal Variables are not.

As a good rule of thumb, try not to malloc static variables. This is because it might not be reachable after the end of the program if not free(d). And usually, static variables are used to store variables and hence not usually clear when should it be free(d).

Memory leaks occur when a block of memory is allocated, pointer to this memory is amended before free(d).
	Do take note of helper functions that employs Malloc. 

	Mem Leak Example:
	str = malloc(10);
	str = "helloworld"
	// in this case, we want to extract hello from helloworld
	str = ft_substring(str, 0, 5); 
	// substring will malloc(6) and point str to another memory, and assign hello to this pointer.
	// In this case, the orginal "helloworld" will not be reachable, and not free(d), hence causing a memory leak
	
	No Leak Example:
	// Create a tmp string to store so that we can free str before reassignment
	str = malloc(10);
	str = "helloworld"
	tmp = ft_strdup(str);
	free(str);
	str = ft_substring(tmp, 0, 5);
	free(tmp);
	tmp = NULL;

Pay attention to how we exit the function / program and make sure that free is called for malloc.

The follwing code will cause a double free issue because in the event you meet 2 conditions, free(d) will be called twice. 
Double free is not a issue if its "if, else". it is a issue for "if, if"
	
 	str = malloc(5);
 	if (condition 1)
  	{
   		call function 1;
  		free(str);
		str = NULL; // to prevent rubbish data from being read if str is access from other functions.
		return(NULL);
	}
 	if (condition 2) 
  	{
      	call function 2;
		free(str);
		str = NULL;
		return(NULL);
   	}

To prevent, free str after your conditions.

	str = malloc(5);
 	if (condition 1)
   		call function 1;
 	if (condition 2) 
      	call function 2;
	free(str);
	str = NULL;
	return(NULL);
