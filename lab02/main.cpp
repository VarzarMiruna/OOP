// Design a C++ class named Movie that reflects the properties of a movie. The class should include the following:
// - methods to set and get the name of the movie(max 256 characters);
// - methods to set and get the release year;
// - methods to set and get the IMDB score(a double with values between 1 and 10);
// - methods to set and get the length of a movie, in minutes;
// - a method to get the number of passed years since the release(calculated at every call);
// - 5 global functions that compare two movies in terms of name, released year, IMDB score, length, and earpassed ys.
// 
// The last functions will return an int with the values :
// -1 if first < second;
// 0 if first == second;
// 1 if first > second;
//
// Design a second class named MovieSeries that is able to hold at most 16 movies as pointers. The class will have
// methods for:
// - initialization (setting the count to 0);
// - adding a Movie as a pointer;
// - printing the information about the movies, each on a line;
// - sorting the movies descending after the number of passed years since the release;
//
// Make sure that you have the following for each class:
// - header (.h) file for the class declaration;
// - source (.cpp) file for the methods specific to the class;
// - the variables should be private and the functions public;
// 
// Also:
// - a header file for the global functions declaration;
// - a cpp file for the global functions implementation;
// - a main file called main.cpp that contains the main function with the code from below;
#include "Movie.h"
#include <iostream>

int main() {
    Movie ep5;
    ep5.set_name((char*)"Star Wars: Episode V - The Empire Strikes Back");
    ep5.set_score(8.7);
    ep5.set_year(1980);
    ep5.set_length(124);

    Movie ep4;
    ep4.set_name((char*)"Star Wars: Episode IV - A New Hope");
    ep4.set_score(8.6);
    ep4.set_year(1977);
    ep4.set_length(121);

    Movie ep6;
    ep6.set_name((char*)"Star Wars: Episode VI - Return of the Jedi");
    ep6.set_score(8.3);
    ep6.set_year(1983);
    ep6.set_length(131);
   
   printf(
 R"(
ep4, ep5 comparisons:
name        : %d
year        : %d
score       : %d
length      : %d
passed years: %d
)", movie_compare_name(ep4, ep5),
movie_compare_year(ep4, ep5),
movie_compare_score(ep4, ep5),
movie_compare_length(ep4, ep5),
movie_compare_passed_years(ep4, ep5));

   /* MovieSeries series;
    series.init();
    series.add(&ep5);
    series.add(&ep4);
    series.add(&ep6);

    series.sort();
    series.print();*/
}