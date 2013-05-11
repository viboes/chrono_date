//  ymd_date
//
//  (C) Copyright Howard Hinnant
//  Copyright 2011 Vicente J. Botet Escriba
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#ifndef BOOST_CHRONO_DATE_YMD_DATE_HPP
#define BOOST_CHRONO_DATE_YMD_DATE_HPP

#define BOOST_CHRONO_DATE_YMD_DATE_HAS_LEAP_FIELD

#include <boost/cstdint.hpp>
#include <boost/chrono/system_clocks.hpp>
#include <boost/chrono/date/date_durations.hpp>
#include <boost/chrono/date/no_check.hpp>
#include <boost/chrono/date/date_durations.hpp>
#include <boost/chrono/date/exceptions.hpp>
#include <boost/chrono/date/year.hpp>
#include <boost/chrono/date/month.hpp>
#include <boost/chrono/date/day.hpp>
#include <boost/chrono/date/day_of_year.hpp>
#include <boost/chrono/date/weekday.hpp>
#include <boost/chrono/date/week.hpp>
#include <boost/chrono/date/tuples.hpp>
#include <boost/chrono/date/config.hpp>
#include <boost/chrono/date/days_date.hpp>
#include <boost/chrono/date/optional_date.hpp>
#include <boost/chrono/date/is_date.hpp>

namespace boost
{
  namespace chrono
  {

    /**
     * The class @c ymd_date is a model of Date storing
     * - the @c year,
     * - the @c month,
     * - the @c day of the month
     * - whether the year is leap or not.
     *
     * Provides month and year arithmetic, but not day arithmetic (see @c days_date).
     * Provides @c day, @c month, @c year, @c is_leap_year accessors, but tot @c weekday (see @c days_date).
     */
    class ymd_date
    {

//      // Store x, y/m/d, leap. Total 64 bits
//      int_least16_t y_;
//
//      uint_least8_t m_ ; //:4;
//      //int_least16_t reserved1_ :4;
//
//      uint_least8_t d_ :5;
//      uint_least8_t leap_ :1;
//      //uint_least8_t reserved2_ :2;

//      int_least16_t y_;
//      uint_least8_t m_ ; //:4;
//      uint_least8_t d_ ;
//      bool leap_ ;

#if defined  BOOST_CHRONO_DATE_YMD_DATE_HAS_LEAP_FIELD
#if defined __clang__
      int_least32_t y_;
      int_least16_t m_;
      int_least16_t d_;
#else
      int_least16_t y_;
      int_least8_t m_;
      int_least8_t d_;
#endif
      bool leap_ ;
#else
      int_least32_t y_;
      int_least16_t m_;
      int_least16_t d_;
#endif

    public:
#if ! defined  BOOST_CHRONO_DATE_DOXYGEN_INVOKED
    private:
      // emulates forwarding constructors
      void ymd_date_c(chrono::year::rep y, chrono::month::rep m, chrono::day::rep d, check_t);
#endif
      /**
       * @Effect Constructs a @c ymd_date using the @c year, @c month, @c day stored in the arguments as follows:
       * If the value stored in @c d is outside the range of valid dates for this month @c m and year @c y,
       * throws an exception of type @c bad_date.
       * Else constructs a @c ymd_date for which <c>year() == y && month() == m && day() == d</c>.
       * @Throws @c bad_date if the specified @c ymd_date is invalid.
       */
    public:
      ymd_date(chrono::year y, chrono::month m, chrono::day d, check_t)
      {
        ymd_date_c(y,m,d, check);
      }
      ymd_date(int y, chrono::month m, chrono::day d, check_t)
      {
        ymd_date_c(y,m,d, check);
      }
      ymd_date(chrono::year y, int m, chrono::day d, check_t)
      {
        ymd_date_c(y,m,d, check);
      }
      ymd_date(chrono::year y, chrono::month m, int d, check_t)
      {
        ymd_date_c(y,m,d, check);
      }

#if ! defined  BOOST_CHRONO_DATE_DOXYGEN_INVOKED
    private:
      // emulates forwarding constructors
      void ymd_date_c(chrono::year::rep y, chrono::month::rep m, chrono::day::rep d) BOOST_NOEXCEPT;
#endif
      /**
       * @Effect Constructs a @c ymd_date constructor from @c year, @c month, @c day stored in the arguments as follows:
       * Constructs a ymd_date so that <c>year() == y && month() = m && day() == d</c>.
       */
    public:

