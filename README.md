# Thread_assignment

Run shuf to create 5 input files: \
$ time shuf -r -i 0-100000000 -n 10000000 > shuffled.1.txt \
$ time shuf -r -i 0-100000000 -n 10000000 > shuffled.2.txt \
$ time shuf -r -i 0-100000000 -n 10000000 > shuffled.3.txt \
$ time shuf -r -i 0-100000000 -n 10000000 > shuffled.4.txt \
$ time shuf -r -i 0-100000000 -n 10000000 > shuffled.5.txt 

Write a C program that uses multithreading to:
* sort each of these files in parallel and write to sorted.1.txt, sorted.2.txt, sorted.3.txt, sorted.4.txt, sorted.5.txt.  Use any standard library method to sort the individual files.
* sort the sorted.*.txt files to produce sorted.full.txt.  Write your own function to produce sorted.full.txt
