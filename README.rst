RBTree and LL Playground
========================

This repository contains a Red Black Tree and Sorted Linked List ``C++``
implementation that I use to test some stuff (mostly performance related).
Both the tree and the list only have keys (no key-value pairs) basically
because that is what `pyqcs <https://github.com/daknuett/PyQCS>`_ needs.

Building
--------

Use meson. It's simple:

.. code::

    meson builddir
    meson compile -C builddir

Running Tests
-------------

After making a builddir (see Building_):

.. code::

   meson test -C builddir

Benchmarks
----------

The benchmarks are really just little tests what is faster. They are found
under ``benchmarks/``. They are compiled during building. You have to run them
manually. The resulting executables all start with ``bench_``.


What's implemented?
-------------------

- Insertion and deletion.
- Exporting the tree to `dot
  <https://en.wikipedia.org/wiki/DOT_(graph_description_language)>`_.
- Exporting the values to a ``std::vector<int>``. Both using recursion and an
  iterative algorithm.  The latter is surprisingly slower.
- Checking some Red Black Tree properties.

The linked list also has some features but they are less important.

More Notes
----------

- ``visual_tests/`` contains some stuff to visually check. Check the comments
  in the source code.
- ``main.cpp`` usually contains whatever I am currently working on.
