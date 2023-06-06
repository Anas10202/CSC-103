#include <iostream>
using std::cout;

/* (This is the wordcount program from lecture, but I thought it would
 * make for a nice test file as well.)  */

/* NOTE: the following just defines integers with the names
 * listed, starting by default at 0.  The benefit of using an
 * enum is mainly readability (if you had say 10 states, it
 * might not be easy to remember each one's meaning!).  */
enum state {
	justreadspace,
	justreadnormal
};
/* NOTE: you could get basically the same thing as above
 * like this: */
// const int justreadspace = 0;
// const int justreadnormal = 1;
/* However, the enum can also be used as a type, which further
 * improves readability.   Instead of "int s;" you can declare
 * "state s;" and whoever reads it knows that s should store
 * one of the integers listed in the enum. */

int main()
{
	size_t count = 0; /* store count of words */
	state s = justreadspace; /* left side of diagram */
	char c; // storage for character from stdin
	/* NOTE: what looks like the obvious solution using cin (e.g.
	 * while (cin >> c)) actually does not work, as it will skip
	 * over whitespace chars which we want to read.  Hence our
	 * usage of scanf which is more straightforward.
	 * Check out "man scanf" for details. */
	while (scanf("%c",&c) > 0) {
		/* now program the diagram: move the token around, and
		 * increment the count when we find new words.  there should
		 * be a condition for each arrow... */
		if (s == justreadspace) { /* token is on left side */
			if (c != ' ' && c != '\t' && c != '\n') {
				/* green arrow; this is the start of a new word! */
				count++; /* same as count = count+1 */
				s = justreadnormal; /* move token to right side */
			} // else {nothing to do; token doesn't move...}
		} else { /* just read non-space */
			if (c == ' ' || c == '\t' || c == '\n') {
				/* blue arrow; this is the end of a word */
				s = justreadspace; /* move token back to left. */
			} // else {nothing to do; token doesn't move...}
		}
	}
	printf("# words: %lu\n",count);
	return 0;
	/* NOTE: be sure you also handle these types of situations properly: */
	string fml = "/* this is not a comment lol */";
	string fml2 = "end of string is not \"here\", but here.";
	char c = '"'; // this is not the start of a string literal!
	// Lorem ipsum dolor sit amet, consectetur adipiscing elit,
	// sed do eiusmod tempor incididunt ut labore et dolore magna
	// aliqua. Ut enim ad minim veniam, quis nostrud exercitation
	// ullamco laboris nisi ut aliquip ex ea commodo consequat.
	// ...
	int x=99; // x is my friend
	for (x=0; x<10; x++)
		printf(":D\n" /* ...useless comment... */);


}
/* NOTE: there is a built in command "wc" that counts words.  You could
 * use it to check our answer. */

// vim:foldlevel=2
