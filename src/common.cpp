#include <cpptoolkit/test/tool/common.h>
#include <string>

namespace cpptoolkit {
namespace test {
namespace tool {

void ThrowTestFailException(std::string why,
                            std::string file,
                            uint32_t line) {
  std::string where = file + ":" + std::to_string(line);
  throw TestFailException(why.c_str(), where.c_str());
}

} // namespace tool
} // namespace test
} // namespace cpptoolkit
