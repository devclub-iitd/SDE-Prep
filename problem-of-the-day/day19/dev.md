# Dev Problem of the Day - Concurrency Issues in OS : Deadlock, Livelock and Starvation.

## Concurrency Issues in Operating Systems

In [Week 3](https://github.com/devclub-iitd/SDE-Prep/blob/main/problem-of-the-day/day03/dev.md),
we discussed about using Multithreading for achieving concurrency and it's applications, 
However, managing concurrency introduces several challenges.
Let’s explore three critical issues: Deadlocks, Livelocks, and Starvation.

- ### DeadLocks and Livelocks: 
  A deadlock occurs when two or more processes are unable to proceed because each is waiting for a resource held by another process.
  The classic example involves two processes competing for two resources (e.g., printer and scanner), resulting in a circular wait.
  
  A livelock occurs when processes are active but unable to make progress.
  Unlike deadlocks, where processes are stuck, livelocked processes keep executing futile actions.
  Imagine two people politely stepping aside for each other in a narrow corridor, preventing either from moving forward.
  This [Wikipedia](https://en.wikipedia.org/wiki/Deadlock) article is a must-read for gaining a thorough understanding of deadlocks.
  
- ### Starvation: 

  Starvation happens when a process is perpetually denied access to a resource it needs.
  While not as severe as deadlocks or livelocks, it impacts system performance.
  This article by [Javatpoint](https://www.javatpoint.com/starvation-and-aging-in-operating-systems) discusses about Starvation and Aging(
  A method used to tackle starvation).

### Follow up:
- You may read about Resource Allocation Graphs, Banker's algorithm or Priority Inheritance Protocols which are used to tackle DeadLocks. Apart from this,
  Randomness (Jitter) is also used to tackle Livelocks.
- [Sqldbaiq](https://sqldbaiq.blogspot.com/p/locks-iq.html) has questions on Deadlocks appearing on SQL servers.
- On page 3 of [this](http://courses.csail.mit.edu/iap/interview/Hacking_a_Google_Interview_Handout_1.pdf) pdf, you will find a good question on Parallelism and Deadlock by MIT.
- Also, [GFG](https://www.geeksforgeeks.org/quizzes/deadlock-gq/) and [StudyTonight](https://www.studytonight.com/operating-system/tests/20.php) have
   some decent quizzes to practice deadlock questions.
