//  Copyright 2011 Vicente J. Botet Escriba

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/chrono/chrono.hpp>
#include <boost/chrono/chrono_io.hpp>
#include <boost/chrono/date/date.hpp>

using namespace boost::chrono;
const int ntimes = 100000000;
int main()
{
  typedef boost::chrono::high_resolution_clock Clock;
  typedef boost::chrono::duration<double> sec;
  //////////////////////
  {
    int cnt = 0;
    Clock::time_point t0 = Clock::now();
    for (int x = 0; x < ntimes; ++x)
      for (int y = 1; y <= 12; ++y)
      {
        cnt += y+x;
        //if (cnt %4096==0) std::cout << cnt << " ";
      }
    //std::cout << std::endl;
    Clock::time_point t1 = Clock::now();
    std::cout << "none:     " << t1 - t0 << " " << cnt << "\n";
  }
  {
    int cnt = 0;
    Clock::time_point t0 = Clock::now();
    for (int x = 0; x < ntimes; ++x)
      for (int y = 1; y <= 12; ++y)
      {
        cnt += month(y,no_check)+x;
        //if (cnt %4096==0) std::cout << cnt << " ";
      }
    //std::cout << std::endl;
    Clock::time_point t1 = Clock::now();
    std::cout << "no_check: " << t1 - t0 << " " << cnt << "\n";
  }
  {
    int cnt = 0;
    Clock::time_point t0 = Clock::now();
    for (int x = 0; x < ntimes; ++x)
      for (int y = 1; y <= 12; ++y)
      {
        //month aYear(y);
        cnt += month(y)+x;
        //if (cnt %4096==0) std::cout << cnt << " ";
      }
    //std::cout << std::endl;
    Clock::time_point t1 = Clock::now();
    std::cout << "   check: " << t1 - t0 << " " << cnt << "\n";
  }
  //////////////////////
  {
    int cnt = 0;
    Clock::time_point t0 = Clock::now();
    for (int x = 0; x < ntimes; ++x)
      for (int y = 1; y <= 12; ++y)
      {
        cnt += y+x;
        //if (cnt %4096==0) std::cout << cnt << " ";
      }
    //std::cout << std::endl;
    Clock::time_point t1 = Clock::now();
    std::cout << "none:     " << t1 - t0 << " " << cnt << "\n";
  }
  {
    int cnt = 0;
    Clock::time_point t0 = Clock::now();
    for (int x = 0; x < ntimes; ++x)
      for (int y = 1; y <= 12; ++y)
      {
        cnt += month(y, no_check)+x;
        //if (cnt %4096==0) std::cout << cnt << " ";
      }
    //std::cout << std::endl;
    Clock::time_point t1 = Clock::now();
    std::cout << "no_check: " << t1 - t0 << " " << cnt << "\n";
  }
  {
    int cnt = 0;
    Clock::time_point t0 = Clock::now();
    for (int x = 0; x < ntimes; ++x)
      for (int y = 1; y <= 12; ++y)
      {
        //month aYear(y);
        cnt += month(y)+x;
        //if (cnt %4096==0) std::cout << cnt << " ";
      }
    //std::cout << std::endl;
    Clock::time_point t1 = Clock::now();
    std::cout << "   check: " << t1 - t0 << " " << cnt << "\n";
  }
  //////////////////////
  {
    int cnt = 0;
    Clock::time_point t0 = Clock::now();
    for (int x = 0; x < ntimes; ++x)
      for (int y = 1; y <= 12; ++y)
      {
        cnt += y+x;
        //if (cnt %4096==0) std::cout << cnt << " ";
      }
    //std::cout << std::endl;
    Clock::time_point t1 = Clock::now();
    std::cout << "none:     " << t1 - t0 << " " << cnt << "\n";
  }
  {
    int cnt = 0;
    Clock::time_point t0 = Clock::now();
    for (int x = 0; x < ntimes; ++x)
      for (int y = 1; y <= 12; ++y)
      {
        //month aYear(y,no_check);
        cnt += month(y, no_check)+x;
        //if (cnt %4096==0) std::cout << cnt << " ";
      }
    //std::cout << std::endl;
    Clock::time_point t1 = Clock::now();
    std::cout << "no_check: " << t1 - t0 << " " << cnt << "\n";
  }
  {
    int cnt = 0;
    Clock::time_point t0 = Clock::now();
    for (int x = 0; x < ntimes; ++x)
      for (int y = 1; y <= 12; ++y)
      {
        cnt += month(y)+x;
        //if (cnt %4096==0) std::cout << cnt << " ";
      }
    //std::cout << std::endl;
    Clock::time_point t1 = Clock::now();
    std::cout << "   check: " << t1 - t0 << " " << cnt << "\n";
  }
  Clock::duration none_d;
  {
    int cnt = 0;
    Clock::time_point t0 = Clock::now();
    for (int x = 0; x < ntimes; ++x)
      for (int y = 1; y <= 12; ++y)
      {
        cnt += y+x;
        //if (cnt %4096==0) std::cout << cnt << " ";
      }
    //std::cout << std::endl;
    Clock::time_point t1 = Clock::now();
    none_d=t1 - t0;
    std::cout << "none:     " << t1 - t0 << " " << cnt << "\n";
  }
  Clock::duration no_check_d;
  {
    int cnt = 0;
    Clock::time_point t0 = Clock::now();
    for (int x = 0; x < ntimes; ++x)
      for (int y = 1; y <= 12; ++y)
      {
        cnt += month(y, no_check)+x;
        //if (cnt %4096==0) std::cout << cnt << " ";
      }
    //std::cout << std::endl;
    Clock::time_point t1 = Clock::now();
    no_check_d=t1 - t0;
    std::cout << "no_check: " << t1 - t0 << " " << cnt << "\n";
  }
  Clock::duration check_d;
  {
    int cnt = 0;
    Clock::time_point t0 = Clock::now();
    for (int x = 0; x < ntimes; ++x)
      for (int y = 1; y <= 12; ++y)
      {
        //month aYear(y);
        cnt += month(y)+x;
        //if (cnt %4096==0) std::cout << cnt << " ";
      }
    //std::cout << std::endl;
    Clock::time_point t1 = Clock::now();
    check_d=t1 - t0;
    std::cout << "   check: " << t1 - t0 << " " << cnt << "\n";
  }
  std::cout << "   check-none: " << (check_d-none_d) <<  "\n";
  std::cout << "   no_check-none: " << (no_check_d-none_d)  << "\n";

  return 1;

}
