# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from mavros/CommandLongRequest.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class CommandLongRequest(genpy.Message):
  _md5sum = "bb6840e41e614584eb95ba6c8d464953"
  _type = "mavros/CommandLongRequest"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """


uint16 CMD_DO_SET_MODE = 176
uint16 CMD_DO_JUMP = 177
uint16 CMD_DO_CHANGE_SPEED = 178
uint16 CMD_DO_SET_HOME = 179
uint16 CMD_DO_SET_RELAY = 181
uint16 CMD_DO_REPEAT_RELAY = 182
uint16 CMD_DO_SET_SERVO = 183
uint16 CMD_DO_REPEAT_SERVO = 184
uint16 CMD_DO_CONTROL_VIDEO = 200
uint16 CMD_DO_SET_ROI = 201
uint16 CMD_DO_MOUNT_CONTROL = 205
uint16 CMD_DO_SET_CAM_TRIGG_DIST = 206
uint16 CMD_DO_FENCE_ENABLE = 207
uint16 CMD_DO_PARACHUTE = 208
uint16 CMD_DO_INVERTED_FLIGHT = 210
uint16 CMD_DO_MOUNT_CONTROL_QUAT = 220
uint16 CMD_PREFLIGHT_CALIBRATION = 241
uint16 CMD_MISSION_START = 300
uint16 CMD_COMPONENT_ARM_DISARM = 400
uint16 CMD_START_RX_PAIR = 500
uint16 CMD_REQUEST_AUTOPILOT_CAPABILITIES = 520

bool broadcast

uint16 command
uint8 confirmation
float32 param1
float32 param2
float32 param3
float32 param4
float32 param5
float32 param6
float32 param7
"""
  # Pseudo-constants
  CMD_DO_SET_MODE = 176
  CMD_DO_JUMP = 177
  CMD_DO_CHANGE_SPEED = 178
  CMD_DO_SET_HOME = 179
  CMD_DO_SET_RELAY = 181
  CMD_DO_REPEAT_RELAY = 182
  CMD_DO_SET_SERVO = 183
  CMD_DO_REPEAT_SERVO = 184
  CMD_DO_CONTROL_VIDEO = 200
  CMD_DO_SET_ROI = 201
  CMD_DO_MOUNT_CONTROL = 205
  CMD_DO_SET_CAM_TRIGG_DIST = 206
  CMD_DO_FENCE_ENABLE = 207
  CMD_DO_PARACHUTE = 208
  CMD_DO_INVERTED_FLIGHT = 210
  CMD_DO_MOUNT_CONTROL_QUAT = 220
  CMD_PREFLIGHT_CALIBRATION = 241
  CMD_MISSION_START = 300
  CMD_COMPONENT_ARM_DISARM = 400
  CMD_START_RX_PAIR = 500
  CMD_REQUEST_AUTOPILOT_CAPABILITIES = 520

  __slots__ = ['broadcast','command','confirmation','param1','param2','param3','param4','param5','param6','param7']
  _slot_types = ['bool','uint16','uint8','float32','float32','float32','float32','float32','float32','float32']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       broadcast,command,confirmation,param1,param2,param3,param4,param5,param6,param7

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(CommandLongRequest, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.broadcast is None:
        self.broadcast = False
      if self.command is None:
        self.command = 0
      if self.confirmation is None:
        self.confirmation = 0
      if self.param1 is None:
        self.param1 = 0.
      if self.param2 is None:
        self.param2 = 0.
      if self.param3 is None:
        self.param3 = 0.
      if self.param4 is None:
        self.param4 = 0.
      if self.param5 is None:
        self.param5 = 0.
      if self.param6 is None:
        self.param6 = 0.
      if self.param7 is None:
        self.param7 = 0.
    else:
      self.broadcast = False
      self.command = 0
      self.confirmation = 0
      self.param1 = 0.
      self.param2 = 0.
      self.param3 = 0.
      self.param4 = 0.
      self.param5 = 0.
      self.param6 = 0.
      self.param7 = 0.

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_struct_BHB7f.pack(_x.broadcast, _x.command, _x.confirmation, _x.param1, _x.param2, _x.param3, _x.param4, _x.param5, _x.param6, _x.param7))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      _x = self
      start = end
      end += 32
      (_x.broadcast, _x.command, _x.confirmation, _x.param1, _x.param2, _x.param3, _x.param4, _x.param5, _x.param6, _x.param7,) = _struct_BHB7f.unpack(str[start:end])
      self.broadcast = bool(self.broadcast)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_struct_BHB7f.pack(_x.broadcast, _x.command, _x.confirmation, _x.param1, _x.param2, _x.param3, _x.param4, _x.param5, _x.param6, _x.param7))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      end = 0
      _x = self
      start = end
      end += 32
      (_x.broadcast, _x.command, _x.confirmation, _x.param1, _x.param2, _x.param3, _x.param4, _x.param5, _x.param6, _x.param7,) = _struct_BHB7f.unpack(str[start:end])
      self.broadcast = bool(self.broadcast)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
_struct_BHB7f = struct.Struct("<BHB7f")
# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from mavros/CommandLongResponse.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class CommandLongResponse(genpy.Message):
  _md5sum = "1cd894375e4e3d2861d2222772894fdb"
  _type = "mavros/CommandLongResponse"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """bool success

uint8 result

"""
  __slots__ = ['success','result']
  _slot_types = ['bool','uint8']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       success,result

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(CommandLongResponse, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.success is None:
        self.success = False
      if self.result is None:
        self.result = 0
    else:
      self.success = False
      self.result = 0

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_struct_2B.pack(_x.success, _x.result))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      _x = self
      start = end
      end += 2
      (_x.success, _x.result,) = _struct_2B.unpack(str[start:end])
      self.success = bool(self.success)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_struct_2B.pack(_x.success, _x.result))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      end = 0
      _x = self
      start = end
      end += 2
      (_x.success, _x.result,) = _struct_2B.unpack(str[start:end])
      self.success = bool(self.success)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
_struct_2B = struct.Struct("<2B")
class CommandLong(object):
  _type          = 'mavros/CommandLong'
  _md5sum = '2ec02bae9849b6b9d67123f2decbf605'
  _request_class  = CommandLongRequest
  _response_class = CommandLongResponse
