Reading 06
==========

A. MapReduce attempts to break down big problems and processes into smaller processes over multiple nodes. It allows for solutions that worked on smaller problems to be scaled to larger projects. 

B. There are three phases, the "map" step, the "shuffle" step, and the "reduce" step. The map step applies the map function to the local data and writes the output to temporary storage. The shuffle step then works to redistribute data based on the output produced by the map function. The reduce step processes each group of output data in parallel. 
