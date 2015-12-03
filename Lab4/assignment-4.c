/*
	Name: Shah, Sahil
    UT EID: ss63683
    Section: 16215
    EE312-Assignment 4
*/

#define FALSE 0
#define TRUE 1



/************************************************************/
/* This function is called by the 'match' function.
If the passed character is one of the base set (a,c,g, or t), it
returns 1, else it returns 0.
*/
/************************************************************/
int isBase(char c) {
	if ((c == 'a') || (c == 'c') || (c == 'g') || (c == 't')) {
		return 1;
	}

	return 0;
}



/************************************************************/
/************************************************************/
/*
This is a recursive function that returns 1 if the string s matches
the ME string r. It returns 0 otherwise.
You need to implement the following logic in this function:

1. If length(r)=length(s)=0, they match: return 1.

2. If length(r)=length(s)=1, then r matches s only if either r is '.'
(which matches any character), or the same character as s.

3. If length(r) > 1, then r can match s in one of these cases:

a) If r[0] is a base character that matches s[0], and r[1] is a
base character or a '.', then r and s match only if r[1..end]
matches s[1..end] (checked by a recursive call to match).

b) If r[0] is a base character, and r[1] is '*', then r matches s
only if s is composed as follows:
0 or more occurences of r[0], followed by a string that matches
r[2..end]. This can be checked by calling match recursively for
each possible suffix of s.

c) If r[0] is '.' and r[1]!='*', then unless s is empty, r and s match
only if r[1..end] matches s[1..end] (checked by a recursive call to
match).

d) If r[0] is '.' and r[1]='*', r and s match if any suffix of s
matches r[2:end].
*/

int match(char *s, char *r) {

	/************************************************************

	<YOUR CODE GOES HERE>

	************************************************************/
	int i = 0;									//length of s
	while (s[i] != '\0') {
		i++;
	}
	int j = 0;									//length or r
	while (r[j] != '\0') {
		j++;
	}
	if (i == 0 && j == 0) {						//checks case 1
		return TRUE;
	}
	if (i == 1 && j == 1) {						//checks case 2
		if (s[0] == r[0]) {
			return TRUE;
		}
		else if (r[0] == '.') {
			return TRUE;
		}
	}
	if (r[0] == 'c' || r[0] == 'a' || r[0] == 'g' || r[0] == 't') {		//checks 3a (is base characters just cagt?)
		if (r[0] == s[0]) {
			if (r[1] == 'c' || r[1] == 'a' || r[1] == 'g' || r[1] == 't' || r[1] == '.') {
				return match(s + 1, r + 1);
			}
		}
	}
	if (r[0] == 'c' || r[0] == 'a' || r[0] == 'g' || r[0] == 't') {		//checks 3b
		if (r[1] == '*') {
			int counter = 0;
			while (r[0] == s[counter]) {
				counter++;
			}
			return match(s + counter, r + 2);
		}
	}
	if (r[0] == '.') {													//checks 3c (what happens when s is empty)
		if (r[1] != '*') {
			if (i != 0) {												//checks if s is empty
				return match(s + 1, r + 1);
			}
		}
	}
	if (r[0] == '.') {													//checks 3d
		if (r[1] == '*') {
			int length;
			int decrement=0;
			int length1;
			int increment = 0;
			if (j == 2) {
				return match(s + 1, r + 2);
			}
			for (length = j - 1; length > 1; length--) {
				if (r[length] == '*') {
					if (r[length - 1] == '.') {
						decrement++;
						length = length - 2;
						if (length > 2) {
							decrement++;
						}
					}
				}
			}
			length1 = j - 2 - decrement;
			return match(s + i - length1, r + 2);
		}
	}
	return FALSE;
}
/************************************************************/
/************************************************************/