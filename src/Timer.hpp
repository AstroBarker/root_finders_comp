#ifndef _TIMER_HPP_
#define _TIMER_HPP_

/**
 * File     :  Timer.hpp
 * --------------
 *
 * Author   : Brandon L. Barker
 *   Inspiration from of https://gist.github.com/mcleary/b0bf4fa88830ff7c882d
 * Purpose  : Simple timer class
 **/

#include <chrono>

class Timer {
 public:
  void start( ) {
    m_StartTime = std::chrono::steady_clock::now( );
    m_bRunning  = true;
  }
  void stop( ) {
    m_EndTime  = std::chrono::steady_clock::now( );
    m_bRunning = false;
  }

  double elapsedNanoseconds( ) {
    std::chrono::time_point<std::chrono::steady_clock> endTime;

    // if we haven't stopped the timer, use current time
    if ( m_bRunning ) {
      endTime = std::chrono::steady_clock::now( );
    } else {
      endTime = m_EndTime;
    }

    return std::chrono::duration_cast<std::chrono::nanoseconds>( endTime -
                                                                  m_StartTime )
        .count( );
  }


  /* support microseconds up to hours (days+ requires C++20) */
  double elapsedMicroseconds( ) { return elapsedNanoseconds( ) / 1.0e3; }
  double elapsedMilliseconds( ) { return elapsedNanoseconds( ) / 1.0e6; }
  double elapsedSeconds( ) { return elapsedNanoseconds( ) / 1.0e9; }
  double elapsedMinutes( ) { return elapsedSeconds( ) / 60.0; }
  double elapsedHours( ) { return elapsedMinutes( ) / 60.0; }

 private:
  std::chrono::time_point<std::chrono::steady_clock> m_StartTime;
  std::chrono::time_point<std::chrono::steady_clock> m_EndTime;
  bool m_bRunning = false;
};

#endif // _TIMER_HPP_
