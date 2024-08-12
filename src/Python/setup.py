from setuptools import setup, Extension
import os

os.environ['CC'] = 'g++'
setup(name="model",
      py_modules=["model"],
      ext_modules=[Extension("_model",
                             ["_model.i", "Model.cpp"],
                             swig_opts=['-c++', '-I.'],
                             extra_compile_args=['--std=c++20'])])