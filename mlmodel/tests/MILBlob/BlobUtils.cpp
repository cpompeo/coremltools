// Copyright (c) 2021, Apple Inc. All rights reserved.
//
// Use of this source code is governed by a BSD-3-clause license that can be
// found in the LICENSE.txt file or at https://opensource.org/licenses/BSD-3-Clause

#include "BlobUtils.hpp"

namespace MILBlob {
namespace TestUtil {

AutoDeleteTempFile MakeStorageTempFileWith3Records()
{
    AutoDeleteTempFile tempfile;

    // clang-format off
    std::vector<uint16_t> bytes {
        // HEADER
        0x0001, 0x0000, 0x0002, 0x0000,  // count=1, version=2
        0x0000, 0x0000, 0x0000, 0x0000,  // reserved_0
        0x0000, 0x0000, 0x0000, 0x0000,  // reserved_1
        0x0000, 0x0000, 0x0000, 0x0000,  // reserved_2
        0x0000, 0x0000, 0x0000, 0x0000,  // reserved_3
        0x0000, 0x0000, 0x0000, 0x0000,  // reserved_4
        0x0000, 0x0000, 0x0000, 0x0000,  // reserved_5
        0x0000, 0x0000, 0x0000, 0x0000,  // reserved_6
        // 64 Bytes
        // METADATA 1
        0xBEEF, 0xDEAD, 0x0003, 0x0000,  // sentinel=0xDEADBEEF, mil_dtype=uint8_t
        0x0005, 0x0000, 0x0000, 0x0000,  // sizeInBytes=5 bytes
        0x0080, 0x0000, 0x0000, 0x0000,  // offset
        0x0000, 0x0000, 0x0000, 0x0000,  // reserved_0
        0x0000, 0x0000, 0x0000, 0x0000,  // reserved_1
        0x0001, 0x0000, 0x0000, 0x0000,  // reserved_2
        0x0000, 0x0000, 0x0000, 0x0000,  // reserved_3
        0x0000, 0x0000, 0x0000, 0x0000,  // reserved_4
        // 128 Bytes
        // DATA 1
        0x0002, 0x0040, 0x0007, 0x0000,
        // Padding
        0x0000, 0x0000, 0x0000, 0x0000,
        0x0000, 0x0000, 0x0000, 0x0000,
        0x0000, 0x0000, 0x0000, 0x0000,
        0x0000, 0x0000, 0x0000, 0x0000,
        0x0000, 0x0000, 0x0000, 0x0000,
        0x0000, 0x0000, 0x0000, 0x0000,
        0x0000, 0x0000, 0x0000, 0x0000,
        // 192 Bytes
        // METADATA 2
        0xBEEF, 0xDEAD, 0x0001, 0x0000,  // sentinel=0xDEADBEEF, mil_dtype=Fp16
        0x0008, 0x0000, 0x0000, 0x0000,  // sizeInBytes=8 bytes
        0x0100, 0x0000, 0x0000, 0x0000,  // offset
        0x0000, 0x0000, 0x0000, 0x0000,  // reserved_0
        0x0000, 0x0000, 0x0000, 0x0000,  // reserved_1
        0x0001, 0x0000, 0x0000, 0x0000,  // reserved_2
        0x0000, 0x0000, 0x0000, 0x0000,  // reserved_3
        0x0000, 0x0000, 0x0000, 0x0000,  // reserved_4
        // 256 Bytes
        // DATA 2
        0x000E, 0xC0FE, 0x0810, 0x0000,
        // Padding
        0x0000, 0x0000, 0x0000, 0x0000,
        0x0000, 0x0000, 0x0000, 0x0000,
        0x0000, 0x0000, 0x0000, 0x0000,
        0x0000, 0x0000, 0x0000, 0x0000,
        0x0000, 0x0000, 0x0000, 0x0000,
        0x0000, 0x0000, 0x0000, 0x0000,
        0x0000, 0x0000, 0x0000, 0x0000,
        // 320 Bytes
        // METADATA 3
        0xBEEF, 0xDEAD, 0x0002, 0x0000,  // sentinel=0xDEADBEEF, mil_dtype=Float32
        0x0010, 0x0000, 0x0000, 0x0000,  // sizeInBytes=16 bytes
        0x0180, 0x0000, 0x0000, 0x0000,  // offset
        0x0000, 0x0000, 0x0000, 0x0000,  // reserved_0
        0x0000, 0x0000, 0x0000, 0x0000,  // reserved_1
        0x0001, 0x0000, 0x0000, 0x0000,  // reserved_2
        0x0000, 0x0000, 0x0000, 0x0000,  // reserved_3
        0x0000, 0x0000, 0x0000, 0x0000,  // reserved_4
        // 384 Bytes
        // DATA 3
        0x0000, 0x0070, 0x0FEE, 0x000C,
        0xFACE, 0x0008, 0xFADE, 0x0091,
        // Padding
        0x0000, 0x0000, 0x0000, 0x0000,
        0x0000, 0x0000, 0x0000, 0x0000,
        0x0000, 0x0000, 0x0000, 0x0000,
        0x0000, 0x0000, 0x0000, 0x0000,
        0x0000, 0x0000, 0x0000, 0x0000,
        0x0000, 0x0000, 0x0000, 0x0000,
        //448 Bytes
        // METADATA 4
        0xBEEF, 0xDEAD, 0x0004, 0x0000,  // sentinel=0xDEADBEEF, mil_dtype=Int8
        0x0006, 0x0000, 0x0000, 0x0000,  // sizeInBytes=6 bytes
        0x0200, 0x0000, 0x0000, 0x0000,  // offset
        0x0000, 0x0000, 0x0000, 0x0000,  // reserved_0
        0x0000, 0x0000, 0x0000, 0x0000,  // reserved_1
        0x0001, 0x0000, 0x0000, 0x0000,  // reserved_2
        0x0000, 0x0000, 0x0000, 0x0000,  // reserved_3
        0x0000, 0x0000, 0x0000, 0x0000,  // reserved_4
        // 512 Bytes
        // DATA 4
        0xf8f0, 0x02fe, 0x1008, 0x0000, // [-16, -8, -2, 2, 8, 16]
    };
    // clang-format on

    WriteBlobFile(tempfile.GetFilename(), Util::MakeSpan(bytes));
    return tempfile;
}

}  // namespace TestUtil
}  // namespace MILBlob
