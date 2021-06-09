#include <UnitTest++/UnitTest++.h>
#include <CRC32.cpp>
SUITE(KeyTest)
{
TEST(CorrectName) {CRC32 crc("111.txt");
CHECK(true);
}
TEST(EmptyString) {CHECK_THROW(CRC32 object(""), CRC32_error);
}
TEST(NoPoint) {CHECK_THROW(CRC32 object("111txt"), CRC32_error);
}
TEST(NoLetters) {CHECK_THROW(CRC32 object("!!!!!"), CRC32_error);
}
TEST(NoExtension) {CHECK_THROW(CRC32 object("111."), CRC32_error);
}
}
      SUITE(calculate)
{
