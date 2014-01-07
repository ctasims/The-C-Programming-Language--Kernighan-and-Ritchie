# Control Flow

## Summary
1. `;` terminates a statement and `{}` define blocks, or compound statements.
2. `If-Else` statements express a decision.
3. `Else-If` to express multi-way decision paths.
4. `Switch` to test against constant int values.
5. `for` loops equivalent to `while`. Use former when initialization, incrementing.
6. `Do-While` always runs the inner statements once.
7. `break` to exit a loop or `continue` to jump to the next iteration.
8. `goto` can be easily abused so avoid it if possible!

## Exercises
1. Done. Easy. Used Paul Griffith's timing code.
2. Done.
3. Done, with O(n) solution. Interesting question.
4. Done. Had to clarify using solutions.
5. Done.
6. Done.


## 3.1 Statements and Blocks
Statements are terminated with a `;`.  
Blocks are known as compound statements and are surrounded by `{}`.


## 3.2 If-Else
Always use braces with nested `If-Else` statements to avoid ambiguity with `Else` block.


## 3.3 Else-If
Simple stuff here. This chapter is mostly review.


## 3.4 Switch
Each case matches one integer-valued constant or constant expression.
`break` to avoid falling through to next case.

    switch (expression) {
      case const-expr: statements
      case const-expr: statements
      default: statements
    }


## 3.5 Loops - While and For
These are basically equivalent. In general, can prefer `for` loops when incremeneting and initializing some value.  
Can use comma operator to separate expressions in `for` statement.


## 3.6 Loops - Do-while
Execute loop at least once by using `do-while` loop, which checks logical expression after the loop.


## 3.7 Break and Continue
`break` to exit out of a loop.  
`continue` to jump to the next iteration.  
Be careful with these, since they can make the control flow of the logic difficult to follow.


## 3.8 Goto and Labels
`goto` can also be abused, resulting in difficult-to-follow logic.
Avoid using it whenever possible. K&R do give an example of error control, though:

    for ( ... )
        for ( ... ) {
            ...
            if (disaster)
                goto error;
        }
    ...

    error:
        cleanup

