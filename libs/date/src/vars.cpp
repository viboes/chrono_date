//  date.cpp
//
//  (C) Copyright Howard Hinnant
//  Copyright 2011-2013 Vicente J. Botet Escriba
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <boost/chrono/date/weekday.hpp>
#include <boost/chrono/date/month.hpp>
#include <boost/chrono/date/nth_week.hpp>
//#include <boost/chrono/date/nth.hpp>
#include <boost/chrono/date/month_nth.hpp>
#include <boost/chrono/date/tuples.hpp>

namespace boost
{
  namespace chrono
  {

    //BOOST_CONSTEXPR_OR_EXTERN_CONST_DEF(nth_tag, last, 0)
    BOOST_CONSTEXPR_OR_EXTERN_CONST_DEF(nth_1_5_tag, _1st, 1)
    BOOST_CONSTEXPR_OR_EXTERN_CONST_DEF(nth_1_5_tag, _2nd, 2)
    BOOST_CONSTEXPR_OR_EXTERN_CONST_DEF(nth_1_5_tag, _3rd, 3)
    BOOST_CONSTEXPR_OR_EXTERN_CONST_DEF(nth_1_5_tag, _4th, 4)
    BOOST_CONSTEXPR_OR_EXTERN_CONST_DEF(nth_1_5_tag, _5th, 5)
    BOOST_CONSTEXPR_OR_EXTERN_CONST_DEF(nth_6_31_tag, _6th, 6)
    BOOST_CONSTEXPR_OR_EXTERN_CONST_DEF(nth_6_31_tag, _7th, 7)
    BOOST_CONSTEXPR_OR_EXTERN_CONST_DEF(nth_6_31_tag, _8th, 8)
    BOOST_CONSTEXPR_OR_EXTERN_CONST_DEF(nth_6_31_tag, _9th, 9)
    BOOST_CONSTEXPR_OR_EXTERN_CONST_DEF(nth_6_31_tag, _10th, 10)
    BOOST_CONSTEXPR_OR_EXTERN_CONST_DEF(nth_6_31_tag, _29th, 29)

    BOOST_CONSTEXPR_OR_EXTERN_CONST_DEF(month, jan, 1)
    BOOST_CONSTEXPR_OR_EXTERN_CONST_DEF(month, feb, 2)
    BOOST_CONSTEXPR_OR_EXTERN_CONST_DEF(month, mar, 3)
    BOOST_CONSTEXPR_OR_EXTERN_CONST_DEF(month, apr, 4)
    BOOST_CONSTEXPR_OR_EXTERN_CONST_DEF(month, may, 5)
    BOOST_CONSTEXPR_OR_EXTERN_CONST_DEF(month, jun, 6)
    BOOST_CONSTEXPR_OR_EXTERN_CONST_DEF(month, jul, 7)
    BOOST_CONSTEXPR_OR_EXTERN_CONST_DEF(month, aug, 8)
    BOOST_CONSTEXPR_OR_EXTERN_CONST_DEF(month, sep, 9)
    BOOST_CONSTEXPR_OR_EXTERN_CONST_DEF(month, oct, 10)
    BOOST_CONSTEXPR_OR_EXTERN_CONST_DEF(month, nov, 11)
    BOOST_CONSTEXPR_OR_EXTERN_CONST_DEF(month, dec, 12)

    BOOST_CONSTEXPR_OR_EXTERN_CONST_DEF(weekday, sun, 0)
    BOOST_CONSTEXPR_OR_EXTERN_CONST_DEF(weekday, mon, 1)
    BOOST_CONSTEXPR_OR_EXTERN_CONST_DEF(weekday, tue, 2)
    BOOST_CONSTEXPR_OR_EXTERN_CONST_DEF(weekday, wed, 3)
    BOOST_CONSTEXPR_OR_EXTERN_CONST_DEF(weekday, thu, 4)
    BOOST_CONSTEXPR_OR_EXTERN_CONST_DEF(weekday, fri, 5)
    BOOST_CONSTEXPR_OR_EXTERN_CONST_DEF(weekday, sat, 6)


//    const month_nth jan_1st(month(1), 1);
//
//    const month_day jan_01(month(1), day( 1, no_check));
//    const month_day jan_02(month(1), day( 2, no_check));
//    const month_day jan_03(month(1), day( 3, no_check));
//    const month_day jan_04(month(1), day( 4, no_check));
//    const month_day jan_05(month(1), day( 5, no_check));
//    const month_day jan_06(month(1), day( 6, no_check));
//    const month_day jan_07(month(1), day( 7, no_check));
//    const month_day jan_08(month(1), day( 8, no_check));
//    const month_day jan_09(month(1), day( 9, no_check));
//    const month_day jan_10(month(1), day( 10, no_check));
//    const month_day jan_11(month(1), day( 11, no_check));
//    const month_day jan_12(month(1), day( 12, no_check));
//    const month_day jan_13(month(1), day( 13, no_check));
//    const month_day jan_14(month(1), day( 14));
//    const month_day jan_15(month(1), day( 15));
//    const month_day jan_16(month(1), day( 16));
//    const month_day jan_17(month(1), day( 17));
//    const month_day jan_18(month(1), day( 18));
//    const month_day jan_19(month(1), day( 19));
//    const month_day jan_20(month(1), day( 20));
//    const month_day jan_21(month(1), day( 21));
//    const month_day jan_22(month(1), day( 22));
//    const month_day jan_23(month(1), day( 23));
//    const month_day jan_24(month(1), day( 24));
//    const month_day jan_25(month(1), day( 25));
//    const month_day jan_26(month(1), day( 26));
//    const month_day jan_27(month(1), day( 27));
//    const month_day jan_28(month(1), day( 28));
//    const month_day jan_29(month(1), day( 29));
//    const month_day jan_30(month(1), day( 30));
//    const month_day jan_31(month(1), day( 31));