      BOOST_CHRONO_DATE_CONSTEXPR ymd_date(chrono::year y, chrono::month m, chrono::day d) BOOST_NOEXCEPT :
        y_(y),
        m_(m),
        d_(d)
#if defined  BOOST_CHRONO_DATE_YMD_DATE_HAS_LEAP_FIELD
        , leap_(boost::chrono::is_leap(y_))
#endif
      {
      }
      BOOST_CHRONO_DATE_CONSTEXPR ymd_date(int y, chrono::month m, chrono::day d) BOOST_NOEXCEPT :
      y_(y),
      m_(m),
      d_(d)
#if defined  BOOST_CHRONO_DATE_YMD_DATE_HAS_LEAP_FIELD
      , leap_(boost::chrono::is_leap(y_))
#endif
    {
    }
      BOOST_CHRONO_DATE_CONSTEXPR ymd_date(chrono::year y, int m, chrono::day d) BOOST_NOEXCEPT :
      y_(y),
      m_(m),
      d_(d)
#if defined  BOOST_CHRONO_DATE_YMD_DATE_HAS_LEAP_FIELD
      , leap_(boost::chrono::is_leap(y_))
#endif
    {
    }
      BOOST_CHRONO_DATE_CONSTEXPR ymd_date(chrono::year y, chrono::month m, int d) BOOST_NOEXCEPT :
      y_(y),
      m_(m),
      d_(d)
#if defined  BOOST_CHRONO_DATE_YMD_DATE_HAS_LEAP_FIELD
      , leap_(boost::chrono::is_leap(y_))
#endif
    {
    }

