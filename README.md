# WorkTrack

WorkTrack utlizes a red black tree structure to keep work projects organized that is able to be quickly searched and altered. Worktrack uses a command line interface that can be accessed by using the run app function. It tracks job details such as customer name, cost of job, employee assigned, pay status, due date, and time estimate. 

A red black tree is a type of self balancing tree that use color coding in order to maintain the balance with each node being designated either red or black.

invarients of a red black tree:

- root node is always black
-  red node cannot have a red child
- every path from root to bottom must maintain the same number of black nodes

By running the app you are able to access the menu which brings up a list of functions including

search (searches for all jobs that a customer has)
new (creates a new node, inputs data, then inserts the node into the tree)
delete (removes a node from the tree)
save (writes current tree data into a txt file)
load (converts txt file into a tree)
clear (erases current data from txt file)
menu (reprints menu for reference)

*All inputs are required to be lowercase and any spaces used must be replaced by a "_"*

The save function converes your current data and writes it to the empty txt file included. Once you have a save you run the load function to convert the txt file back into nodes and inserts them into your current tree. If you want to clear your save data you can run the clear function.
