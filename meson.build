project('backend_rewrite', 'cpp')
add_global_arguments('-O3', language:'cpp')

incdir = include_directories('include/')

ll = shared_library('ll', 'src/ll/ll.cpp', include_directories:incdir)
rbt = shared_library('rbt', 'src/rbt/tree.cpp', 'src/rbt/iterator.cpp', include_directories:incdir)

main = executable('main', 'main.cpp', link_with:[ll, rbt], include_directories:incdir)
visual_graph = executable('visual_graph_deletion', 'visual_tests/graph_deletion_cases.cpp', link_with:[rbt], include_directories:incdir)

benchmark_setup = static_library('benchmark_setup', 'benchmarks/setup.cpp', include_directories: [incdir])

test_filenames = [['test_rbt_insert', 'tests/rbtree_insert.cpp'] 
                , ['test_ll_insert', 'tests/ll_insert.cpp']
                , ['test_rbt_has_value', 'tests/rbtree_has_value.cpp']
                , ['test_ll_has_value', 'tests/ll_has_value.cpp']
                , ['test_rbt_delete', 'tests/rbtree_delete.cpp']
                , ['test_ll_delete', 'tests/ll_delete.cpp']
                , ['test_ll_iterator', 'tests/ll_iterator.cpp']
                , ['test_rbt_iterative_export', 'tests/rbtree_iterative_export.cpp']
                , ['test_rbt_iterator', 'tests/rbtree_iterator.cpp']]

bench_filenames = [['bench_rbt_export', 'benchmarks/rbtree_export.cpp']
                , ['bench_iterator_ll_vs_tree', 'benchmarks/rbtree_vs_ll_iterator.cpp']
                , ['bench_rbt_vs_set', 'benchmarks/rbtree_vs_set.cpp']]

tests = []
foreach tfname: test_filenames
    tests += [[tfname[0], executable(tfname[0]
                            , tfname[1]
                            , include_directories: [incdir]
                            , link_with: [ll, rbt]
                            , install: false)]]
endforeach

benchmarks = []
foreach bfname: bench_filenames
    benchmarks += [[bfname[0], executable(bfname[0]
                                , bfname[1]
                                , include_directories: [incdir]
                                , link_with: [ll, rbt, benchmark_setup]
                                , install: false)]]
endforeach



foreach t:tests
    test(t[0], t[1])
endforeach

