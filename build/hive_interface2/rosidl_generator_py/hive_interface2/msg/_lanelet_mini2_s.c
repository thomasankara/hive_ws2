// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from hive_interface2:msg/LaneletMini2.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "hive_interface2/msg/detail/lanelet_mini2__struct.h"
#include "hive_interface2/msg/detail/lanelet_mini2__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool hive_interface2__msg__lanelet_mini2__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[48];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("hive_interface2.msg._lanelet_mini2.LaneletMini2", full_classname_dest, 47) == 0);
  }
  hive_interface2__msg__LaneletMini2 * ros_message = _ros_message;
  {  // enterprise_full_id_str
    PyObject * field = PyObject_GetAttrString(_pymsg, "enterprise_full_id_str");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->enterprise_full_id_str, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // deployment_full_id_str
    PyObject * field = PyObject_GetAttrString(_pymsg, "deployment_full_id_str");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->deployment_full_id_str, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // slam_session_full_id_str
    PyObject * field = PyObject_GetAttrString(_pymsg, "slam_session_full_id_str");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->slam_session_full_id_str, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // lanelet_mini_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "lanelet_mini_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->lanelet_mini_id = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // start_point_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "start_point_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->start_point_x = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // start_point_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "start_point_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->start_point_y = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // start_point_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "start_point_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->start_point_z = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // end_point_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "end_point_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->end_point_x = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // end_point_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "end_point_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->end_point_y = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // end_point_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "end_point_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->end_point_z = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // navigation_direction
    PyObject * field = PyObject_GetAttrString(_pymsg, "navigation_direction");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->navigation_direction = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // border_mode
    PyObject * field = PyObject_GetAttrString(_pymsg, "border_mode");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->border_mode = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // u_turn_allowed
    PyObject * field = PyObject_GetAttrString(_pymsg, "u_turn_allowed");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->u_turn_allowed = (Py_True == field);
    Py_DECREF(field);
  }
  {  // slope_alert
    PyObject * field = PyObject_GetAttrString(_pymsg, "slope_alert");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->slope_alert = (Py_True == field);
    Py_DECREF(field);
  }
  {  // vegetation_alert
    PyObject * field = PyObject_GetAttrString(_pymsg, "vegetation_alert");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->vegetation_alert = (Py_True == field);
    Py_DECREF(field);
  }
  {  // offroad_alert
    PyObject * field = PyObject_GetAttrString(_pymsg, "offroad_alert");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->offroad_alert = (Py_True == field);
    Py_DECREF(field);
  }
  {  // configuration_group_id_str
    PyObject * field = PyObject_GetAttrString(_pymsg, "configuration_group_id_str");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->configuration_group_id_str, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // road_group_id_str
    PyObject * field = PyObject_GetAttrString(_pymsg, "road_group_id_str");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->road_group_id_str, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // max_speed
    PyObject * field = PyObject_GetAttrString(_pymsg, "max_speed");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->max_speed = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // width
    PyObject * field = PyObject_GetAttrString(_pymsg, "width");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->width = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * hive_interface2__msg__lanelet_mini2__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of LaneletMini2 */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("hive_interface2.msg._lanelet_mini2");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "LaneletMini2");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  hive_interface2__msg__LaneletMini2 * ros_message = (hive_interface2__msg__LaneletMini2 *)raw_ros_message;
  {  // enterprise_full_id_str
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->enterprise_full_id_str.data,
      strlen(ros_message->enterprise_full_id_str.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "enterprise_full_id_str", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // deployment_full_id_str
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->deployment_full_id_str.data,
      strlen(ros_message->deployment_full_id_str.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "deployment_full_id_str", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // slam_session_full_id_str
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->slam_session_full_id_str.data,
      strlen(ros_message->slam_session_full_id_str.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "slam_session_full_id_str", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // lanelet_mini_id
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->lanelet_mini_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "lanelet_mini_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // start_point_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->start_point_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "start_point_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // start_point_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->start_point_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "start_point_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // start_point_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->start_point_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "start_point_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // end_point_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->end_point_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "end_point_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // end_point_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->end_point_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "end_point_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // end_point_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->end_point_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "end_point_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // navigation_direction
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->navigation_direction);
    {
      int rc = PyObject_SetAttrString(_pymessage, "navigation_direction", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // border_mode
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->border_mode);
    {
      int rc = PyObject_SetAttrString(_pymessage, "border_mode", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // u_turn_allowed
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->u_turn_allowed ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "u_turn_allowed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // slope_alert
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->slope_alert ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "slope_alert", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // vegetation_alert
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->vegetation_alert ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "vegetation_alert", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // offroad_alert
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->offroad_alert ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "offroad_alert", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // configuration_group_id_str
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->configuration_group_id_str.data,
      strlen(ros_message->configuration_group_id_str.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "configuration_group_id_str", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // road_group_id_str
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->road_group_id_str.data,
      strlen(ros_message->road_group_id_str.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "road_group_id_str", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // max_speed
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->max_speed);
    {
      int rc = PyObject_SetAttrString(_pymessage, "max_speed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // width
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->width);
    {
      int rc = PyObject_SetAttrString(_pymessage, "width", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
