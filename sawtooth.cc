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

#include "sawtooth.h"

#include <cctype>
#include <cmath>
#include <string>

// The SawtoothCase function returns the input string with each
// letter alternating between uppercase and lowercase.
// Usage: > create function sawtooth(string) returns string
//          location '/user/cloudera/libsawtooth.so' SYMBOL='SawtoothCase';
//        > select sawtooth('Sphinx of black quartz, judge my vow!');
//        > select sawtooth(c1) from t1;
StringVal SawtoothCase(FunctionContext* context, const StringVal& arg1) {
	if (arg1.is_null) return StringVal::null();

	bool nextUpper = false; // Next: uppercase?
	std::string original((const char *)arg1.ptr,arg1.len);
	std::string jagged(""); // The converted string

	for (int index = 0; index < original.length(); index++) {
        // If the next character should be uppercase
		if ( nextUpper )
		{
			// If the character is a lowercase letter, make it uppercase
			if ( islower( original [index] ) )
				jagged += toupper( original [index] );
			else // Leave non-letter characters unchanged 
				jagged += original [index];

			// Switch the next character to lowercase
			nextUpper = false;
		} 
		else // If the next character should be lowercase
		{
			// If an uppercase letter, make it lowercase
			if ( isupper( original [index] ) )
				jagged += tolower( original [index] );
			else // Leave non-letter characters unchanged 
				jagged += original [index];

			// Switch the next character to uppercase
			nextUpper = true;
		}
	}
	// Copy the converted string into a StringVal in Impala-managed memory
	return StringVal::CopyFrom(context, 
		reinterpret_cast<const uint8_t*>(jagged.c_str()), jagged.size());
}
