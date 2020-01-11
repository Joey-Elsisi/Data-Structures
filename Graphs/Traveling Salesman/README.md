


## Assignment:

//middleearth files written by Aaron Bloomfield

The world we have chosen is  [Middle-Earth](http://en.wikipedia.org/wiki/Middle-earth), the location of J.R.R. Tolkien's Hobbit and Lord of the Rings books and movies. The middleearth.h and middleearth.cpp files, that you commented in the pre-lab, contain a class that will create a random 2-dimensional world. The "randomness" means that it will pick a given number of cities (or places), and randomly place them in the "world". You can travel from any city to any other city, for a given cost (the distance). The city names are all from the books and movies, and can be seen at the beginning of the middleearth.cpp file -- there is a textual description in the code as to what all the places are. The randomness of the world means that cities that are nowhere near each other in the books/movies might be right next to each other in the random world.

When your program is completed, you will need to specify five command-line parameters to execute the traveling salesperson problem. The parameters are, in order:

1.  The x-size (i.e. width) of the world. We'll use 20 throughout this lab.
2.  The y-size (i.e. height) of the world. We'll use 20 throughout this lab.
3.  The number of cities in the world. There are currently 40 names specified at the top of middleearth.cpp, so you can't specify more than 40 cities.
4.  The random seed. If you specify a given number, the same world will be created each time -- we'll use this, below, when we talk about debugging. Supplying -1 will create a different random world each time the program is run.
5.  The number of cities to visit, other than the "home" city -- this can be as low as 1.
### Sample output

The Linux results for a random seed of 14, world size of 20x20 with 20 cities, and various path lengths:

1.  Minimum path has distance 16.4499: Dunharrow -> The Grey Havens -> Dunharrow
2.  Minimum path has distance 38.5555: Dunharrow -> Hobbiton -> The Grey Havens -> Dunharrow
3.  Minimum path has distance 39.1172: Dunharrow -> Cirith Ungol -> Hobbiton -> The Grey Havens -> Dunharrow
4.  Minimum path has distance 44.6487: Dunharrow -> Cirith Ungol -> Hobbiton -> The Grey Havens -> Lothlorien -> Dunharrow
5.  Minimum path has distance 51.7731: Dunharrow -> Cirith Ungol -> Hobbiton -> Minas Tirith -> The Grey Havens -> Lothlorien -> Dunharrow
6.  Minimum path has distance 53.8414: Dunharrow -> Cirith Ungol -> Edoras -> Hobbiton -> Minas Tirith -> The Grey Havens -> Lothlorien -> Dunharrow
7.  Minimum path has distance 53.9410: Dunharrow -> Cirith Ungol -> Edoras -> Hobbiton -> Minas Tirith -> The Grey Havens -> Mirkwood -> Lothlorien -> Dunharrow
8.  Minimum path has distance 53.9495: Dunharrow -> Lothlorien -> Mirkwood -> The Grey Havens -> Minas Tirith -> Weathertop -> Hobbiton -> Edoras -> Cirith Ungol -> Dunharrow
9.  Minimum path has distance 55.6973: Dunharrow -> Edoras -> Cirith Ungol -> Dagorlad -> Hobbiton -> Weathertop -> Minas Tirith -> The Grey Havens -> Mirkwood -> Lothlorien -> Dunharrow
10.  Minimum path has distance 55.7040: Dunharrow -> Lothlorien -> Mirkwood -> Orodruin -> The Grey Havens -> Minas Tirith -> Weathertop -> Hobbiton -> Dagorlad -> Cirith Ungol -> Edoras -> Dunharrow

Note that your cycle may be the same cities but in reverse; this is perfectly acceptable.