      BOOST_CHRONO_DATE_CONSTEXPR ymd_date(chrono::month m, chrono::day d, chrono::year y) BOOST_NOEXCEPT :
      y_(y),
      m_(m),
      d_(d)
#if defined  BOOST_CHRONO_DATE_YMD_DATE_HAS_LEAP_FIELD
      , leap_(boost::chrono::is_leap(y_))
#endif
    {
    }
      BOOST_CHRONO_DATE_CONSTEXPR ymd_date(chrono::month m, chrono::day d, int y) BOOST_NOEXCEPT :
      y_(y),
      m_(m),
      d_(d)
#if defined  BOOST_CHRONO_DATE_YMD_DATE_HAS_LEAP_FIELD
      , leap_(boost::chrono::is_leap(y_))
#endif
    {
    }
      BOOST_CHRONO_DATE_CONSTEXPR ymd_date(chrono::month m, int d, chrono::year y) BOOST_NOEXCEPT :
      y_(y),
      m_(m),
      d_(d)
#if defined  BOOST_CHRONO_DATE_YMD_DATE_HAS_LEAP_FIELD
      , leap_(boost::chrono::is_leap(y_))
#endif
    {
    }
      BOOST_CHRONO_DATE_CONSTEXPR ymd_date(int m, chrono::day d, chrono::year y) BOOST_NOEXCEPT :
      y_(y),
      m_(m),
      d_(d)
#if defined  BOOST_CHRONO_DATE_YMD_DATE_HAS_LEAP_FIELD
      , leap_(boost::chrono::is_leap(y_))
#endif
    {
    }
      BOOST_CHRONO_DATE_CONSTEXPR ymd_date(chrono::day d, chrono::month m, chrono::year y) BOOST_NOEXCEPT :
      y_(y),
      m_(m),
      d_(d)
#if defined  BOOST_CHRONO_DATE_YMD_DATE_HAS_LEAP_FIELD
      , leap_(boost::chrono::is_leap(y_))
#endif
    {
    }
      BOOST_CHRONO_DATE_CONSTEXPR ymd_date(chrono::day d, chrono::month m, int y) BOOST_NOEXCEPT :
      y_(y),
      m_(m),
      d_(d)
#if defined  BOOST_CHRONO_DATE_YMD_DATE_HAS_LEAP_FIELD
      , leap_(boost::chrono::is_leap(y_))
#endif
    {
    }
      BOOST_CHRONO_DATE_CONSTEXPR ymd_date(chrono::day d, int m, chrono::year y) BOOST_NOEXCEPT :
      y_(y),
      m_(m),
      d_(d)
#if defined  BOOST_CHRONO_DATE_YMD_DATE_HAS_LEAP_FIELD
      , leap_(boost::chrono::is_leap(y_))
#endif
    {
    }
      BOOST_CHRONO_DATE_CONSTEXPR ymd_date(int d, chrono::month m, chrono::year y) BOOST_NOEXCEPT :
      y_(y),
      m_(m),
      d_(d)
#if defined  BOOST_CHRONO_DATE_YMD_DATE_HAS_LEAP_FIELD
      , leap_(boost::chrono::is_leap(y_))
#endif
    {
    }
      /**
       * @Effect Constructs a ymd_date using the year, month_day stored in the arguments as follows:
       * If the value stored in md is outside the range of valid dates for this year y,
       * throws an exception of type bad_date.
       * Else constructs a ymd_date for which year(*this) == y, month(*this) == month(md), day(*this) == day(md).
       *
       * @Throws bad_date if the specified ymd_date is invalid.
       * @Note This constructor can be more efficient as the month_day is already valid.
       */
      ymd_date(chrono::year y, month_day md, check_t);
      /**
       * @Effect Constructs a ymd_date using the year, month_day stored in the arguments as follows:
       * Constructs a ymd_date for which year() == y, month() == month(md), day() == month(md).
       * @Note This constructor can be more efficient as the month_day is already valid.
       */
      ymd_date(chrono::year, month_day) BOOST_NOEXCEPT;

//      /**
//       * @Effect Constructs a ymd_date using the year, day_of_year stored in the arguments as follows:
//       * If the value stored in doy is 366 and the year.is_leap()
//       * throws an exception of type bad_date.
//       * Else constructs a ymd_date for which days_since_epoch() == y.days_since_epoch()+doy
//       * @Throws bad_date if the specified ymd_date is invalid.
//       * @Note This constructor can be more efficient as the check is simple.
//       */
//      ymd_date(chrono::year y, day_of_year doy, check_t);
//      /**
//       * @Effect Constructs a ymd_date using the year, day_of_year stored in the arguments as follows:
//       * Constructs a ymd_date for which days_since_epoch() == y.days_since_epoch()+doy
//       * @Throws bad_date if the specified ymd_date is invalid.
//       */
//      ymd_date(chrono::year y, day_of_year m) BOOST_NOEXCEPT;

//      /**
//       * @Effect Constructs a ymd_date using the days given as parameter so that:
//       * days_since_epoch() == ds.count()
//       */
//      explicit ymd_date(days, check_t);
//      /**
//       * Unchecked constructor from days.
//       */
//      ymd_date(days m) BOOST_NOEXCEPT;

      /**
       * Unchecked constructor from days+ymd+leap
       */
      BOOST_CHRONO_DATE_CONSTEXPR ymd_date(days::rep, year::rep y, month::rep m, day::rep d, bool leap) BOOST_NOEXCEPT
      :
      y_(y),
      m_(m),
      d_(d)
#if defined  BOOST_CHRONO_DATE_YMD_DATE_HAS_LEAP_FIELD
      , leap_(leap)
#endif
      {
      }
      /**
       * Unchecked constructor from ymd+leap
       */
      BOOST_CHRONO_DATE_CONSTEXPR ymd_date(year::rep y, month::rep m, day::rep d, bool leap) BOOST_NOEXCEPT
      : y_(y),
      m_(m),
      d_(d)
#if defined  BOOST_CHRONO_DATE_YMD_DATE_HAS_LEAP_FIELD
      , leap_(leap)
#endif
      {
      }

