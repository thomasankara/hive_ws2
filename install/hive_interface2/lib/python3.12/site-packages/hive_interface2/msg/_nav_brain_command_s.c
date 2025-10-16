// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from hive_interface2:msg/NavBrainCommand.idl
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
#include "hive_interface2/msg/detail/nav_brain_command__struct.h"
#include "hive_interface2/msg/detail/nav_brain_command__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool geometry_msgs__msg__pose_stamped__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * geometry_msgs__msg__pose_stamped__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool hive_interface2__msg__nav_brain_command__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[55];
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
    assert(strncmp("hive_interface2.msg._nav_brain_command.NavBrainCommand", full_classname_dest, 54) == 0);
  }
  hive_interface2__msg__NavBrainCommand * ros_message = _ros_message;
  {  // free_zone_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "free_zone_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->free_zone_id = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // poi_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "poi_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->poi_id = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // destination
    PyObject * field = PyObject_GetAttrString(_pymsg, "destination");
    if (!field) {
      return false;
    }
    if (!geometry_msgs__msg__pose_stamped__convert_from_py(field, &ros_message->destination)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // object_tracking_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "object_tracking_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->object_tracking_id = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // mission_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "mission_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->mission_id = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * hive_interface2__msg__nav_brain_command__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of NavBrainCommand */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("hive_interface2.msg._nav_brain_command");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "NavBrainCommand");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  hive_interface2__msg__NavBrainCommand * ros_message = (hive_interface2__msg__NavBrainCommand *)raw_ros_message;
  {  // free_zone_id
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->free_zone_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "free_zone_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // poi_id
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->poi_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "poi_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // destination
    PyObject * field = NULL;
    field = geometry_msgs__msg__pose_stamped__convert_to_py(&ros_message->destination);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "destination", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // object_tracking_id
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->object_tracking_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "object_tracking_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // mission_id
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->mission_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "mission_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
