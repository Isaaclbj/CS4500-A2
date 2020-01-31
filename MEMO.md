Array supports int/float/bool/String, grows when pushed back, as well as reading/writing to indices of the Array.
Queue supports Objects and String to be enqueued/dequeued into a Queue container. Additionally, it limits the use of new/delete operators in enqueue/dequeue operations.
Map supports 

Array
    Documentation Quality:
    Responsiveness:
    Test quality:
Queue
    Documentation Quality: Solid input/output, deeper intricacies of implementation were left out.
    Responsiveness: Responsive. Issues I had were addressed by another team who had received prompt response from the Spec pair.
    Test quality: tests were sufficient, however there were no tests that tested limits (dequeueing an empty Queue, enqueueing a full Queue, etc).

Map