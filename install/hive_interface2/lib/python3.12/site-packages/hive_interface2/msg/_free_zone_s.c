// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from hive_interface2:msg/FreeZone.idl
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
#include "hive_interface2/msg/detail/free_zone__struct.h"
#include "hive_interface2/msg/detail/free_zone__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool hive_interface2__msg__free_zone__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[40];
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
    assert(strncmp("hive_interface2.msg._free_zone.FreeZone", full_classname_dest, 39) == 0);
  }
  hive_interface2__msg__FreeZone * ros_message = _ros_message;
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
  {  // free_zone_full_id_str
    PyObject * field = PyObject_GetAttrString(_pymsg, "free_zone_full_id_str");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->free_zone_full_id_str, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // free_zone_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "free_zone_id");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->free_zone_id, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // is_parking_available
    PyObject * field = PyObject_GetAttrString(_pymsg, "is_parking_available");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->is_parking_available = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // is_offpoi_parking_allowed
    PyObject * field = PyObject_GetAttrString(_pymsg, "is_offpoi_parking_allowed");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->is_offpoi_parking_allowed = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // is_long_wait_zone
    PyObject * field = PyObject_GetAttrString(_pymsg, "is_long_wait_zone");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->is_long_wait_zone = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // zone_polygon_points_json
    PyObject * field = PyObject_GetAttrString(_pymsg, "zone_polygon_points_json");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->zone_polygon_points_json, PyBytes_AS_STRING(encoded_field));
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

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * hive_interface2__msg__free_zone__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of FreeZone */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("hive_interface2.msg._free_zone");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "FreeZone");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  hive_interface2__msg__FreeZone * ros_message = (hive_interface2__msg__FreeZone *)raw_ros_message;
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
  {  // free_zone_full_id_str
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->free_zone_full_id_str.data,
      strlen(ros_message->free_zone_full_id_str.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "free_zone_full_id_str", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // free_zone_id
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->free_zone_id.data,
      strlen(ros_message->free_zone_id.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "free_zone_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // is_parking_available
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->is_parking_available);
    {
      int rc = PyObject_SetAttrString(_pymessage, "is_parking_available", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // is_offpoi_parking_allowed
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->is_offpoi_parking_allowed);
    {
      int rc = PyObject_SetAttrString(_pymessage, "is_offpoi_parking_allowed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // is_long_wait_zone
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->is_long_wait_zone);
    {
      int rc = PyObject_SetAttrString(_pymessage, "is_long_wait_zone", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // zone_polygon_points_json
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->zone_polygon_points_json.data,
      strlen(ros_message->zone_polygon_points_json.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "zone_polygon_points_json", field);
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

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
