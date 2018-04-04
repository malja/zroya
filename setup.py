# -*- coding: utf-8 -*-

from setuptools import setup, Extension
from setuptools.command.build_ext import build_ext
from python.scripts.generate_stubs import GenerateStubFile
import os

# Include path for _zroya module
includes_list = ["./module"]

# List of all *.cpp files in ./module directory
sources_list = []
for root, dirs, files in os.walk("./module"):
    for f in files:
        if os.path.splitext(f)[1] == ".cpp":
            sources_list.append(os.path.join(root, f))

# Python C/CPP Api extension configuration
ext_modules = [
    Extension("_zroya",
              sources=sources_list,
              include_dirs=includes_list,
              extra_compile_args=[
                  "/utf-8"
              ]
    )
]


def findPydFile():
    """
    Return path to .pyd after successful build command.
    :return: Path to .pyd file or None.
    """

    if not os.path.isdir("./build"):
        raise NotADirectoryError

    for path, dirs, files in os.walk("./build"):
        for file_name in files:
            file_name_parts = os.path.splitext(file_name)
            if file_name_parts[1] == ".pyd":
                return path
    return None


class PostInstall(build_ext):
    def run(self):
        build_ext.run(self)

        print("running post_install")
        # Generate .pyd file for this module
        GenerateStubFile(findPydFile())


setup(name='zroya',
    version='0.2.0',
    description='Python implementation of Windows notifications.',
    author='Jan Malcak',
    author_email='jan@malcakov.cz',
    url='https://github.com/malja/python',
    data_files=[
      (".", ["./python/zroya.pyi", "./python/template_enums.py", "./python/zroya.py"])
    ],
    ext_modules=ext_modules,
    cmdclass={
        "build_ext": PostInstall
    }
)