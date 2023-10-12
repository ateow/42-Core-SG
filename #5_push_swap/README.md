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
* Check input for error
* Convert input into INT
* check if sorted
* if not, pass into sorting hat
* if stack size is 3, 4 or 5, use sort3, sort4, sort5 algo respectively
* if stack size is above 5, use custom algo, with a determined chunk size
* for custom algo 2 steps:
  * Move stack A into stack B in chunks.
      *  First chunk will consist of the smallest values of chunk size. last chunk will have the largest value
      *  When we pass in chunk of smallest value, we further split chunk into 2 depending on if it falls in the first half or second half of the chunk. use rotate
  * Move stack B back into stack A sorted
      *  When moving back, we find largest value and push is back to stack A
      *  Algo finds index and determine if rot up or down uses less moves
      *  If we find 2nd largest, on the way to finding the largest, we push 2nd largest to stack A, then perform a swap a after pushing in largest value
      *  if we we find 3rd largest after finding 2nd largest, also push in 3rd largest. in this case, perform a series of actions for the 3 largest unsorted values in stack A.

### How to test push_swap program
* `make` 2 program will be created. push_swap and checker
* `./push_swap 3 2 1` Output is sa and rra. means swap A and rotate down. Performing both actions will result in a sorted stack
* `ARG="3 2 1"; ./push_swap $ARG | ./checker_linux $ARG` Output is "OK". checker_linux is provided by project to check if moves will sort stack correctly.
* `ARG="3 2 1"; ./push_swap $ARG | ./checker $ARG` Output is "OK". Checker is done as bonus work. Replicates checker_linux to check if moves will sort stack correctly.
* push_swap Testers used for huge stack: https://github.com/izenynn/push_swap_tester >> `./tester.sh ../ -rn 100 -600 600 500 -b`
* visualiser used: https://github.com/o-reo/push_swap_visualizer >> use `cmake -DCMAKE_C_COMPLIER=/usr/bin/gcc -DCMAKE_CXX_COMPILER=/usr/bin/g++ ..` instead of cmake for 42SG
