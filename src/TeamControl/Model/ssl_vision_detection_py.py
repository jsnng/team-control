import logging

log = logging.getLogger()
log.setLevel(logging.NOTSET)

class SSL_DetectionBall:
    """re-implemention of `ssl_vision_detection_pb2.SSL_DetectionBall`

    Properties
    ----------
    confidence : float
        shows the probability of the ball being detected correctly by `vision_ssl` and is given as a precentage.
    area : int
        size of the detection (:math:`mm^2`)
    x, y : float
        x or y distance (mm) from the origin (center dot of the field).
    z : float, optional
        z distance (mm) from the origin (center dot of the field).
    pixel_x, pixel_y : float
        x or y coordinates of detection's center pixel 

    Examples
    --------
    An example of `google.json_format.MessageToDict()` is shown below:
    
    >>> proto2 = ssl_vision_wrapper_pb2.SSL_WrapperPacket()
    >>> from_vision_ssl = proto2.FromString(from_vision_ssl)
    >>> ssl_vision_wrapper = json_format.MessageToDict(from_vision_ssl)
    >>> print(ssl_vision_wrapper)
        'balls': [
            {
                'confidence': 0.91821826, 
                'x': 1144.5864, 
                'y': 948.55133, 
                'pixelX': 1144.5864, 
                'pixelY': 948.55133
            }
            ...
        ]
        ...

    After deserialisation to a `dict` object, a `SSL_DetectionBall` can be created
    by unpacking a dictionary object stored in list `balls` within `SSL_DetectionWrapper` object:

    >>> ball = SSL_DetectionBall(*s*ssl_vision_wrapper.balls[0])
    >>> print(ball.confidence)
        0.91821826
    """
    def __init__(self, **kwargs) -> object:
        """
        **kwargs : dict, optional
            refer to :doc:`src/TeamControl/SSL/proto2/ssl_vision_detection.proto` for 
            the structure of `SSL_DetectionBall`
        """
        for kw in kwargs:
            setattr(self, kw, kwargs[kw])

    @property
    def confidence(self) -> float:
        return self._confidence

    @confidence.setter
    def confidence(self, confidence: float) -> None:
        if not isinstance(type, float):
            log.error(f'parameter `confidence` is not an object of type `{float}`')
        self._confidence = confidence

    @property
    def area(self) -> int:
        return self._area

    @area.setter
    def area(self, area: int) -> None:
        if not isinstance(type, int):
            log.error(f'parameter `area` is not an object of type `{int}`')
        self._area = area

    @property
    def x(self) -> float:
        return self._x

    @x.setter
    def x(self, x: float) -> None:
        if not isinstance(type, float):
            log.error(f'parameter `x` is not an object of type `{float}`')
        self._x = x

    @property
    def y(self) -> float:
        return self._y

    @y.setter
    def y(self, y: float) -> None:
        if not isinstance(type, float):
            log.error(f'parameter `y` is not an object of type `{float}`')
        self._y = y

    @property
    def z(self) -> float:
        return self._z

    @z.setter
    def orientation(self, z: float) -> None:
        if not isinstance(type, float):
            log.error(f'parameter `z` is not an object of type `{float}`')
        self._z = z

    @property
    def pixel_x(self) -> float:
        return self._pixel_x

    @pixel_x.setter
    def pixel_x(self, pixel_x: float) -> None:
        if not isinstance(type, float):
            log.error(f'parameter `pixel_x` is not an object of type `{float}`')
        self._pixel_x = pixel_x

    @property
    def pixel_y(self) -> float:
        return self._pixel_y

    @pixel_y.setter
    def pixel_y(self, pixel_y: float) -> None:
        if not isinstance(type, float):
            log.error(f'parameter `pixel_y` is not an object of type `{float}`')
        self._pixel_y = pixel_y


