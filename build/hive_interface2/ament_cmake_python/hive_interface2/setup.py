from setuptools import find_packages
from setuptools import setup

setup(
    name='hive_interface2',
    version='0.0.1',
    packages=find_packages(
        include=('hive_interface2', 'hive_interface2.*')),
)
