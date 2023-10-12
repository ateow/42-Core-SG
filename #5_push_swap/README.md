# push_swap

The Push swap project is algorithm project that asks to sort data on a stack, with a prescribed limited set of actions, using the lowest possible number moves.
* Input: A set of integer values
* Output: Prints out moves to sort Int from smallest to largest

### The rules
* You have 2 stacks named a and b. At the beginning, the stack A contains a random amount of negative and/or positive numbers which cannot be duplicated. The stack B is empty.
* The goal is to sort in ascending order numbers into stack a. To do so you have the following operations at your disposal:

    * sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
    * sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
    * ss : sa and sb at the same time.
    * pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
    * pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.    
    * ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
    * rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
    * rr : ra and rb at the same time.
    * rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
    * rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
    * rrr : rra and rrb at the same time

* Project provides checker_linux to check if the moves provided sorts the stack correctly. Output for checker will be either: "OK", "KO", "Error"
* Bonus work consist of replicating this checker program
  
### ateow concept


### how to test program
* `make` 2 program will be created. push_swap and checker
* `./push_swap 3 2 1` Output is sa and rra. means swap A and rotate down. Performing both actions will result in a sorted stack
* `ARG="3 2 1"; ./push_swap $ARG | ./checker_linux $ARG` Output is "OK". checker_linux is provided by project to check if moves will sort stack correctly.
* `ARG="3 2 1"; ./push_swap $ARG | ./checker $ARG` Output is "OK". Checker is done as bonus work. Replicates checker_linux to check if moves will sort stack correctly.


* https://github.com/izenynn/push_swap_tester
* ./tester.sh ../PS_submit/ -rn 100 -600 -1 500


* https://github.com/o-reo/push_swap_visualizer
* mkdir build
* cd build
* cmake -DCMAKE_C_COMPLIER=/usr/bin/gcc -DCMAKE_CXX_COMPILER=/usr/bin/g++ ..
* make
* dir: ~/Desktop/PS_submit/push_swap
export PS1="\[\e[32m\](\u)-[\w]\$ \[\e[0m\]"
