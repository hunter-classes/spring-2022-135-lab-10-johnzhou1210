#pragma once

enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};

class Movie {
public:
  std::string title;
  Genre genre; // only one genre per Movie
  int duration; // in minutes
};

std::string movieStr(Movie mv);
