/*
 * CSc103 Project 6: Towers of Hanoi
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * References:5
 *
 *
 * Finally, please indicate approximately how many hours you spent on this:
 * #hours: 
 */

#include <iostream>
#include <getopt.h>
#include <cstdlib>

void tower(int n, int start, int end, int other) {
    if (n == 0) {
        return;
    }
    tower(n - 1, start, other, end);
    std::cout << start << '\t' << end << std::endl;
    tower(n - 1, other, end, start);
}

int main(int argc, char *argv[]) {
    int n = 0, start = 1, end = 3;
    
    // Process the options
    int opt;
    while ((opt = getopt(argc, argv, "n:s:e:")) != -1) {
        switch (opt) {
            case 'n': // Process option n
                n = atoi(optarg);
                break;
            case 's': // Process option s
                start = atoi(optarg);
                break;
            case 'e': // Process option e
                end = atoi(optarg);
                break;
            case '?': // Catch unknown options
                return 1;
        }
    }
    
    // Solve the puzzle
    tower(n, start, end, 6 - (start + end));
    
    return 0;
}