      /**
       * @Effects Update the ymd_date if the parameters represents a valid ymd_date.
       * @Returns true if the parameters represents a valid ymd_date.
       */
      bool set_if_valid_date(chrono::year y, chrono::month m, day d) BOOST_NOEXCEPT;
      /**
       * @Effects Update the ymd_date if the parameters represents a valid ymd_date.
       * @Returns true if the parameters represents a valid ymd_date.
       */
      bool set_if_valid_date(chrono::year y, day_of_year doy) BOOST_NOEXCEPT;

      /**
       * @Effects Update the ymd_date if the parameters represents a valid ymd_date.
       * @Returns true if the parameters represents a valid ymd_date.
       */
      bool set_if_valid_date(days d) BOOST_NOEXCEPT;

      /**
       * @Return A ymd_date which represents the current day taking the local time zone into account.
       */
      static ymd_date today() BOOST_NOEXCEPT;

      /**
       * Effects: Constructs a ymd_date as if by year(0)/jan/1.
       * Note: the purpose of this constructor is to have a very efficient means
       * of ymd_date construction when the specific value for that ymd_date is unimportant.
       */
      BOOST_CONSTEXPR ymd_date() BOOST_NOEXCEPT
      :
      y_(0),
      m_(1),
      d_(1)
#if defined  BOOST_CHRONO_DATE_YMD_DATE_HAS_LEAP_FIELD
      , leap_(true)
#endif
      {
      }
      /**
       * @Effects: tp is converted to UTC, and then trucated to 00:00:00 hours.
       * A ymd_date is created which reflects this point in time.
       * @Throws If the conversion from tp overflows the range of ymd_date, throws
       * an exception of type bad_date.
       *
       */
      explicit ymd_date(system_clock::time_point tp);
      /**
       * @Returns: A system_clock::time_point which represents the ymd_date
       * referred to by *this at 00:00:00 UTC.
       *
       * @Throws: If the conversion to tp overflows the range of
       * system_clock::time_point, throws an exception of type bad_date.
       *
       * @Notes Provided only of explicit conversion is supported (See @c to_date_clock_time_point()).
       */
      BOOST_CHRONO_EXPLICT operator system_clock::time_point () const;
//      /**
//       * @Returns: A system_clock::time_point which represents the ymd_date
//       * referred to by *this at 00:00:00 UTC.
//       *
//       * @Throws: If the conversion to tp overflows the range of
//       * system_clock::time_point, throws an exception of type bad_date.
//       *
//       */
//      system_clock::time_point to_date_clock_time_point() const { return system_clock::time_point(*this); }

      /**
       *
       * @Returns whether the year()/month()/day() is a valid proleptic Gregorian date.
       */
      // @todo BOOST_CONSTEXPR
      bool is_valid() const BOOST_NOEXCEPT;

//#if ! defined  BOOST_CHRONO_DATE_DOXYGEN_INVOKED
//    private:
//      /*
//       * @Returns: the number of days since an undefined epoch.
//       */
//      days days_since_epoch() const
//      {
//        return days(day_number_from_ymd());
//      }
//#endif
//    private:
//      /*
//       * @Returns: the number of days since an undefined epoch.
//       */
//      days to_days() const
//      {
//        return days(day_number_from_ymd());
//      }
    public:

      /**
       * Conversion from @c days_date
       */
      explicit ymd_date(days_date dt);
      /**
       * Conversion from @c days
       */
      explicit ymd_date(days d);

      /**
       * Conversion to @c days_date
       */
      //BOOST_CHRONO_EXPLICT
      operator days_date() const
      {
        return days_date(days(day_number_from_ymd()));
      }

