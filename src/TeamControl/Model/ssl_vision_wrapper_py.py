from TeamControl.Model.ssl_vision_detection_py import SSL_DetectionFrame
from TeamControl.Model.ssl_vision_geometry_py import SSL_GeometryData
import logging

log = logging.getLogger()
log.setLevel(logging.NOTSET)

class SSL_WrapperPacket:
    """re-implementation of `ssl_vision_wrapper_pb2.SSL_WrapperPacket`

    Properties
    ----------
    is_detection_frame : bool
        True if `detection` is not None, otherwise False.
    is_geometry_data : bool
        True if `geometry` is not None, otherwise False.
    detection : SSL_DetectionFrame
        object which stores the message `ssl_vision_wrapper_pb2.SSL_WrapperPacket.SSL_DetectionFrame`
    geometry : SSL_GeometryData
        object which stores the message `ssl_vision_wrapper_pb2.SSL_WrapperPacket.SSL_GeometeryData`

    Examples
    -------
    protobuf `SSL_WrapperPacket` message structure is shown below:

        message SSL_WrapperPacket {
            optional SSL_DetectionFrame detection = 1;
            optional SSL_GeometryData geometry = 2;
        }

    """
    
    def __init__(self, **kwargs) -> None:
        """
        Parameters
        ----------

        **kwargs : dict, optional
            refer to :doc:`src/TeamControl/SSL/proto2/ssl_vision_wrapper.proto` for 
            the structure of `SSL_WrapperPacket`.

        Attributes
        ----------
            see :class:`SSL_WrapperPacket`.
        """
        self._is_detection_frame = False
        self._is_geometry_data = False

        self._detection = None
        self.geometry = None

        for kw in kwargs:
            setattr(self, kw, kwargs[kw])

    @property
    def is_detection_frame(self) -> bool:
        return self._is_detection_frame
    
    @property
    def is_geometry_data(self) -> bool:
        return self._is_geometry_data

    @property
    def detection(self) -> SSL_DetectionFrame:
        return self._detection
    
    @detection.setter
    def detection(self, detection: SSL_DetectionFrame):
        if not isinstance(detection, SSL_DetectionFrame):
            log.error(f'parameter `detection` {type(detection)} is not an object of type `{SSL_DetectionFrame}`')
        self._detection = detection
    
    @property
    def geometry(self) -> SSL_GeometryData:
        return self._geometry
    
    @geometry.setter
    def geometry(self, geomety: SSL_GeometryData) -> None:
        if not isinstance(geomety, SSL_GeometryData):
            log.error(f'parameter `geomety` {type(geomety)} is not an object of type `{SSL_GeometryData}`')
        self._geometry = geomety

    def __setattr__(self, name: object, value: object) -> None:
        '''overloaded __setattr__ for handling `SSL_DetectionFrame` and `SSL_GeometryData` message field types
        '''
        match name:
            case 'detection':
                self._is_detection_frame = True
                self._detection = SSL_DetectionFrame(**value)
            
            case 'geometry':
                self._is_geometry_data = True
                self._geometry = SSL_GeometryData(**value)