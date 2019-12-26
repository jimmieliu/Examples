#!/usr/bin/env python
from distutils.core import setup, Extension

MOD = 'demo'

module1 = Extension(MOD,
                    sources = ['Demo.cpp'])

setup (name = MOD,
       version = '1.0',
       description = 'demo package',
       ext_modules = [module1])