      /**
       * Returns: chrono::day(d_).
       */
      BOOST_CONSTEXPR chrono::day to_day() const BOOST_NOEXCEPT
      {
        return chrono::day(d_);
      }
      /**
       * Returns: chrono::day(d_).
       */
      //BOOST_CONSTEXPR chrono::day day() const BOOST_NOEXCEPT
      BOOST_CHRONO_EXPLICT BOOST_CONSTEXPR operator chrono::day() const BOOST_NOEXCEPT
      {
        return chrono::day(d_);
      }
      /**
       * Returns: chrono::month(m_).
       */
      BOOST_CONSTEXPR chrono::month to_month() const BOOST_NOEXCEPT
      {
        return chrono::month(m_);
      }
      /**
       * Returns: chrono::month(m_).
       */
      //BOOST_CONSTEXPR chrono::month month() const BOOST_NOEXCEPT
      BOOST_CHRONO_EXPLICT BOOST_CONSTEXPR operator chrono::month() const BOOST_NOEXCEPT
      {
        return chrono::month(m_);
      }
      /**
       * Returns: chrono::year(y_).
       */
      BOOST_CONSTEXPR chrono::year to_year() const BOOST_NOEXCEPT
      {
        return chrono::year(y_);
      }
      /**
       * Returns: chrono::year(y_).
       */
      //BOOST_CONSTEXPR chrono::year year() const BOOST_NOEXCEPT
      BOOST_CHRONO_EXPLICT BOOST_CONSTEXPR operator chrono::year() const BOOST_NOEXCEPT
      {
        return chrono::year(y_);
      }
      chrono::month_day get_month_day() const BOOST_NOEXCEPT
      {
        return chrono::month_day(chrono::month(m_), chrono::day(d_));
      }
      chrono::year_month get_year_month() const BOOST_NOEXCEPT
      {
        return chrono::year_month(chrono::year(y_),chrono::month(m_));
      }
      chrono::year_month_day get_year_month_day() const BOOST_NOEXCEPT
      {
        return chrono::year_month_day(chrono::year(y_),chrono::month(m_),chrono::day(d_));
      }
      /**
       * Returns: whether year() is a leap year.
       */
      BOOST_CONSTEXPR bool is_leap_year() const BOOST_NOEXCEPT
      {
#if defined  BOOST_CHRONO_DATE_YMD_DATE_HAS_LEAP_FIELD
            return leap_;
#else
        return is_leap(y_);
#endif
      }

      /**
       * @Returns: A weekday constructed with an int corresponding to *this
       * ymd_date's day of the week (a value in the range of [0 - 6], 0 is Sunday).
       *
       * @Notes this function needs a conversion to @c days_date, so maybe you would do better to not use it.
       *
       */
      chrono::weekday to_weekday() const BOOST_NOEXCEPT
      {
        return chrono::weekday((day_number_from_ymd()+1) % chrono::weekday::size);
      }

//      /**
//       * @Effects: Adds d.count() days to the current ymd_date.
//       * @Returns: *this.
//       * @Throws: If the addition would create a ymd_date with a y_ outside of the
//       * range of year, throws an exception of type bad_date.
//       *
//       */
//      ymd_date& operator+=(days d);
//
//      /**
//       * @Effects: *this += days(1).
//       * @Returns: *this.
//       */
//      ymd_date& operator++()
//      {
//        return *this += days(1);
//      }
//      /**
//       * @Effects: *this += days(1).
//       * @Returns: A copy of *this prior to the increment.
//       */
//      ymd_date operator++(int)
//      {
//        ymd_date tmp(*this);
//        ++(*this);
//        return tmp;
//      }
//      /**
//       * @Effects: *this += -d.
//       * @Returns: *this.
//       */
//      ymd_date& operator-=(days d)
//      {
//        return *this += -d;
//      }
//      /**
//       * @Effects: *this -= days(1).
//       * @Returns: *this.
//       */
//      ymd_date& operator--()
//      {
//        return *this -= days(1);
//      }
//      /**
//       * @Effects: *this -= days(1).
//       * @Returns: A copy of *this prior to the increment.
//       */
//      ymd_date operator--(int)
//      {
//        ymd_date tmp(*this); --(*this); return tmp;
//      }
//
//      /**
//       * @Returns: dt += d.
//       *
//       */
//      friend ymd_date operator+(ymd_date dt, days d)
//      {
//        dt += d;
//        return dt;
//      }
//      /**
//       * @Returns: dt += d.
//       *
//       */
//      friend ymd_date operator+(days d, ymd_date dt)
//      {
//        dt += d;
//        return dt;
//      }
//      /**
//       * @Returns: dt -= d.
//       *
//       */
//      friend ymd_date operator-(ymd_date dt, days d)
//      {
//        dt -= d;
//        return dt;
//      }
//      /**
//       * @Returns: Computes the number of days x is ahead of y in the calendar,
//       * and returns that signed integral number n as days(n).
//       */
//      friend days operator-(ymd_date x, ymd_date y) BOOST_NOEXCEPT
//      {
//        return days(x.days_since_epoch() - y.days_since_epoch());
//      }
//      friend days operator-(days_date x, ymd_date y) BOOST_NOEXCEPT
//      {
//        return days(x.days_since_epoch() - y.days_since_epoch());
//      }
//      friend days operator-(ymd_date x, days_date y) BOOST_NOEXCEPT
//      {
//        return days(x.days_since_epoch() - y.days_since_epoch());
//      }

