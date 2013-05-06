//  date
//
//  (C) Copyright Howard Hinnant
//  Copyright 2011 Vicente J. Botet Escriba
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#ifndef BOOST_CHRONO_DATE_MONTH_HPP
#define BOOST_CHRONO_DATE_MONTH_HPP

#include <boost/cstdint.hpp>
#include <boost/chrono/date/detail/bounded.hpp>
#include <boost/chrono/date/detail/helpers.hpp>
#include <boost/chrono/date/date_durations.hpp>


namespace boost
{
  namespace chrono
  {

    /**
     * month tag
     */
    struct month_tag {};
    /**
     * The class @c month is used to specify the month of the year when constructing a date.  Its range is [1,12].
     */
    class month: public bounded<month_tag, 1, 12, int_least8_t>
    {
      typedef bounded<month_tag, 1, 12, int_least8_t> base_type;
    public:
      /**
       * @Effects: Constructs an object of class month by storing m.
       * @Postconditions: static_cast<int>(*this) == m.
       */
      BOOST_CONSTEXPR explicit month(int m) :
        base_type(m)
      {
      }

      /**
       * @Effects: Constructs an object of class month by storing m.
       * @Postconditions: static_cast<int>(*this) == m.
       * @Throws: if m is outside of the supported range, throws an exception of type bad_date.
       */
      BOOST_CONSTEXPR month(int m, check_t) BOOST_NOEXCEPT
      : base_type(m, check)
      {}

      /**
       * @Return the number of days of the month depending on the @c is_leap_year parameter.
       */
      days days_in(bool is_leap_year) const BOOST_NOEXCEPT
      {
        return days(days_in_month(is_leap_year, value()));
      }
    };

    /**
     * month pseudo-literals.
     */
#ifndef  BOOST_NO_CXX11_CONSTEXPR
    BOOST_CONSTEXPR_OR_CONST month jan(1);
    BOOST_CONSTEXPR_OR_CONST month feb(2);
    BOOST_CONSTEXPR_OR_CONST month mar(3);
    BOOST_CONSTEXPR_OR_CONST month apr(4);
    BOOST_CONSTEXPR_OR_CONST month may(5);
    BOOST_CONSTEXPR_OR_CONST month jun(6);
    BOOST_CONSTEXPR_OR_CONST month jul(7);
    BOOST_CONSTEXPR_OR_CONST month aug(8);
    BOOST_CONSTEXPR_OR_CONST month sep(9);
    BOOST_CONSTEXPR_OR_CONST month oct(10);
    BOOST_CONSTEXPR_OR_CONST month nov(11);
    BOOST_CONSTEXPR_OR_CONST month dec(12);
#else
    extern const month jan;
    extern const month feb;
    extern const month mar;
    extern const month apr;
    extern const month may;
    extern const month jun;
    extern const month jul;
    extern const month aug;
    extern const month sep;
    extern const month oct;
    extern const month nov;
    extern const month dec;

#endif

    /**
     * Overload for month conversion to string.
     * @param v the @c month
     * @return the string representing the month.
     */
    inline std::string to_string(month v) {
      switch (v) {
      case 1: return "Jan";
      case 2: return "Feb";
      case 3: return "Mar";
      case 4: return "Apr";
      case 5: return "May";
      case 6: return "Jun";
      case 7: return "Jul";
      case 8: return "Aug";
      case 9: return "Sep";
      case 10: return "Oct";
      case 11: return "Nov";
      case 12: return "Dec";
      default: throw_exception( bad_date("month " + boost::chrono::to_string(unsigned(v.value())) + " is out of range") );

      }
    }

  } // chrono

} // boost

#endif  // header
