//
// Created by Larry on 2022/1/2.
//

#ifndef APUE_BOOST_RANDOM_H
#define APUE_BOOST_RANDOM_H

// #include <boost/random/mersenne_twister.hpp>
#include <boost/random/random_device.hpp>
#include <boost/random/uniform_int_distribution.hpp>
#include <iostream>

int runRandom() {
  int guessNumber;
  std::cout << "Select number among 0 to 10: ";
  std::cin >> guessNumber;
  if (guessNumber < 0 || guessNumber > 10) {
    return 1;
  }
  // boost::random::mt19937 rng;
  boost::random::random_device rng;
  boost::random::uniform_int_distribution<> ten(0, 10);
  int randomNumber = ten(rng);
  if (guessNumber == randomNumber) {
    std::cout << "Congratulation, " << guessNumber << " is your lucky number.\n";
  } else {
    std::cout << "Sorry, I'm thinking about number " << randomNumber << "\n";
  }
  return 0;
}

#endif //APUE_BOOST_RANDOM_H
