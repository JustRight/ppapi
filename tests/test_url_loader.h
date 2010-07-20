// Copyright (c) 2010 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef PAPPI_TESTS_TEST_URL_LOADER_H_
#define PAPPI_TESTS_TEST_URL_LOADER_H_

#include <string>

#include "ppapi/tests/test_case.h"

namespace pp {
class URLLoader;
class URLRequestInfo;
}

class TestURLLoader : public TestCase {
 public:
  explicit TestURLLoader(TestInstance* instance) : TestCase(instance) {}

  // TestCase implementation.
  virtual bool Init();
  virtual void RunTest();
  
 private:
  std::string ReadEntireResponseBody(pp::URLLoader* loader, std::string* body);
  std::string LoadAndCompareBody(const pp::URLRequestInfo& request,
                                 const std::string& expected_body);

  std::string TestBasicGET();
  std::string TestBasicPOST();
  std::string TestCompoundBodyPOST();
  std::string TestEmptyDataPOST();
  std::string TestCustomRequestHeader();
  std::string TestIgnoresBogusContentLength();
};

#endif  // PAPPI_TESTS_TEST_URL_LOADER_H_
