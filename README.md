
<p align="center">
  <img src="https://github.com/user-attachments/assets/8b2e805f-3d70-4b00-9ddc-2f56d3ad25b2"/>
</p>

# Push Swap
You have 2 stacks, one a random assortment of integers, and the other empty. How can you sort the first stack efficiently by rotating the stacks, swapping the top 2 elements, and pushing the top number from one stack to the other?

## Getting Started
### Recommended method
I'd highly recommend the visualiser [here](https://github.com/o-reo/push_swap_visualizer) by o-reo. It'll generate the numbers for you and you can watch the sorting algorithm work, as well as see the number of steps used.

### Manual method
```
make
./push_swap {integers separated by spaces}
```
The program will then print out all of the instructions. You can pipe the output into 'wc -l' if you're interested in the number of steps.



## Algorithm Used
It first calculates the number of steps needed for each number in the left stack to be in their optimal position in the right stack, it then chooses the number with the fewest steps needed and executes the steps. It repeats this until the left stack is "solvable" (ascending order) and then reverses the order to move everything back.

It isn't computationally efficient, but the goal was to complete the task in the fewest steps possible, not to do so in the most time-efficient manner.

There are other algorithms that are more efficient with larger stacks of numbers (quicksort), but they are less efficient for small stacks of numbers, and this is also assessed. Over-all I'm quite happy with the approach but if I had the time, I would consider the following:
- After the move, how 'sorted' is the list? A move may be efficient but could leave the remaining numbers more costly to sort.
- The algorithm only utilises rotations and pushing, incorporating swapping could help.
- If I had access to a super-computer then recursive backtracking could be fun to find the best possible solution.
