# generated from rosidl_generator_py/resource/_idl.py.em
# with input from hive_interface2:msg/Poi.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Poi(type):
    """Metaclass of message 'Poi'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('hive_interface2')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'hive_interface2.msg.Poi')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__poi
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__poi
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__poi
            cls._TYPE_SUPPORT = module.type_support_msg__msg__poi
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__poi

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Poi(metaclass=Metaclass_Poi):
    """Message class 'Poi'."""

    __slots__ = [
        '_enterprise_full_id_str',
        '_deployment_full_id_str',
        '_slam_session_full_id_str',
        '_free_zone_full_id_str',
        '_is_in_free_zone',
        '_poi_full_id_str',
        '_poi_id',
        '_x',
        '_y',
        '_z',
        '_yaw',
        '_parking_mode',
        '_is_available',
        '_charging_mode',
        '_is_long_wait_zone',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'enterprise_full_id_str': 'string',
        'deployment_full_id_str': 'string',
        'slam_session_full_id_str': 'string',
        'free_zone_full_id_str': 'string',
        'is_in_free_zone': 'int32',
        'poi_full_id_str': 'string',
        'poi_id': 'int32',
        'x': 'float',
        'y': 'float',
        'z': 'float',
        'yaw': 'float',
        'parking_mode': 'int32',
        'is_available': 'int32',
        'charging_mode': 'int32',
        'is_long_wait_zone': 'int32',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        if 'check_fields' in kwargs:
            self._check_fields = kwargs['check_fields']
        else:
            self._check_fields = ros_python_check_fields == '1'
        if self._check_fields:
            assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
                'Invalid arguments passed to constructor: %s' % \
                ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.enterprise_full_id_str = kwargs.get('enterprise_full_id_str', str())
        self.deployment_full_id_str = kwargs.get('deployment_full_id_str', str())
        self.slam_session_full_id_str = kwargs.get('slam_session_full_id_str', str())
        self.free_zone_full_id_str = kwargs.get('free_zone_full_id_str', str())
        self.is_in_free_zone = kwargs.get('is_in_free_zone', int())
        self.poi_full_id_str = kwargs.get('poi_full_id_str', str())
        self.poi_id = kwargs.get('poi_id', int())
        self.x = kwargs.get('x', float())
        self.y = kwargs.get('y', float())
        self.z = kwargs.get('z', float())
        self.yaw = kwargs.get('yaw', float())
        self.parking_mode = kwargs.get('parking_mode', int())
        self.is_available = kwargs.get('is_available', int())
        self.charging_mode = kwargs.get('charging_mode', int())
        self.is_long_wait_zone = kwargs.get('is_long_wait_zone', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.get_fields_and_field_types().keys(), self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    if self._check_fields:
                        assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.enterprise_full_id_str != other.enterprise_full_id_str:
            return False
        if self.deployment_full_id_str != other.deployment_full_id_str:
            return False
        if self.slam_session_full_id_str != other.slam_session_full_id_str:
            return False
        if self.free_zone_full_id_str != other.free_zone_full_id_str:
            return False
        if self.is_in_free_zone != other.is_in_free_zone:
            return False
        if self.poi_full_id_str != other.poi_full_id_str:
            return False
        if self.poi_id != other.poi_id:
            return False
        if self.x != other.x:
            return False
        if self.y != other.y:
            return False
        if self.z != other.z:
            return False
        if self.yaw != other.yaw:
            return False
        if self.parking_mode != other.parking_mode:
            return False
        if self.is_available != other.is_available:
            return False
        if self.charging_mode != other.charging_mode:
            return False
        if self.is_long_wait_zone != other.is_long_wait_zone:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def enterprise_full_id_str(self):
        """Message field 'enterprise_full_id_str'."""
        return self._enterprise_full_id_str

    @enterprise_full_id_str.setter
    def enterprise_full_id_str(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'enterprise_full_id_str' field must be of type 'str'"
        self._enterprise_full_id_str = value

    @builtins.property
    def deployment_full_id_str(self):
        """Message field 'deployment_full_id_str'."""
        return self._deployment_full_id_str

    @deployment_full_id_str.setter
    def deployment_full_id_str(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'deployment_full_id_str' field must be of type 'str'"
        self._deployment_full_id_str = value

    @builtins.property
    def slam_session_full_id_str(self):
        """Message field 'slam_session_full_id_str'."""
        return self._slam_session_full_id_str

    @slam_session_full_id_str.setter
    def slam_session_full_id_str(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'slam_session_full_id_str' field must be of type 'str'"
        self._slam_session_full_id_str = value

    @builtins.property
    def free_zone_full_id_str(self):
        """Message field 'free_zone_full_id_str'."""
        return self._free_zone_full_id_str

    @free_zone_full_id_str.setter
    def free_zone_full_id_str(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'free_zone_full_id_str' field must be of type 'str'"
        self._free_zone_full_id_str = value

    @builtins.property
    def is_in_free_zone(self):
        """Message field 'is_in_free_zone'."""
        return self._is_in_free_zone

    @is_in_free_zone.setter
    def is_in_free_zone(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'is_in_free_zone' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'is_in_free_zone' field must be an integer in [-2147483648, 2147483647]"
        self._is_in_free_zone = value

    @builtins.property
    def poi_full_id_str(self):
        """Message field 'poi_full_id_str'."""
        return self._poi_full_id_str

    @poi_full_id_str.setter
    def poi_full_id_str(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'poi_full_id_str' field must be of type 'str'"
        self._poi_full_id_str = value

    @builtins.property
    def poi_id(self):
        """Message field 'poi_id'."""
        return self._poi_id

    @poi_id.setter
    def poi_id(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'poi_id' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'poi_id' field must be an integer in [-2147483648, 2147483647]"
        self._poi_id = value

    @builtins.property
    def x(self):
        """Message field 'x'."""
        return self._x

    @x.setter
    def x(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'x' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'x' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._x = value

    @builtins.property
    def y(self):
        """Message field 'y'."""
        return self._y

    @y.setter
    def y(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'y' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'y' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._y = value

    @builtins.property
    def z(self):
        """Message field 'z'."""
        return self._z

    @z.setter
    def z(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'z' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'z' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._z = value

    @builtins.property
    def yaw(self):
        """Message field 'yaw'."""
        return self._yaw

    @yaw.setter
    def yaw(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'yaw' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'yaw' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._yaw = value

    @builtins.property
    def parking_mode(self):
        """Message field 'parking_mode'."""
        return self._parking_mode

    @parking_mode.setter
    def parking_mode(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'parking_mode' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'parking_mode' field must be an integer in [-2147483648, 2147483647]"
        self._parking_mode = value

    @builtins.property
    def is_available(self):
        """Message field 'is_available'."""
        return self._is_available

    @is_available.setter
    def is_available(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'is_available' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'is_available' field must be an integer in [-2147483648, 2147483647]"
        self._is_available = value

    @builtins.property
    def charging_mode(self):
        """Message field 'charging_mode'."""
        return self._charging_mode

    @charging_mode.setter
    def charging_mode(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'charging_mode' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'charging_mode' field must be an integer in [-2147483648, 2147483647]"
        self._charging_mode = value

    @builtins.property
    def is_long_wait_zone(self):
        """Message field 'is_long_wait_zone'."""
        return self._is_long_wait_zone

    @is_long_wait_zone.setter
    def is_long_wait_zone(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'is_long_wait_zone' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'is_long_wait_zone' field must be an integer in [-2147483648, 2147483647]"
        self._is_long_wait_zone = value
