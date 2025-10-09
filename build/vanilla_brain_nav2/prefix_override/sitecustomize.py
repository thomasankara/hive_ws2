import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/thomas24/hive_ws2/install/vanilla_brain_nav2'