class SSL_DetectionRobot:
    """re-implemention of `ssl_vision_detection_pb2.SSL_DetectionRobot`

    Properties
    ----------
    confidence : float
        shows the probability of the robot being detected correctly by `vision_ssl` and is given as a precentage.
    robot_id : int
        the id associated with the pattern displayed on top of the robot
    x, y : float
        x, y distance (mm) from the origin (center dot of the field).
    orientation: float, optional
        radians offset of the robot from the x-axis
    pixel_x, pixel_y : float
        x, y coordinates of detection's center pixel
    height : float, optional
        height of the robot

    Example
    -------
    An example of `google.json_format.MessageToDict()` is shown below:
    
    >>> proto2 = ssl_vision_wrapper_pb2.SSL_WrapperPacket()
    >>> from_vision_ssl = proto2.FromString(from_vision_ssl)
    >>> ssl_vision_wrapper = json_format.MessageToDict(from_vision_ssl)
    >>> print(ssl_vision_wrapper)
        'robotsYellow': [
            {
                'confidence': 1.0,
                'robotId': 0, 
                'x': 1499.9728, 
                'y': 1120.0, 
                'orientation': 3.1415927, 
                'pixelX': 1499.9728, 
                'pixelY': 1120.0
            }
            ...
        ],  
        ...
    """
    def __init__(self, **kwargs) -> object:
        """
        **kwargs : dict, optional
            refer to :doc:`src/TeamControl/SSL/proto2/ssl_vision_detection.proto` for 
            the structure of `SSL_DetectionRobot`
        """
        for kw in kwargs:
            setattr(self, kw, kwargs[kw])

    @property
    def confidence(self) -> float:
        return self._confidence

    @confidence.setter
    def confidence(self, confidence: float) -> None:
        if not isinstance(type, float):
            log.error(f'parameter `confidence` is not an object of type `{float}`')
        self._confidence = confidence

    @property
    def robotId(self) -> int:
        return self._robotId

    @robotId.setter
    def robotId(self, robotId: int) -> None:
        if not isinstance(type, int):
            log.error(f'parameter `robotId` is not an object of type `{int}`')
        self._robotId = robotId

    @property
    def x(self) -> float:
        return self._x

    @x.setter
    def x(self, x: float) -> None:
        if not isinstance(type, float):
            log.error(f'parameter `x` is not an object of type `{float}`')
        self._x = x

    @property
    def y(self) -> float:
        return self._y

    @y.setter
    def y(self, y: float) -> None:
        if not isinstance(type, float):
            log.error(f'parameter `y` is not an object of type `{float}`')
        self._y = y

    @property
    def z(self):
        return self._z

    @z.setter
    def orientation(self, z):
        if not isinstance(type, float):
            log.error(f'parameter `z` is not an object of type `{float}`')
        self._z = z

    @property
    def pixel_x(self):
        return self._pixel_x

    @pixel_x.setter
    def pixel_x(self, pixel_x):
        if not isinstance(type, float):
            log.error(f'parameter `pixel_x` is not an object of type `{float}`')
        self._pixel_x = pixel_x

    @property
    def pixel_y(self):
        return self._pixel_y

    @pixel_y.setter
    def pixel_y(self, pixel_y):
        if not isinstance(type, float):
            log.error(f'parameter `pixel_y` is not an object of type `{float}`')
        self._pixel_y = pixel_y


