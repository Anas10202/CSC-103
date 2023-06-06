/*
 * CSc103 Project 2: prime numbers.
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * References:
 *
 */
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <cmath>

bool isPrime(int x) {
    bool prime = true;
    if (x == 1) {
        prime = false;
    }
    for(int i=2; i<=sqrt(x); i++) {
        if(x%i == 0) {
            prime = false;
            break;
        }
    }
    return prime;
}
int main() {
	unsigned long num;
	while(cin>>num)

    if(isPrime(num)) {
        cout << 1   << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}