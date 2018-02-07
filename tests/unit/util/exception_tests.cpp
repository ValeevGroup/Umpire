#include "umpire/util/Exception.hpp"
#include "umpire/util/Macros.hpp"

#include "gtest/gtest.h"

TEST(Exception, ThrowException)
{
  ASSERT_THROW(throw umpire::util::Exception("Test Exception", __FILE__, __LINE__),
               umpire::util::Exception);
}

TEST(Exception, ThrowFromErrorMacro)
{
  ASSERT_THROW(UMPIRE_ERROR( "Test Exception" ),
      umpire::util::Exception);
}
