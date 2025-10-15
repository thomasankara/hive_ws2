# generated from rosidl_generator_py/resource/_idl.py.em
# with input from hive_interface2:msg/LaneletMini2.idl
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


class Metaclass_LaneletMini2(type):
    """Metaclass of message 'LaneletMini2'."""

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
                'hive_interface2.msg.LaneletMini2')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__lanelet_mini2
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__lanelet_mini2
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__lanelet_mini2
            cls._TYPE_SUPPORT = module.type_support_msg__msg__lanelet_mini2
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__lanelet_mini2

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class LaneletMini2(metaclass=Metaclass_LaneletMini2):
    """Message class 'LaneletMini2'."""

    __slots__ = [
        '_enterprise_full_id_str',
        '_deployment_full_id_str',
        '_slam_session_full_id_str',
        '_lanelet_mini_id',
        '_start_point_x',
        '_start_point_y',
        '_start_point_z',
        '_end_point_x',
        '_end_point_y',
        '_end_point_z',
        '_navigation_direction',
        '_border_mode',
        '_u_turn_allowed',
        '_slope_alert',
        '_vegetation_alert',
        '_offroad_alert',
        '_configuration_group_id_str',
        '_road_group_id_str',
        '_max_speed',
        '_width',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'enterprise_full_id_str': 'string',
        'deployment_full_id_str': 'string',
        'slam_session_full_id_str': 'string',
        'lanelet_mini_id': 'int32',
        'start_point_x': 'float',
        'start_point_y': 'float',
        'start_point_z': 'float',
        'end_point_x': 'float',
        'end_point_y': 'float',
        'end_point_z': 'float',
        'navigation_direction': 'int32',
        'border_mode': 'int32',
        'u_turn_allowed': 'boolean',
        'slope_alert': 'boolean',
        'vegetation_alert': 'boolean',
        'offroad_alert': 'boolean',
        'configuration_group_id_str': 'string',
        'road_group_id_str': 'string',
        'max_speed': 'int32',
        'width': 'float',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
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
        self.lanelet_mini_id = kwargs.get('lanelet_mini_id', int())
        self.start_point_x = kwargs.get('start_point_x', float())
        self.start_point_y = kwargs.get('start_point_y', float())
        self.start_point_z = kwargs.get('start_point_z', float())
        self.end_point_x = kwargs.get('end_point_x', float())
        self.end_point_y = kwargs.get('end_point_y', float())
        self.end_point_z = kwargs.get('end_point_z', float())
        self.navigation_direction = kwargs.get('navigation_direction', int())
        self.border_mode = kwargs.get('border_mode', int())
        self.u_turn_allowed = kwargs.get('u_turn_allowed', bool())
        self.slope_alert = kwargs.get('slope_alert', bool())
        self.vegetation_alert = kwargs.get('vegetation_alert', bool())
        self.offroad_alert = kwargs.get('offroad_alert', bool())
        self.configuration_group_id_str = kwargs.get('configuration_group_id_str', str())
        self.road_group_id_str = kwargs.get('road_group_id_str', str())
        self.max_speed = kwargs.get('max_speed', int())
        self.width = kwargs.get('width', float())

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
        if self.lanelet_mini_id != other.lanelet_mini_id:
            return False
        if self.start_point_x != other.start_point_x:
            return False
        if self.start_point_y != other.start_point_y:
            return False
        if self.start_point_z != other.start_point_z:
            return False
        if self.end_point_x != other.end_point_x:
            return False
        if self.end_point_y != other.end_point_y:
            return False
        if self.end_point_z != other.end_point_z:
            return False
        if self.navigation_direction != other.navigation_direction:
            return False
        if self.border_mode != other.border_mode:
            return False
        if self.u_turn_allowed != other.u_turn_allowed:
            return False
        if self.slope_alert != other.slope_alert:
            return False
        if self.vegetation_alert != other.vegetation_alert:
            return False
        if self.offroad_alert != other.offroad_alert:
            return False
        if self.configuration_group_id_str != other.configuration_group_id_str:
            return False
        if self.road_group_id_str != other.road_group_id_str:
            return False
        if self.max_speed != other.max_speed:
            return False
        if self.width != other.width:
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
    def lanelet_mini_id(self):
        """Message field 'lanelet_mini_id'."""
        return self._lanelet_mini_id

    @lanelet_mini_id.setter
    def lanelet_mini_id(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'lanelet_mini_id' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'lanelet_mini_id' field must be an integer in [-2147483648, 2147483647]"
        self._lanelet_mini_id = value

    @builtins.property
    def start_point_x(self):
        """Message field 'start_point_x'."""
        return self._start_point_x

    @start_point_x.setter
    def start_point_x(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'start_point_x' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'start_point_x' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._start_point_x = value

    @builtins.property
    def start_point_y(self):
        """Message field 'start_point_y'."""
        return self._start_point_y

    @start_point_y.setter
    def start_point_y(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'start_point_y' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'start_point_y' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._start_point_y = value

    @builtins.property
    def start_point_z(self):
        """Message field 'start_point_z'."""
        return self._start_point_z

    @start_point_z.setter
    def start_point_z(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'start_point_z' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'start_point_z' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._start_point_z = value

    @builtins.property
    def end_point_x(self):
        """Message field 'end_point_x'."""
        return self._end_point_x

    @end_point_x.setter
    def end_point_x(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'end_point_x' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'end_point_x' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._end_point_x = value

    @builtins.property
    def end_point_y(self):
        """Message field 'end_point_y'."""
        return self._end_point_y

    @end_point_y.setter
    def end_point_y(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'end_point_y' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'end_point_y' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._end_point_y = value

    @builtins.property
    def end_point_z(self):
        """Message field 'end_point_z'."""
        return self._end_point_z

    @end_point_z.setter
    def end_point_z(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'end_point_z' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'end_point_z' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._end_point_z = value

    @builtins.property
    def navigation_direction(self):
        """Message field 'navigation_direction'."""
        return self._navigation_direction

    @navigation_direction.setter
    def navigation_direction(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'navigation_direction' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'navigation_direction' field must be an integer in [-2147483648, 2147483647]"
        self._navigation_direction = value

    @builtins.property
    def border_mode(self):
        """Message field 'border_mode'."""
        return self._border_mode

    @border_mode.setter
    def border_mode(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'border_mode' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'border_mode' field must be an integer in [-2147483648, 2147483647]"
        self._border_mode = value

    @builtins.property
    def u_turn_allowed(self):
        """Message field 'u_turn_allowed'."""
        return self._u_turn_allowed

    @u_turn_allowed.setter
    def u_turn_allowed(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'u_turn_allowed' field must be of type 'bool'"
        self._u_turn_allowed = value

    @builtins.property
    def slope_alert(self):
        """Message field 'slope_alert'."""
        return self._slope_alert

    @slope_alert.setter
    def slope_alert(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'slope_alert' field must be of type 'bool'"
        self._slope_alert = value

    @builtins.property
    def vegetation_alert(self):
        """Message field 'vegetation_alert'."""
        return self._vegetation_alert

    @vegetation_alert.setter
    def vegetation_alert(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'vegetation_alert' field must be of type 'bool'"
        self._vegetation_alert = value

    @builtins.property
    def offroad_alert(self):
        """Message field 'offroad_alert'."""
        return self._offroad_alert

    @offroad_alert.setter
    def offroad_alert(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'offroad_alert' field must be of type 'bool'"
        self._offroad_alert = value

    @builtins.property
    def configuration_group_id_str(self):
        """Message field 'configuration_group_id_str'."""
        return self._configuration_group_id_str

    @configuration_group_id_str.setter
    def configuration_group_id_str(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'configuration_group_id_str' field must be of type 'str'"
        self._configuration_group_id_str = value

    @builtins.property
    def road_group_id_str(self):
        """Message field 'road_group_id_str'."""
        return self._road_group_id_str

    @road_group_id_str.setter
    def road_group_id_str(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'road_group_id_str' field must be of type 'str'"
        self._road_group_id_str = value

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

    @builtins.property
    def width(self):
        """Message field 'width'."""
        return self._width

    @width.setter
    def width(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'width' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'width' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._width = value
