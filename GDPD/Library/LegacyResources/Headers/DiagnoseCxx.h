//
//  DiagnoseCxx.h
//  ReportServiceCore
//
//  Created by Sun on 3/9/18.
//  Copyright © 2018 MicroStrategy, Inc. All rights reserved.
//

#ifndef DiagnoseCxx_h
#define DiagnoseCxx_h
#include <stdio.h>
#define CHECK_HR  {if (hr != S_OK) {print_stacktrace(hr); return hr;}}
#define CHECK_PTR(p) {if (!p) {print_stacktrace(); return E_POINTER;}}
#define CHECK_NEWED_PTR(p) {if (!p) {print_stacktrace(); return E_OUT_OF_MEMORY;}}
#define CHECK_HR_PTR(ptr) { CHECK_HR; CHECK_PTR(ptr);}
#define AE_ASSERT(expr) {_ASSERT(expr); if (!(expr)) return E_ASSERT;}
#define CHECK_HR_BLOCK(type) {CHECK_HR; if (type != lBlockType) {print_stacktrace(); return E_DATABLOCK;}}
#define CHECK_HR_OBJTYPE(type) {CHECK_HR; if (type != lObjectType) {print_stacktrace(); return E_DATABLOCK;}}

void print_stacktrace(long hr = 0, unsigned int max_frames = 63);

#endif /* TraceCxx_h */
