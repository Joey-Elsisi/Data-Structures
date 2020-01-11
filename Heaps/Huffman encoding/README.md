


## Assignment:

The basic steps in compression are:

1.  Read the source file and determine the frequencies of the characters in the file.
2.  Store the character frequencies in a heap (priority queue).
3.  Build a tree of prefix codes (a Huffman code) that determines the unique bit codes for each character.
4.  Write the prefix codes to the output file, following the file format above.
5.  Re-read the source file and for each character read, write its prefix code to the output, following the file format described herein.

We are also writing additional information to the file (compression ratio and tree cost), as described herein.

The basic steps in decompression are:

1.  Read in the prefix code structure from the compressed file. You can NOT assume that you can re-use the tree currently in memory, as we will be testing your in-lab code on files that you have not encoded.
2.  Re-create the Huffman tree from the code structure read in from the file.
3.  Read in one bit at a time from the compressed file and move through the prefix code tree until a leaf node is reached.
4.  Output the character stored at the leaf node.
5.  Repeat the last two steps until the encoded file is finished.
## Testing :
Use these files to test first the encoding, then the decoding. There should be no difference in the string of characters before and after being run in both huffman files.
-   [normal1.txt](https://uva-cs.github.io/pdr/labs/lab10/examples/normal1.txt)  /  [encoded1.txt](https://uva-cs.github.io/pdr/labs/lab10/examples/encoded1.txt): This is the first example from the lecture slides (`dbacaad`). The Huffman tree can be viewed  [here](https://uva-cs.github.io/pdr/labs/lab10/prelab-tree.png).
-   [normal2.txt](https://uva-cs.github.io/pdr/labs/lab10/examples/normal2.txt)  /  [encoded2.txt](https://uva-cs.github.io/pdr/labs/lab10/examples/encoded2.txt): This is the second example from the lecture slides, in the "Huffman Encoding" section. This is the example that we built up the Huffman tree from. The Huffman tree can be viewed  [here](https://uva-cs.github.io/pdr/labs/lab10/inlab-tree-2.png).
-   [normal3.txt](https://uva-cs.github.io/pdr/labs/lab10/examples/normal3.txt)  /  [encoded3.txt](https://uva-cs.github.io/pdr/labs/lab10/examples/encoded3.txt): This is a paragraph from  [Gadsby](http://en.wikipedia.org/wiki/%20Gadsby_%28novel%29), which is a novel that does not ever use the letter 'e'.
-   [normal4.txt](https://uva-cs.github.io/pdr/labs/lab10/examples/normal4.txt)  /  [encoded4.txt](https://uva-cs.github.io/pdr/labs/lab10/examples/encoded4.txt): The first paragraph from a  [front page story in the 27 November 2007 edition of the Cavalier Daily](http://www.cavalierdaily.com/CVArticle.asp?ID=31789&pid=1656).
    -   [encoded4a.txt](https://uva-cs.github.io/pdr/labs/lab10/examples/encoded4a.txt): This is the same encoding as the previous file ([encoded4.txt](https://uva-cs.github.io/pdr/labs/lab10/examples/encoded4.txt)), but with all spaces in the middle section of the file removed, so that it's just a very long string of  `0`s and  `1`s.

## Report:
A report including the space and time complexities of my implementation has been included, with reasoning for why I went about choosing the data structures that I did. 
