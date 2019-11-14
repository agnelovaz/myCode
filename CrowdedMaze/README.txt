////////////////////////////////////
// Crowded Maze
////////////////////////////////////

A maze of maximum size NxM is filled with walls
and empty spaces. An up to 4 persons are placed inside.
Each one has a desired spot in the maze where
wants to finish.

The person can move "up/down/left/right/none” in each
time step, and cannot collide with other persons.
Also, they want to have a personal space at all times, 
and for this reason after each time step there
has to be at least 1 space gap between them.


Start position are marked as "ABCD", and end positions
as "abcd". "." are spaces, and "#" are walls.
For all purposes, "abcd" can be treated as spaces, 
and after a person moves it leaves a space behind.

t0:  t1:  t2:  t3: DONE!
...a ...a ...a ...A 
.##. .##. .##A .##. 
.##. .##A .##. .##. 
...A .... .... .... 

NOT ALLOWED (because of proximity rule):
...  .A.  
.AB  .B.
...  ...

This kind of movement is valid: (“A left” + “B right” at the same time step)
.A    A.
B. -> .B


LIMITS:
4 people maximum, labeled ABCD (3 people -> ABC, 2 -> AB, 1 -> A)
Max size limits 10x10


RETURN VALUE:
Minimum timesteps for all people to reach thir spots.
If it is not possible, return -1