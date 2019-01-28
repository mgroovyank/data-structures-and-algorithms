/* Web tracking. Suppose that you are tracking n web sites and m users and you want to support the following API:

User visits a website.
How many times has a given user visited a given site?
What data structure or data structures would you use?

Hint: maintain a symbol table of symbol tables. */
/*
Solution - 

You can maintain a linked list of users.
Each user in the users linked list should point to the next user as well as the correspoding linked list storing website related data.

The website related data for each user is stored in separate linked lists.
this means that number of website related linked lists is equal to number of users.

So the total number of linked lists you need to maintain is 1 + n; where n is number of users.
each of the n linked lists have m nodes; where m is number of websites.

@author mgroovyank(MAYANK CHHIPA)
 
*/
