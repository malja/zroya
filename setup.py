from setuptools import setup, Extension
import shutil
import os

includes_list = ["./zroya/include", "./zroya/include/python" ]
sources_list = []
for root, dirs, files in os.walk("./zroya"):
    for f in files:
        if os.path.splitext(f)[1] == ".cpp":
            sources_list.append(os.path.join(root, f))

ext_modules = [Extension("zroya", sources = sources_list, include_dirs= includes_list)]

for e in ext_modules:
    e.cython_directives = {"embedsignature": True}

setup(name='zroya',
      version='0.2.0',
      description='Python implementation of Windows notifications.',
      author='Jan Malčák',
      author_email='jan@malcakov.cz',
      url='https://github.com/malja/zroya',
      ext_modules=ext_modules
)