      /**
       * @Effects Adds m.count() months to the current ymd_date.
       * This is accomplished as if by storing temporary values of the ymd_date's y_, m_, d_.
       * Computing new values for y_ and m_ based on m. And then assigning to
       * *this a new ymd_date constructed from the newly computed y_ and m_, and the
       * original d_.
       *
       * @Note Thus for example if a ymd_date is constructed as the second Sunday
       * in May, adding two months to this ymd_date results in the second Sunday
       * in July.
       *
       * @Returns: *this.
       *
       * @Throws: If the addition would create a ymd_date with a y_ outside of the
       * range of year, or a d_ outside the range for the newly computed y_/m_,
       * throws an exception of type bad_date.
       *
       */
      ymd_date& operator+=(months m);

      /**
       * Returns: *this += -m.
       */
      ymd_date& operator-=(months m)
      {
        return *this += months(-m.count());
      }

      /**
       * @Returns: dt += m.
       *
       */
      friend ymd_date operator+(ymd_date dt, months m)
      {
        dt += m;
        return dt;
      }
      /**
       * @Returns: dt += m.
       *
       */
      friend ymd_date operator+(months m, ymd_date dt)
      {
        dt += m;
        return dt;
      }
      /**
       * @Returns: dt += -m.
       *
       */
      friend ymd_date operator-(ymd_date dt, months m)
      {
        dt -= m;
        return dt;
      }

      /*
       * @Effects: Adds y.count() years to the current ymd_date.
       * This is accomplished as if by storing temporary values of the ymd_date's
       * y_, m_, d_. Computing a new value for y_. And then assigning to *this
       * a new ymd_date constructed from the newly computed y_, and the original m_, d_.
       * @Note: Thus for example if a ymd_date is constructed as the second Sunday
       * in May 2011, adding two years to this ymd_date results in the second Sunday
       * in May 2013.
       * @Returns: *this.
       * @Throws: If the addition would create a ymd_date with a y_ outside of the
       * range of year, or a d_ outside the range for the newly computed y_/m_,
       * throws an exception of type bad_date.
       */
      ymd_date& operator+=(years y);

      /**
       * @Returns: *this += -y.
       *
       */
      ymd_date& operator-=(years y)
      {
        return *this += years(-y.count());
      }

      /**
       * @Returns: dt += y.
       *
       */
      friend ymd_date operator+(ymd_date dt, years y)
      {
        dt += y;
        return dt;
      }
      /**
       * @Returns: dt += y.
       *
       */
      friend ymd_date operator+(years y, ymd_date dt)
      {
        dt += y;
        return dt;
      }
      /**
       * @Returns: dt -= y.
       *
       */
      friend ymd_date operator-(ymd_date dt, years y)
      {
        dt -= y;
        return dt;
      }

      /**
       * Returns: x.year() == y.year() && x.month() == y.month() && x.day() == y.day()
       */
      friend BOOST_CONSTEXPR bool operator==(const ymd_date& x, const ymd_date& y) BOOST_NOEXCEPT
      {
        return x.y_ == y.y_ && x.m_ == y.m_ && x.d_ == y.d_;
      }
      /**
       * Returns: x.year_month_day() < y.year_month_day() in lexicographic order.
       */
      friend BOOST_CONSTEXPR bool operator< (const ymd_date& x, const ymd_date& y)
      {
        return x.y_ < y.y_ ||
        (!(y.y_ < x.y_) && (x.m_ < y.m_ ||
                (!(y.m_ < x.m_) && x.d_ < y.d_)));
      }

