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

#ifndef CPPTOOLKIT_TEST_CORE_H_
#define CPPTOOLKIT_TEST_CORE_H_

#include <cpptoolkit/test/tool/base_test.h>
#include <cpptoolkit/test/tool/test_fail_exception.h>

#include <string>
#include <vector>

namespace cpptoolkit {
namespace test {

/// struct TestsResult execution result
struct TestResult {
  /// @is_success Is success current test or not
  bool is_success;

  /// @name Test name
  std::string name;

  /// @where File name and line number where test fail
  std::string where;

  /// @why Description why test fail
  std::string why;
};

/// @brief Test container and runner (this object is singleton)
class Core {
 public:
  /// @brief Add test environment to queue for run
  /// @param Test environment
  void Add(cpptoolkit::test::tool::BaseTest *test);

  /// @brief Get all test count
  uint32_t count();

  /// @brief Run all unit tests
  /// @return Details about each test execution
  std::vector<TestResult> RunTests();

  /// @brief Get pointer to instance of test container
  static Core *instance();

 private:
  Core() = default;

 private:
  std::vector<cpptoolkit::test::tool::BaseTest *> test_list_;
  static Core *instance_;
};

}  // namespace test
}  // namespace cpptoolkit

#endif  // CPPTOOLKIT_TEST_CORE_H_