class SSL_DetectionFrame:
    """re-implemention of `ssl_vision_detection_pb2.SSL_DetectionFrame`

    Properties
    ----------
    frame_number : int
        sequence of the frame when captured by `vision_ssl`
    t_capture : float
        time of capture
    t_sent : float
        time when the SSL_DetectionFrame was sent
    camera_id : int
        id of the camera created the frame
    balls : list of ``SSL_DetectionBalls``
        all instances of balls detected by `vision_ssl`
    robots_yellow, robots_blue : list of ``SSL_DetectionRobot``
        all instances of robots on the `yellow` or `blue` team
    
    Examples
    --------
    An example of `google.json_format.MessageToDict()` is shown below::
    
    >>> proto2 = ssl_vision_wrapper_pb2.SSL_WrapperPacket()
    >>> from_vision_ssl = proto2.FromString(from_vision_ssl)
    >>> ssl_vision_wrapper = json_format.MessageToDict(from_vision_ssl)
    >>> print(ssl_vision_wrapper)
        {
        'detection': 
            {
                'frameNumber': 996, 
                'tCapture': 16.616666666667005, 
                'tSent': 16.616666666667005, 
                'cameraId': 0, 
                'balls': [
                    ...
                ], 
                'robotsYellow': [
                    ...
                ], 
                'robotsBlue': [
                    ...
                ]
            }
        }
    """
    def __init__(self, **kwargs) -> object:
        """
        **kwargs : dict, optional
            refer to :doc:`src/TeamControl/SSL/proto2/ssl_vision_wrapper.proto` for 
            the structure of `SSL_DetectionFrame`
        """
        for kw in kwargs:
            setattr(self, kw, kwargs[kw])

    @property
    def frame_number(self) -> int:
        return self._frame_number

    @frame_number.setter
    def frame_number(self, frame_number: int) -> None:
        if not isinstance(frame_number, int):
            log.error(f'parameter `frame_number` is not an object of type `{int}`')
        self._frame_number = frame_number

    @property
    def t_capture(self) -> float:
        return self._t_capture

    @t_capture.setter
    def t_capture(self, t_capture: float) -> None:
        if not isinstance(t_capture, float):
            log.error(f'parameter `t_capture` is not an object of type `{float}`')
        self._t_capture = t_capture

    @property
    def t_sent(self) -> float:
        return self._t_sent

    @t_sent.setter
    def t_sent(self, t_sent: float) -> None:
        if not isinstance(t_sent, float):
            log.error(f'parameter `t_sent` is not an object of type `{float}`')
        self._t_sent = t_sent

    @property
    def camera_id(self) -> int:
        return self._camera_id

    @camera_id.setter
    def camera_id(self, camera_id: int) -> None:
        if not isinstance(camera_id, int):
            log.error(f'parameter `camera_id` is not an object of type `{int}`')
        self._camera_id = camera_id

    @property
    def balls(self) -> list[SSL_DetectionBall]:
        return self._balls

    @balls.setter
    def balls(self, balls: list[SSL_DetectionBall]) -> None:
        if not isinstance(balls, list):
            log.error(f'parameter `balls` is not an object of type `{list}`')
        self._balls = balls

    @property
    def robots_yellow(self) -> list[SSL_DetectionRobot]:
        return self._robots_yellow

    @robots_yellow.setter
    def robots_yellow(self, robots_yellow: list[SSL_DetectionRobot]) -> None:
        if not isinstance(robots_yellow, list):
            log.error(f'parameter `robots_yellow` is not an object of type `{list}`')
        self._robots_yellow = robots_yellow

    @property
    def robots_blue(self) -> list[SSL_DetectionRobot]:
        return self._robots_blue

    @robots_blue.setter
    def robots_blue(self, robots_blue: list[SSL_DetectionRobot]) -> None:
        if not isinstance(robots_blue, list):
            log.error(f'parameter `robots_blue` is not an object of type `{list}`')
        self._robots_blue = robots_blue

    def __setattr__(self, name: object, value: object) -> None:
        '''overloaded __setattr__ for handling protobuf `repeated` message field
        '''
        repeated = []
        match name:
            case 'balls':
                for ball in value:
                    new_ball = SSL_DetectionBall(**ball)
                    repeated.append(new_ball)
                value = repeated

            case 'robots_yellow' | 'robots_blue':
                for robot in value:
                    new_robot = SSL_DetectionRobot(**robot)
                    repeated.append(new_robot)
                value = repeated

        object.__setattr__(self, name, value)