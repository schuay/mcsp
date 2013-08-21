Parallel Multi-Criteria Shortest Path
=====================================

Setup
-----

A couple of requirements are:

* CMake
* A working compiler toolchain
* graphviz (Graph library)
* Doxygen (Documentation)
* GTest (Unit testing)
* Astyle (Code formatting)
* Pheet (www.pheet.org)

Install the astyle pre-commit hook:

```bash
cd .git/hooks && ln -s ../../misc/pre-commit && cd -
```

Point cmake to the pheet path (by default, it checks in ../pheet).
