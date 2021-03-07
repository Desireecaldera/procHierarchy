# procHierarchy
This lab displays the creation of a three level hierarchy of processes. Each process will be annotated with a different tag as follows:

"1" annotates the root process.
"1.1.1" annotates the first child of "1.1".
"1.1.2" annotates the second child of "1.1".
"1.2.1" annotates the first child of "1.2".
"1.2.2" annotates the second child of "1.2".
"1.1" annotates the first child of "1".
"1.2" annotates the second child of "1".

The root process should remain proc_hier and wait for all children to terminate.
All children and grandchildren should morph to iam process.
The iam program is activated programmatically using the execlp() function invoked in proc_hier.c. 
