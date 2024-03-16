if (ENABLE_WRAPPED_ALLOCATOR)

   add_library (wrapped-allocator SHARED allocator-functions.c)
   target_compile_options (wrapped-allocator PRIVATE
      "-Wno-missing-noreturn" "-Wno-unused-parameter" "-Wno-return-type")
   target_link_libraries (global-libs INTERFACE wrapped-allocator)
   install (TARGETS wrapped-allocator RUNTIME DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT clickhouse)

endif ()
