Committing to zroya
===================

This page is work in progress.

Changes in C files
------------------

1. Build Python extension from C source.

.. code-block:: bash

    python setup.py build

Make sure there are no errors.

2. Run current tests.

.. code-block:: bash

    python setup.py test

3. Write your own tests when necessary.

4. Change documentation. See :ref:`changes_in_documentation` section.

5. Make stubs

.. code-block:: bash

    python setup.py stubs

Changes in Python files
-----------------------

1. Test your changes with existing tests

.. code-block:: bash

    python setup.py test

2. Write your own tests when necessary.

3. Change documentation. See :ref:`changes_in_documentation` section.

4. Make stubs

.. code-block:: bash

    python setup.py stubs

.. _changes_in_documentation:

Changes in documentation
------------------------

1. Build html documentation.

.. code-block:: bash

    python setup.py docs
