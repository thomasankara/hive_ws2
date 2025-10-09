from setuptools import setup
import os
from glob import glob

package_name = 'vanilla_brain_nav2'

setup(
    name=package_name,
    version='0.0.1',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'), glob('launch/*.launch.py')),
        (os.path.join('share', package_name, 'config'), glob('config/*.yaml')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Thomas',
    maintainer_email='you@example.com',
    description='Minimal brain to orchestrate Nav2 planner+controller with manual goals.',
    license='Apache-2.0',
    entry_points={
        'console_scripts': [
            'vanilla_knifebrain = vanilla_brain_nav2.vanilla_knifebrain_node:main',
        ],
    },
)
