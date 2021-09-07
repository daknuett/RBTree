project('backend_rewrite', 'cpp')
add_global_arguments('-O3', language:'cpp')

incdir = include_directories('include/')

ll = shared_library('ll', 'src/ll/ll.cpp', include_directories:incdir)
rbt = shared_library('rbt', 'src/rbt/tree.cpp', 'src/rbt/iterator.cpp', include_directories:incdir)