    BOOST_STATIC_CONSTEXPR day_rep days_in_month_[2][13] =
    {
    { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
    { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
    };

    namespace chrono_detail
    {
#ifdef  BOOST_NO_CXX11_CONSTEXPR
      day_rep leap_days_in_month_[13] =
        { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

      day_rep normal_days_in_month_[13] =
        { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

      day_rep leap_days_in_year_before_[13] =
          { -1, 30, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };

      day_rep normal_days_in_year_before_[13] =
          { -1, 30, 58, 89, 119, 150, 180, 211, 242, 272, 303, 333, 364 };

#endif
    }

//    days year::days_in_month(month m) const BOOST_NOEXCEPT
//    {
//      return days(days_in_month_[is_leap()][m]);
//    }
    //BOOST_CONSTEXPR
    day::rep days_in_month(bool leap, month::rep m) BOOST_NOEXCEPT
    {
      return days_in_month_[leap][m];
    }


    //BOOST_STATIC_CONSTEXPR
    day_of_year::rep days_in_year_before_[2][13] =
    {
    { -1, 30, 58, 89, 119, 150, 180, 211, 242, 272, 303, 333, 364 },
    { -1, 30, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 } };

    BOOST_STATIC_CONSTEXPR month::rep
        day_of_year_month_[2][366] =
            {
            { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12 },

            { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12

            } };

    BOOST_STATIC_CONSTEXPR day::rep
        day_of_year_day_of_month_[2][366] =
            {
            { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 0 // no leap years have 365 days
            },
            { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31

            }

            };

    BOOST_STATIC_CONSTEXPR day_of_year::rep
        month_day_to_day_of_year_[2][12][31] =
            {
            { // no_leap
            { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
            { 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 77, 58, 59, 0, 0, 0 },
            { 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90 },
            { 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 0 },
            { 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151 },
            { 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 0 },
            { 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212 },
            { 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243 },
            { 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 256, 257, 258, 259, 260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 270, 271, 272, 273, 0 },
            { 274, 275, 276, 277, 278, 279, 280, 281, 282, 283, 284, 285, 286, 287, 288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 300, 301, 302, 303, 304 },
            { 305, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 318, 319, 320, 321, 322, 323, 324, 325, 326, 327, 328, 329, 330, 331, 332, 333, 334, 0 },
            { 335, 336, 337, 338, 339, 340, 341, 342, 343, 344, 345, 346, 347, 348, 349, 350, 351, 352, 353, 354, 355, 356, 357, 358, 359, 360, 361, 362, 363, 364, 365 } },
            { // leap
            { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
            { 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 77, 58, 59, 60, 0, 0 },
            { 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91 },
            { 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 0 },
            { 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152 },
            { 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 0 },
            { 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213 },
            { 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244 },
            { 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 256, 257, 258, 259, 260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 270, 271, 272, 273, 274, 0 },
            { 275, 276, 277, 278, 279, 280, 281, 282, 283, 284, 285, 286, 287, 288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 300, 301, 302, 303, 304, 305 },
            { 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 318, 319, 320, 321, 322, 323, 324, 325, 326, 327, 328, 329, 330, 331, 332, 333, 334, 335, 0 },
            { 336, 337, 338, 339, 340, 341, 342, 343, 344, 345, 346, 347, 348, 349, 350, 351, 352, 353, 354, 355, 356, 357, 358, 359, 360, 361, 362, 363, 364, 365, 366 } } };



    //BOOST_CONSTEXPR
    day_of_year::rep days_in_year_before(bool b, month::rep m) BOOST_NOEXCEPT
    {
      return days_in_year_before_[b][m];
    }
    //BOOST_CONSTEXPR
    const day_of_year::rep* days_in_year_before(bool b) BOOST_NOEXCEPT
    {
      return days_in_year_before_[b];
    }

    //BOOST_CONSTEXPR
    month::rep day_of_year_month(bool b, day_of_year::rep d) BOOST_NOEXCEPT
    {
      return day_of_year_month_[b][d-1];
    }

    //BOOST_CONSTEXPR
    day::rep day_of_year_day_of_month(bool b, day_of_year::rep d) BOOST_NOEXCEPT
    {
      return day_of_year_day_of_month_[b][d-1];
    }
    //BOOST_CONSTEXPR
    day_of_year::rep month_day_to_day_of_year(bool b, month::rep m, day::rep d) BOOST_NOEXCEPT
    {
      return month_day_to_day_of_year_[b][m-1][d-1];
    }

    // year_month

    year_month&
    year_month::operator+=(months mn) BOOST_NOEXCEPT
    {
      year::rep y = y_;
      month::rep m = m_;
      m += mn.count();
      if (m < 1)
      {
        int dy = (12 - m) / 12;
        y -= dy;
        m += 12 * dy;
      }
      else if (m > 12)
      {
        int dy = (m - 1) / 12;
        y += dy;
        m -= 12 * dy;
      }
      y_ = chrono::year(y);
      m_ = chrono::month(m);
      return *this;
    }

//    months operator-(year_month x, year_month y) BOOST_NOEXCEPT
//    {
//      year::rep y1 = x.y_;
//      month::rep m1 = x.m_;
//      year::rep y2 = y.y_;
//      month::rep m2 = y.m_;
//      return months(y1 * 12 + m1 - (y2 * 12 + m2));
//    }

} // boost
  } // chrono