      /**
       * @Returns: !(x == y).
       */
      friend BOOST_CONSTEXPR bool operator!=(const ymd_date& x, const ymd_date& y) BOOST_NOEXCEPT
      {
        return !(x == y);
      }
      /**
       * @Returns: y < x.
       */
      friend BOOST_CONSTEXPR bool operator> (const ymd_date& x, const ymd_date& y) BOOST_NOEXCEPT
      {
        return y < x;
      }
      /**
       * @Returns: !(y < x).
       */
      friend BOOST_CONSTEXPR bool operator<=(const ymd_date& x, const ymd_date& y) BOOST_NOEXCEPT
      {
        return !(y < x);
      }
      /**
       * @Returns: !(x < y).
       */
      friend bool operator>=(const ymd_date& x, const ymd_date& y) BOOST_NOEXCEPT
      {
        return !(x < y);
      }

#if ! defined  BOOST_CHRONO_DATE_DOXYGEN_INVOKED
    private:

      days::rep day_number_from_ymd() const BOOST_NOEXCEPT;
#endif

    };
    /**
     * Partial specialization of @c is_date<ymd_date> as a @c true_type.
     */
    template <>
    struct is_date<ymd_date> : true_type {};

//    /**
//     * A type representing an optional ymd_date.
//     */
//    typedef optional<ymd_date> optional_ymd_date;
//    /**
//     * @Returns If the parameters represents a valid ymd_date the ymd_date,
//     * otherwise a none optional.
//     */
//    inline optional_ymd_date make_valid_ymd_date(year y, month m, day d) BOOST_NOEXCEPT
//    {
//      ymd_date res;
//      if (res.set_if_valid_date(y,m,d)) return optional_ymd_date(res);
//      else return optional_ymd_date();
//
//    }

    //    ymd_date make_ymd_date(year::rep,month::rep,day::rep) BOOST_NOEXCEPT;
    //    ymd_date make_ydoy_date(year::rep,day_of_year::rep) BOOST_NOEXCEPT;
    //    ymd_date make_epoch_date(days::rep) BOOST_NOEXCEPT;

    /**
     * @c ymd_date factory.
     * @Returns @c ymd_date(year(ym),month(ym),d)
     */
    inline BOOST_CHRONO_DATE_CONSTEXPR ymd_date operator/(year_month ym, day d)
    {
      return ymd_date(year(ym), month(ym), d);
    }
    /**
     * @c ymd_date factory.
     * @Returns @c ym/day(d)
     */
    inline BOOST_CHRONO_DATE_CONSTEXPR ymd_date operator/(year_month ym, int d)
    {
      return ym / day(d);
    }
    /**
     * @c ymd_date factory.
     * @Returns @c ymd_date(y,month(md),day(md))
     */
    inline BOOST_CHRONO_DATE_CONSTEXPR ymd_date operator/(month_day md, year y)
    {
      return ymd_date(y, month(md), day(md));
    }
    /**
     * @c ymd_date factory.
     * @Returns @c ymd_date(y,month(md),day(md))
     */
    inline BOOST_CHRONO_DATE_CONSTEXPR ymd_date operator/(year y, month_day md)
    {
      return ymd_date(y, month(md), day(md));
    }
    /**
     * @c ymd_date factory.
     * @Returns @c md/year(y)
     */
    inline BOOST_CHRONO_DATE_CONSTEXPR ymd_date operator/(month_day md, int y)
    {
      return md / year(y);
    }

    inline BOOST_CHRONO_DATE_CONSTEXPR ymd_date make_date(year y,month m, day d)
    {
      return ymd_date(y, m, d);
    }
    inline BOOST_CHRONO_DATE_CONSTEXPR ymd_date make_date(year y,month m, int d)
    {
      return ymd_date(y, m, day(d));
    }
    inline BOOST_CHRONO_DATE_CONSTEXPR ymd_date make_date(year y,int m, day d)
    {
      return ymd_date(y, month(m), d);
    }
    inline BOOST_CHRONO_DATE_CONSTEXPR ymd_date make_date(int y,month m, day d)
    {
      return ymd_date(year(y), m, d);
    }

  } // chrono

} // boost


#endif  // header
