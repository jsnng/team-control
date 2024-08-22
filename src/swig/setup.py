#! /usr/bin/env python

from setuptools import setup, find_packages, Extension

if __name__ == '__main__':
    extension = Extension(
        name = "swig",
        sources = ["src/World_wrap.cxx"],
        include_dirs = ["src/", "../protobuf", "../TeamControl"],
        py_limited_api = True,
    )

    kwargs = dict(
        packages = find_packages(where="src"),
        package_dirs = {"": "src"},
        ext_modules = [extension],
    )
    setuptools.setup(**kwargs)
    