# Dining Philosopher Problem
A classic problem in synchronization, the dining philosopher problem deals with the issue of deadlocks in process synchronization which leads to starvation through inefficient resource allocation. This problem is handled using the concept of semaphores, both counting semaphores as well as binary semaphores.
<br>

## First Part
In first part, we try to solve a modified version of dining philosopher problem involving five philosophers, each having a plate and a fork to his/her left and another on the right. Since deadlock arises when every philosopher picks up one fork, which does not allow to make any progress as non of the philosophers can eat. To solve this issue, we use a binary semaphore which ensures that at any instance there will always be only one philosopher
that will pick up two forks. Also, since each fork is related to a binary semaphore, we can know which fork is picked up.

## Second Part
In second part, we assume that the philosophers need both the forks to eat and now also require the sauce bowl to eat. To tackle this, a counting semaphore has been used which will keep track of the number of sauces available, and when we are picking the philosopher that will get 2 forks, we
also ensure that they get a bowl of sauce as well.

## Testing

    make
    ./p1 for first part
    ./p2 for second part