# -*- coding: utf-8 -*-

from shutil import rmtree
from setuptools import setup, Extension, Command
from setuptools.command.test import test
from setuptools.command.build_ext import build_ext
import generate_stubs
import os
import sys

sys.path.append(os.path.abspath("./zroya/"))

import version

here = os.path.abspath(os.path.dirname(__file__))

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
        include_dirs=includes_list
    )
]


def discover_and_run_tests():
    import unittest

    # use the default shared TestLoader instance
    test_loader = unittest.defaultTestLoader

    # use the basic test runner that outputs to sys.stderr
    test_runner = unittest.TextTestRunner()

    # automatically discover all tests
    # NOTE: only works for python 2.7 and later
    test_suite = test_loader.discover( os.path.join(here, "tests"))

    # run the test suite
    test_runner.run(test_suite)


def find_pyd_file():
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


class StubsCommand(build_ext):

    description = "Generate python stubs with documentation from C code."

    def run(self):
        build_ext.run(self)

        print("running stubs")
        # Generate .pyd file for this module
        generate_stubs.GenerateStubFile(find_pyd_file(), os.path.abspath("./zroya/"))


class DocumentationCommand(Command):

    description = "Generate documentation from /docs_source directory."
    user_options = []

    def initialize_options(self):
        pass

    def finalize_options(self):
        pass

    def run(self):
        os.system("{} {}".format(os.path.join(os.path.abspath("./docs_source/sphinx/"), "make.bat"), "html"))
        sys.exit()


class UploadCommand(Command):

    description = 'Build and publish the package.'
    user_options = [
        (
            "pypi=",
            "p",
            "Set PyPi repository in which should be distribution uploaded. Valid values are 'test' for TestPyPi or \
            'standard' for regular PyPi."
        )
    ]

    @staticmethod
    def status(s):
        """Prints things in bold."""
        print('\033[1m{0}\033[0m'.format(s))

    def initialize_options(self):
        self.pypi = "standard"

    def finalize_options(self):
        assert(self.pypi == "standard" or self.pypi == "test")

    def run(self):
        try:
            self.status('Removing previous builds…')
            rmtree(os.path.join(here, 'dist'))
        except OSError:
            pass

        self.status('Building Source and Wheel (universal) distribution…')
        os.system('{0} setup.py sdist bdist_wheel --universal'.format(sys.executable))

        self.status('Uploading the package to PyPi via Twine…')

        if self.pypi == "standard":
            os.system('twine upload --repository pypi dist/*')
        else:
            os.system('twine upload --repository testpypi dist/*')

        sys.exit()


class DiscoverTest(test):
    """
    Discover and run tests.
    See: https://stackoverflow.com/questions/17001010/how-to-run-unittest-discover-from-python-setup-py-test
    """

    description = "Run tests in /tests folder with unittest."

    def finalize_options(self):
        test.finalize_options(self)
        self.test_args = []
        self.test_suite = True

    def run_tests(self):
        discover_and_run_tests()


setup(name='zroya',
    version=version.__version__,
    description='Python library for creating native Windows notifications.',
    long_description=open("README.md").read(),

    author='Jan Malčák',
    author_email='looorin@gmail.com',

    license='MIT',
    url='https://malja.github.io/zroya',

    keywords=["notifications", "windows", "toast"],
    classifiers=[
        "Development Status :: 4 - Beta",
        "Environment :: Win32 (MS Windows)",
        "License :: OSI Approved :: MIT License",
        "Operating System :: Microsoft :: Windows",
        "Programming Language :: C",
        "Programming Language :: C++",
        "Programming Language :: Python :: 3",
        "Topic :: Software Development :: User Interfaces"
    ],

    ext_modules=ext_modules,
    test_suite="tests",
    packages=["zroya"],
    cmdclass={
        "stubs": StubsCommand,
        'upload': UploadCommand,
        "docs": DocumentationCommand,
        "test": DiscoverTest,
    }
)
