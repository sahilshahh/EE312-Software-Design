#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_URL_LENGTH 100
//#define _CRT_SECURE_NO_WARNINGS

 struct tnode { /* the tree node: */
   char *key; /* points to the url string */
   int count; /* number of occurrences */
   struct tnode *left; /* left child */
   struct tnode *right; /* right child */
 };


 /* add_to_tree:  add a node with url, at or below p 
  * p: pointer to the root of the (sub)tree where you must add a value
  * url: the URL to be added
  */
 struct tnode* add_to_tree(struct tnode* p, char* url)
 {
	 int x;
	 struct tnode* node;
	 struct tnode* nextnode;
	 char* nodeurl;
	 char* urls = (char*)malloc(strlen(url) + 1);

	 if (p) {
		 nodeurl = p->key;
		 strcpy(urls, url);
		 x = strcmp(urls, nodeurl);
		 if (x < 0) {					//left node
			 nextnode = (p->left);
			 if ((p->left)) {
				 add_to_tree(nextnode, url);
				 return p;
			 }
			 else {
				 node = (struct tnode*)malloc(sizeof(struct tnode));
				 node->count = 1;
				 node->key = url;
				 node->left = NULL;
				 node->right = NULL;
				 (p->left) = node;
				 return p;
			 }
		 }
		 else if (x > 0) {				//right node
			 nextnode = (p->right);
			 if ((p->right)) {
				 add_to_tree(nextnode, url);
				 return p;
			 }
			 else {						
				 node = (struct tnode*)malloc(sizeof(struct tnode));
				 node->count = 1;
				 node->key = url;
				 node->left = NULL;
				 node->right = NULL;
				 (p->right) = node;
				 return p;
			 }
		 }
		 else {							//node
			 p->count++;
			 return p;
		 }
	 }
	 else {								//have to create first node
		 node = (struct tnode*)malloc(sizeof(struct tnode));
		 node->count = 1;
		 node->key = url;	
		 node->left = NULL;
		 node->right = NULL;
		 return node;
	 }

 }


 /* populate_tree: repeatedly call add_to_tree on urls from a file 
  * url_file: name of file to read URLs from
  * R: pointer to the root pointer of the tree
  */
 void populate_tree(char *url_file, struct tnode** R)
 {
	 int x;
	 char temp[MAX_URL_LENGTH];
	 char* url;
	 char* check;
	 char* check1;
	 FILE* fp = fopen(url_file, "r");
	 while (!feof(fp)) {
		 check1 = fgets(temp, MAX_URL_LENGTH, fp);
		 if (check1) {
			 url = (char*)malloc(MAX_URL_LENGTH + 1);
			 strcpy(url, temp);
			 check = url;
			 for (x = 0; x<MAX_URL_LENGTH; x++) {
				 if (*check == '\n') {
					 *check = NULL;
					 break;
				 }
				 check++;
			 }
			 add_to_tree(*R, url);
		 }
	 }
	 fclose(fp);
	 return;
 }





 /* lookup:  look up a url in the tree rooted at p, return the frequency of that url
  * p: pointer to the root of the (sub)tree
  * url: url to look for
  */
 int lookup(struct tnode* p, char* url) // Return the frequency of the url
 {
	 int x;
	 struct tnode* nextnode;
	 char* nodeurl;
	 char urlarray[MAX_URL_LENGTH];
	 char* b;

	 if (p) {						//p isn't null
		 nodeurl = p->key;
		 b = urlarray;

		 strcpy(b, url);
		 x = strcmp(b, nodeurl);

		 if (x < 0) {
			 nextnode = (p->left);
			 if ((p->left)) {		//recursive call
				 return lookup(nextnode, url);
			 }
			 else {					//end of branch
				 return 0;
			 }
		 }

		 else if (x > 0) {
			 nextnode = (p->right);
			 if ((p->right)) {		//recursive call
				 return lookup(nextnode, url);
			 }
			 else {                 //end of branch
				 return 0;
			 }
		 }

		 else {						//the node
			 return (p->count);
		 }

	 }
	 else { 
		 return 0; 
	 }
 }


 /* treeprint:  in-order print of tree p
  * Set the urls in the passed in array in alphabetical fashion. Also set their respective frequencies in a second int array.
  * Return the number of elements set
  * size: how many elements you have currently inserted into the array(s)
  * p: pointer to the root of the (sub)tree
  * URL_array: array to store URLs in
  * n: integer array to store frequencies in
  */ 
int treeprint(int size, struct tnode* p, char URL_array[][MAX_URL_LENGTH], int *n)
{
	if (size < 10) {
		if (p->left) {			//left node is valid
			if (size<10) {
				size = treeprint(size, (p->left), URL_array, n);
			}
		}
		if (p) {				//current node
			if (size<10) {
				strcpy(&URL_array[size][0], p->key);
				*(n + size) = p->count;
				size++;
			}
		}
		if (p->right) {			//right node
			if (size<10) {
				size = treeprint(size, (p->right), URL_array, n);
			}
		}
	}
	return size;
}

