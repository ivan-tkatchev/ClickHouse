#include <Common/AlignedBuffer.h>

#include <Common/Exception.h>
#include <Common/formatReadable.h>

#include "config.h"

namespace DB
{

namespace ErrorCodes
{
    extern const int CANNOT_ALLOCATE_MEMORY;
}


void AlignedBuffer::alloc(size_t size, size_t alignment)
{
    void * new_buf;
    int res = ALLOC_PREFIX(posix_memalign)(&new_buf, std::max(alignment, sizeof(void*)), size);
    if (0 != res)
        throw ErrnoException(
            ErrorCodes::CANNOT_ALLOCATE_MEMORY,
            "Cannot allocate memory (posix_memalign), size: {}, alignment: {}.",
            ReadableSize(size),
            ReadableSize(alignment));
    buf = new_buf;
}

void AlignedBuffer::dealloc()
{
    if (buf)
        ALLOC_PREFIX(free)(buf);
}

void AlignedBuffer::reset(size_t size, size_t alignment)
{
    dealloc();
    alloc(size, alignment);
}

AlignedBuffer::AlignedBuffer(size_t size, size_t alignment)
{
    alloc(size, alignment);
}

AlignedBuffer::~AlignedBuffer()
{
    dealloc();
}

}
