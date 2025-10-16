# generated from rosidl_generator_py/resource/_idl.py.em
# with input from hive_interface2:msg/FreeZone.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_FreeZone(type):
    """Metaclass of message 'FreeZone'."""

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
                'hive_interface2.msg.FreeZone')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__free_zone
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__free_zone
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__free_zone
            cls._TYPE_SUPPORT = module.type_support_msg__msg__free_zone
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__free_zone

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class FreeZone(metaclass=Metaclass_FreeZone):
    """Message class 'FreeZone'."""

    __slots__ = [
        '_enterprise_full_id_str',
        '_deployment_full_id_str',
        '_slam_session_full_id_str',
        '_free_zone_full_id_str',
        '_free_zone_id',
        '_is_parking_available',
        '_is_offpoi_parking_allowed',
        '_is_long_wait_zone',
        '_zone_polygon_points_json',
        '_max_speed',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'enterprise_full_id_str': 'string',
        'deployment_full_id_str': 'string',
        'slam_session_full_id_str': 'string',
        'free_zone_full_id_str': 'string',
        'free_zone_id': 'string',
        'is_parking_available': 'int32',
        'is_offpoi_parking_allowed': 'int32',
        'is_long_wait_zone': 'int32',
        'zone_polygon_points_json': 'string',
        'max_speed': 'int32',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
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
        self.free_zone_id = kwargs.get('free_zone_id', str())
        self.is_parking_available = kwargs.get('is_parking_available', int())
        self.is_offpoi_parking_allowed = kwargs.get('is_offpoi_parking_allowed', int())
        self.is_long_wait_zone = kwargs.get('is_long_wait_zone', int())
        self.zone_polygon_points_json = kwargs.get('zone_polygon_points_json', str())
        self.max_speed = kwargs.get('max_speed', int())

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
        if self.free_zone_id != other.free_zone_id:
            return False
        if self.is_parking_available != other.is_parking_available:
            return False
        if self.is_offpoi_parking_allowed != other.is_offpoi_parking_allowed:
            return False
        if self.is_long_wait_zone != other.is_long_wait_zone:
            return False
        if self.zone_polygon_points_json != other.zone_polygon_points_json:
            return False
        if self.max_speed != other.max_speed:
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
    def free_zone_id(self):
        """Message field 'free_zone_id'."""
        return self._free_zone_id

    @free_zone_id.setter
    def free_zone_id(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'free_zone_id' field must be of type 'str'"
        self._free_zone_id = value

    @builtins.property
    def is_parking_available(self):
        """Message field 'is_parking_available'."""
        return self._is_parking_available

    @is_parking_available.setter
    def is_parking_available(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'is_parking_available' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'is_parking_available' field must be an integer in [-2147483648, 2147483647]"
        self._is_parking_available = value

    @builtins.property
    def is_offpoi_parking_allowed(self):
        """Message field 'is_offpoi_parking_allowed'."""
        return self._is_offpoi_parking_allowed

    @is_offpoi_parking_allowed.setter
    def is_offpoi_parking_allowed(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'is_offpoi_parking_allowed' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'is_offpoi_parking_allowed' field must be an integer in [-2147483648, 2147483647]"
        self._is_offpoi_parking_allowed = value

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

    @builtins.property
    def zone_polygon_points_json(self):
        """Message field 'zone_polygon_points_json'."""
        return self._zone_polygon_points_json

    @zone_polygon_points_json.setter
    def zone_polygon_points_json(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'zone_polygon_points_json' field must be of type 'str'"
        self._zone_polygon_points_json = value

    @builtins.property
    def max_speed(self):
        """Message field 'max_speed'."""
        return self._max_speed

    @max_speed.setter
    def max_speed(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'max_speed' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'max_speed' field must be an integer in [-2147483648, 2147483647]"
        self._max_speed = value
