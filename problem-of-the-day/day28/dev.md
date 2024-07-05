# Dev Problem of the Day

## Branch Prediction

- ### What is Branch Prediction?

  Branch prediction is a crucial technique in modern CPUs. It uses a dedicated hardware unit called a branch prediction unit (BPU) to predict the outcome of conditional operations with high confidence based on the current encoded instruction. When a branch instruction comes to the CPU, it predicts the next instruction to fetch while the current instruction is being decoded, reducing wasted cycles. This can lead to one of the two situations as follows:

  - _Correct prediction_: This will result in no wastage of cycles resulting in faster execution.
  - _Incorrect prediction_: This will cause the CPU to fetch the correct instruction and discard the already-fetched instruction, leading to the wastage of cycles.

- ### Types of Branch Prediction

  - **Static branch prediction** : It always predicts the same whenever it sees a specific branch.
  - **Dynamic branch prediction** : Rely on the past results of the conditional operation to predict whether to take the branch or not.

- ### Resources

  - This [thread](https://stackoverflow.com/questions/11227809/why-is-processing-a-sorted-array-faster-than-processing-an-unsorted-array) explains branch prediction with an example and an analogy.
  - [CMU Branch Prediction I](https://course.ece.cmu.edu/~ece447/s15/lib/exe/fetch.php?media=onur-447-spring15-lecture9-branch-prediction-afterlecture.pdf) and [CMU Branch Prediction II](https://course.ece.cmu.edu/~ece447/s15/lib/exe/fetch.php?media=onur-447-spring15-lecture10-branch-prediction-ii.pdf) are good resources to get an in-depth understanding of the topic.
  - This [article](https://www.educative.io/answers/what-is-branch-prediction) explains branch prediction and its types with examples.
