/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <stddef.h>
#include <stdint.h>

#include <qnnpack/params.h>

#ifdef __cplusplus
extern "C" {
#endif

#define DECLARE_Q8CONV_UKERNEL_FUNCTION(fn_name)                          \
  void fn_name(                                                           \
      size_t mr,                                                          \
      size_t nr,                                                          \
      size_t kc,                                                          \
      size_t ks,                                                          \
      const uint8_t** a,                                                  \
      const uint8_t* b,                                                   \
      const int32_t* bias,                                                \
      uint8_t* c,                                                         \
      size_t c_stride,                                                    \
      const uint8_t a_offset,                                             \
      const uint8_t b_offset,                                             \
      const union qnnp_q31_requantization_params* requantization_params);

DECLARE_Q8CONV_UKERNEL_FUNCTION(q8conv_ukernel_4x8__neon)
DECLARE_Q8CONV_UKERNEL_FUNCTION(q8conv_ukernel_4x8__aarch32_neon)
DECLARE_Q8CONV_UKERNEL_FUNCTION(q8conv_ukernel_8x8__aarch64_neon)
DECLARE_Q8CONV_UKERNEL_FUNCTION(q8conv_ukernel_8x8__neon)
DECLARE_Q8CONV_UKERNEL_FUNCTION(q8conv_ukernel_4x4c2__sse2)

#ifdef __cplusplus
} /* extern "C" */
#endif