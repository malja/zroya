# -*- coding: utf-8 -*-

from setuptools import setup, Extension
import os

includes_list = ["./module"]
sources_list = []
for root, dirs, files in os.walk("./module"):
    for f in files:
        if os.path.splitext(f)[1] == ".cpp":
            sources_list.append(os.path.join(root, f))

ext_modules = [
    Extension("_zroya",
              sources=sources_list,
              include_dirs=includes_list,
              extra_compile_args=[
                  "/utf-8"
              ]
    )
]

for e in ext_modules:
    e.cython_directives = {"embedsignature": True}

setup(name='zroya',
    version='0.2.0',
    description='Python implementation of Windows notifications.',
    author='Jan Malcak',
    author_email='jan@malcakov.cz',
    url='https://github.com/malja/python',
    data_files=[
      (".", ["./python/zroya.pyi", "./python/template_enums.py", "./python/zroya.py"])
    ],
    ext_modules=ext_modules
)