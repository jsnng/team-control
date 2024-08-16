#! /usr/bin/env python

from distutils.core import setup, Extension

world_model_module = Extension(
    '_world_model',
    sources=['world_model_wrap.cxx', 'world_model.cpp']
)

setup(
    name            = 'world_model',
    version         = '0.0',
    author          = "",
    descrption      = "",
    ext_modules     = [],
    py_modules      = [],
)