// Copyright 2018 Cloudera Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


#ifndef SAWTOOTH_CASE_H
#define SAWTOOTH_CASE_H 

#include <impala_udf/udf.h>

using namespace impala_udf;

// Usage: > create function sawtooth(string) returns string
//          location '/user/cloudera/libsawtooth.so' SYMBOL='SawtoothCase';
//        > select sawtooth('Sphinx of black quartz, judge my vow!');
//        > select sawtooth(c1) from t1;
StringVal SawtoothCase(FunctionContext* context, const StringVal& arg1);


#endif
