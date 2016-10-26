PROJECT
-------

Random Keyboard Mapping

AUTHOR
------

Shenli Yuan [shenliy@stanford.edu](mailto:shenliy@stanford.edu)

FUNCTIONALITY
------------

This plug in remap the midi keynotes from input (128 notes). The slider has 8 levels, with 0 being no remapping and 7 being entirely random. At each level n, the 128 notes are divided evenly into 128/(2^n) segments and 2^n in each segments. The notes are shuffled in each segment. e.g. if n = 1, 128 notes are divided into half, the notes in each half will be shuffled. 

