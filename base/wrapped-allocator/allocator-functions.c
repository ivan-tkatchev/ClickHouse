#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#define ALLOC_PREFIX(func) wrap_##func

static void fail(const char* func) {
    fprintf(stderr, "%s called", func);
    abort();
}

void *ALLOC_PREFIX(malloc)(size_t size) { fail(__func__); }

void ALLOC_PREFIX(free)(void *ptr) { fail(__func__); }

void *ALLOC_PREFIX(calloc)(size_t nmemb, size_t size) { fail(__func__); }

void *ALLOC_PREFIX(realloc)(void *ptr, size_t size) { fail(__func__); }

int ALLOC_PREFIX(posix_memalign)(void **memptr, size_t alignment, size_t size) { fail(__func__); }

void *ALLOC_PREFIX(aligned_alloc)(size_t alignment, size_t size) { fail(__func__); }

void *ALLOC_PREFIX(valloc)(size_t size) { fail(__func__); }

void *ALLOC_PREFIX(memalign)(size_t alignment, size_t size) { fail(__func__); }

void *ALLOC_PREFIX(pvalloc)(size_t size) { fail(__func__); }

size_t ALLOC_PREFIX(malloc_usable_size)(void *ptr) { fail(__func__); }

size_t ALLOC_PREFIX(malloc_cached_memory_size)(void) { fail(__func__); }


