/*
 * BSD 2-Clause License
 *
 * Copyright (c) 2023, Vladimir Fomchenkov
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef CPPTOOLKIT_TEST_TOOL_COMMON_H_
#define CPPTOOLKIT_TEST_TOOL_COMMON_H_

#include <cpptoolkit/test/tool/test_fail_exception.h>
#include <type_traits>

namespace cpptoolkit {
namespace test {
namespace tool {

/// @brief Function for throw TestFailException for failed tests
/// @param why Fail reason description
/// @param file File with failed test
/// @param line Line number where test fail
void ThrowTestFailException(std::string why, std::string file, uint32_t line);

/// @brief Message for not equal strings
/// @param actual Actual string
/// @param expected Expected string
std::string StrNotEqualMessage(std::string actual, std::string expected);

/// @brief Message for not equal values
/// @tparam N Type of actual value (int, short int, long int, double end etc.)
/// @tparam M Type of expected value (int, short int, long int, double and etc.)
/// @param actual Actual value
/// @param expected Expected value
template<typename N, typename M>
std::string ValNotEqualMessage(N actual, M expected) {
  std::string res = std::to_string(actual);
  res += " != ";
  res += std::to_string(expected);
  return res;
}

}  // namespace tool
}  // namespace test
}  // namespace cpptoolkit

#endif  // CPPTOOLKIT_TEST_TOOL_COMMON_H_

